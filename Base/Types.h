/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#ifndef SECAPI_TYPES_H
#define SECAPI_TYPES_H

#ifdef SERIOUSENGINECAPI_EXPORTS
#define SECAPI __declspec(dllexport)
#include <Engine/Engine.h>
typedef __int64 int64_t;
#else
#define SECAPI __declspec(dllimport)
#include <stdint.h>

typedef int32_t BOOL;
typedef int32_t INDEX;
typedef int32_t PIX;
typedef int32_t MEX;
typedef int16_t SWORD;
typedef uint16_t UWORD;
typedef int32_t SLONG;
#ifndef BASETYPES
typedef uint32_t ULONG; // on redefinition error, make sure its included after <windows.h>
#endif
typedef uint32_t COLOR;
typedef signed char SBYTE;
typedef unsigned char UBYTE;
typedef float FLOAT;
typedef float ANGLE;
typedef float TIME;
typedef double DOUBLE;

#define MAX_SLONG ((SLONG)0x7FFFFFFFL)
#define MAX_SWORD ((UWORD)0x7FFF)
#define MAX_SBYTE ((SBYTE)0x7F)

#define MIN_SLONG ((SLONG)0x80000000L)
#define MIN_SWORD ((SWORD)0x8000)
#define MIN_SBYTE ((SBYTE)0x80)

#define MIN_ULONG ((ULONG)0x00000000L)
#define MIN_UWORD ((UWORD)0x0000)
#define MIN_UBYTE ((UBYTE)0x00)

#define MAX_ULONG ((ULONG)0xFFFFFFFFL)
#define MAX_UWORD ((UWORD)0xFFFF)
#define MAX_UBYTE ((UBYTE)0xFF)

// macros for windows/croteam true color conversion
#define CLRF_CLR(clr) ( ((clr & 0xff000000) >> 24) | \
                        ((clr & 0x00ff0000) >>  8) | \
                        ((clr & 0x0000ff00) <<  8))
#define CLR_CLRF(clrref) ( ((clrref & 0x000000ff) << 24) | \
                           ((clrref & 0x0000ff00) <<  8) | \
                           ((clrref & 0x00ff0000) >>  8))

// z-buffer depth constants
#define ZBUF_FRONT  (0.0f)
#define ZBUF_BACK   (1.0f)

// alpha factor constants
#define CT_OPAQUE      MAX_UBYTE
#define CT_TRANSPARENT MIN_UBYTE

// line types (masks)
#define _FULL_	   0xFFFFFFFF
#define _SYMMET16_ 0xFF88FF88
#define _SYMMET32_ 0xFFFF0180
#define _POINT_    0xAAAAAAAA

#define _DOT2_	   0xCCCCCCCC
#define _DOT4_	   0xF0F0F0F0
#define _DOT8_	   0xFF00FF00
#define _DOT16_    0xFFFF0000

#define _TY31_	   0xEEEEEEEE
#define _TY62_	   0xFCFCFCFC
#define _TY124_    0xFFF0FFF0
#define _TY13_	   0x88888888
#define _TY26_	   0xC0C0C0C0
#define _TY412_    0xF000F000

// some mexels constants
#define MAX_MEX_LOG2 10
#define MIN_MEX_LOG2  0
#define MAX_MEX     (1L<<MAX_MEX_LOG2)
#define MIN_MEX     (1L<<MIN_MEX_LOG2)

// macro for converting mexels to meters
#define METERS_MEX(mex)    ((FLOAT)(((FLOAT)mex)/MAX_MEX))
#define MEX_METERS(meters) ((MEX)(meters*MAX_MEX))

// sound volume constants
#define SL_VOLUME_MIN (0.0f)
#define SL_VOLUME_MAX (4.0f)

// standard angles
#define ANGLE_0    (  0.0f)
#define ANGLE_90   ( 90.0f)
#define ANGLE_180  (180.0f)
#define ANGLE_270  (270.0f)
#define ANGLE_360  (360.0f)

#define _SE_DEMO            0   // set for demo versions
#define _SE_BUILD_MAJOR 10000   // use new number for each released version
#define _SE_BUILD_MINOR     7   // minor versions that are data-compatibile, but are not netgame-compatibile
#define _SE_BUILD_EXTRA    ""   // extra version with minor code changes
#define _SE_VER_STRING  "1.07"  // usually shown in server browser, etc

