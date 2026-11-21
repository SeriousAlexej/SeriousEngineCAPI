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

#include "ModelObject.h"

CModelObject_* CModelObject_new()
{
  return (CModelObject_*)(new CModelObject());
}

void CModelObject_delete(CModelObject_* p)
{
  delete ((CModelObject*)p);
}

CTextureObject_* CModelObject_mo_toTexture(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (CTextureObject_*)(&(m.mo_toTexture));
}

CTextureObject_* CModelObject_mo_toReflection(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (CTextureObject_*)(&(m.mo_toReflection));
}

CTextureObject_* CModelObject_mo_toSpecular(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (CTextureObject_*)(&(m.mo_toSpecular));
}

CTextureObject_* CModelObject_mo_toBump(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (CTextureObject_*)(&(m.mo_toBump));
}

FLOAT3D_* CModelObject_mo_Stretch(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (FLOAT3D_*)(&(m.mo_Stretch));
}

ULONG* CModelObject_mo_ColorMask(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return &(m.mo_ColorMask);
}

INDEX* CModelObject_mo_iLastRenderMipLevel(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return &(m.mo_iLastRenderMipLevel);
}

COLOR* CModelObject_mo_colBlendColor(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return &(m.mo_colBlendColor);
}

CListHead_* CModelObject_mo_lhAttachments(CModelObject_* p)
{
  CModelObject& m = *((CModelObject*)p);
  return (CListHead_*)(&(m.mo_lhAttachments));
}

void CModelObject_Copy(CModelObject_* p, CModelObject_* moOther)
{
  ((CModelObject*)p)->Copy(*((CModelObject*)moOther));
}

MEX CModelObject_GetWidth(CModelObject_* p)
{
  return ((CModelObject*)p)->GetWidth();
}

MEX CModelObject_GetHeight(CModelObject_* p)
{
  return ((CModelObject*)p)->GetHeight();
}

void CModelObject_GetModelInfo(CModelObject_* p, CModelInfo_* miInfo)
{
  ((CModelObject*)p)->GetModelInfo(*((CModelInfo*)miInfo));
}

BOOL CModelObject_IsModelVisible(CModelObject_* p, FLOAT fMipFactor)
{
  return ((CModelObject*)p)->IsModelVisible(fMipFactor);
}

INDEX CModelObject_GetMipModel(CModelObject_* p, FLOAT fMipFactor)
{
  return ((CModelObject*)p)->GetMipModel(fMipFactor);
}

BOOL CModelObject_HasShadow(CModelObject_* p, INDEX iModelMip)
{
  return ((CModelObject*)p)->HasShadow(iModelMip);
}

FLOATaabbox3D_* CModelObject_GetFrameBBox(CModelObject_* p, INDEX iFrameNo)
{
  FLOATaabbox3D res = ((CModelObject*)p)->GetFrameBBox(iFrameNo);
  return (FLOATaabbox3D_*)(new FLOATaabbox3D(res));
}

BOOL CModelObject_IsAutoMipModeling(CModelObject_* p)
{
  return ((CModelObject*)p)->IsAutoMipModeling();
}

void CModelObject_AutoMipModelingOn(CModelObject_* p)
{
  ((CModelObject*)p)->AutoMipModelingOn();
}

void CModelObject_AutoMipModelingOff(CModelObject_* p)
{
  ((CModelObject*)p)->AutoMipModelingOff();
}

INDEX CModelObject_GetManualMipLevel(CModelObject_* p)
{
  return ((CModelObject*)p)->GetManualMipLevel();
}

void CModelObject_SetManualMipLevel(CModelObject_* p, INDEX iNewMipLevel)
{
  ((CModelObject*)p)->SetManualMipLevel(iNewMipLevel);
}

void CModelObject_PrevManualMipLevel(CModelObject_* p)
{
  ((CModelObject*)p)->PrevManualMipLevel();
}

void CModelObject_NextManualMipLevel(CModelObject_* p)
{
  ((CModelObject*)p)->NextManualMipLevel();
}

void CModelObject_SetMipSwitchFactor(CModelObject_* p, INDEX iMipLevel, FLOAT fMipFactor)
{
  ((CModelObject*)p)->SetMipSwitchFactor(iMipLevel, fMipFactor);
}

