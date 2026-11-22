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

#include "Brush.h"

CBrushVertex_* CBrushVertex_new()
{
  return (CBrushVertex_*)(new CBrushVertex());
}

CBrushVertex_* CBrushVertex_clone(const CBrushVertex_* p)
{
  return (CBrushVertex_*)(new CBrushVertex(*((const CBrushVertex*)p)));
}

void CBrushVertex_delete(CBrushVertex_* p)
{
  delete ((CBrushVertex*)p);
}

void CBrushVertex_copy(CBrushVertex_* a, const CBrushVertex_* b)
{
  *((CBrushVertex*)a) = *((const CBrushVertex*)b);
}

CWorkingVertex_** CBrushVertex_bvx_pwvxWorking(CBrushVertex_* p)
{
  CBrushVertex& m = *((CBrushVertex*)p);
  return (CWorkingVertex_**)(&(m.bvx_pwvxWorking));
}

FLOAT3D_* CBrushVertex_bvx_vAbsolute(CBrushVertex_* p)
{
  CBrushVertex& m = *((CBrushVertex*)p);
  return (FLOAT3D_*)(&(m.bvx_vAbsolute));
}

FLOAT3D_* CBrushVertex_bvx_vRelative(CBrushVertex_* p)
{
  CBrushVertex& m = *((CBrushVertex*)p);
  return (FLOAT3D_*)(&(m.bvx_vRelative));
}

DOUBLE3D_* CBrushVertex_bvx_vdPreciseRelative(CBrushVertex_* p)
{
  CBrushVertex& m = *((CBrushVertex*)p);
  return (DOUBLE3D_*)(&(m.bvx_vdPreciseRelative));
}

CBrushSector_** CBrushVertex_bvx_pbscSector(CBrushVertex_* p)
{
  CBrushVertex& m = *((CBrushVertex*)p);
  return (CBrushSector_**)(&(m.bvx_pbscSector));
}

BOOL CBrushVertex_IsSelected(const CBrushVertex_* p)
{
  return ((const CBrushVertex*)p)->IsSelected(BVXF_SELECTED);
}

void CBrushVertex_SetAbsolutePosition(CBrushVertex_* p, const DOUBLE3D_* v)
{
  ((CBrushVertex*)p)->SetAbsolutePosition(*((const DOUBLE3D*)v));
}

CBrushPlane_* CBrushPlane_new()
{
  return (CBrushPlane_*)(new CBrushPlane());
}

CBrushPlane_* CBrushPlane_clone(const CBrushPlane_* p)
{
  return (CBrushPlane_*)(new CBrushPlane(*((const CBrushPlane*)p)));
}

void CBrushPlane_delete(CBrushPlane_* p)
{
  delete ((CBrushPlane*)p);
}

void CBrushPlane_copy(CBrushPlane_* a, const CBrushPlane_* b)
{
  *((CBrushPlane*)a) = *((const CBrushPlane*)b);
}

CWorkingPlane_** CBrushPlane_bpl_pwplWorking(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (CWorkingPlane_**)(&(m.bpl_pwplWorking));
}

FLOATplane3D_* CBrushPlane_bpl_plAbsolute(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (FLOATplane3D_*)(&(m.bpl_plAbsolute));
}

FLOATplane3D_* CBrushPlane_bpl_plRelative(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (FLOATplane3D_*)(&(m.bpl_plRelative));
}

DOUBLEplane3D_** CBrushPlane_bpl_ppldPreciseAbsolute(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (DOUBLEplane3D_**)(&(m.bpl_ppldPreciseAbsolute));
}

DOUBLEplane3D_* CBrushPlane_bpl_pldPreciseRelative(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (DOUBLEplane3D_*)(&(m.bpl_pldPreciseRelative));
}

INDEX* CBrushPlane_bpl_iPlaneMajorAxis1(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (INDEX*)(&(m.bpl_iPlaneMajorAxis1));
}

INDEX* CBrushPlane_bpl_iPlaneMajorAxis2(CBrushPlane_* p)
{
  CBrushPlane& m = *((CBrushPlane*)p);
  return (INDEX*)(&(m.bpl_iPlaneMajorAxis2));
}

CBrushEdge_* CBrushEdge_new()
{
  return (CBrushEdge_*)(new CBrushEdge());
}