inline float UpperLimit(float x) { return +3E38f; }
inline float LowerLimit(float x) { return -3E38f; }
inline double UpperLimit(double x) { return +1E308; }
inline double LowerLimit(double x) { return -1E308; }
inline SLONG UpperLimit(SLONG x) { return MAX_SLONG; }
inline SLONG LowerLimit(SLONG x) { return MIN_SLONG; }
inline SWORD UpperLimit(SWORD x) { return MAX_SWORD; }
inline SWORD LowerLimit(SWORD x) { return MIN_SWORD; }

#endif

typedef INDEX SurfaceShadingType_;
typedef INDEX SurfaceTranslucencyType_;
typedef INDEX ParticleBlendType_;
typedef INDEX GfxAPIType_;
typedef INDEX DisplayDepth_;
typedef INDEX SoundFormat_;
typedef INDEX LayerType_;
typedef INDEX FillType_;
typedef INDEX SelectionType_;
typedef INDEX ShadowsType_;
typedef INDEX LensFlaresType_;
typedef INDEX PropertyType_;
typedef INDEX RenderType_;
typedef INDEX TestType_;
typedef INDEX WorldMirrorType_;
typedef INDEX EEditingTool_;
typedef INDEX BufferType_;
typedef INDEX SelectionFill_;
typedef INDEX FPUPrecisionType_;
typedef INDEX GfxBlend_;
typedef INDEX GfxBlendEquation_;

typedef struct FLOAT2D_ FLOAT2D_;
typedef struct FLOAT3D_ FLOAT3D_;
typedef struct FLOAT4D_ FLOAT4D_;
typedef FLOAT3D_ ANGLE3D_;
typedef struct DOUBLE2D_ DOUBLE2D_;
typedef struct DOUBLE3D_ DOUBLE3D_;
typedef struct DOUBLE4D_ DOUBLE4D_;
typedef struct INDEX2D_ INDEX2D_;
typedef struct INDEX3D_ INDEX3D_;
typedef struct INDEX4D_ INDEX4D_;
typedef INDEX2D_ PIX2D_;
typedef INDEX2D_ MEX2D_;
typedef struct SWORD3D_ SWORD3D_;
typedef struct SBYTE3D_ SBYTE3D_;
typedef SWORD3D_ SWPOINT3D_;
typedef SBYTE3D_ SBPOINT3D_;

typedef struct GFXTexCoord_ GFXTexCoord_;
typedef struct GFXTexCoord4_ GFXTexCoord4_;
typedef struct GFXColor_ GFXColor_;
typedef struct GFXVertex3_ GFXVertex3_;
typedef struct GFXVertex4_ GFXVertex4_;
typedef struct GFXNormal3_ GFXNormal3_;
typedef struct GFXNormal4_ GFXNormal4_;

typedef struct FLOATmatrix2D_ FLOATmatrix2D_;
typedef struct FLOATmatrix3D_ FLOATmatrix3D_;
typedef struct FLOATmatrix4D_ FLOATmatrix4D_;
typedef FLOATmatrix3D_ ANGLEmatrix3D_;
typedef struct DOUBLEmatrix2D_ DOUBLEmatrix2D_;
typedef struct DOUBLEmatrix3D_ DOUBLEmatrix3D_;
typedef struct DOUBLEmatrix4D_ DOUBLEmatrix4D_;
typedef struct INDEXmatrix2D_ INDEXmatrix2D_;
typedef struct INDEXmatrix3D_ INDEXmatrix3D_;
typedef struct INDEXmatrix4D_ INDEXmatrix4D_;
typedef INDEXmatrix2D_ PIXmatrix2D_;
typedef INDEXmatrix2D_ MEXmatrix2D_;

typedef struct INDEXaabbox2D_ INDEXaabbox2D_;
typedef INDEXaabbox2D_ PIXaabbox2D_;
typedef INDEXaabbox2D_ MEXaabbox2D_;
typedef struct FLOATaabbox2D_ FLOATaabbox2D_;
typedef struct FLOATaabbox3D_ FLOATaabbox3D_;
typedef struct DOUBLEaabbox2D_ DOUBLEaabbox2D_;
typedef struct DOUBLEaabbox3D_ DOUBLEaabbox3D_;

typedef struct FLOATobbox3D_ FLOATobbox3D_;
typedef struct DOUBLEobbox3D_ DOUBLEobbox3D_;

typedef struct CPlacement3D_ CPlacement3D_;

