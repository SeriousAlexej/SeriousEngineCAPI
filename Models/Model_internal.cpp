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

#include "Model_internal.h"

COLOR* PaletteColorValues_()
{
  return &(PaletteColorValues[0]);
}

ModelFrameVertex8_* ModelFrameVertex8_new()
{
  return (ModelFrameVertex8_*)(new ModelFrameVertex8());
}

ModelFrameVertex8_* ModelFrameVertex8_clone(const ModelFrameVertex8_* p)
{
  return (ModelFrameVertex8_*)(new ModelFrameVertex8(*((const ModelFrameVertex8*)p)));
}

void ModelFrameVertex8_delete(ModelFrameVertex8_* p)
{
  delete ((ModelFrameVertex8*)p);
}

void ModelFrameVertex8_copy(ModelFrameVertex8_* a, const ModelFrameVertex8_* b)
{
  *((ModelFrameVertex8*)a) = *((const ModelFrameVertex8*)b);
}

SBPOINT3D_* ModelFrameVertex8_mfv_SBPoint(ModelFrameVertex8_* p)
{
  ModelFrameVertex8& v = *((ModelFrameVertex8*)p);
  return (SBPOINT3D_*)(&(v.mfv_SBPoint));
}

UBYTE* ModelFrameVertex8_mfv_NormIndex(ModelFrameVertex8_* p)
{
  ModelFrameVertex8& v = *((ModelFrameVertex8*)p);
  return &(v.mfv_NormIndex);
}

ModelFrameVertex16_* ModelFrameVertex16_new()
{
  return (ModelFrameVertex16_*)(new ModelFrameVertex16());
}

ModelFrameVertex16_* ModelFrameVertex16_clone(const ModelFrameVertex16_* p)
{
  return (ModelFrameVertex16_*)(new ModelFrameVertex16(*((const ModelFrameVertex16*)p)));
}

void ModelFrameVertex16_delete(ModelFrameVertex16_* p)
{
  delete ((ModelFrameVertex16*)p);
}

void ModelFrameVertex16_copy(ModelFrameVertex16_* a, const ModelFrameVertex16_* b)
{
  *((ModelFrameVertex16*)a) = *((const ModelFrameVertex16*)b);
}

SWPOINT3D_* ModelFrameVertex16_mfv_SWPoint(ModelFrameVertex16_* p)
{
  ModelFrameVertex16& v = *((ModelFrameVertex16*)p);
  return (SWPOINT3D_*)(&(v.mfv_SWPoint));
}

UBYTE* ModelFrameVertex16_mfv_ubNormH(ModelFrameVertex16_* p)
{
  ModelFrameVertex16& v = *((ModelFrameVertex16*)p);
  return &(v.mfv_ubNormH);
}

UBYTE* ModelFrameVertex16_mfv_ubNormP(ModelFrameVertex16_* p)
{
  ModelFrameVertex16& v = *((ModelFrameVertex16*)p);
  return &(v.mfv_ubNormP);
}

ModelFrameInfo_* ModelFrameInfo_new()
{
  return (ModelFrameInfo_*)(new ModelFrameInfo());
}

ModelFrameInfo_* ModelFrameInfo_clone(const ModelFrameInfo_* p)
{
  return (ModelFrameInfo_*)(new ModelFrameInfo(*((const ModelFrameInfo*)p)));
}

void ModelFrameInfo_delete(ModelFrameInfo_* p)
{
  delete ((ModelFrameInfo*)p);
}

void ModelFrameInfo_copy(ModelFrameInfo_* a, const ModelFrameInfo_* b)
{
  *((ModelFrameInfo*)a) = *((const ModelFrameInfo*)b);
}

FLOATaabbox3D_* ModelFrameInfo_mfi_Box(ModelFrameInfo_* p)
{
  ModelFrameInfo& m = *((ModelFrameInfo*)p);
  return (FLOATaabbox3D_*)(&(m.mfi_Box));
}

ModelTextureVertex_* ModelTextureVertex_new()
{
  return (ModelTextureVertex_*)(new ModelTextureVertex());
}