CBrushEdge_* CBrushEdge_new_v(CBrushVertex_* v0, CBrushVertex_* v1)
{
  return (CBrushEdge_*)(new CBrushEdge((CBrushVertex*)v0, (CBrushVertex*)v1));
}

CBrushEdge_* CBrushEdge_clone(const CBrushEdge_* p)
{
  return (CBrushEdge_*)(new CBrushEdge(*((const CBrushEdge*)p)));
}

void CBrushEdge_delete(CBrushEdge_* p)
{
  delete ((CBrushEdge*)p);
}

void CBrushEdge_copy(CBrushEdge_* a, const CBrushEdge_* b)
{
  *((CBrushEdge*)a) = *((const CBrushEdge*)b);
}

CBrushVertex_** CBrushEdge_bed_pbvxVertex0(CBrushEdge_* p)
{
  CBrushEdge& e = *((CBrushEdge*)p);
  return (CBrushVertex_**)(&(e.bed_pbvxVertex0));
}

CBrushVertex_** CBrushEdge_bed_pbvxVertex1(CBrushEdge_* p)
{
  CBrushEdge& e = *((CBrushEdge*)p);
  return (CBrushVertex_**)(&(e.bed_pbvxVertex1));
}


CBrushPolygonEdge_* CBrushPolygonEdge_new()
{
  return (CBrushPolygonEdge_*)(new CBrushPolygonEdge());
}

CBrushPolygonEdge_* CBrushPolygonEdge_clone(const CBrushPolygonEdge_* p)
{
  return (CBrushPolygonEdge_*)(new CBrushPolygonEdge(*((const CBrushPolygonEdge*)p)));
}

void CBrushPolygonEdge_delete(CBrushPolygonEdge_* p)
{
  delete ((CBrushPolygonEdge*)p);
}

void CBrushPolygonEdge_copy(CBrushPolygonEdge_* a, const CBrushPolygonEdge_* b)
{
  *((CBrushPolygonEdge*)a) = *((const CBrushPolygonEdge*)b);
}

void CBrushPolygonEdge_GetVertexCoordinatesAbsolute(CBrushPolygonEdge_* p, FLOAT3D_* v0, FLOAT3D_* v1)
{
  CBrushPolygonEdge& e = *((CBrushPolygonEdge*)p);
  e.GetVertexCoordinatesAbsolute(*((FLOAT3D*)v0), *((FLOAT3D*)v1));
}

void CBrushPolygonEdge_GetVertexCoordinatesRelative(CBrushPolygonEdge_* p, FLOAT3D_* v0, FLOAT3D_* v1)
{
  CBrushPolygonEdge& e = *((CBrushPolygonEdge*)p);
  e.GetVertexCoordinatesRelative(*((FLOAT3D*)v0), *((FLOAT3D*)v1));
}

void CBrushPolygonEdge_GetVertexCoordinatesPreciseRelative(CBrushPolygonEdge_* p, DOUBLE3D_* v0, DOUBLE3D_* v1)
{
  CBrushPolygonEdge& e = *((CBrushPolygonEdge*)p);
  e.GetVertexCoordinatesPreciseRelative(*((DOUBLE3D*)v0), *((DOUBLE3D*)v1));
}

void CBrushPolygonEdge_GetVertexCoordinatesPreciseAbsolute(CBrushPolygonEdge_* p, DOUBLE3D_* v0, DOUBLE3D_* v1)
{
  CBrushPolygonEdge& e = *((CBrushPolygonEdge*)p);
  e.GetVertexCoordinatesPreciseAbsolute(*((DOUBLE3D*)v0), *((DOUBLE3D*)v1));
}

CBrushEdge_** CBrushPolygonEdge_bpe_pbedEdge(CBrushPolygonEdge_* p)
{
  CBrushPolygonEdge& e = *((CBrushPolygonEdge*)p);
  return (CBrushEdge_**)(&(e.bpe_pbedEdge));
}

CListNode_* CBrushShadowLayer_bsl_lnInShadowMap(CBrushShadowLayer_* p)
{
  CBrushShadowLayer& s = *((CBrushShadowLayer*)p);
  return (CListNode_*)(&(s.bsl_lnInShadowMap));
}

CBrushShadowLayer_* CBrushShadowLayer_from_bsl_lnInShadowMap(CListNode_* p)
{
  CListNode& node = *((CListNode*)p);
  CBrushShadowLayer* res = ((CBrushShadowLayer*)(((UBYTE*)(&node)) - offsetof(CBrushShadowLayer, bsl_lnInShadowMap)));
  return (CBrushShadowLayer_*)res;
}

