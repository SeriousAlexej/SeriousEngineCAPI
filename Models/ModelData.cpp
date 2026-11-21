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

#include "ModelData.h"
#include "../Base/OneAnim.h"

CModelPatch_* CModelPatch_new()
{
  return (CModelPatch_*)(new CModelPatch());
}

void CModelPatch_delete(CModelPatch_* p)
{
  delete ((CModelPatch*)p);
}

CTString_* CModelPatch_mp_strName(CModelPatch_* p)
{
  CModelPatch& pt = *((CModelPatch*)p);
  return (CTString_*)(&(pt.mp_strName));
}

CTextureObject_* CModelPatch_mp_toTexture(CModelPatch_* p)
{
  CModelPatch& pt = *((CModelPatch*)p);
  return (CTextureObject_*)(&(pt.mp_toTexture));
}

MEX2D_* CModelPatch_mp_mexPosition(CModelPatch_* p)
{
  CModelPatch& pt = *((CModelPatch*)p);
  return (MEX2D_*)(&(pt.mp_mexPosition));
}

FLOAT* CModelPatch_mp_fStretch(CModelPatch_* p)
{
  CModelPatch& pt = *((CModelPatch*)p);
  return &(pt.mp_fStretch);
}

static void sehCModelPatch_Read_t(CModelPatch_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CModelPatch*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CModelPatch_Read_t(CModelPatch_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelPatch_Read_t(p, s);
  STREAM_CATCH
}

static void sehCModelPatch_Write_t(CModelPatch_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CModelPatch*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CModelPatch_Write_t(CModelPatch_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelPatch_Write_t(p, s);
  STREAM_CATCH
}


ModelMipInfo_* ModelMipInfo_new()
{
  return (ModelMipInfo_*)(new ModelMipInfo());
}

void ModelMipInfo_delete(ModelMipInfo_* p)
{
  delete ((ModelMipInfo*)p);
}

void ModelMipInfo_copy(ModelMipInfo_* a, const ModelMipInfo_* b)
{
  *((ModelMipInfo*)a) = *((const ModelMipInfo*)b);
}

INDEX* ModelMipInfo_mmpi_PolygonsCt(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_PolygonsCt);
}

ULONG* ModelMipInfo_mmpi_ulFlags(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_ulFlags);
}

CStaticArray_PolygonsPerPatch_* ModelMipInfo_mmpi_aPolygonsPerPatch(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_PolygonsPerPatch_*)(&(m.mmpi_aPolygonsPerPatch));
}

CStaticArray_ModelPolygon_* ModelMipInfo_mmpi_Polygons(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_ModelPolygon_*)(&(m.mmpi_Polygons));
}

CStaticArray_ModelTextureVertex_* ModelMipInfo_mmpi_TextureVertices(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_ModelTextureVertex_*)(&(m.mmpi_TextureVertices));
}

CStaticArray_MappingSurface_* ModelMipInfo_mmpi_MappingSurfaces(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_MappingSurface_*)(&(m.mmpi_MappingSurfaces));
}

INDEX* ModelMipInfo_mmpi_ctMipVx(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_ctMipVx);
}

INDEX* ModelMipInfo_mmpi_ctSrfVx(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_ctSrfVx);
}

CStaticArray_UWORD_* ModelMipInfo_mmpi_auwMipToMdl(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_UWORD_*)(&(m.mmpi_auwMipToMdl));
}

CStaticArray_UWORD_* ModelMipInfo_mmpi_auwSrfToMip(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_UWORD_*)(&(m.mmpi_auwSrfToMip));
}

CStaticArray_FLOAT2D_* ModelMipInfo_mmpi_avmexTexCoord(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_FLOAT2D_*)(&(m.mmpi_avmexTexCoord));
}

CStaticArray_FLOAT3D_* ModelMipInfo_mmpi_avBumpU(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_FLOAT3D_*)(&(m.mmpi_avBumpU));
}

CStaticArray_FLOAT3D_* ModelMipInfo_mmpi_avBumpV(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticArray_FLOAT3D_*)(&(m.mmpi_avBumpV));
}

