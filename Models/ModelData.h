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

#ifndef SECAPI_MODELS_MODEL_DATA_H
#define SECAPI_MODELS_MODEL_DATA_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI CModelPatch_* CModelPatch_new();
SECAPI void CModelPatch_delete(CModelPatch_* p);
SECAPI CTString_* CModelPatch_mp_strName(CModelPatch_* p);
SECAPI CTextureObject_* CModelPatch_mp_toTexture(CModelPatch_* p);
SECAPI MEX2D_* CModelPatch_mp_mexPosition(CModelPatch_* p);
SECAPI FLOAT* CModelPatch_mp_fStretch(CModelPatch_* p);
SECAPI void CModelPatch_Read_t(CModelPatch_* p, CTStream_* s);
SECAPI void CModelPatch_Write_t(CModelPatch_* p, CTStream_* s);

SECAPI ModelMipInfo_* ModelMipInfo_new();
SECAPI void ModelMipInfo_delete(ModelMipInfo_* p);
SECAPI void ModelMipInfo_copy(ModelMipInfo_* a, const ModelMipInfo_* b);
SECAPI INDEX* ModelMipInfo_mmpi_PolygonsCt(ModelMipInfo_* p);
SECAPI ULONG* ModelMipInfo_mmpi_ulFlags(ModelMipInfo_* p);
SECAPI CStaticArray_PolygonsPerPatch_* ModelMipInfo_mmpi_aPolygonsPerPatch(ModelMipInfo_* p);
SECAPI CStaticArray_ModelPolygon_* ModelMipInfo_mmpi_Polygons(ModelMipInfo_* p);
SECAPI CStaticArray_ModelTextureVertex_* ModelMipInfo_mmpi_TextureVertices(ModelMipInfo_* p);
SECAPI CStaticArray_MappingSurface_* ModelMipInfo_mmpi_MappingSurfaces(ModelMipInfo_* p);
SECAPI INDEX* ModelMipInfo_mmpi_ctMipVx(ModelMipInfo_* p);
SECAPI INDEX* ModelMipInfo_mmpi_ctSrfVx(ModelMipInfo_* p);
SECAPI CStaticArray_UWORD_* ModelMipInfo_mmpi_auwMipToMdl(ModelMipInfo_* p);
SECAPI CStaticArray_UWORD_* ModelMipInfo_mmpi_auwSrfToMip(ModelMipInfo_* p);
SECAPI CStaticArray_FLOAT2D_* ModelMipInfo_mmpi_avmexTexCoord(ModelMipInfo_* p);
SECAPI CStaticArray_FLOAT3D_* ModelMipInfo_mmpi_avBumpU(ModelMipInfo_* p);
SECAPI CStaticArray_FLOAT3D_* ModelMipInfo_mmpi_avBumpV(ModelMipInfo_* p);
SECAPI ULONG* ModelMipInfo_mmpi_ulLayerFlags(ModelMipInfo_* p);
SECAPI INDEX* ModelMipInfo_mmpi_ctTriangles(ModelMipInfo_* p);
SECAPI CStaticStackArray_INDEX_* ModelMipInfo_mmpi_aiElements(ModelMipInfo_* p);
SECAPI void ModelMipInfo_Clear(ModelMipInfo_* p);
SECAPI void ModelMipInfo_Read_t(ModelMipInfo_* p, CTStream_* s, BOOL readPolygonalPatches, BOOL readPolygonsPerSurface, BOOL readSurfaceColors);
SECAPI void ModelMipInfo_Write_t(ModelMipInfo_* p, CTStream_* s);