CLightSource_** CBrushShadowLayer_bsl_plsLightSource(CBrushShadowLayer_* p)
{
  CBrushShadowLayer& s = *((CBrushShadowLayer*)p);
  return (CLightSource_**)(&(s.bsl_plsLightSource));
}


void CBrushShadowMap_DiscardAllLayers(CBrushShadowMap_* p)
{
  ((CBrushShadowMap*)p)->DiscardAllLayers();
}

ULONG CBrushShadowMap_GetShadowSize(CBrushShadowMap_* p)
{
  return ((CBrushShadowMap*)p)->GetShadowSize();
}

SLONG CBrushShadowMap_Uncache(CBrushShadowMap_* p)
{
  return ((CBrushShadowMap*)p)->Uncache();
}

MEMBER_VAL_IMPL(CBrushShadowMap, CListHead_, bsm_lhLayers)

CBrushPolygonTexture_* CBrushPolygonTexture_new()
{
  return (CBrushPolygonTexture_*)(new CBrushPolygonTexture());
}

void CBrushPolygonTexture_delete(CBrushPolygonTexture_* p)
{
  delete ((CBrushPolygonTexture*)p);
}

void CBrushPolygonTexture_CopyTextureProperties(CBrushPolygonTexture_* p, CBrushPolygonTexture_* o, BOOL bCopyMapping)
{
  ((CBrushPolygonTexture*)p)->CopyTextureProperties(*((CBrushPolygonTexture*)o), bCopyMapping);
}

void CBrushPolygonTexture_Clear(CBrushPolygonTexture_* p)
{
  ((CBrushPolygonTexture*)p)->Clear();
}

CTextureObject_* CBrushPolygonTexture_bpt_toTexture(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return (CTextureObject_*)(&(t.bpt_toTexture));
}

CMappingDefinition_* CBrushPolygonTexture_bpt_mdMapping(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return (CMappingDefinition_*)(&(t.bpt_mdMapping));
}

UBYTE* CBrushPolygonTexture_bpt_ubScroll(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return &(t.s.bpt_ubScroll);
}

UBYTE* CBrushPolygonTexture_bpt_ubBlend(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return &(t.s.bpt_ubBlend);
}
 
UBYTE* CBrushPolygonTexture_bpt_ubFlags(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return &(t.s.bpt_ubFlags);
}
 
UBYTE* CBrushPolygonTexture_bpt_ubDummy(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return &(t.s.bpt_ubDummy);
}
 
COLOR* CBrushPolygonTexture_bpt_colColor(CBrushPolygonTexture_* p)
{
  CBrushPolygonTexture& t = *((CBrushPolygonTexture*)p);
  return &(t.s.bpt_colColor);
}


CBrushPolygonProperties_* CBrushPolygonProperties_new()
{
  return (CBrushPolygonProperties_*)(new CBrushPolygonProperties());
}

CBrushPolygonProperties_* CBrushPolygonProperties_clone(const CBrushPolygonProperties_* p)
{
  return (CBrushPolygonProperties_*)(new CBrushPolygonProperties(*((const CBrushPolygonProperties*)p)));
}

void CBrushPolygonProperties_delete(CBrushPolygonProperties_* p)
{
  delete ((CBrushPolygonProperties*)p);
}

void CBrushPolygonProperties_copy(CBrushPolygonProperties_* a, const CBrushPolygonProperties_* b)
{
  *((CBrushPolygonProperties*)a) = *((const CBrushPolygonProperties*)b);
}

UBYTE* CBrushPolygonProperties_bpp_ubSurfaceType(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UBYTE*)(&(m.bpp_ubSurfaceType));
}

UBYTE* CBrushPolygonProperties_bpp_ubIlluminationType(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UBYTE*)(&(m.bpp_ubIlluminationType));
}

UBYTE* CBrushPolygonProperties_bpp_ubShadowBlend(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UBYTE*)(&(m.bpp_ubShadowBlend));
}

UBYTE* CBrushPolygonProperties_bpp_ubMirrorType(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UBYTE*)(&(m.bpp_ubMirrorType));
}

UBYTE* CBrushPolygonProperties_bpp_ubGradientType(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UBYTE*)(&(m.bpp_ubGradientType));
}