ModelTextureVertex_* ModelTextureVertex_clone(const ModelTextureVertex_* p)
{
  return (ModelTextureVertex_*)(new ModelTextureVertex(*((const ModelTextureVertex*)p)));
}

void ModelTextureVertex_delete(ModelTextureVertex_* p)
{
  delete ((ModelTextureVertex*)p);
}

void ModelTextureVertex_copy(ModelTextureVertex_* a, const ModelTextureVertex_* b)
{
  *((ModelTextureVertex*)a) = *((const ModelTextureVertex*)b);
}

FLOAT3D_* ModelTextureVertex_mtv_UVW(ModelTextureVertex_* p)
{
  ModelTextureVertex& m = *((ModelTextureVertex*)p);
  return (FLOAT3D_*)(&(m.mtv_UVW));
}

MEX2D_* ModelTextureVertex_mtv_UV(ModelTextureVertex_* p)
{
  ModelTextureVertex& m = *((ModelTextureVertex*)p);
  return (MEX2D_*)(&(m.mtv_UV));
}

ModelPolygonVertex_* ModelPolygonVertex_new()
{
  return (ModelPolygonVertex_*)(new ModelPolygonVertex());
}

ModelPolygonVertex_* ModelPolygonVertex_clone(const ModelPolygonVertex_* p)
{
  return (ModelPolygonVertex_*)(new ModelPolygonVertex(*((const ModelPolygonVertex*)p)));
}

void ModelPolygonVertex_delete(ModelPolygonVertex_* p)
{
  delete ((ModelPolygonVertex*)p);
}

void ModelPolygonVertex_copy(ModelPolygonVertex_* a, const ModelPolygonVertex_* b)
{
  *((ModelPolygonVertex*)a) = *((const ModelPolygonVertex*)b);
}

TransformedVertexData_** ModelPolygonVertex_mpv_ptvTransformedVertex(ModelPolygonVertex_* p)
{
  ModelPolygonVertex& m = *((ModelPolygonVertex*)p);
  return (TransformedVertexData_**)(&(m.mpv_ptvTransformedVertex));
}

ModelTextureVertex_** ModelPolygonVertex_mpv_ptvTextureVertex(ModelPolygonVertex_* p)
{
  ModelPolygonVertex& m = *((ModelPolygonVertex*)p);
  return (ModelTextureVertex_**)(&(m.mpv_ptvTextureVertex));
}