void CModelObject_GetCurrentFrameBBox(CModelObject_* p, FLOATaabbox3D_* MaxBB)
{
  ((CModelObject*)p)->GetCurrentFrameBBox(*((FLOATaabbox3D*)MaxBB));
}

void CModelObject_GetAllFramesBBox(CModelObject_* p, FLOATaabbox3D_* MaxBB)
{
  ((CModelObject*)p)->GetAllFramesBBox(*((FLOATaabbox3D*)MaxBB));
}

FLOAT3D_* CModelObject_GetCollisionBoxMin(CModelObject_* p, INDEX iCollisionBox)
{
  FLOAT3D res = ((CModelObject*)p)->GetCollisionBoxMin(iCollisionBox);
  return (FLOAT3D_*)(new FLOAT3D(res));
}

FLOAT3D_* CModelObject_GetCollisionBoxMax(CModelObject_* p, INDEX iCollisionBox)
{
  FLOAT3D res = ((CModelObject*)p)->GetCollisionBoxMax(iCollisionBox);
  return (FLOAT3D_*)(new FLOAT3D(res));
}

BOOL CModelObject_HasAlpha(CModelObject_* p)
{
  return ((CModelObject*)p)->HasAlpha();
}

INDEX CModelObject_GetCollisionBoxDimensionEquality(CModelObject_* p, INDEX iCollisionBox)
{
  return ((CModelObject*)p)->GetCollisionBoxDimensionEquality(iCollisionBox);
}

INDEX CModelObject_SurfacesCt(CModelObject_* p, INDEX iMipModel)
{
  return ((CModelObject*)p)->SurfacesCt(iMipModel);
}

INDEX CModelObject_PolygonsInSurfaceCt(CModelObject_* p, INDEX iMipModel, INDEX iSurface)
{
  return ((CModelObject*)p)->PolygonsInSurfaceCt(iMipModel, iSurface);
}

COLOR CModelObject_GetSurfaceColor(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface)
{
  return ((CModelObject*)p)->GetSurfaceColor(iCurrentMip, iCurrentSurface);
}

void CModelObject_SetSurfaceColor(CModelObject_* p, INDEX iCurrentMip, INDEX iSurface, COLOR colNewColorAndAlpha)
{
  ((CModelObject*)p)->SetSurfaceColor(iCurrentMip, iSurface, colNewColorAndAlpha);
}

void CModelObject_GetSurfaceRenderFlags(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType_* sstShading, SurfaceTranslucencyType_* sttTranslucency, ULONG* ulRenderingFlags)
{
  ((CModelObject*)p)->GetSurfaceRenderFlags(iCurrentMip, iCurrentSurface, *((SurfaceShadingType*)sstShading), *((SurfaceTranslucencyType*)sttTranslucency), *ulRenderingFlags);
}

void CModelObject_SetSurfaceRenderFlags(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType_ sstShading, SurfaceTranslucencyType_ sttTranslucency, ULONG ulRenderingFlags)
{
  ((CModelObject*)p)->SetSurfaceRenderFlags(iCurrentMip, iCurrentSurface, (SurfaceShadingType)sstShading, (SurfaceTranslucencyType)sttTranslucency, ulRenderingFlags);
}

CTString_* CModelObject_GetColorName(CModelObject_* p, INDEX iColor)
{
  CTString res = ((CModelObject*)p)->GetColorName(iColor);
  return (CTString_*)(new CTString(res));
}

void CModelObject_SetColorName(CModelObject_* p, INDEX iColor, CTString_* strNewName)
{
  ((CModelObject*)p)->SetColorName(iColor, *((CTString*)strNewName));
}

ULONG CModelObject_GetPatchesMask(CModelObject_* p)
{
  return ((CModelObject*)p)->GetPatchesMask();
}

void CModelObject_SetPatchesMask(CModelObject_* p, ULONG new_patches_mask)
{
  ((CModelObject*)p)->SetPatchesMask(new_patches_mask);
}

void CModelObject_UnpackVertex_rm(CModelObject_* p, CRenderModel_* rm, const INDEX iVertex, FLOAT3D_* vVertex)
{
  ((CModelObject*)p)->UnpackVertex(*((CRenderModel*)rm), iVertex, *((FLOAT3D*)vVertex));
}

BOOL CModelObject_CreateAttachment(CModelObject_* p, CRenderModel_* rmMain, CAttachmentModelObject_* amo)
{
  return ((CModelObject*)p)->CreateAttachment(*((CRenderModel*)rmMain), *((CAttachmentModelObject*)amo));
}