typedef struct FLOATquat3D_ FLOATquat3D_;
typedef struct DOUBLEquat3D_ DOUBLEquat3D_;

typedef struct FLOATplane3D_ FLOATplane3D_;
typedef struct DOUBLEplane3D_ DOUBLEplane3D_;

typedef struct CProjection3D_ CProjection3D_;
typedef struct CPerspectiveProjection3D_ CPerspectiveProjection3D_;
typedef struct CIsometricProjection3D_ CIsometricProjection3D_;
typedef struct CParallelProjection3D_ CParallelProjection3D_;
typedef struct CSimpleProjection3D_ CSimpleProjection3D_;
typedef struct CAnyProjection3D_ CAnyProjection3D_;
typedef struct CSimpleProjection3D_DOUBLE_ CSimpleProjection3D_DOUBLE_;

typedef struct CPlanarGradients_ CPlanarGradients_;
typedef struct CMappingDefinitionUI_ CMappingDefinitionUI_;
typedef struct CMappingVectors_ CMappingVectors_;
typedef struct CMappingDefinition_ CMappingDefinition_;

typedef struct CTCriticalSection_ CTCriticalSection_;
typedef struct CTSingleLock_ CTSingleLock_;
typedef struct CTimerValue_ CTimerValue_;
typedef struct CTimerHandler_ CTimerHandler_;
typedef struct CUpdateable_ CUpdateable_;
typedef struct CUpdateableRT_ CUpdateableRT_;
typedef struct CChangeable_ CChangeable_;
typedef struct CChangeableRT_ CChangeableRT_;
typedef struct CSerial_ CSerial_;
typedef struct CAnimInfo_ CAnimInfo_;
typedef struct COneAnim_ COneAnim_;
typedef struct CAnimData_ CAnimData_;
typedef struct CAnimObject_ CAnimObject_;
typedef struct CChunkID_ CChunkID_;
typedef struct CListNode_ CListNode_;
typedef struct CListHead_ CListHead_;
typedef struct CRelationLnk_ CRelationLnk_;
typedef struct CTStream_ CTStream_;
typedef struct CTFileStream_ CTFileStream_;
typedef struct CTMemoryStream_ CTMemoryStream_;
typedef struct CTString_ CTString_;
typedef struct CTFileName_ CTFileName_;
typedef struct CTranslationPair_ CTranslationPair_;

typedef struct CDynamicArray_FLOAT_ CDynamicArray_FLOAT_;
typedef struct CDynamicArray_CTString_ CDynamicArray_CTString_;
typedef struct CDynamicArray_CTFileName_ CDynamicArray_CTFileName_;
typedef struct CDynamicArray_CTranslationPair_ CDynamicArray_CTranslationPair_;
typedef struct CDynamicArray_CModelCollisionBox_ CDynamicArray_CModelCollisionBox_;
typedef struct CDynamicArray_CAttachedModelPosition_ CDynamicArray_CAttachedModelPosition_;
typedef struct CDynamicArray_CObjectPolygonEdge_ CDynamicArray_CObjectPolygonEdge_;
typedef struct CDynamicArray_CObjectEdge_ CDynamicArray_CObjectEdge_;
typedef struct CDynamicArray_CObjectVertex_ CDynamicArray_CObjectVertex_;
typedef struct CDynamicArray_CObjectPlane_ CDynamicArray_CObjectPlane_;
typedef struct CDynamicArray_CObjectMaterial_ CDynamicArray_CObjectMaterial_;
typedef struct CDynamicArray_CObjectPolygon_ CDynamicArray_CObjectPolygon_;
typedef struct CDynamicArray_CObjectSector_ CDynamicArray_CObjectSector_;
typedef struct CDynamicArray_CBrushSector_ CDynamicArray_CBrushSector_;

typedef struct CDynamicStackArray_FLOAT_ CDynamicStackArray_FLOAT_;
typedef struct CDynamicStackArray_CTString_ CDynamicStackArray_CTString_;
typedef struct CDynamicStackArray_CTFileName_ CDynamicStackArray_CTFileName_;