static void sehModelPolygonVertex_Read_t(ModelPolygonVertex_* p, CTStream_* s)
{
  SECAPI_TRY
  ((ModelPolygonVertex*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void ModelPolygonVertex_Read_t(ModelPolygonVertex_* p, CTStream_* s)
{
  STREAM_TRY
  sehModelPolygonVertex_Read_t(p, s);
  STREAM_CATCH
}

static void sehModelPolygonVertex_Write_t(ModelPolygonVertex_* p, CTStream_* s)
{
  SECAPI_TRY
  ((ModelPolygonVertex*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void ModelPolygonVertex_Write_t(ModelPolygonVertex_* p, CTStream_* s)
{
  STREAM_TRY
  sehModelPolygonVertex_Write_t(p, s);
  STREAM_CATCH
}

ModelPolygon_* ModelPolygon_new()
{
  return (ModelPolygon_*)(new ModelPolygon());
}

void ModelPolygon_delete(ModelPolygon_* p)
{
  delete ((ModelPolygon*)p);
}

void ModelPolygon_copy(ModelPolygon_* a, const ModelPolygon_* b)
{
  *((ModelPolygon*)a) = *((const ModelPolygon*)b);
}

CStaticArray_ModelPolygonVertex_* ModelPolygon_mp_PolygonVertices(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return (CStaticArray_ModelPolygonVertex_*)(&(m.mp_PolygonVertices));
}

ULONG* ModelPolygon_mp_RenderFlags(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return &(m.mp_RenderFlags);
}

ULONG* ModelPolygon_mp_ColorAndAlpha(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return &(m.mp_ColorAndAlpha);
}

INDEX* ModelPolygon_mp_Surface(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return &(m.mp_Surface);
}

SLONG* ModelPolygon_mp_slVisibility(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return &(m.mp_slVisibility);
}

BOOL* ModelPolygon_mp_bClipped(ModelPolygon_* p)
{
  ModelPolygon& m = *((ModelPolygon*)p);
  return &(m.mp_bClipped);
}

static void sehModelPolygon_Read_t(ModelPolygon_* p, CTStream_* s)
{
  SECAPI_TRY
  ((ModelPolygon*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void ModelPolygon_Read_t(ModelPolygon_* p, CTStream_* s)
{
  STREAM_TRY
  sehModelPolygon_Read_t(p, s);
  STREAM_CATCH
}

static void sehModelPolygon_Write_t(ModelPolygon_* p, CTStream_* s)
{
  SECAPI_TRY
  ((ModelPolygon*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void ModelPolygon_Write_t(ModelPolygon_* p, CTStream_* s)
{
  STREAM_TRY
  sehModelPolygon_Write_t(p, s);
  STREAM_CATCH
}

MappingSurface_* MappingSurface_new()
{
  return (MappingSurface_*)(new MappingSurface());
}

void MappingSurface_delete(MappingSurface_* p)
{
  delete ((MappingSurface*)p);
}

void MappingSurface_copy(MappingSurface_* a, const MappingSurface_* b)
{
  *((MappingSurface*)a) = *((const MappingSurface*)b);
}

BOOL MappingSurface_equal(const MappingSurface_* a, const MappingSurface_* b)
{
  return (*((const MappingSurface*)a)) == (*((const MappingSurface*)b));
}

CTString_* MappingSurface_ms_Name(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (CTString_*)(&(s.ms_Name));
}

COLOR* MappingSurface_ms_colColor(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_colColor);
}

FLOAT3D_* MappingSurface_ms_vSurfaceCenterOffset(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (FLOAT3D_*)(&(s.ms_vSurfaceCenterOffset));
}

COLOR* MappingSurface_ms_colDiffuse(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_colDiffuse);
}

COLOR* MappingSurface_ms_colReflections(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_colReflections);
}

COLOR* MappingSurface_ms_colSpecular(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_colSpecular);
}

COLOR* MappingSurface_ms_colBump(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_colBump);
}

ULONG* MappingSurface_ms_ulOnColor(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_ulOnColor);
}

ULONG* MappingSurface_ms_ulOffColor(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_ulOffColor);
}

ULONG* MappingSurface_ms_ulRenderingFlags(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_ulRenderingFlags);
}

SurfaceShadingType_* MappingSurface_ms_sstShadingType(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (SurfaceShadingType_*)(&(s.ms_sstShadingType));
}

SurfaceTranslucencyType_* MappingSurface_ms_sttTranslucencyType(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (SurfaceTranslucencyType_*)(&(s.ms_sttTranslucencyType));
}

CStaticArray_INDEX_* MappingSurface_ms_aiPolygons(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (CStaticArray_INDEX_*)(&(s.ms_aiPolygons));
}

CStaticArray_INDEX_* MappingSurface_ms_aiTextureVertices(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return (CStaticArray_INDEX_*)(&(s.ms_aiTextureVertices));
}

INDEX* MappingSurface_ms_iSrfVx0(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_iSrfVx0);
}

INDEX* MappingSurface_ms_ctSrfVx(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_ctSrfVx);
}

INDEX* MappingSurface_ms_ctSrfEl(MappingSurface_* p)
{
  MappingSurface& s = *((MappingSurface*)p);
  return &(s.ms_ctSrfEl);
}

static void sehMappingSurface_Read_t(MappingSurface_* p, CTStream_* s, BOOL readPolygonsPerSurface, BOOL readSurfaceColors)
{
  SECAPI_TRY
  ((MappingSurface*)p)->Read_t((CTStream*)s, readPolygonsPerSurface, readSurfaceColors);
  SECAPI_CATCH
}

void MappingSurface_Read_t(MappingSurface_* p, CTStream_* s, BOOL readPolygonsPerSurface, BOOL readSurfaceColors)
{
  STREAM_TRY
  sehMappingSurface_Read_t(p, s, readPolygonsPerSurface, readSurfaceColors);
  STREAM_CATCH
}

static void sehMappingSurface_Write_t(MappingSurface_* p, CTStream_* s)
{
  SECAPI_TRY
  ((MappingSurface*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void MappingSurface_Write_t(MappingSurface_* p, CTStream_* s)
{
  STREAM_TRY
  sehMappingSurface_Write_t(p, s);
  STREAM_CATCH
}

static void sehMappingSurface_ReadSettings_t(MappingSurface_* p, CTStream_* s)
{
  SECAPI_TRY
  ((MappingSurface*)p)->ReadSettings_t((CTStream*)s);
  SECAPI_CATCH
}

void MappingSurface_ReadSettings_t(MappingSurface_* p, CTStream_* s)
{
  STREAM_TRY
  sehMappingSurface_ReadSettings_t(p, s);
  STREAM_CATCH
}

static void sehMappingSurface_WriteSettings_t(MappingSurface_* p, CTStream_* s)
{
  SECAPI_TRY
  ((MappingSurface*)p)->WriteSettings_t((CTStream*)s);
  SECAPI_CATCH
}

void MappingSurface_WriteSettings_t(MappingSurface_* p, CTStream_* s)
{
  STREAM_TRY
  sehMappingSurface_WriteSettings_t(p, s);
  STREAM_CATCH
}

PolygonsPerPatch_* PolygonsPerPatch_new()
{
  return (PolygonsPerPatch_*)(new PolygonsPerPatch());
}

void PolygonsPerPatch_delete(PolygonsPerPatch_* p)
{
  delete ((PolygonsPerPatch*)p);
}

void PolygonsPerPatch_copy(PolygonsPerPatch_* a, const PolygonsPerPatch_* b)
{
  *((PolygonsPerPatch*)a) = *((const PolygonsPerPatch*)b);
}

CStaticArray_INDEX_* PolygonsPerPatch_ppp_iPolygons(PolygonsPerPatch_* p)
{
  PolygonsPerPatch& o = *((PolygonsPerPatch*)p);
  return (CStaticArray_INDEX_*)(&(o.ppp_iPolygons));
}

CStaticArray_UWORD_* PolygonsPerPatch_ppp_auwElements(PolygonsPerPatch_* p)
{
  PolygonsPerPatch& o = *((PolygonsPerPatch*)p);
  return (CStaticArray_UWORD_*)(&(o.ppp_auwElements));
}

void PolygonsPerPatch_Clear(PolygonsPerPatch_* p)
{
  ((PolygonsPerPatch*)p)->Clear();
}

TransformedVertexData_* TransformedVertexData_new()
{
  return (TransformedVertexData_*)(new TransformedVertexData());
}

TransformedVertexData_* TransformedVertexData_clone(const TransformedVertexData_* p)
{
  return (TransformedVertexData_*)(new TransformedVertexData(*((const TransformedVertexData*)p)));
}

void TransformedVertexData_delete(TransformedVertexData_* p)
{
  delete ((TransformedVertexData*)p);
}

void TransformedVertexData_copy(TransformedVertexData_* a, const TransformedVertexData_* b)
{
  *((TransformedVertexData*)a) = *((const TransformedVertexData*)b);
}

FLOAT3D_* TransformedVertexData_tvd_TransformedPoint(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return (FLOAT3D_*)(&(v.tvd_TransformedPoint));
}

FLOAT* TransformedVertexData_tvd_fX(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_fX);
}

FLOAT* TransformedVertexData_tvd_fY(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_fY);
}

FLOAT* TransformedVertexData_tvd_fZ(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_fZ);
}

FLOAT* TransformedVertexData_tvd_fU(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_fU);
}

FLOAT* TransformedVertexData_tvd_fV(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_fV);
}

