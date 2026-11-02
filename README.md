# Serious Engine C API

This repository contains C bindings for the original `Engine.dll` of the **Serious Sam - The Second Encounter** game.

They provide `C API` with stable **ABI** to the engine and enable its usage by other languages and newer C++ compilers.

The bindings are mostly complete, but lack some areas, like *Network* subsystem.

Building
--------

This repository is primarily intended to be built with the *Microsoft Visual C++ 6.0* against the *Serious Sam - The Second Encounter SDK v1.07*.

However, this is not a hard requirement - the project could be adapted for the newer version of the engine (i.e. 1.10) and built with other compiler, but some source files contain assembly patches and extensions for the original `Engine.dll` that would need to be made optional (see *Binary patches*).

Prebuilt binary
---------------

Prebuilt `SeriousEngineCAPI.dll` and `SeriousEngineCAPI.lib` are included in the repository.

They were built with the *Microsoft Visual C++ 6.0* against the *Serious Sam - The Second Encounter SDK v1.07*.

Binary patches
--------------

Parts of the engine's behaviour are not reachable through its exported API, so this DLL rewrites a few instructions inside the loaded `Engine.dll` at run time (`VirtualProtect` + `memcpy`). Only the module in memory is touched, not the file on disk.

All offsets below are relative to the engine module base, which each patcher derives from a known export: `&CEntity::HandleSentEvents - 0xFEC80`. They are valid **only for `Engine.dll` v1.07** and must be re-derived for any other build.

### Recursive stream handling - `Base/Stream.cpp` : `PatchStream`