typedef struct CStaticArray_PolygonsPerPatch_ CStaticArray_PolygonsPerPatch_;
typedef struct CStaticArray_ModelPolygon_ CStaticArray_ModelPolygon_;
typedef struct CStaticArray_ModelTextureVertex_ CStaticArray_ModelTextureVertex_;
typedef struct CStaticArray_MappingSurface_ CStaticArray_MappingSurface_;
typedef struct CStaticArray_ModelFrameVertex8_ CStaticArray_ModelFrameVertex8_;
typedef struct CStaticArray_ModelFrameVertex16_ CStaticArray_ModelFrameVertex16_;
typedef struct CStaticArray_ModelFrameInfo_ CStaticArray_ModelFrameInfo_;
typedef struct CStaticArray_TransformedVertexData_ CStaticArray_TransformedVertexData_;
typedef struct CStaticArray_ModelPolygonVertex_ CStaticArray_ModelPolygonVertex_;
typedef struct CStaticArray_UWORD_ CStaticArray_UWORD_;
typedef struct CStaticArray_ULONG_ CStaticArray_ULONG_;
typedef struct CStaticArray_SLONG_ CStaticArray_SLONG_;
typedef struct CStaticArray_INDEX_ CStaticArray_INDEX_;
typedef struct CStaticArray_FLOAT2D_ CStaticArray_FLOAT2D_;
typedef struct CStaticArray_FLOAT3D_ CStaticArray_FLOAT3D_;
typedef struct CStaticArray_DOUBLE3D_ CStaticArray_DOUBLE3D_;
typedef struct CStaticArray_PIX2D_ CStaticArray_PIX2D_;
typedef struct CStaticArray_GFXColor_ CStaticArray_GFXColor_;
typedef struct CStaticArray_GFXTexCoord_ CStaticArray_GFXTexCoord_;
typedef struct CStaticArray_GFXVertex4_ CStaticArray_GFXVertex4_;
typedef struct CStaticArray_TileLayer_ CStaticArray_TileLayer_;
typedef struct CStaticArray_TileArrays_ CStaticArray_TileArrays_;
typedef struct CStaticArray_QuadTreeNode_ CStaticArray_QuadTreeNode_;
typedef struct CStaticArray_QuadTreeLevel_ CStaticArray_QuadTreeLevel_;
typedef struct CStaticArray_CTerrainTile_ CStaticArray_CTerrainTile_;
typedef struct CStaticArray_CArrayHolder_ CStaticArray_CArrayHolder_;
typedef struct CStaticArray_CTerrainLayer_ CStaticArray_CTerrainLayer_;
typedef struct CStaticArray_CBrushVertex_ CStaticArray_CBrushVertex_;
typedef struct CStaticArray_CBrushPolygon_ CStaticArray_CBrushPolygon_;
typedef struct CStaticArray_CBrushPolygonEdge_ CStaticArray_CBrushPolygonEdge_;
typedef struct CStaticArray_CBrushVertexPtr__ CStaticArray_CBrushVertexPtr__;
typedef struct CStaticArray_CBrushEdge_ CStaticArray_CBrushEdge_;
typedef struct CStaticArray_CBrushPlane_ CStaticArray_CBrushPlane_;
typedef struct CStaticArray_CTextureTransformation_ CStaticArray_CTextureTransformation_;
typedef struct CStaticArray_CTextureBlending_ CStaticArray_CTextureBlending_;
typedef struct CStaticArray_CSurfaceType_ CStaticArray_CSurfaceType_;
typedef struct CStaticArray_CContentType_ CStaticArray_CContentType_;
typedef struct CStaticArray_CEnvironmentType_ CStaticArray_CEnvironmentType_;
typedef struct CStaticArray_CIlluminationType_ CStaticArray_CIlluminationType_;

typedef struct CStaticStackArray_PIX2D_ CStaticStackArray_PIX2D_;
typedef struct CStaticStackArray_FLOAT3D_ CStaticStackArray_FLOAT3D_;
typedef struct CStaticStackArray_SLONG_ CStaticStackArray_SLONG_;
typedef struct CStaticStackArray_INDEX_ CStaticStackArray_INDEX_;
typedef struct CStaticStackArray_GFXColor_ CStaticStackArray_GFXColor_;
typedef struct CStaticStackArray_GFXTexCoord_ CStaticStackArray_GFXTexCoord_;
typedef struct CStaticStackArray_GFXVertex4_ CStaticStackArray_GFXVertex4_;
typedef struct CStaticStackArray_TileLayer_ CStaticStackArray_TileLayer_;
typedef struct CStaticStackArray_TileArrays_ CStaticStackArray_TileArrays_;
typedef struct CStaticStackArray_QuadTreeNode_ CStaticStackArray_QuadTreeNode_;
typedef struct CStaticStackArray_QuadTreeLevel_ CStaticStackArray_QuadTreeLevel_;
typedef struct CStaticStackArray_CTerrainLayer_ CStaticStackArray_CTerrainLayer_;