BOOL* TransformedVertexData_tvd_bClipped(TransformedVertexData_* p)
{
  TransformedVertexData& v = *((TransformedVertexData*)p);
  return &(v.tvd_bClipped);
}

CModelCollisionBox_* CModelCollisionBox_new()
{
  return (CModelCollisionBox_*)(new CModelCollisionBox());
}

CModelCollisionBox_* CModelCollisionBox_clone(const CModelCollisionBox_* p)
{
  return (CModelCollisionBox_*)(new CModelCollisionBox(*((const CModelCollisionBox*)p)));
}

void CModelCollisionBox_delete(CModelCollisionBox_* p)
{
  delete ((CModelCollisionBox*)p);
}

void CModelCollisionBox_copy(CModelCollisionBox_* a, const CModelCollisionBox_* b)
{
  *((CModelCollisionBox*)a) = *((const CModelCollisionBox*)b);
}

FLOAT3D_* CModelCollisionBox_mcb_vCollisionBoxMin(CModelCollisionBox_* p)
{
  CModelCollisionBox& o = *((CModelCollisionBox*)p);
  return (FLOAT3D_*)(&(o.mcb_vCollisionBoxMin));
}

FLOAT3D_* CModelCollisionBox_mcb_vCollisionBoxMax(CModelCollisionBox_* p)
{
  CModelCollisionBox& o = *((CModelCollisionBox*)p);
  return (FLOAT3D_*)(&(o.mcb_vCollisionBoxMax));
}

