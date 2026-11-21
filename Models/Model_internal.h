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

#ifndef SECAPI_MODELS_MODEL_INTERNAL_H
#define SECAPI_MODELS_MODEL_INTERNAL_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

// surface shading types
#define SST_INVALID_    -1
#define SST_FULLBRIGHT_  0
#define SST_MATTE_       1
#define SST_FLAT_        2

// surface translucency types
#define STT_INVALID_      -1
#define STT_OPAQUE_        0
#define STT_TRANSLUCENT_   1
#define STT_ALPHAGOURAUD_  2
#define STT_ADD_           3
#define STT_TRANSPARENT_   4
#define STT_MULTIPLY_      5

#ifndef SERIOUSENGINECAPI_EXPORTS
// collision box dimension equality names
#define HEIGHT_EQ_WIDTH 0
#define LENGTH_EQ_WIDTH 1
#define LENGTH_EQ_HEIGHT 2

#define MAX_MODELMIPS         32
#define MAX_TEXTUREPATCHES    32
#define MAX_COLOR_NAMES       32
// surface rendering flags
#define SRF_DOUBLESIDED         (1L<<0)     // double sided polygons
#define SRF_CLIPPOLYGON         (1L<<1)     // polygons are allways cliped, this is old flag
#define SRF_REFLECTIONS         (1L<<2)     // use reflection mapping on this surface
#define SRF_INVISIBLE           (1L<<3)     // if this surface is ignored in rendering process
#define SRF_SPECULAR            (1L<<4)     // use specularity on this surface
#define SRF_DIFFUSE             (1L<<5)     // use difuse texture for this surface
#define SRF_BUMP                (1L<<6)     // use bump on this surface
#define SRF_NEW_TEXTURE_FORMAT  (1L<<7)     // used for reading of old mapping files (ther don't have diffuse flag set)
#define SRF_CYLINDRICAL_MAPPING (1L<<8)     // surface is mapped using spherical mapping
#define SRF_SPHERICAL_MAPPING   (1L<<9)     // surface is mapped using cylindrical mapping
#define SRF_FOG                 (1L<<10)    // used internally for fog
#define SRF_HAZE                (1L<<11)    // used internally for haze
#define SRF_DETAIL              (1L<<12)    // use detail on this surface instead of bump
#define SRF_SELECTED            (1L<<13)    // for editing purposes
#define SRF_OPAQUE              (1L<<14)    // writes to z-buffer
// ! WARNING: this flags are copied to mipinfo var flags which has reserved bits 25 and above !
  
// constant used for spreading mip-switching distances
#define MAX_SWITCH_FACTOR 8.0f

// render defines for model
#define  RT_WIRE_ON         ((1L) << 0)
#define  RT_HIDDEN_LINES    ((1L) << 1)
//-------------------------------------
#define  RT_NO_POLYGON_FILL ((1L) << 2)
#define  RT_WHITE_TEXTURE   ((1L) << 3)
#define  RT_SURFACE_COLORS  ((1L) << 4)
#define  RT_ON_COLORS       ((1L) << 5)
#define  RT_OFF_COLORS      ((1L) << 6)
#define  RT_TEXTURE         ((1L) << 7)
//-------------------------------------
#define  RT_SHADING_NONE    ((1L) << 8)
#define  RT_SHADING_LAMBERT ((1L) << 9)
#define  RT_SHADING_PHONG   ((1L) <<10)
//-------------------------------------
#define  RT_SHADING_MASK  (RT_SHADING_NONE | RT_SHADING_LAMBERT | RT_SHADING_PHONG)
#define  RT_TEXTURE_MASK  (RT_NO_POLYGON_FILL | RT_WHITE_TEXTURE | RT_SURFACE_COLORS | \
                           RT_ON_COLORS | RT_OFF_COLORS | RT_TEXTURE)

// Model flags
#define MF_FACE_FORWARD      ((1L)<<0)
#define MF_REFLECTIONS       ((1L)<<1)
#define MF_REFLECTIONS_HALF  ((1L)<<2)
#define MF_HALF_FACE_FORWARD ((1L)<<3)
#define MF_COMPRESSED_16BIT  ((1L)<<4)
#define MF_STRETCH_DETAIL    ((1L)<<5)

// Mip model flags
#define MM_PATCHES_VISIBLE         ((1L)<<0)
#define MM_ATTACHED_MODELS_VISIBLE ((1L)<<1)
#endif

