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

#ifndef SECAPI_BRUSHES_BRUSH_H
#define SECAPI_BRUSHES_BRUSH_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI CBrushVertex_* CBrushVertex_new();
SECAPI CBrushVertex_* CBrushVertex_clone(const CBrushVertex_* p);
SECAPI void CBrushVertex_delete(CBrushVertex_* p);
SECAPI void CBrushVertex_copy(CBrushVertex_* a, const CBrushVertex_* b);
SECAPI CWorkingVertex_** CBrushVertex_bvx_pwvxWorking(CBrushVertex_* p);
SECAPI FLOAT3D_* CBrushVertex_bvx_vAbsolute(CBrushVertex_* p);
SECAPI FLOAT3D_* CBrushVertex_bvx_vRelative(CBrushVertex_* p);
SECAPI DOUBLE3D_* CBrushVertex_bvx_vdPreciseRelative(CBrushVertex_* p);
SECAPI CBrushSector_** CBrushVertex_bvx_pbscSector(CBrushVertex_* p);
SECAPI BOOL CBrushVertex_IsSelected(const CBrushVertex_* p);
SECAPI void CBrushVertex_SetAbsolutePosition(CBrushVertex_* p, const DOUBLE3D_* v);

SECAPI CBrushPlane_* CBrushPlane_new();
SECAPI CBrushPlane_* CBrushPlane_clone(const CBrushPlane_* p);
SECAPI void CBrushPlane_delete(CBrushPlane_* p);
SECAPI void CBrushPlane_copy(CBrushPlane_* a, const CBrushPlane_* b);
SECAPI CWorkingPlane_** CBrushPlane_bpl_pwplWorking(CBrushPlane_* p);
SECAPI FLOATplane3D_* CBrushPlane_bpl_plAbsolute(CBrushPlane_* p);
SECAPI FLOATplane3D_* CBrushPlane_bpl_plRelative(CBrushPlane_* p);
SECAPI DOUBLEplane3D_** CBrushPlane_bpl_ppldPreciseAbsolute(CBrushPlane_* p);
SECAPI DOUBLEplane3D_* CBrushPlane_bpl_pldPreciseRelative(CBrushPlane_* p);
SECAPI INDEX* CBrushPlane_bpl_iPlaneMajorAxis1(CBrushPlane_* p);
SECAPI INDEX* CBrushPlane_bpl_iPlaneMajorAxis2(CBrushPlane_* p);

SECAPI CBrushEdge_* CBrushEdge_new();
SECAPI CBrushEdge_* CBrushEdge_new_v(CBrushVertex_* v0, CBrushVertex_* v1);
SECAPI CBrushEdge_* CBrushEdge_clone(const CBrushEdge_* p);
SECAPI void CBrushEdge_delete(CBrushEdge_* p);
SECAPI void CBrushEdge_copy(CBrushEdge_* a, const CBrushEdge_* b);
SECAPI CBrushVertex_** CBrushEdge_bed_pbvxVertex0(CBrushEdge_* p);
SECAPI CBrushVertex_** CBrushEdge_bed_pbvxVertex1(CBrushEdge_* p);

SECAPI CBrushPolygonEdge_* CBrushPolygonEdge_new();
SECAPI CBrushPolygonEdge_* CBrushPolygonEdge_clone(const CBrushPolygonEdge_* p);
SECAPI void CBrushPolygonEdge_delete(CBrushPolygonEdge_* p);
SECAPI void CBrushPolygonEdge_copy(CBrushPolygonEdge_* a, const CBrushPolygonEdge_* b);
SECAPI void CBrushPolygonEdge_GetVertexCoordinatesAbsolute(CBrushPolygonEdge_* p, FLOAT3D_* v0, FLOAT3D_* v1);
SECAPI void CBrushPolygonEdge_GetVertexCoordinatesRelative(CBrushPolygonEdge_* p, FLOAT3D_* v0, FLOAT3D_* v1);
SECAPI void CBrushPolygonEdge_GetVertexCoordinatesPreciseRelative(CBrushPolygonEdge_* p, DOUBLE3D_* v0, DOUBLE3D_* v1);
SECAPI void CBrushPolygonEdge_GetVertexCoordinatesPreciseAbsolute(CBrushPolygonEdge_* p, DOUBLE3D_* v0, DOUBLE3D_* v1);
SECAPI CBrushEdge_** CBrushPolygonEdge_bpe_pbedEdge(CBrushPolygonEdge_* p);