void CModelObject_ResetAttachmentModelPosition(CModelObject_* p, INDEX iAttachedPosition)
{
  ((CModelObject*)p)->ResetAttachmentModelPosition(iAttachedPosition);
}

CAttachmentModelObject_* CModelObject_GetAttachmentModel(CModelObject_* p, INDEX iAttachedPosition)
{
  return (CAttachmentModelObject_*)(((CModelObject*)p)->GetAttachmentModel(iAttachedPosition));
}

CAttachmentModelObject_* CModelObject_AddAttachmentModel(CModelObject_* p, INDEX iAttachedPosition)
{
  return (CAttachmentModelObject_*)(((CModelObject*)p)->AddAttachmentModel(iAttachedPosition));
}

void CModelObject_RemoveAttachmentModel(CModelObject_* p, INDEX iAttachedPosition)
{
  ((CModelObject*)p)->RemoveAttachmentModel(iAttachedPosition);
}

void CModelObject_RemoveAllAttachmentModels(CModelObject_* p)
{
  ((CModelObject*)p)->RemoveAllAttachmentModels();
}

void CModelObject_StretchModel(CModelObject_* p, const FLOAT3D_* vStretch)
{
  ((CModelObject*)p)->StretchModel(*((const FLOAT3D*)vStretch));
}

void CModelObject_StretchModelRelative(CModelObject_* p, const FLOAT3D_* vStretch)
{
  ((CModelObject*)p)->StretchModelRelative(*((const FLOAT3D*)vStretch));
}

void CModelObject_StretchSingleModel(CModelObject_* p, const FLOAT3D_* vStretch)
{
  ((CModelObject*)p)->StretchSingleModel(*((const FLOAT3D*)vStretch));
}

void CModelObject_SetupModelRendering(CModelObject_* p, CRenderModel_* rm)
{
  STREAM_TRY
  ((CModelObject*)p)->SetupModelRendering(*((CRenderModel*)rm));
  STREAM_CATCH
}

void CModelObject_RenderModel(CModelObject_* p, CRenderModel_* rm)
{
  STREAM_TRY
  ((CModelObject*)p)->RenderModel(*((CRenderModel*)rm));
  STREAM_CATCH
}

void CModelObject_AddSimpleShadow(CModelObject_* p, CRenderModel_* rm, const FLOAT fIntensity,  const FLOATplane3D_* plShadowPlane)
{
  STREAM_TRY
  ((CModelObject*)p)->AddSimpleShadow(*((CRenderModel*)rm), fIntensity, *((const FLOATplane3D*)plShadowPlane));
  STREAM_CATCH
}

void CModelObject_RenderShadow(CModelObject_* p, CRenderModel_* rm, const CPlacement3D_* plLight, const FLOAT fFallOff, const FLOAT fHotSpot, const FLOAT fIntensity, const FLOATplane3D_* plShadowPlane)
{
  STREAM_TRY
  ((CModelObject*)p)->RenderShadow(*((CRenderModel*)rm), *((const CPlacement3D*)plLight), fFallOff, fHotSpot, fIntensity, *((const FLOATplane3D*)plShadowPlane));
  STREAM_CATCH
}

void CModelObject_GetModelVertices(CModelObject_* p, CStaticStackArray_FLOAT3D_* avVertices, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition, FLOAT fNormalOffset, FLOAT fMipFactor)
{
  ((CModelObject*)p)->GetModelVertices(*((CStaticStackArray<FLOAT3D>*)avVertices), *((FLOATmatrix3D*)mRotation), *((FLOAT3D*)vPosition), fNormalOffset, fMipFactor);
}

void CModelObject_GetAttachmentMatrices(CModelObject_* p, CAttachmentModelObject_* pamo, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition)
{
  ((CModelObject*)p)->GetAttachmentMatrices((CAttachmentModelObject*)pamo, *((FLOATmatrix3D*)mRotation), *((FLOAT3D*)vPosition));
}

void CModelObject_GetAttachmentTransformations(CModelObject_* p, INDEX iAttachment, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition, BOOL bDummyAttachment)
{
  ((CModelObject*)p)->GetAttachmentTransformations(iAttachment, *((FLOATmatrix3D*)mRotation), *((FLOAT3D*)vPosition), bDummyAttachment);
}