SECAPI COLOR* PaletteColorValues_();

SECAPI ModelFrameVertex8_* ModelFrameVertex8_new();
SECAPI ModelFrameVertex8_* ModelFrameVertex8_clone(const ModelFrameVertex8_* p);
SECAPI void ModelFrameVertex8_delete(ModelFrameVertex8_* p);
SECAPI void ModelFrameVertex8_copy(ModelFrameVertex8_* a, const ModelFrameVertex8_* b);
SECAPI SBPOINT3D_* ModelFrameVertex8_mfv_SBPoint(ModelFrameVertex8_* p);
SECAPI UBYTE* ModelFrameVertex8_mfv_NormIndex(ModelFrameVertex8_* p);

SECAPI ModelFrameVertex16_* ModelFrameVertex16_new();
SECAPI ModelFrameVertex16_* ModelFrameVertex16_clone(const ModelFrameVertex16_* p);
SECAPI void ModelFrameVertex16_delete(ModelFrameVertex16_* p);
SECAPI void ModelFrameVertex16_copy(ModelFrameVertex16_* a, const ModelFrameVertex16_* b);
SECAPI SWPOINT3D_* ModelFrameVertex16_mfv_SWPoint(ModelFrameVertex16_* p);
SECAPI UBYTE* ModelFrameVertex16_mfv_ubNormH(ModelFrameVertex16_* p);
SECAPI UBYTE* ModelFrameVertex16_mfv_ubNormP(ModelFrameVertex16_* p);

SECAPI ModelFrameInfo_* ModelFrameInfo_new();
SECAPI ModelFrameInfo_* ModelFrameInfo_clone(const ModelFrameInfo_* p);
SECAPI void ModelFrameInfo_delete(ModelFrameInfo_* p);
SECAPI void ModelFrameInfo_copy(ModelFrameInfo_* a, const ModelFrameInfo_* b);
SECAPI FLOATaabbox3D_* ModelFrameInfo_mfi_Box(ModelFrameInfo_* p);

SECAPI ModelTextureVertex_* ModelTextureVertex_new();
SECAPI ModelTextureVertex_* ModelTextureVertex_clone(const ModelTextureVertex_* p);
SECAPI void ModelTextureVertex_delete(ModelTextureVertex_* p);
SECAPI void ModelTextureVertex_copy(ModelTextureVertex_* a, const ModelTextureVertex_* b);
SECAPI FLOAT3D_* ModelTextureVertex_mtv_UVW(ModelTextureVertex_* p);
SECAPI MEX2D_* ModelTextureVertex_mtv_UV(ModelTextureVertex_* p);

SECAPI ModelPolygonVertex_* ModelPolygonVertex_new();
SECAPI ModelPolygonVertex_* ModelPolygonVertex_clone(const ModelPolygonVertex_* p);
SECAPI void ModelPolygonVertex_delete(ModelPolygonVertex_* p);
SECAPI void ModelPolygonVertex_copy(ModelPolygonVertex_* a, const ModelPolygonVertex_* b);
SECAPI TransformedVertexData_** ModelPolygonVertex_mpv_ptvTransformedVertex(ModelPolygonVertex_* p);
SECAPI ModelTextureVertex_** ModelPolygonVertex_mpv_ptvTextureVertex(ModelPolygonVertex_* p);
SECAPI void ModelPolygonVertex_Read_t(ModelPolygonVertex_* p, CTStream_* s);
SECAPI void ModelPolygonVertex_Write_t(ModelPolygonVertex_* p, CTStream_* s);

SECAPI ModelPolygon_* ModelPolygon_new();
SECAPI void ModelPolygon_delete(ModelPolygon_* p);
SECAPI void ModelPolygon_copy(ModelPolygon_* a, const ModelPolygon_* b);
SECAPI CStaticArray_ModelPolygonVertex_* ModelPolygon_mp_PolygonVertices(ModelPolygon_* p);
SECAPI ULONG* ModelPolygon_mp_RenderFlags(ModelPolygon_* p);
SECAPI ULONG* ModelPolygon_mp_ColorAndAlpha(ModelPolygon_* p);
SECAPI INDEX* ModelPolygon_mp_Surface(ModelPolygon_* p);
SECAPI SLONG* ModelPolygon_mp_slVisibility(ModelPolygon_* p);
SECAPI BOOL* ModelPolygon_mp_bClipped(ModelPolygon_* p);
SECAPI void ModelPolygon_Read_t(ModelPolygon_* p, CTStream_* s);
SECAPI void ModelPolygon_Write_t(ModelPolygon_* p, CTStream_* s);