ULONG* ModelMipInfo_mmpi_ulLayerFlags(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_ulLayerFlags);
}

INDEX* ModelMipInfo_mmpi_ctTriangles(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return &(m.mmpi_ctTriangles);
}

CStaticStackArray_INDEX_* ModelMipInfo_mmpi_aiElements(ModelMipInfo_* p)
{
  ModelMipInfo& m = *((ModelMipInfo*)p);
  return (CStaticStackArray_INDEX_*)(&(m.mmpi_aiElements));
}

void ModelMipInfo_Clear(ModelMipInfo_* p)
{
  ((ModelMipInfo*)p)->Clear();
}

static void sehModelMipInfo_Read_t(ModelMipInfo_* p, CTStream_* s, BOOL readPolygonalPatches, BOOL readPolygonsPerSurface, BOOL readSurfaceColors)
{
  SECAPI_TRY
  ((ModelMipInfo*)p)->Read_t((CTStream*)s, readPolygonalPatches, readPolygonsPerSurface, readSurfaceColors);
  SECAPI_CATCH
}

void ModelMipInfo_Read_t(ModelMipInfo_* p, CTStream_* s, BOOL readPolygonalPatches, BOOL readPolygonsPerSurface, BOOL readSurfaceColors)
{
  STREAM_TRY
  sehModelMipInfo_Read_t(p, s, readPolygonalPatches, readPolygonsPerSurface, readSurfaceColors);
  STREAM_CATCH
}

static void sehModelMipInfo_Write_t(ModelMipInfo_* p, CTStream_* s)
{
  SECAPI_TRY
  ((ModelMipInfo*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void ModelMipInfo_Write_t(ModelMipInfo_* p, CTStream_* s)
{
  STREAM_TRY
  sehModelMipInfo_Write_t(p, s);
  STREAM_CATCH
}


CModelData_* CModelData_new()
{
  return (CModelData_*)(new CModelData());
}

void CModelData_delete(CModelData_* p)
{
  delete ((CModelData*)p);
}

INDEX* CModelData_md_VerticesCt(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_VerticesCt);
}

INDEX* CModelData_md_FramesCt(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_FramesCt);
}

CStaticArray_ModelFrameVertex8_* CModelData_md_FrameVertices8(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_ModelFrameVertex8_*)(&(m.md_FrameVertices8));
}

CStaticArray_ModelFrameVertex16_* CModelData_md_FrameVertices16(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_ModelFrameVertex16_*)(&(m.md_FrameVertices16));
}

CStaticArray_ModelFrameInfo_* CModelData_md_FrameInfos(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_ModelFrameInfo_*)(&(m.md_FrameInfos));
}

CStaticArray_FLOAT3D_* CModelData_md_MainMipVertices(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_FLOAT3D_*)(&(m.md_MainMipVertices));
}

CStaticArray_TransformedVertexData_* CModelData_md_TransformedVertices(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_TransformedVertexData_*)(&(m.md_TransformedVertices));
}

CStaticArray_ULONG_* CModelData_md_VertexMipMask(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CStaticArray_ULONG_*)(&(m.md_VertexMipMask));
}

INDEX* CModelData_md_MipCt(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_MipCt);
}

FLOAT* CModelData_md_MipSwitchFactors(CModelData_* p, INDEX i)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_MipSwitchFactors[i]);
}

ModelMipInfo_* CModelData_md_MipInfos(CModelData_* p, INDEX i)
{
  CModelData& m = *((CModelData*)p);
  return (ModelMipInfo_*)(&(m.md_MipInfos[i]));
}

MEX* CModelData_md_Width(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_Width);
}

MEX* CModelData_md_Height(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_Height);
}

CModelPatch_* CModelData_md_mpPatches(CModelData_* p, INDEX i)
{
  CModelData& m = *((CModelData*)p);
  return (CModelPatch_*)(&(m.md_mpPatches[i]));
}

CTString_* CModelData_md_ColorNames(CModelData_* p, INDEX i)
{
  CModelData& m = *((CModelData*)p);
  return (CTString_*)(&(m.md_ColorNames[i]));
}

