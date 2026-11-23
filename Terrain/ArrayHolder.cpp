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

#include "ArrayHolder.h"
#include <Engine/Terrain/ArrayHolder.h>

TileLayer_* TileLayer_new()
{
  return (TileLayer_*)(new TileLayer());
}

void TileLayer_delete(TileLayer_* p)
{
  delete ((TileLayer*)p);
}

void TileLayer_copy(TileLayer_* a, const TileLayer_* b)
{
  *((TileLayer*)a) = *((const TileLayer*)b);
}

CStaticStackArray_INDEX_* TileLayer_tl_auiIndices(TileLayer_* p)
{
  TileLayer& t = *((TileLayer*)p);
  return (CStaticStackArray_INDEX_*)(&t.tl_auiIndices);
}

CStaticStackArray_GFXColor_* TileLayer_tl_acColors(TileLayer_* p)
{
  TileLayer& t = *((TileLayer*)p);
  return (CStaticStackArray_GFXColor_*)(&t.tl_acColors);
}

CStaticStackArray_GFXTexCoord_* TileLayer_tl_atcTexCoords(TileLayer_* p)
{
  TileLayer& t = *((TileLayer*)p);
  return (CStaticStackArray_GFXTexCoord_*)(&t.tl_atcTexCoords);
}

CStaticStackArray_GFXVertex4_* TileLayer_tl_avVertices(TileLayer_* p)
{
  TileLayer& t = *((TileLayer*)p);
  return (CStaticStackArray_GFXVertex4_*)(&t.tl_avVertices);
}

TileArrays_* TileArrays_new()
{
  return (TileArrays_*)(new TileArrays());
}

void TileArrays_delete(TileArrays_* p)
{
  delete ((TileArrays*)p);
}

void TileArrays_copy(TileArrays_* a, const TileArrays_* b)
{
  *((TileArrays*)a) = *((const TileArrays*)b);
}

CStaticStackArray_GFXVertex4_* TileArrays_ta_avVertices(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_GFXVertex4_*)(&a.ta_avVertices);
}

CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvTexCoords(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_GFXTexCoord_*)(&a.ta_auvTexCoords);
}

CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvShadowMap(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_GFXTexCoord_*)(&a.ta_auvShadowMap);
}

CStaticStackArray_GFXTexCoord_* TileArrays_ta_auvDetailMap(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_GFXTexCoord_*)(&a.ta_auvDetailMap);
}

CStaticStackArray_INDEX_* TileArrays_ta_auiIndices(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_INDEX_*)(&a.ta_auiIndices);
}

CStaticStackArray_TileLayer_* TileArrays_ta_atlLayers(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CStaticStackArray_TileLayer_*)(&a.ta_atlLayers);
}

CTextureData_** TileArrays_ta_ptdTopMap(TileArrays_* p)
{
  TileArrays& a = *((TileArrays*)p);
  return (CTextureData_**)(&a.ta_ptdTopMap);
}

CArrayHolder_* CArrayHolder_new()
{
  return (CArrayHolder_*)(new CArrayHolder());
}

void CArrayHolder_delete(CArrayHolder_* p)
{
  delete ((CArrayHolder*)p);
}

INDEX CArrayHolder_GetNewArrays(CArrayHolder_* p)
{
  return ((CArrayHolder*)p)->GetNewArrays();
}

void CArrayHolder_FreeArrays(CArrayHolder_* p, INDEX i)
{
  ((CArrayHolder*)p)->FreeArrays(i);
}

void CArrayHolder_EmptyArrays(CArrayHolder_* p, INDEX i)
{
  ((CArrayHolder*)p)->EmptyArrays(i);
}

void CArrayHolder_Clear(CArrayHolder_* p)
{
  ((CArrayHolder*)p)->Clear();
}

SLONG CArrayHolder_GetUsedMemory(CArrayHolder_* p)
{
  return ((CArrayHolder*)p)->GetUsedMemory();
}

CTerrain_** CArrayHolder_ah_ptrTerrain(CArrayHolder_* p)
{
  CArrayHolder& a = *((CArrayHolder*)p);
  return (CTerrain_**)(&a.ah_ptrTerrain);
}

CStaticStackArray_TileArrays_* CArrayHolder_ah_ataTileArrays(CArrayHolder_* p)
{
  CArrayHolder& a = *((CArrayHolder*)p);
  return (CStaticStackArray_TileArrays_*)(&a.ah_ataTileArrays);
}

CStaticStackArray_INDEX_* CArrayHolder_ah_aiFreeArrays(CArrayHolder_* p)
{
  CArrayHolder& a = *((CArrayHolder*)p);
  return (CStaticStackArray_INDEX_*)(&a.ah_aiFreeArrays);
}

INDEX* CArrayHolder_ah_iLod(CArrayHolder_* p)
{
  CArrayHolder& a = *((CArrayHolder*)p);
  return &a.ah_iLod;
}