SECAPI CListNode_* CBrushShadowLayer_bsl_lnInShadowMap(CBrushShadowLayer_* p);
SECAPI CBrushShadowLayer_* CBrushShadowLayer_from_bsl_lnInShadowMap(CListNode_* p);
SECAPI CLightSource_** CBrushShadowLayer_bsl_plsLightSource(CBrushShadowLayer_* p);

SECAPI void CBrushShadowMap_DiscardAllLayers(CBrushShadowMap_* p);
SECAPI ULONG CBrushShadowMap_GetShadowSize(CBrushShadowMap_* p);
SECAPI SLONG CBrushShadowMap_Uncache(CBrushShadowMap_* p);
SECAPI MEMBER_VAL_DECL(CBrushShadowMap, CListHead_, bsm_lhLayers)

#ifndef SERIOUSENGINECAPI_EXPORTS
// one texture on a brush polygon
#define BPTF_CLAMPU         (1U<<0)    // clamp u coordinate in texture
#define BPTF_CLAMPV         (1U<<1)    // clamp v coordinate in texture
#define BPTF_DISCARDABLE    (1U<<2)    // texture doesn't have to be drawn
#define BPTF_AFTERSHADOW    (1U<<3)    // texture is to be applied after shadow
#define BPTF_REFLECTION     (1U<<4)    // texture will be reflection-mapped
#endif

SECAPI CBrushPolygonTexture_* CBrushPolygonTexture_new();
SECAPI void CBrushPolygonTexture_delete(CBrushPolygonTexture_* p);
SECAPI void CBrushPolygonTexture_CopyTextureProperties(CBrushPolygonTexture_* p, CBrushPolygonTexture_* o, BOOL bCopyMapping);
SECAPI void CBrushPolygonTexture_Clear(CBrushPolygonTexture_* p);
SECAPI CTextureObject_* CBrushPolygonTexture_bpt_toTexture(CBrushPolygonTexture_* p);
SECAPI CMappingDefinition_* CBrushPolygonTexture_bpt_mdMapping(CBrushPolygonTexture_* p);
SECAPI UBYTE* CBrushPolygonTexture_bpt_ubScroll(CBrushPolygonTexture_* p);
SECAPI UBYTE* CBrushPolygonTexture_bpt_ubBlend(CBrushPolygonTexture_* p); 
SECAPI UBYTE* CBrushPolygonTexture_bpt_ubFlags(CBrushPolygonTexture_* p); 
SECAPI UBYTE* CBrushPolygonTexture_bpt_ubDummy(CBrushPolygonTexture_* p); 
SECAPI COLOR* CBrushPolygonTexture_bpt_colColor(CBrushPolygonTexture_* p);