SBYTE* CBrushPolygonProperties_bpp_sbShadowClusterSize(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (SBYTE*)(&(m.bpp_sbShadowClusterSize));
}

UWORD* CBrushPolygonProperties_bpp_uwPretenderDistance(CBrushPolygonProperties_* p)
{
  CBrushPolygonProperties& m = *((CBrushPolygonProperties*)p);
  return (UWORD*)(&(m.bpp_uwPretenderDistance));
}


CBrushPolygon_* CBrushPolygon_new()
{
  return (CBrushPolygon_*)(new CBrushPolygon());
}

void CBrushPolygon_delete(CBrushPolygon_* p)
{
  delete ((CBrushPolygon*)p);
}

void CBrushPolygon_InitializeShadowMap(CBrushPolygon_* p)
{
  ((CBrushPolygon*)p)->InitializeShadowMap();
}

void CBrushPolygon_CopyProperties(CBrushPolygon_* p, CBrushPolygon_* o, BOOL bCopyMapping)
{
  ((CBrushPolygon*)p)->CopyProperties(*((CBrushPolygon*)o), bCopyMapping);
}

void CBrushPolygon_CopyPropertiesWithoutTexture(CBrushPolygon_* p, CBrushPolygon_* o)
{
  ((CBrushPolygon*)p)->CopyPropertiesWithoutTexture(*((CBrushPolygon*)o));
}

void CBrushPolygon_CopyTextures(CBrushPolygon_* p, CBrushPolygon_* o)
{
  ((CBrushPolygon*)p)->CopyTextures(*((CBrushPolygon*)o));
}

BOOL CBrushPolygon_IsSelected(const CBrushPolygon_* p)
{
  return ((const CBrushPolygon*)p)->IsSelected(BPOF_SELECTED);
}

void CBrushPolygon_SelectSimilarByColor(CBrushPolygon_* p, CSelection_CBrushPolygon_* s)
{
  ((CBrushPolygon*)p)->SelectSimilarByColor(*((CSelection<CBrushPolygon, BPOF_SELECTED>*)s));
}

void CBrushPolygon_SelectSimilarByTexture(CBrushPolygon_* p, CSelection_CBrushPolygon_* s, INDEX iTexture)
{
  ((CBrushPolygon*)p)->SelectSimilarByTexture(*((CSelection<CBrushPolygon, BPOF_SELECTED>*)s), iTexture);
}

void CBrushPolygon_SelectByTextureInSector(CBrushPolygon_* p, CSelection_CBrushPolygon_* s, INDEX iTexture)
{
  ((CBrushPolygon*)p)->SelectByTextureInSector(*((CSelection<CBrushPolygon, BPOF_SELECTED>*)s), iTexture);
}

void CBrushPolygon_SelectByColorInSector(CBrushPolygon_* p, CSelection_CBrushPolygon_* s)
{
  ((CBrushPolygon*)p)->SelectByColorInSector(*((CSelection<CBrushPolygon, BPOF_SELECTED>*)s));
}

void CBrushPolygon_DiscardShadows(CBrushPolygon_* p)
{
  ((CBrushPolygon*)p)->DiscardShadows();
}

CBrushPolygon_* CBrushPolygon_from_bpo_rsOtherSideSectors(CListHead_* p)
{
  CListHead& node = *((CListHead*)p);
  CBrushPolygon* res = ((CBrushPolygon*)(((UBYTE*)(&node)) - offsetof(CBrushPolygon, bpo_rsOtherSideSectors)));
  return (CBrushPolygon_*)res;
}

MEMBER_PTR_IMPL(CBrushPolygon, CBrushPlane_, bpo_pbplPlane)
MEMBER_VAL_IMPL(CBrushPolygon, CStaticArray_CBrushPolygonEdge_, bpo_abpePolygonEdges)
MEMBER_VAL_IMPL(CBrushPolygon, CStaticArray_CBrushVertexPtr__, bpo_apbvxTriangleVertices)
MEMBER_VAL_IMPL(CBrushPolygon, CStaticArray_INDEX_, bpo_aiTriangleElements)
MEMBER_ARR_IMPL(CBrushPolygon, CBrushPolygonTexture_, bpo_abptTextures)
MEMBER_VAL_IMPL(CBrushPolygon, COLOR, bpo_colColor)
MEMBER_VAL_IMPL(CBrushPolygon, ULONG, bpo_ulFlags)
MEMBER_VAL_IMPL(CBrushPolygon, COLOR, bpo_colShadow)
MEMBER_VAL_IMPL(CBrushPolygon, CBrushShadowMap_, bpo_smShadowMap)
MEMBER_VAL_IMPL(CBrushPolygon, CMappingDefinition_, bpo_mdShadow)
MEMBER_VAL_IMPL(CBrushPolygon, CBrushPolygonProperties_, bpo_bppProperties)
MEMBER_VAL_IMPL(CBrushPolygon, FLOATaabbox3D_, bpo_boxBoundingBox)
MEMBER_PTR_IMPL(CBrushPolygon, CBrushSector_, bpo_pbscSector)
MEMBER_VAL_IMPL(CBrushPolygon, CListHead_, bpo_rsOtherSideSectors)