void CModelObject_ProjectFrameVertices(CModelObject_* p, CProjection3D_* pProjection, INDEX iMipModel)
{
  ((CModelObject*)p)->ProjectFrameVertices((CProjection3D*)pProjection, iMipModel);
}

void CModelObject_ColorizeRegion(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D_* box, INDEX iChoosedColor, BOOL bOnColorMode)
{
  ((CModelObject*)p)->ColorizeRegion((CDrawPort*)pDP, (CProjection3D*)projection, *((PIXaabbox2D*)box), iChoosedColor, bOnColorMode);
}

void CModelObject_ColorizePolygon(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iChoosedColor, BOOL bOnColorMode)
{
  ((CModelObject*)p)->ColorizePolygon((CDrawPort*)pDP, (CProjection3D*)projection, x1, y1, iChoosedColor, bOnColorMode); 
}

void CModelObject_ApplySurfaceToPolygon(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iSurface, COLOR colSurfaceColor)
{
  ((CModelObject*)p)->ApplySurfaceToPolygon((CDrawPort*)pDP, (CProjection3D*)projection, x1, y1, iSurface, colSurfaceColor);
}

void CModelObject_ApplySurfaceToPolygonsInRegion(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D_* box, INDEX iSurface, COLOR colSurfaceColor)
{
  ((CModelObject*)p)->ApplySurfaceToPolygonsInRegion((CDrawPort*)pDP, (CProjection3D*)projection, *((PIXaabbox2D*)box), iSurface, colSurfaceColor);
}

void CModelObject_UnpackVertex(CModelObject_* p, INDEX iFrame, INDEX iVertex, FLOAT3D_* vVertex)
{
  ((CModelObject*)p)->UnpackVertex(iFrame, iVertex, *((FLOAT3D*)vVertex));
}

CPlacement3D_* CModelObject_GetAttachmentPlacement(CModelObject_* p, CAttachmentModelObject_* amo)
{
  CPlacement3D res = ((CModelObject*)p)->GetAttachmentPlacement(*((CAttachmentModelObject*)amo));
  return (CPlacement3D_*)(new CPlacement3D(res));
}

ModelPolygon_* CModelObject_PolygonHit(CModelObject_* p, CPlacement3D_* plRay, CPlacement3D_* plObject, INDEX iCurrentMip, FLOAT* fHitDistance)
{
  return (ModelPolygon_*)(((CModelObject*)p)->PolygonHit(*((CPlacement3D*)plRay), *((CPlacement3D*)plObject), iCurrentMip, *fHitDistance));
}

ModelPolygon_* CModelObject_PolygonHitModelData(CModelObject_* p, CModelData_* pMD, CPlacement3D_* plRay, CPlacement3D_* plObject, INDEX iCurrentMip, FLOAT* fHitDistance)
{
  return (ModelPolygon_*)(((CModelObject*)p)->PolygonHitModelData((CModelData*)pMD, *((CPlacement3D*)plRay), *((CPlacement3D*)plObject), iCurrentMip, *fHitDistance));
}

void CModelObject_PickPolyColor(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX* iPickedColorNo, BOOL bOnColorMode)
{
  ((CModelObject*)p)->PickPolyColor((CDrawPort*)pDP, (CProjection3D*)projection, x1, y1, *iPickedColorNo, bOnColorMode);
}

INDEX CModelObject_PickPolySurface(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1)
{
  return ((CModelObject*)p)->PickPolySurface((CDrawPort*)pDP, (CProjection3D*)projection, x1, y1);
}

INDEX CModelObject_PickVertexIndex(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, FLOAT3D_* vClosestVertex)
{
  return ((CModelObject*)p)->PickVertexIndex((CDrawPort*)pDP, (CProjection3D*)projection, x1, y1, *((FLOAT3D*)vClosestVertex));
}

void CModelObject_ShowPatch(CModelObject_* p, INDEX iMaskBit)
{
  ((CModelObject*)p)->ShowPatch(iMaskBit);
}

void CModelObject_HidePatch(CModelObject_* p, INDEX iMaskBit)
{
  ((CModelObject*)p)->HidePatch(iMaskBit);
}

static void sehCModelObject_Read_t(CModelObject_* p, CTStream_* istrFile)
{
  SECAPI_TRY
  ((CModelObject*)p)->Read_t((CTStream*)istrFile);
  SECAPI_CATCH
}