#ifndef SERIOUSENGINECAPI_EXPORTS
// a polygon in brush
// Flags
// flags 0-2 are used by CObjectPolygon, flags 3-31 are used by CBrushPolygon
// OPOF_PORTAL  // set if the polygon is a portal - used for CSG in CObject3D
#define BPOF_DOUBLESIDED            (1UL<< 3)    // polygon is renderable from both sides
#define BPOF_SHOOTTHRU              (1UL<< 4)    // physical ray-casts can pass through the polygon, even if it is not passable
#define BPOF_TRANSPARENT            (1UL<< 5)    // render with alpha-testing and write z-buffer
#define BPOF_RENDERASPORTAL         (1UL<< 6)    // internal used in rendering
#define BPOF_STAIRS                 (1UL<< 7)    // polygon is part of a staircase
#define BPOF_SELECTED               (1UL<< 8)    // set if the polygon is selected
#define BPOF_SELECTEDFORCSG         (1UL<< 9)    // set if the polygon is selected for CSG
#define BPOF_WASPORTAL              (1UL<<10)    // set if it was portal before CSG
#define BPOF_PASSABLE               (1UL<<11)    // set if not a physical barrier
#define BPOF_DOESNOTCASTSHADOW      (1UL<<12)    // set to make a wall passable for light beams
#define BPOF_WASBRUSHPOLYGON        (1UL<<13)    // this polygon was brush polygon before (not just created)
#define BPOF_FULLBRIGHT             (1UL<<14)    // set to make a wall full-bright
#define BPOF_TRANSLUCENT            (1UL<<15)    // set for translucent portals
#define BPOF_HASDIRECTIONALLIGHT    (1UL<<16)    // set if polygon accepts directional lights
#define BPOF_INVISIBLE              (1UL<<17)    // set if the polygon is ignored during rendering
#define BPOF_DARKCORNERS            (1UL<<18)    // polygons will have dark corners (here was gouraud!!!!)
#define BPOF_RENDERTRANSLUCENT      (1UL<<19)    // internal used in rendering
#define BPOF_NOPLANEDIFFUSION       (1UL<<20)    // plane normal is ignored when shading
#define BPOF_DETAILPOLYGON          (1UL<<21)    // not used for visibility determination
#define BPOF_PORTAL                 (1UL<<22)    // should behave like a portal (not same as OPOF_PORTAL)
#define BPOF_ACCURATESHADOWS        (1UL<<23)    // shadows are calculated for each mip-map independently
#define BPOF_HASDIRECTIONALAMBIENT  (1UL<<24)    // set if polygon accepts directional ambient
#define BPOF_MARKEDLAYER            (1UL<<25)    // used in FindShadowLayers()
#define BPOF_DYNAMICLIGHTSONLY      (1UL<<26)    // only dynamic lights used in shadow map
#define BPOF_DOESNOTRECEIVESHADOW   (1UL<<27)    // has lightmap, but no shadows on it
#define BPOF_NODYNAMICLIGHTS        (1UL<<28)    // dynamic lights do not influence it
#define BPOF_INVALIDTRIANGLES       (1UL<<29)    // polygons could not be triangulated well
#define BPOF_OCCLUDER               (1UL<<30)    // occluder polygon
#endif

SECAPI CBrushPolygonProperties_* CBrushPolygonProperties_new();
SECAPI CBrushPolygonProperties_* CBrushPolygonProperties_clone(const CBrushPolygonProperties_* p);
SECAPI void CBrushPolygonProperties_delete(CBrushPolygonProperties_* p);
SECAPI void CBrushPolygonProperties_copy(CBrushPolygonProperties_* a, const CBrushPolygonProperties_* b);
SECAPI UBYTE* CBrushPolygonProperties_bpp_ubSurfaceType(CBrushPolygonProperties_* p);
SECAPI UBYTE* CBrushPolygonProperties_bpp_ubIlluminationType(CBrushPolygonProperties_* p);
SECAPI UBYTE* CBrushPolygonProperties_bpp_ubShadowBlend(CBrushPolygonProperties_* p);
SECAPI UBYTE* CBrushPolygonProperties_bpp_ubMirrorType(CBrushPolygonProperties_* p);
SECAPI UBYTE* CBrushPolygonProperties_bpp_ubGradientType(CBrushPolygonProperties_* p);
SECAPI SBYTE* CBrushPolygonProperties_bpp_sbShadowClusterSize(CBrushPolygonProperties_* p);
SECAPI UWORD* CBrushPolygonProperties_bpp_uwPretenderDistance(CBrushPolygonProperties_* p);