ULONG* CModelData_md_Flags(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_Flags);
}

SLONG* CModelData_md_ShadowQuality(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_ShadowQuality);
}

FLOAT3D_* CModelData_md_Stretch(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (FLOAT3D_*)(&(m.md_Stretch));
}

FLOAT3D_* CModelData_md_vCenter(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (FLOAT3D_*)(&(m.md_vCenter));
}

FLOAT3D_* CModelData_md_vCompressedCenter(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (FLOAT3D_*)(&(m.md_vCompressedCenter));
}

BOOL* CModelData_md_bHasAlpha(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_bHasAlpha);
}

CDynamicArray_CModelCollisionBox_* CModelData_md_acbCollisionBox(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CDynamicArray_CModelCollisionBox_*)(&(m.md_acbCollisionBox));
}

BOOL* CModelData_md_bCollideAsCube(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_bCollideAsCube);
}

CDynamicArray_CAttachedModelPosition_* CModelData_md_aampAttachedPosition(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return (CDynamicArray_CAttachedModelPosition_*)(&(m.md_aampAttachedPosition));
}

BOOL* CModelData_md_bIsEdited(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_bIsEdited);
}

COLOR* CModelData_md_colDiffuse(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_colDiffuse);
}

COLOR* CModelData_md_colReflections(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_colReflections);
}

COLOR* CModelData_md_colSpecular(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_colSpecular);
}

COLOR* CModelData_md_colBump(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_colBump);
}

BOOL* CModelData_md_bPreparedForRendering(CModelData_* p)
{
  CModelData& m = *((CModelData*)p);
  return &(m.md_bPreparedForRendering);
}

void CModelData_SpreadMipSwitchFactors(CModelData_* p, INDEX iFirst, FLOAT fStartingFactor)
{
  ((CModelData*)p)->SpreadMipSwitchFactors(iFirst, fStartingFactor);
}

void CModelData_GetTextureDimensions(CModelData_* p, MEX* mexWidth, MEX* mexHeight)
{
  ((CModelData*)p)->GetTextureDimensions(*mexWidth, *mexHeight);
}

void CModelData_GetAllFramesBBox(CModelData_* p, FLOATaabbox3D_* MaxBB)
{
  ((CModelData*)p)->GetAllFramesBBox(*((FLOATaabbox3D*)MaxBB));
}

FLOAT3D_* CModelData_GetCollisionBoxMin(CModelData_* p, INDEX iCollisionBox)
{
  FLOAT3D res = ((CModelData*)p)->GetCollisionBoxMin(iCollisionBox);
  return (FLOAT3D_*)(new FLOAT3D(res));
}

FLOAT3D_* CModelData_GetCollisionBoxMax(CModelData_* p, INDEX iCollisionBox)
{
  FLOAT3D res = ((CModelData*)p)->GetCollisionBoxMax(iCollisionBox);
  return (FLOAT3D_*)(new FLOAT3D(res));
}

INDEX CModelData_GetCollisionBoxDimensionEquality(CModelData_* p, INDEX iCollisionBox)
{
  return ((CModelData*)p)->GetCollisionBoxDimensionEquality(iCollisionBox);
}

ULONG CModelData_GetFlags(CModelData_* p)
{
  return ((CModelData*)p)->GetFlags();
}

void CModelData_Clear(CModelData_* p)
{
  ((CModelData*)p)->Clear();
}

void CModelData_ClearAnimations(CModelData_* p)
{
  ((CModelData*)p)->ClearAnimations();
}

void CModelData_LinkDataForSurfaces(CModelData_* p, BOOL bFirstMip)
{
  ((CModelData*)p)->LinkDataForSurfaces(bFirstMip);
}

void CModelData_CreateAnimationsRaw(CModelData_* p, INDEX ct)
{
  CModelData& md = *((CModelData*)p);
  md.CAnimData::Clear();
  md.ad_NumberOfAnims = ct;
  md.ad_Anims = new COneAnim[ct];
}
