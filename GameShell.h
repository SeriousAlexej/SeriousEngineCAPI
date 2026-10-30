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

#ifndef SECAPI_GAME_SHELL_H
#define SECAPI_GAME_SHELL_H
#include "Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI GameGUI_interface_* GameGUI_interface_new();
SECAPI void GameGUI_interface_delete(GameGUI_interface_* p);
SECAPI void GameGUI_interface_Initialize(GameGUI_interface_* p, const CTFileName_* f);
SECAPI void GameGUI_interface_End(GameGUI_interface_* p);
SECAPI void GameGUI_interface_QuickTest(GameGUI_interface_* p, const CTFileName_* fnMapName, CDrawPort_* pdp, CViewPort_* pvp);

#ifdef __cplusplus
}
#endif

#endif