SECAPI CBrushPolygon_* CBrushPolygon_new();
SECAPI void CBrushPolygon_delete(CBrushPolygon_* p);
SECAPI void CBrushPolygon_InitializeShadowMap(CBrushPolygon_* p);
SECAPI void CBrushPolygon_CopyProperties(CBrushPolygon_* p, CBrushPolygon_* o, BOOL bCopyMapping);
SECAPI void CBrushPolygon_CopyPropertiesWithoutTexture(CBrushPolygon_* p, CBrushPolygon_* o);
SECAPI void CBrushPolygon_CopyTextures(CBrushPolygon_* p, CBrushPolygon_* o);
SECAPI BOOL CBrushPolygon_IsSelected(const CBrushPolygon_* p);
SECAPI void CBrushPolygon_SelectSimilarByColor(CBrushPolygon_* p, CSelection_CBrushPolygon_* s);
SECAPI void CBrushPolygon_SelectSimilarByTexture(CBrushPolygon_* p, CSelection_CBrushPolygon_* s, INDEX iTexture);
SECAPI void CBrushPolygon_SelectByTextureInSector(CBrushPolygon_* p, CSelection_CBrushPolygon_* s, INDEX iTexture);
SECAPI void CBrushPolygon_SelectByColorInSector(CBrushPolygon_* p, CSelection_CBrushPolygon_* s);
SECAPI void CBrushPolygon_DiscardShadows(CBrushPolygon_* p);
SECAPI CBrushPolygon_* CBrushPolygon_from_bpo_rsOtherSideSectors(CListHead_* p);
SECAPI MEMBER_PTR_DECL(CBrushPolygon, CBrushPlane_, bpo_pbplPlane)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CStaticArray_CBrushPolygonEdge_, bpo_abpePolygonEdges)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CStaticArray_CBrushVertexPtr__, bpo_apbvxTriangleVertices)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CStaticArray_INDEX_, bpo_aiTriangleElements)
SECAPI MEMBER_ARR_DECL(CBrushPolygon, CBrushPolygonTexture_, bpo_abptTextures)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, COLOR, bpo_colColor)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, ULONG, bpo_ulFlags)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, COLOR, bpo_colShadow)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CBrushShadowMap_, bpo_smShadowMap)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CMappingDefinition_, bpo_mdShadow)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CBrushPolygonProperties_, bpo_bppProperties)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, FLOATaabbox3D_, bpo_boxBoundingBox)
SECAPI MEMBER_PTR_DECL(CBrushPolygon, CBrushSector_, bpo_pbscSector)
SECAPI MEMBER_VAL_DECL(CBrushPolygon, CListHead_, bpo_rsOtherSideSectors)

#ifndef SERIOUSENGINECAPI_EXPORTS
// sector flags
#define BSCF_SELECTED           (1L<<0)   // set if the sector is selected
#define BSCF_HIDDEN             (1L<<1)   // set if the sector is hidden (for editing)
#define BSCF_SELECTEDFORCSG     (1L<<2)   // set if the sector is selected for CSG
#define BSCF_OPENSECTOR         (1L<<3)   // set if the sector polygons are facing outwards
#define BSCF_NEARTESTED         (1L<<4)   // already tested for near polygon
#define BSCF_INVISIBLE          (1L<<5)   // active, but not visible
#define BSCF_RAYTESTED          (1L<<6)   // already tested by ray
#define BSCF_NEEDSCLIPPING      (1L<<7)   // set if its polygons needs clipping
#define BSCB_CONTENTTYPE  24      // upper 8 bits are used for sector content type
#define BSCB_FORCETYPE    16      // next 8 bits are used for sector gravity type
#define BSCB_FOGTYPE      12      // 4 bits for fog
#define BSCB_HAZETYPE      8      // 4 bits for haze

#define BSCB2_ENVIRONMENTTYPE      0      // 8 bits for environment sound effects (EAX and similar)
#define BSCF2_VISIBILITYINCLUDE (1<<8)    // toggle include/exclude for visibility (exclude is default)