SECAPI CModelData_* CModelData_new();
SECAPI void CModelData_delete(CModelData_* p);
SECAPI INDEX* CModelData_md_VerticesCt(CModelData_* p);
SECAPI INDEX* CModelData_md_FramesCt(CModelData_* p);
SECAPI CStaticArray_ModelFrameVertex8_* CModelData_md_FrameVertices8(CModelData_* p);
SECAPI CStaticArray_ModelFrameVertex16_* CModelData_md_FrameVertices16(CModelData_* p);
SECAPI CStaticArray_ModelFrameInfo_* CModelData_md_FrameInfos(CModelData_* p);
SECAPI CStaticArray_FLOAT3D_* CModelData_md_MainMipVertices(CModelData_* p);
SECAPI CStaticArray_TransformedVertexData_* CModelData_md_TransformedVertices(CModelData_* p);
SECAPI CStaticArray_ULONG_* CModelData_md_VertexMipMask(CModelData_* p);
SECAPI INDEX* CModelData_md_MipCt(CModelData_* p);
SECAPI FLOAT* CModelData_md_MipSwitchFactors(CModelData_* p, INDEX i);
SECAPI ModelMipInfo_* CModelData_md_MipInfos(CModelData_* p, INDEX i);
SECAPI MEX* CModelData_md_Width(CModelData_* p);
SECAPI MEX* CModelData_md_Height(CModelData_* p);
SECAPI CModelPatch_* CModelData_md_mpPatches(CModelData_* p, INDEX i);
SECAPI CTString_* CModelData_md_ColorNames(CModelData_* p, INDEX i);
SECAPI ULONG* CModelData_md_Flags(CModelData_* p);
SECAPI SLONG* CModelData_md_ShadowQuality(CModelData_* p);
SECAPI FLOAT3D_* CModelData_md_Stretch(CModelData_* p);
SECAPI FLOAT3D_* CModelData_md_vCenter(CModelData_* p);
SECAPI FLOAT3D_* CModelData_md_vCompressedCenter(CModelData_* p);
SECAPI BOOL* CModelData_md_bHasAlpha(CModelData_* p);
SECAPI CDynamicArray_CModelCollisionBox_* CModelData_md_acbCollisionBox(CModelData_* p);
SECAPI BOOL* CModelData_md_bCollideAsCube(CModelData_* p);
SECAPI CDynamicArray_CAttachedModelPosition_* CModelData_md_aampAttachedPosition(CModelData_* p);
SECAPI BOOL* CModelData_md_bIsEdited(CModelData_* p);
SECAPI COLOR* CModelData_md_colDiffuse(CModelData_* p);
SECAPI COLOR* CModelData_md_colReflections(CModelData_* p);
SECAPI COLOR* CModelData_md_colSpecular(CModelData_* p);
SECAPI COLOR* CModelData_md_colBump(CModelData_* p);
SECAPI BOOL* CModelData_md_bPreparedForRendering(CModelData_* p);
SECAPI void CModelData_SpreadMipSwitchFactors(CModelData_* p, INDEX iFirst, FLOAT fStartingFactor);
SECAPI void CModelData_GetTextureDimensions(CModelData_* p, MEX* mexWidth, MEX* mexHeight);
SECAPI void CModelData_GetAllFramesBBox(CModelData_* p, FLOATaabbox3D_* MaxBB);
SECAPI FLOAT3D_* CModelData_GetCollisionBoxMin(CModelData_* p, INDEX iCollisionBox);
SECAPI FLOAT3D_* CModelData_GetCollisionBoxMax(CModelData_* p, INDEX iCollisionBox);
SECAPI INDEX CModelData_GetCollisionBoxDimensionEquality(CModelData_* p, INDEX iCollisionBox); // returns HEIGHT_EQ_WIDTH, LENGTH_EQ_WIDTH or LENGTH_EQ_HEIGHT
SECAPI ULONG CModelData_GetFlags(CModelData_* p);
SECAPI void CModelData_Clear(CModelData_* p);
SECAPI void CModelData_ClearAnimations(CModelData_* p);
SECAPI void CModelData_LinkDataForSurfaces(CModelData_* p, BOOL bFirstMip);
// The created COneAnim elements are raw; the consumer must initialize every
// field, incl. allocating a frame-index array per anim (oa_FrameIndices),
// before CModelData_ClearAnimations()/CModelData_delete() frees the block.
SECAPI void CModelData_CreateAnimationsRaw(CModelData_* p, INDEX ct);

#ifdef __cplusplus
}
#endif

#endif