Turns the thread stream-handling flag (`_bThreadCanHandleStreams` or `[ESI+8]` in the engine's per-thread block) from a boolean into a reference counter, by rewriting 12 bytes inside `CTStream::EnableStreamHandling` (at `0x2749A`) and 10 bytes inside `CTStream::DisableStreamHandling` (at `0x27506`). This makes `CTSTREAM_BEGIN` / `CTSTREAM_END` nestable - and with them the C API calls that stream - so that the innermost one no longer disables stream handling for the outer ones.

Applied once, on the first `CTStream_ExecuteWithStreamHandling` call.

### Blend equation for OpenGL and D3D - `Engine.cpp` : `PatchInitContext_OGL` and `PatchGFX_SetFunctionPointers`

Adds `gfxBlendEquation` support, exposed publicly through `Shader.h` as `shaBlendEquation_` and `shaGetBlendEquation_`. This one is a two-level patch, because the added work has to happen at the engine's own GFX-context and renderer-switch points:

- The call to `ReloadTextures` in `InitContext_OGL` is replaced by a call to `InitContext_OGL_Extra` (5 bytes at `0x58037`), which resolves `glBlendEquation` through the engine's own `wglGetProcAddress` pointer and then calls `ReloadTextures` itself.
- `GFX_SetFunctionPointers` itself is left alone, instead all six of its call sites (`0x6203C`, `0x621D7`, `0x659DD`, `0x65C2E`, `0x65E25`, `0x65FD7`) are redirected to `GFX_SetFunctionPointers_Extra`, which installs the OGL / D3D / no-op pair of implementations for the API being activated and then calls the original.

Applied on `SE_InitEngine_` and `SE_InitEngineAtDirectory_` calls.

### Matrix decomposition precision - `Engine.cpp` : `PatchDecomposeMatrixPrecision`

A single byte at `0x2F275` redirects the `FCOMP` operand of the `if (a < 0.001)` test inside `DecomposeRotationMatrixNoSnap` from the engine's `0.001` double to its own `0.0001` double - the more precise constant the engine already uses in `void operator^=(ANGLE3D &a3dAngles, const DOUBLEmatrix3D &t3dRotation)` in `Geometry.cpp`. Minor accuracy improvement.

Applied together with the two patches above.

### Engine paths for embedded hosts - `Engine.cpp` : `SE_InitEngineAtDirectory_`

`SE_InitEngine` derives `_fnmApplicationPath` and `_fnmApplicationExe` from `GetModuleFileNameA`, i.e. from whatever process loaded the engine. When the engine is driven from an interpreted language such as Python, that is the path of the `python` executable rather than the path of the `.py` script, and everything resolved from it breaks from that point on.

`SE_InitEngineAtDirectory_` assigns `_fnmApplicationPath` and `_fnmApplicationExe` from its own arguments and defaults `_strLogFile`, then writes a 5-byte `jmp` at `SE_InitEngine + 0x44` that jumps over that derivation block, into the first instruction after it. The jump is temporary: the 5 original bytes are read out beforehand and written back as soon as `SE_InitEngine` returns.

### Missing-resource file requester - `Engine.cpp` : `PatchReplaceFile`

When a map opened in *Serious Editor* is missing a resource (a texture, a model, ...), `Engine.dll` asks for a replacement through a hardcoded callback: `CallFileRequester` in `Base/ReplaceFile.cpp` does `GetModuleHandleA("EngineGUI.dll")` and then `GetProcAddress` for the mangled name it expects to find there. The patch overwrites the `"EngineGUI.dll"` string literal at `0x1DB318` with `"SeriousEngineCAPI.dll"`, so that lookup resolves this DLL instead. The overwrite is safe because the literal is stored twice, 16 bytes apart: the 22-byte write covers the first copy plus padding, and only spills into the second copy, which is used solely as the name printed in the `Cannot load %s` warning.

The other half of the mechanism is on the binding side: this DLL re-exports its own `FileRequester` under exactly the mangled name the engine looks up (`#pragma comment(linker, "/export:CAPIFileRequester=?FileRequester@@YA?AVCTFileName@@PAD000@Z")`), and that implementation forwards to the callback registered with `SetFileRequesterCallback`. Applied on the first `SetFileRequesterCallback` call.

### Lasso entity selection - `Rendering/Render.cpp` : `PatchSelection`

Lets the host listen and react while the user drags a lasso over entities in *Serious Editor*, which the Qt-based property tree and event-driven selection depend on. `SelectEntityOnRender` (engine's `Rendering/SelectOnRender.cpp`) projects each entity's bounding box against the lasso and, on a hit, calls `_pselenSelectOnRender->Deselect(en)` or `->Select(en)`. Those calls are inlined by MSVC 6.0, so the 14-byte patches at `0xF968A` and `0xF96CF` replace the inlined bodies rather than `call` instructions: `push EBX` (the `CEntity&`, already in that register), `call OnLassoDeselection` / `OnLassoSelection`, `add ESP,4` - stack cleanup after pushing before the call, then `jmp` to the epilogue of the function, which is where the original branch ended anyway. The engine's lasso test and its `IsSelected` checks still run, and the entity itself is otherwise unaffected.

Because the engine's own selection object is bypassed, the C API points `_pselenSelectOnRender` at a private dummy `CEntitySelection`, so that the engine still takes those branches. Callbacks are registered with `SetLassoSelectionCallback` and `SetLassoDeselectionCallback`, the patch is applied on the first such call.

### Engine internals read by computed address

Not patches, but the same `module base + offset` trick is used wherever the engine keeps a value or a helper that it does not export:

- `GetGroFileCount`, `_GetGroFileAtIndex` and `_GetGroFileArchiveAtIndex` in `Base/Stream.cpp` call the engine's internal archive listing helpers (`0x2DC30`, `0x2DC40`).
- `Particle_GetProjection_` in `Graphics/DrawPort.cpp` reads the projection that the engine keeps for the particle rendering pass (`0x1F64C8`).
- The blend-equation code above reads the engine's `wglGetProcAddress` (`0x1FA4D4`) and `glGetIntegerv` (`0x1F9E60`) pointers, and calls its `ReloadTextures` (`0x61AF0`).