// vis flags
#define VISM_INCLUDEEXCLUDE   (0x0000FFFF)  // for visibility include/exclude
#define VISM_DONTCLASSIFY     (0xFFFF0000)  // to disable classification in certain sectors
#endif

SECAPI CBrushSector_* CBrushSector_new();
SECAPI void CBrushSector_delete(CBrushSector_* p);
SECAPI void CBrushSector_UpdateSector(CBrushSector_* p);
SECAPI void CBrushSector_Clear(CBrushSector_* p);
SECAPI void CBrushSector_TriangularizePolygon(CBrushSector_* p, CBrushPolygon_* pbpo);
SECAPI void CBrushSector_TriangularizeForVertices(CBrushSector_* p, CBrushVertexSelection_* selVertex);
SECAPI void CBrushSector_InsertVertexIntoTriangle(CBrushSector_* p, CBrushPolygonSelection_* selPolygon, FLOAT3D_* v);
SECAPI BOOL CBrushSector_IsReTripleAvailable(CBrushSector_* p, CBrushPolygonSelection_* selPolygon);
SECAPI void CBrushSector_ReTriple(CBrushSector_* p, CBrushPolygonSelection_* selPolygon);
SECAPI BOOL CBrushSector_IsSelected(const CBrushSector_* p);
SECAPI void CBrushSector_Read_t(CBrushSector_* p, CTStream_* s);
SECAPI void CBrushSector_Write_t(CBrushSector_* p, CTStream_* s);
SECAPI void CBrushSector_UncacheLightMaps(CBrushSector_* p);
SECAPI INDEX CBrushSector_GetContentType(CBrushSector_* p);
SECAPI void CBrushSector_SetContentType(CBrushSector_* p, INDEX i);
SECAPI INDEX CBrushSector_GetForceType(CBrushSector_* p);
SECAPI void CBrushSector_SetForceType(CBrushSector_* p, INDEX i);
SECAPI INDEX CBrushSector_GetFogType(CBrushSector_* p);
SECAPI void CBrushSector_SetFogType(CBrushSector_* p, INDEX i);
SECAPI INDEX CBrushSector_GetHazeType(CBrushSector_* p);
SECAPI void CBrushSector_SetHazeType(CBrushSector_* p, INDEX i);
SECAPI INDEX CBrushSector_GetEnvironmentType(CBrushSector_* p);
SECAPI void CBrushSector_SetEnvironmentType(CBrushSector_* p, INDEX i);
SECAPI CBrushSector_* CBrushSector_from_bsc_rdOtherSidePortals(CListHead_* p);
SECAPI CBrushSector_* CBrushSector_from_bsc_rsEntities(CListHead_* p);
SECAPI MEMBER_VAL_DECL(CBrushSector, CStaticArray_CBrushVertex_, bsc_abvxVertices)
SECAPI MEMBER_VAL_DECL(CBrushSector, CStaticArray_CBrushEdge_, bsc_abedEdges)
SECAPI MEMBER_VAL_DECL(CBrushSector, CStaticArray_CBrushPlane_, bsc_abplPlanes)
SECAPI MEMBER_VAL_DECL(CBrushSector, CStaticArray_CBrushPolygon_, bsc_abpoPolygons)
SECAPI MEMBER_PTR_DECL(CBrushSector, CBrushMip_, bsc_pbmBrushMip)
SECAPI MEMBER_VAL_DECL(CBrushSector, COLOR, bsc_colColor)
SECAPI MEMBER_VAL_DECL(CBrushSector, COLOR, bsc_colAmbient)
SECAPI MEMBER_VAL_DECL(CBrushSector, ULONG, bsc_ulFlags)
SECAPI MEMBER_VAL_DECL(CBrushSector, ULONG, bsc_ulFlags2)
SECAPI MEMBER_VAL_DECL(CBrushSector, ULONG, bsc_ulVisFlags)
SECAPI MEMBER_VAL_DECL(CBrushSector, FLOATaabbox3D_, bsc_boxBoundingBox)
SECAPI MEMBER_VAL_DECL(CBrushSector, CListHead_, bsc_rdOtherSidePortals)
SECAPI MEMBER_VAL_DECL(CBrushSector, CListHead_, bsc_rsEntities)
SECAPI MEMBER_VAL_DECL(CBrushSector, CTString_, bsc_strName)