SECAPI MappingSurface_* MappingSurface_new();
SECAPI void MappingSurface_delete(MappingSurface_* p);
SECAPI void MappingSurface_copy(MappingSurface_* a, const MappingSurface_* b);
SECAPI BOOL MappingSurface_equal(const MappingSurface_* a, const MappingSurface_* b);
SECAPI CTString_* MappingSurface_ms_Name(MappingSurface_* p);
SECAPI COLOR* MappingSurface_ms_colColor(MappingSurface_* p);
SECAPI FLOAT3D_* MappingSurface_ms_vSurfaceCenterOffset(MappingSurface_* p);
SECAPI COLOR* MappingSurface_ms_colDiffuse(MappingSurface_* p);
SECAPI COLOR* MappingSurface_ms_colReflections(MappingSurface_* p);
SECAPI COLOR* MappingSurface_ms_colSpecular(MappingSurface_* p);
SECAPI COLOR* MappingSurface_ms_colBump(MappingSurface_* p);
SECAPI ULONG* MappingSurface_ms_ulOnColor(MappingSurface_* p);
SECAPI ULONG* MappingSurface_ms_ulOffColor(MappingSurface_* p);
SECAPI ULONG* MappingSurface_ms_ulRenderingFlags(MappingSurface_* p);
SECAPI SurfaceShadingType_* MappingSurface_ms_sstShadingType(MappingSurface_* p);
SECAPI SurfaceTranslucencyType_* MappingSurface_ms_sttTranslucencyType(MappingSurface_* p);
SECAPI CStaticArray_INDEX_* MappingSurface_ms_aiPolygons(MappingSurface_* p);
SECAPI CStaticArray_INDEX_* MappingSurface_ms_aiTextureVertices(MappingSurface_* p);
SECAPI INDEX* MappingSurface_ms_iSrfVx0(MappingSurface_* p);
SECAPI INDEX* MappingSurface_ms_ctSrfVx(MappingSurface_* p);
SECAPI INDEX* MappingSurface_ms_ctSrfEl(MappingSurface_* p);
SECAPI void MappingSurface_Read_t(MappingSurface_* p, CTStream_* s, BOOL readPolygonsPerSurface, BOOL readSurfaceColors);
SECAPI void MappingSurface_Write_t(MappingSurface_* p, CTStream_* s);
SECAPI void MappingSurface_ReadSettings_t(MappingSurface_* p, CTStream_* s);
SECAPI void MappingSurface_WriteSettings_t(MappingSurface_* p, CTStream_* s);

SECAPI PolygonsPerPatch_* PolygonsPerPatch_new();
SECAPI void PolygonsPerPatch_delete(PolygonsPerPatch_* p);
SECAPI void PolygonsPerPatch_copy(PolygonsPerPatch_* a, const PolygonsPerPatch_* b);
SECAPI CStaticArray_INDEX_* PolygonsPerPatch_ppp_iPolygons(PolygonsPerPatch_* p);
SECAPI CStaticArray_UWORD_* PolygonsPerPatch_ppp_auwElements(PolygonsPerPatch_* p);
SECAPI void PolygonsPerPatch_Clear(PolygonsPerPatch_* p);

SECAPI TransformedVertexData_* TransformedVertexData_new();
SECAPI TransformedVertexData_* TransformedVertexData_clone(const TransformedVertexData_* p);
SECAPI void TransformedVertexData_delete(TransformedVertexData_* p);
SECAPI void TransformedVertexData_copy(TransformedVertexData_* a, const TransformedVertexData_* b);
SECAPI FLOAT3D_* TransformedVertexData_tvd_TransformedPoint(TransformedVertexData_* p);
SECAPI FLOAT* TransformedVertexData_tvd_fX(TransformedVertexData_* p);
SECAPI FLOAT* TransformedVertexData_tvd_fY(TransformedVertexData_* p);
SECAPI FLOAT* TransformedVertexData_tvd_fZ(TransformedVertexData_* p);
SECAPI FLOAT* TransformedVertexData_tvd_fU(TransformedVertexData_* p);
SECAPI FLOAT* TransformedVertexData_tvd_fV(TransformedVertexData_* p);
SECAPI BOOL* TransformedVertexData_tvd_bClipped(TransformedVertexData_* p);