CBrushSector_* CBrushSector_new()
{
  return (CBrushSector_*)(new CBrushSector());
}

void CBrushSector_delete(CBrushSector_* p)
{
  delete ((CBrushSector*)p);
}
void CBrushSector_UpdateSector(CBrushSector_* p)
{
  ((CBrushSector*)p)->UpdateSector();
}

void CBrushSector_Clear(CBrushSector_* p)
{
  ((CBrushSector*)p)->Clear();
}

void CBrushSector_TriangularizePolygon(CBrushSector_* p, CBrushPolygon_* pbpo)
{
  ((CBrushSector*)p)->TriangularizePolygon((CBrushPolygon*)pbpo);
}

void CBrushSector_TriangularizeForVertices(CBrushSector_* p, CBrushVertexSelection_* selVertex)
{
  ((CBrushSector*)p)->TriangularizeForVertices(*((CBrushVertexSelection*)selVertex));
}

void CBrushSector_InsertVertexIntoTriangle(CBrushSector_* p, CBrushPolygonSelection_* selPolygon, FLOAT3D_* v)
{
  ((CBrushSector*)p)->InsertVertexIntoTriangle(*((CBrushPolygonSelection*)selPolygon), *((FLOAT3D*)v));
}

BOOL CBrushSector_IsReTripleAvailable(CBrushSector_* p, CBrushPolygonSelection_* selPolygon)
{
  return ((CBrushSector*)p)->IsReTripleAvailable(*((CBrushPolygonSelection*)selPolygon));
}

void CBrushSector_ReTriple(CBrushSector_* p, CBrushPolygonSelection_* selPolygon)
{
  ((CBrushSector*)p)->ReTriple(*((CBrushPolygonSelection*)selPolygon));
}

BOOL CBrushSector_IsSelected(const CBrushSector_* p)
{
  return ((const CBrushSector*)p)->IsSelected(BSCF_SELECTED);
}