SECAPI CBrushMip_* CBrushMip_new();
SECAPI void CBrushMip_delete(CBrushMip_* p);
SECAPI void CBrushMip_Reoptimize(CBrushMip_* p);
SECAPI void CBrushMip_Clear(CBrushMip_* p);
SECAPI void CBrushMip_Copy(CBrushMip_* p, CBrushMip_* o, FLOAT fStretch, BOOL bMirrorX);
SECAPI void CBrushMip_SetMipDistance(CBrushMip_* p, FLOAT fMipDistance);
SECAPI FLOAT CBrushMip_GetMipDistance(CBrushMip_* p);
SECAPI INDEX CBrushMip_GetMipIndex(CBrushMip_* p);
SECAPI CBrushMip_* CBrushMip_GetNext(CBrushMip_* p);
SECAPI CBrushMip_* CBrushMip_GetPrev(CBrushMip_* p);
SECAPI CBrushMip_* CBrushMip_from_bm_lnInBrush(CListNode_* p);
SECAPI MEMBER_VAL_DECL(CBrushMip, CDynamicArray_CBrushSector_, bm_abscSectors)
SECAPI MEMBER_PTR_DECL(CBrushMip, CBrush3D_, bm_pbrBrush)
SECAPI MEMBER_VAL_DECL(CBrushMip, CListNode_, bm_lnInBrush)
SECAPI MEMBER_VAL_DECL(CBrushMip, FLOATaabbox3D_, bm_boxBoundingBox)

SECAPI CBrush3D_* CBrush3D_new();
SECAPI void CBrush3D_delete(CBrush3D_* p);
SECAPI void CBrush3D_CalculateBoundingBoxes(CBrush3D_* p);
SECAPI void CBrush3D_Clear(CBrush3D_* p);
SECAPI void CBrush3D_FromObject3D_t(CBrush3D_* p, CObject3D_* ob);
SECAPI void CBrush3D_AddMipBrushFromObject3D_t(CBrush3D_* p, CObject3D_* ob, FLOAT fSwitchDistance);
SECAPI void CBrush3D_Copy(CBrush3D_* p, CBrush3D_* o, FLOAT fStretch, BOOL bMirrorX);
SECAPI void CBrush3D_DeleteBrushMip(CBrush3D_* p, CBrushMip_* pbmToDelete);
SECAPI CBrushMip_* CBrush3D_NewBrushMipAfter(CBrush3D_* p, CBrushMip_* pbm, BOOL bCopy);
SECAPI CBrushMip_* CBrush3D_NewBrushMipBefore(CBrush3D_* p, CBrushMip_* pbm, BOOL bCopy);
SECAPI CBrushMip_* CBrush3D_GetBrushMipByDistance(CBrush3D_* p, FLOAT fDistance);
SECAPI CBrushMip_* CBrush3D_GetFirstMip(CBrush3D_* p);
SECAPI CBrushMip_* CBrush3D_GetLastMip(CBrush3D_* p);
SECAPI void CBrush3D_SwitchToNonZoning(CBrush3D_* p);
SECAPI void CBrush3D_SwitchToZoning(CBrush3D_* p);
SECAPI void CBrush3D_Read_t(CBrush3D_* p, CTStream_* s);
SECAPI void CBrush3D_Write_t(CBrush3D_* p, CTStream_* s);
SECAPI MEMBER_PTR_DECL(CBrush3D, CEntity_, br_penEntity)
SECAPI MEMBER_VAL_DECL(CBrush3D, CListHead_, br_lhBrushMips)

#ifdef __cplusplus
}
#endif

#endif