SECAPI CModelCollisionBox_* CModelCollisionBox_new();
SECAPI CModelCollisionBox_* CModelCollisionBox_clone(const CModelCollisionBox_* p);
SECAPI void CModelCollisionBox_delete(CModelCollisionBox_* p);
SECAPI void CModelCollisionBox_copy(CModelCollisionBox_* a, const CModelCollisionBox_* b);
SECAPI FLOAT3D_* CModelCollisionBox_mcb_vCollisionBoxMin(CModelCollisionBox_* p);
SECAPI FLOAT3D_* CModelCollisionBox_mcb_vCollisionBoxMax(CModelCollisionBox_* p);
SECAPI ULONG* CModelCollisionBox_mcb_iCollisionBoxDimensionEquality(CModelCollisionBox_* p);
SECAPI CTString_* CModelCollisionBox_mcb_strName(CModelCollisionBox_* p);
SECAPI void CModelCollisionBox_Read_t(CModelCollisionBox_* p, CTStream_* s);
SECAPI void CModelCollisionBox_ReadName_t(CModelCollisionBox_* p, CTStream_* s);
SECAPI void CModelCollisionBox_Write_t(CModelCollisionBox_* p, CTStream_* s);

SECAPI CAttachedModelPosition_* CAttachedModelPosition_new();
SECAPI CAttachedModelPosition_* CAttachedModelPosition_clone(const CAttachedModelPosition_* p);
SECAPI void CAttachedModelPosition_delete(CAttachedModelPosition_* p);
SECAPI void CAttachedModelPosition_copy(CAttachedModelPosition_* a, const CAttachedModelPosition_* b);
SECAPI INDEX* CAttachedModelPosition_amp_iCenterVertex(CAttachedModelPosition_* p);
SECAPI INDEX* CAttachedModelPosition_amp_iFrontVertex(CAttachedModelPosition_* p);
SECAPI INDEX* CAttachedModelPosition_amp_iUpVertex(CAttachedModelPosition_* p);
SECAPI CPlacement3D_* CAttachedModelPosition_amp_plRelativePlacement(CAttachedModelPosition_* p);
SECAPI void CAttachedModelPosition_Read_t(CAttachedModelPosition_* p, CTStream_* s);
SECAPI void CAttachedModelPosition_Write_t(CAttachedModelPosition_* p, CTStream_* s);

SECAPI CMipInfo_* CMipInfo_new();
SECAPI CMipInfo_* CMipInfo_clone(const CMipInfo_* p);
SECAPI void CMipInfo_delete(CMipInfo_* p);
SECAPI void CMipInfo_copy(CMipInfo_* a, const CMipInfo_* b);
SECAPI INDEX* CMipInfo_mi_TrianglesCt(CMipInfo_* p);
SECAPI INDEX* CMipInfo_mi_PolygonsCt(CMipInfo_* p);
SECAPI INDEX* CMipInfo_mi_VerticesCt(CMipInfo_* p);

SECAPI CModelInfo_* CModelInfo_new();
SECAPI CModelInfo_* CModelInfo_clone(const CModelInfo_* p);
SECAPI void CModelInfo_delete(CModelInfo_* p);
SECAPI void CModelInfo_copy(CModelInfo_* a, const CModelInfo_* b);
SECAPI INDEX* CModelInfo_mi_VerticesCt(CModelInfo_* p);
SECAPI INDEX* CModelInfo_mi_FramesCt(CModelInfo_* p);
SECAPI INDEX* CModelInfo_mi_MipCt(CModelInfo_* p);
SECAPI CMipInfo_* CModelInfo_mi_MipInfos(CModelInfo_* p, INDEX i);
SECAPI CTFileName_* CModelInfo_mi_PatchFiles(CModelInfo_* p, INDEX i);
SECAPI MEX* CModelInfo_mi_Width(CModelInfo_* p);
SECAPI MEX* CModelInfo_mi_Height(CModelInfo_* p);
SECAPI BOOL* CModelInfo_mi_Flags(CModelInfo_* p);
SECAPI SLONG* CModelInfo_mi_ShadowQuality(CModelInfo_* p);
SECAPI FLOAT3D_* CModelInfo_mi_Stretch(CModelInfo_* p);

#ifdef __cplusplus
}
#endif

#endif