static void sehCBrushSector_Read_t(CBrushSector_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CBrushSector*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CBrushSector_Read_t(CBrushSector_* p, CTStream_* s)
{
  STREAM_TRY
  sehCBrushSector_Read_t(p, s);
  STREAM_CATCH
}

static void sehCBrushSector_Write_t(CBrushSector_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CBrushSector*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CBrushSector_Write_t(CBrushSector_* p, CTStream_* s)
{
  STREAM_TRY
  sehCBrushSector_Write_t(p, s);
  STREAM_CATCH
}

void CBrushSector_UncacheLightMaps(CBrushSector_* p)
{
  ((CBrushSector*)p)->UncacheLightMaps();
}

INDEX CBrushSector_GetContentType(CBrushSector_* p)
{
  return ((CBrushSector*)p)->GetContentType();
}

void CBrushSector_SetContentType(CBrushSector_* p, INDEX i)
{
  ((CBrushSector*)p)->SetContentType(i);
}

INDEX CBrushSector_GetForceType(CBrushSector_* p)
{
  return ((CBrushSector*)p)->GetForceType();
}

void CBrushSector_SetForceType(CBrushSector_* p, INDEX i)
{
  ((CBrushSector*)p)->SetForceType(i);
}

INDEX CBrushSector_GetFogType(CBrushSector_* p)
{
  return ((CBrushSector*)p)->GetFogType();
}

void CBrushSector_SetFogType(CBrushSector_* p, INDEX i)
{
  ((CBrushSector*)p)->SetFogType(i);
}

INDEX CBrushSector_GetHazeType(CBrushSector_* p)
{
  return ((CBrushSector*)p)->GetHazeType();
}

void CBrushSector_SetHazeType(CBrushSector_* p, INDEX i)
{
  ((CBrushSector*)p)->SetHazeType(i);
}

INDEX CBrushSector_GetEnvironmentType(CBrushSector_* p)
{
  return ((CBrushSector*)p)->GetEnvironmentType();
}

void CBrushSector_SetEnvironmentType(CBrushSector_* p, INDEX i)
{
  ((CBrushSector*)p)->SetEnvironmentType(i);
}

CBrushSector_* CBrushSector_from_bsc_rdOtherSidePortals(CListHead_* p)
{
  CListHead& node = *((CListHead*)p);
  CBrushSector* res = ((CBrushSector*)(((UBYTE*)(&node)) - offsetof(CBrushSector, bsc_rdOtherSidePortals)));
  return (CBrushSector_*)res;
}

CBrushSector_* CBrushSector_from_bsc_rsEntities(CListHead_* p)
{
  CListHead& node = *((CListHead*)p);
  CBrushSector* res = ((CBrushSector*)(((UBYTE*)(&node)) - offsetof(CBrushSector, bsc_rsEntities)));
  return (CBrushSector_*)res;
}

MEMBER_VAL_IMPL(CBrushSector, CStaticArray_CBrushVertex_, bsc_abvxVertices)
MEMBER_VAL_IMPL(CBrushSector, CStaticArray_CBrushEdge_, bsc_abedEdges)
MEMBER_VAL_IMPL(CBrushSector, CStaticArray_CBrushPlane_, bsc_abplPlanes)
MEMBER_VAL_IMPL(CBrushSector, CStaticArray_CBrushPolygon_, bsc_abpoPolygons)
MEMBER_PTR_IMPL(CBrushSector, CBrushMip_, bsc_pbmBrushMip)
MEMBER_VAL_IMPL(CBrushSector, COLOR, bsc_colColor)
MEMBER_VAL_IMPL(CBrushSector, COLOR, bsc_colAmbient)
MEMBER_VAL_IMPL(CBrushSector, ULONG, bsc_ulFlags)
MEMBER_VAL_IMPL(CBrushSector, ULONG, bsc_ulFlags2)
MEMBER_VAL_IMPL(CBrushSector, ULONG, bsc_ulVisFlags)
MEMBER_VAL_IMPL(CBrushSector, FLOATaabbox3D_, bsc_boxBoundingBox)
MEMBER_VAL_IMPL(CBrushSector, CListHead_, bsc_rdOtherSidePortals)
MEMBER_VAL_IMPL(CBrushSector, CListHead_, bsc_rsEntities)
MEMBER_VAL_IMPL(CBrushSector, CTString_, bsc_strName)

CBrushMip_* CBrushMip_new()
{
  return (CBrushMip_*)(new CBrushMip());
}

void CBrushMip_delete(CBrushMip_* p)
{
  delete ((CBrushMip*)p);
}

void CBrushMip_Reoptimize(CBrushMip_* p)
{
  ((CBrushMip*)p)->Reoptimize();
}

void CBrushMip_Clear(CBrushMip_* p)
{
  ((CBrushMip*)p)->Clear();
}

void CBrushMip_Copy(CBrushMip_* p, CBrushMip_* o, FLOAT fStretch, BOOL bMirrorX)
{
  ((CBrushMip*)p)->Copy(*((CBrushMip*)o), fStretch, bMirrorX);
}

void CBrushMip_SetMipDistance(CBrushMip_* p, FLOAT fMipDistance)
{
  ((CBrushMip*)p)->SetMipDistance(fMipDistance);
}

FLOAT CBrushMip_GetMipDistance(CBrushMip_* p)
{
  return ((CBrushMip*)p)->GetMipDistance();
}

INDEX CBrushMip_GetMipIndex(CBrushMip_* p)
{
  return ((CBrushMip*)p)->GetMipIndex();
}

CBrushMip_* CBrushMip_GetNext(CBrushMip_* p)
{
  return (CBrushMip_*)(((CBrushMip*)p)->GetNext());
}

CBrushMip_* CBrushMip_GetPrev(CBrushMip_* p)
{
  return (CBrushMip_*)(((CBrushMip*)p)->GetPrev());
}

CBrushMip_* CBrushMip_from_bm_lnInBrush(CListNode_* p)
{
  CListNode& node = *((CListNode*)p);
  CBrushMip* res = ((CBrushMip*)(((UBYTE*)(&node)) - offsetof(CBrushMip, bm_lnInBrush)));
  return (CBrushMip_*)res;
}

MEMBER_VAL_IMPL(CBrushMip, CDynamicArray_CBrushSector_, bm_abscSectors)
MEMBER_PTR_IMPL(CBrushMip, CBrush3D_, bm_pbrBrush)
MEMBER_VAL_IMPL(CBrushMip, CListNode_, bm_lnInBrush)
MEMBER_VAL_IMPL(CBrushMip, FLOATaabbox3D_, bm_boxBoundingBox)

CBrush3D_* CBrush3D_new()
{
  return (CBrush3D_*)(new CBrush3D());
}

void CBrush3D_delete(CBrush3D_* p)
{
  delete ((CBrush3D*)p);
}
void CBrush3D_CalculateBoundingBoxes(CBrush3D_* p)
{
  ((CBrush3D*)p)->CalculateBoundingBoxes();
}

void CBrush3D_Clear(CBrush3D_* p)
{
  ((CBrush3D*)p)->Clear();
}

void CBrush3D_FromObject3D_t(CBrush3D_* p, CObject3D_* ob)
{
  SECAPI_TRY
  ((CBrush3D*)p)->FromObject3D_t(*((CObject3D*)ob));
  SECAPI_CATCH
}

void CBrush3D_AddMipBrushFromObject3D_t(CBrush3D_* p, CObject3D_* ob, FLOAT fSwitchDistance)
{
  SECAPI_TRY
  ((CBrush3D*)p)->AddMipBrushFromObject3D_t(*((CObject3D*)ob), fSwitchDistance);
  SECAPI_CATCH
}

void CBrush3D_Copy(CBrush3D_* p, CBrush3D_* o, FLOAT fStretch, BOOL bMirrorX)
{
  ((CBrush3D*)p)->Copy(*((CBrush3D*)o), fStretch, bMirrorX);
}

void CBrush3D_DeleteBrushMip(CBrush3D_* p, CBrushMip_* pbmToDelete)
{
  ((CBrush3D*)p)->DeleteBrushMip((CBrushMip*)pbmToDelete);
}

CBrushMip_* CBrush3D_NewBrushMipAfter(CBrush3D_* p, CBrushMip_* pbm, BOOL bCopy)
{
  return (CBrushMip_*)(((CBrush3D*)p)->NewBrushMipAfter((CBrushMip*)pbm, bCopy));
}

CBrushMip_* CBrush3D_NewBrushMipBefore(CBrush3D_* p, CBrushMip_* pbm, BOOL bCopy)
{
  return (CBrushMip_*)(((CBrush3D*)p)->NewBrushMipBefore((CBrushMip*)pbm, bCopy));
}

CBrushMip_* CBrush3D_GetBrushMipByDistance(CBrush3D_* p, FLOAT fDistance)
{
  return (CBrushMip_*)(((CBrush3D*)p)->GetBrushMipByDistance(fDistance));
}

CBrushMip_* CBrush3D_GetFirstMip(CBrush3D_* p)
{
  return (CBrushMip_*)(((CBrush3D*)p)->GetFirstMip());
}

CBrushMip_* CBrush3D_GetLastMip(CBrush3D_* p)
{
  return (CBrushMip_*)(((CBrush3D*)p)->GetLastMip());
}

void CBrush3D_SwitchToNonZoning(CBrush3D_* p)
{
  ((CBrush3D*)p)->SwitchToNonZoning();
}

void CBrush3D_SwitchToZoning(CBrush3D_* p)
{
  ((CBrush3D*)p)->SwitchToZoning();
}

static void sehCBrush3D_Read_t(CBrush3D_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CBrush3D*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CBrush3D_Read_t(CBrush3D_* p, CTStream_* s)
{
  STREAM_TRY
  sehCBrush3D_Read_t(p, s);
  STREAM_CATCH
}

static void sehCBrush3D_Write_t(CBrush3D_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CBrush3D*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CBrush3D_Write_t(CBrush3D_* p, CTStream_* s)
{
  STREAM_TRY
  sehCBrush3D_Write_t(p, s);
  STREAM_CATCH
}

MEMBER_PTR_IMPL(CBrush3D, CEntity_, br_penEntity)
MEMBER_VAL_IMPL(CBrush3D, CListHead_, br_lhBrushMips)