void CModelObject_Read_t(CModelObject_* p, CTStream_* istrFile)
{
  STREAM_TRY
  sehCModelObject_Read_t(p, istrFile);
  STREAM_CATCH
}

static void sehCModelObject_Write_t(CModelObject_* p, CTStream_* ostrFile)
{
  SECAPI_TRY
  ((CModelObject*)p)->Write_t((CTStream*)ostrFile);
  SECAPI_CATCH
}

void CModelObject_Write_t(CModelObject_* p, CTStream_* ostrFile)
{
  STREAM_TRY
  sehCModelObject_Write_t(p, ostrFile);
  STREAM_CATCH
}

void CModelObject_SetTextureData(CModelObject_* p, CTextureData_* ptdNewMainTexture)
{
  STREAM_TRY
  ((CModelObject*)p)->SetTextureData((CTextureData*)ptdNewMainTexture);
  STREAM_CATCH
}

CTFileName_* CModelObject_GetName(CModelObject_* p)
{
  CTFileName res = ((CModelObject*)p)->GetName();
  return (CTFileName_*)(new CTFileName(res));
}

void CModelObject_AutoSetTextures(CModelObject_* p)
{
  STREAM_TRY
  ((CModelObject*)p)->AutoSetTextures();
  STREAM_CATCH
}

void CModelObject_AutoSetAttachments(CModelObject_* p)
{
  STREAM_TRY
  ((CModelObject*)p)->AutoSetAttachments();
  STREAM_CATCH
}

static void SetData_t(CModelObject_* p, const CTFileName_* fnmModel)
{
  SECAPI_TRY
  ((CModelObject*)p)->SetData_t(*((const CTFileName*)fnmModel));
  SECAPI_CATCH
}

void CModelObject_SetData_t(CModelObject_* p, const CTFileName_* fnmModel)
{
  STREAM_TRY
  SetData_t(p, fnmModel);
  STREAM_CATCH
}

void CModelObject_SetData(CModelObject_* p, CModelData_* pmd)
{
  STREAM_TRY
  ((CModelObject*)p)->SetData((CModelData*)pmd);
  STREAM_CATCH
}

CModelData_* CModelObject_GetData(CModelObject_* p)
{
  return (CModelData_*)(((CModelObject*)p)->GetData());
}

void CModelObject_Synchronize(CModelObject_* p, CModelObject_* moOther)
{
  ((CModelObject*)p)->Synchronize(*((CModelObject*)moOther));
}

SLONG CModelObject_GetUsedMemory(CModelObject_* p)
{
  return ((CModelObject*)p)->GetUsedMemory();
}

CListNode_* CAttachmentModelObject_amo_lnInMain(CAttachmentModelObject_* p)
{
  CAttachmentModelObject& m = *((CAttachmentModelObject*)p);
  return (CListNode_*)(&(m.amo_lnInMain));
}

INDEX* CAttachmentModelObject_amo_iAttachedPosition(CAttachmentModelObject_* p)
{
  CAttachmentModelObject& m = *((CAttachmentModelObject*)p);
  return &(m.amo_iAttachedPosition);
}

CPlacement3D_* CAttachmentModelObject_amo_plRelative(CAttachmentModelObject_* p)
{
  CAttachmentModelObject& m = *((CAttachmentModelObject*)p);
  return (CPlacement3D_*)(&(m.amo_plRelative));
}

CModelObject_* CAttachmentModelObject_amo_moModelObject(CAttachmentModelObject_* p)
{
  CAttachmentModelObject& m = *((CAttachmentModelObject*)p);
  return (CModelObject_*)(&(m.amo_moModelObject));
}

CRenderModel_** CAttachmentModelObject_amo_prm(CAttachmentModelObject_* p)
{
  CAttachmentModelObject& m = *((CAttachmentModelObject*)p);
  return (CRenderModel_**)(&(m.amo_prm));
}

CAttachmentModelObject_* CAttachmentModelObject_from_amo_lnInMain(CListNode_* p)
{
  CListNode& node = *((CListNode*)p);
  CAttachmentModelObject* res = ((CAttachmentModelObject*)(((UBYTE*)(&node)) - offsetof(CAttachmentModelObject, amo_lnInMain)));
  return (CAttachmentModelObject_*)res;
}