ULONG* CModelCollisionBox_mcb_iCollisionBoxDimensionEquality(CModelCollisionBox_* p)
{
  CModelCollisionBox& o = *((CModelCollisionBox*)p);
  return &(o.mcb_iCollisionBoxDimensionEquality);
}

CTString_* CModelCollisionBox_mcb_strName(CModelCollisionBox_* p)
{
  CModelCollisionBox& o = *((CModelCollisionBox*)p);
  return (CTString_*)(&(o.mcb_strName));
}

static void sehCModelCollisionBox_Read_t(CModelCollisionBox_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CModelCollisionBox*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CModelCollisionBox_Read_t(CModelCollisionBox_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelCollisionBox_Read_t(p, s);
  STREAM_CATCH
}

static void sehCModelCollisionBox_ReadName_t(CModelCollisionBox_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CModelCollisionBox*)p)->ReadName_t((CTStream*)s);
  SECAPI_CATCH
}

void CModelCollisionBox_ReadName_t(CModelCollisionBox_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelCollisionBox_ReadName_t(p, s);
  STREAM_CATCH
}

static void sehCModelCollisionBox_Write_t(CModelCollisionBox_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CModelCollisionBox*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CModelCollisionBox_Write_t(CModelCollisionBox_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelCollisionBox_Write_t(p, s);
  STREAM_CATCH
}

CAttachedModelPosition_* CAttachedModelPosition_new()
{
  return (CAttachedModelPosition_*)(new CAttachedModelPosition());
}

CAttachedModelPosition_* CAttachedModelPosition_clone(const CAttachedModelPosition_* p)
{
  return (CAttachedModelPosition_*)(new CAttachedModelPosition(*((const CAttachedModelPosition*)p)));
}

void CAttachedModelPosition_delete(CAttachedModelPosition_* p)
{
  delete ((CAttachedModelPosition*)p);
}

void CAttachedModelPosition_copy(CAttachedModelPosition_* a, const CAttachedModelPosition_* b)
{
  *((CAttachedModelPosition*)a) = *((const CAttachedModelPosition*)b);
}

INDEX* CAttachedModelPosition_amp_iCenterVertex(CAttachedModelPosition_* p)
{
  CAttachedModelPosition& o = *((CAttachedModelPosition*)p);
  return &(o.amp_iCenterVertex);
}

INDEX* CAttachedModelPosition_amp_iFrontVertex(CAttachedModelPosition_* p)
{
  CAttachedModelPosition& o = *((CAttachedModelPosition*)p);
  return &(o.amp_iFrontVertex);
}

INDEX* CAttachedModelPosition_amp_iUpVertex(CAttachedModelPosition_* p)
{
  CAttachedModelPosition& o = *((CAttachedModelPosition*)p);
  return &(o.amp_iUpVertex);
}

CPlacement3D_* CAttachedModelPosition_amp_plRelativePlacement(CAttachedModelPosition_* p)
{
  CAttachedModelPosition& o = *((CAttachedModelPosition*)p);
  return (CPlacement3D_*)(&(o.amp_plRelativePlacement));
}

static void sehCAttachedModelPosition_Read_t(CAttachedModelPosition_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CAttachedModelPosition*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CAttachedModelPosition_Read_t(CAttachedModelPosition_* p, CTStream_* s)
{
  STREAM_TRY
  sehCAttachedModelPosition_Read_t(p, s);
  STREAM_CATCH
}

static void sehCAttachedModelPosition_Write_t(CAttachedModelPosition_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CAttachedModelPosition*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CAttachedModelPosition_Write_t(CAttachedModelPosition_* p, CTStream_* s)
{
  STREAM_TRY
  sehCAttachedModelPosition_Write_t(p, s);
  STREAM_CATCH
}

CMipInfo_* CMipInfo_new()
{
  return (CMipInfo_*)(new CMipInfo());
}

CMipInfo_* CMipInfo_clone(const CMipInfo_* p)
{
  return (CMipInfo_*)(new CMipInfo(*((const CMipInfo*)p)));
}

void CMipInfo_delete(CMipInfo_* p)
{
  delete ((CMipInfo*)p);
}

void CMipInfo_copy(CMipInfo_* a, const CMipInfo_* b)
{
  *((CMipInfo*)a) = *((const CMipInfo*)b);
}

INDEX* CMipInfo_mi_TrianglesCt(CMipInfo_* p)
{
  CMipInfo& o = *((CMipInfo*)p);
  return &(o.mi_TrianglesCt);
}

INDEX* CMipInfo_mi_PolygonsCt(CMipInfo_* p)
{
  CMipInfo& o = *((CMipInfo*)p);
  return &(o.mi_PolygonsCt);
}

INDEX* CMipInfo_mi_VerticesCt(CMipInfo_* p)
{
  CMipInfo& o = *((CMipInfo*)p);
  return &(o.mi_VerticesCt);
}

CModelInfo_* CModelInfo_new()
{
  return (CModelInfo_*)(new CModelInfo());
}

CModelInfo_* CModelInfo_clone(const CModelInfo_* p)
{
  return (CModelInfo_*)(new CModelInfo(*((const CModelInfo*)p)));
}

void CModelInfo_delete(CModelInfo_* p)
{
  delete ((CModelInfo*)p);
}

void CModelInfo_copy(CModelInfo_* a, const CModelInfo_* b)
{
  *((CModelInfo*)a) = *((const CModelInfo*)b);
}

INDEX* CModelInfo_mi_VerticesCt(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_VerticesCt);
}

INDEX* CModelInfo_mi_FramesCt(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_FramesCt);
}

INDEX* CModelInfo_mi_MipCt(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_MipCt);
}

CMipInfo_* CModelInfo_mi_MipInfos(CModelInfo_* p, INDEX i)
{
  CModelInfo& o = *((CModelInfo*)p);
  return (CMipInfo_*)(&(o.mi_MipInfos[i]));
}

CTFileName_* CModelInfo_mi_PatchFiles(CModelInfo_* p, INDEX i)
{
  CModelInfo& o = *((CModelInfo*)p);
  return (CTFileName_*)(&(o.mi_PatchFiles[i]));
}

MEX* CModelInfo_mi_Width(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_Width);
}

MEX* CModelInfo_mi_Height(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_Height);
}

BOOL* CModelInfo_mi_Flags(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_Flags);
}

SLONG* CModelInfo_mi_ShadowQuality(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return &(o.mi_ShadowQuality);
}

FLOAT3D_* CModelInfo_mi_Stretch(CModelInfo_* p)
{
  CModelInfo& o = *((CModelInfo*)p);
  return (FLOAT3D_*)(&(o.mi_Stretch));
}