typedef struct CDynamicContainer_CTextureData_ CDynamicContainer_CTextureData_;
typedef struct CDynamicContainer_CBrushVertex_ CDynamicContainer_CBrushVertex_;
typedef struct CDynamicContainer_CBrushPolygon_ CDynamicContainer_CBrushPolygon_;
typedef struct CDynamicContainer_CBrushSector_ CDynamicContainer_CBrushSector_;
typedef struct CDynamicContainer_CEntity_ CDynamicContainer_CEntity_;

typedef struct CSelection_CBrushVertex_ CSelection_CBrushVertex_;
typedef CSelection_CBrushVertex_ CBrushVertexSelection_;
typedef struct CSelection_CBrushPolygon_ CSelection_CBrushPolygon_;
typedef CSelection_CBrushPolygon_ CBrushPolygonSelection_;
typedef struct CSelection_CBrushSector_ CSelection_CBrushSector_;
typedef CSelection_CBrushSector_ CBrushSectorSelection_;
typedef struct CSelection_CEntity_ CSelection_CEntity_;
typedef CSelection_CEntity_ CEntitySelection_;

typedef struct CImageInfo_ CImageInfo_;
typedef struct CTextureData_ CTextureData_;
typedef struct CTextureObject_ CTextureObject_;

typedef struct ModelPolygonVertex_ ModelPolygonVertex_;
typedef struct PolygonsPerPatch_ PolygonsPerPatch_;
typedef struct ModelPolygon_ ModelPolygon_;
typedef struct ModelTextureVertex_ ModelTextureVertex_;
typedef struct MappingSurface_ MappingSurface_;
typedef struct ModelFrameVertex8_ ModelFrameVertex8_;
typedef struct ModelFrameVertex16_ ModelFrameVertex16_;
typedef struct ModelFrameInfo_ ModelFrameInfo_;
typedef struct TransformedVertexData_ TransformedVertexData_;
typedef struct CModelCollisionBox_ CModelCollisionBox_;
typedef struct CAttachedModelPosition_ CAttachedModelPosition_;
typedef struct CMipInfo_ CMipInfo_;
typedef struct CModelInfo_ CModelInfo_;
typedef struct CModelPatch_ CModelPatch_;
typedef struct ModelMipInfo_ ModelMipInfo_;
typedef struct CModelData_ CModelData_;
typedef struct CModelRenderPrefs_ CModelRenderPrefs_;
typedef struct CRenderModel_ CRenderModel_;
typedef struct CModelObject_ CModelObject_;
typedef struct CAttachmentModelObject_ CAttachmentModelObject_;

typedef struct CFontCharData_ CFontCharData_;
typedef struct CFontData_ CFontData_;
typedef struct CRaster_ CRaster_;
typedef struct CViewPort_ CViewPort_;
typedef struct CDrawPort_ CDrawPort_;
typedef struct CDisplayMode_ CDisplayMode_;
typedef struct CDisplayModeEnumerator_ CDisplayModeEnumerator_;

typedef struct CSoundData_ CSoundData_;
typedef struct CSoundObject_ CSoundObject_;
typedef struct CSoundListener_ CSoundListener_;

typedef struct CEntityPropertyEnumValue_ CEntityPropertyEnumValue_;
typedef struct CEntityPropertyEnumType_ CEntityPropertyEnumType_;
typedef struct CEntityProperty_ CEntityProperty_;
typedef struct CDLLEntityClass_ CDLLEntityClass_;
typedef struct CEntityClass_ CEntityClass_;
typedef struct CEntityPointer_ CEntityPointer_;
typedef struct CEntity_ CEntity_;
typedef struct CEntityEvent_ CEntityEvent_;
typedef struct CShadingInfo_ CShadingInfo_;

typedef struct GameGUI_interface_ GameGUI_interface_;

typedef struct CTerrainLayer_ CTerrainLayer_;
typedef struct TileLayer_ TileLayer_;
typedef struct TileArrays_ TileArrays_;
typedef struct CArrayHolder_ CArrayHolder_;
typedef struct CTerrainTile_ CTerrainTile_;
typedef struct CTerrain_ CTerrain_;
typedef struct QuadTreeNode_ QuadTreeNode_;
typedef struct QuadTreeLevel_ QuadTreeLevel_;
typedef struct Rect_ Rect_;

