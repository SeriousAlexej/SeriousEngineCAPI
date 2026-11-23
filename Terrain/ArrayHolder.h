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

#ifndef SECAPI_TERRAIN_ARRAY_HOLDER_H
#define SECAPI_TERRAIN_ARRAY_HOLDER_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI TileLayer_* TileLayer_new();
SECAPI void TileLayer_delete(TileLayer_* p);
SECAPI void TileLayer_copy(TileLayer_* a, const TileLayer_* b);
SECAPI CStaticStackArray_INDEX_* TileLayer_tl_auiIndices(TileLayer_* p);
SECAPI CStaticStackArray_GFXColor_* TileLayer_tl_acColors(TileLayer_* p);
SECAPI CStaticStackArray_GFXTexCoord_* TileLayer_tl_atcTexCoords(TileLayer_* p);
SECAPI CStaticStackArray_GFXVertex4_* TileLayer_tl_avVertices(TileLayer_* p);

SECAPI TileArrays_* TileArrays_new();
SECAPI void TileArrays_delete(TileArrays_* p);
SECAPI void TileArrays_copy(TileArrays_* a, const TileArrays_* b);
SECAPI CStaticStackArray_GFXVertex4_* TileArrays_ta_avVertices(TileArrays_* p);
SECAPI CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvTexCoords(TileArrays_* p);
SECAPI CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvShadowMap(TileArrays_* p);
SECAPI CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvDetailMap(TileArrays_* p);
SECAPI CStaticStackArray_INDEX_* TileArrays_ta_auiIndices(TileArrays_* p);
SECAPI CStaticStackArray_TileLayer_* TileArrays_ta_atlLayers(TileArrays_* p);
SECAPI CTextureData_** TileArrays_ta_ptdTopMap(TileArrays_* p);

SECAPI CArrayHolder_* CArrayHolder_new();
SECAPI void CArrayHolder_delete(CArrayHolder_* p);
SECAPI INDEX CArrayHolder_GetNewArrays(CArrayHolder_* p);
SECAPI void CArrayHolder_FreeArrays(CArrayHolder_* p, INDEX i);
SECAPI void CArrayHolder_EmptyArrays(CArrayHolder_* p, INDEX i);
SECAPI void CArrayHolder_Clear(CArrayHolder_* p);
SECAPI SLONG CArrayHolder_GetUsedMemory(CArrayHolder_* p);
SECAPI CTerrain_** CArrayHolder_ah_ptrTerrain(CArrayHolder_* p);
SECAPI CStaticStackArray_TileArrays_* CArrayHolder_ah_ataTileArrays(CArrayHolder_* p);
SECAPI CStaticStackArray_INDEX_* CArrayHolder_ah_aiFreeArrays(CArrayHolder_* p);
SECAPI INDEX* CArrayHolder_ah_iLod(CArrayHolder_* p);

#ifdef __cplusplus
}
#endif

#endif