typedef struct CObjectVertex_ CObjectVertex_;
typedef struct CObjectPlane_ CObjectPlane_;
typedef struct CObjectEdge_ CObjectEdge_;
typedef struct CObjectMaterial_ CObjectMaterial_;
typedef struct CObjectPolygonEdge_ CObjectPolygonEdge_;
typedef struct CObjectPolygon_ CObjectPolygon_;
typedef struct CObjectSector_ CObjectSector_;
typedef struct CEdgeEx_ CEdgeEx_;
typedef struct CObject3D_ CObject3D_;

typedef struct CWorkingVertex_ CWorkingVertex_;
typedef struct CWorkingPlane_ CWorkingPlane_;
typedef struct CWorkingEdge_ CWorkingEdge_;
typedef struct CBrushVertex_ CBrushVertex_;
typedef struct CBrushVertex_ *CBrushVertexPtr_;
typedef struct CBrushPlane_ CBrushPlane_;
typedef struct CBrushEdge_ CBrushEdge_;
typedef struct CBrushPolygonEdge_ CBrushPolygonEdge_;
typedef struct CBrushShadowLayer_ CBrushShadowLayer_;
typedef struct CBrushShadowMap_ CBrushShadowMap_;
typedef struct CBrushPolygonTexture_ CBrushPolygonTexture_;
typedef struct CBrushPolygonProperties_ CBrushPolygonProperties_;
typedef struct CBrushPolygon_ CBrushPolygon_;
typedef struct CBrushSector_ CBrushSector_;
typedef struct CBrushMip_ CBrushMip_;
typedef struct CBrush3D_ CBrush3D_;

typedef struct CLightSource_ CLightSource_;

typedef struct CWorldRenderPrefs_ CWorldRenderPrefs_;

typedef struct CTextureTransformation_ CTextureTransformation_;
typedef struct CTextureBlending_ CTextureBlending_;
typedef struct CSurfaceType_ CSurfaceType_;
typedef struct CContentType_ CContentType_;
typedef struct CEnvironmentType_ CEnvironmentType_;
typedef struct CIlluminationType_ CIlluminationType_;
typedef struct CCastRay_ CCastRay_;
typedef struct CWorld_ CWorld_;

typedef struct CProfileForm_ CProfileForm_;
typedef struct CShellSymbol_ CShellSymbol_;

#define MEMBER_VAL_DECL(baseclass, member_type, member_var) member_type* baseclass##_##member_var(baseclass##_* p);
#define MEMBER_PTR_DECL(baseclass, member_type, member_var) member_type** baseclass##_##member_var(baseclass##_* p);
#define MEMBER_ARR_DECL(baseclass, member_type, member_var) member_type* baseclass##_##member_var(baseclass##_* p, INDEX i);

#ifdef SERIOUSENGINECAPI_EXPORTS

#define MEMBER_VAL_IMPL(baseclass, member_type, member_var) \
member_type* baseclass##_##member_var(baseclass##_* p) \
{ \
  baseclass& bc = *((baseclass*)p); \
  return (member_type*)(&(bc.member_var)); \
}

#define MEMBER_PTR_IMPL(baseclass, member_type, member_var) \
member_type** baseclass##_##member_var(baseclass##_* p) \
{ \
  baseclass& bc = *((baseclass*)p); \
  return (member_type**)(&(bc.member_var)); \
}

#define MEMBER_ARR_IMPL(baseclass, member_type, member_var) \
member_type* baseclass##_##member_var(baseclass##_* p, INDEX i) \
{ \
  baseclass& bc = *((baseclass*)p); \
  return (member_type*)(&(bc.member_var[i])); \
}

#endif

#ifdef __cplusplus
extern "C" {
#endif

SECAPI BOOL HasException();
SECAPI char* GrabException();

#ifdef __cplusplus
}
#endif

void SetException(char* s);

#define SECAPI_TRY\
  try {
#define SECAPI_CATCH\
  } catch (char* e) { SetException(e); }
#define STREAM_TRY\
  __try {
#define STREAM_CATCH\
  }\
  __except(CTStream::ExceptionFilter(GetExceptionCode(), GetExceptionInformation()))\
  {\
     CTStream::ExceptionFatalError();\
  }

#endif
