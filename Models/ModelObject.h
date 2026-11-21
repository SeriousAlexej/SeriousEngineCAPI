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

#ifndef SECAPI_MODELS_MODEL_OBJECT_H
#define SECAPI_MODELS_MODEL_OBJECT_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI CModelObject_* CModelObject_new();
SECAPI void CModelObject_delete(CModelObject_* p);
SECAPI CTextureObject_* CModelObject_mo_toTexture(CModelObject_* p);
SECAPI CTextureObject_* CModelObject_mo_toReflection(CModelObject_* p);
SECAPI CTextureObject_* CModelObject_mo_toSpecular(CModelObject_* p);
SECAPI CTextureObject_* CModelObject_mo_toBump(CModelObject_* p);
SECAPI FLOAT3D_* CModelObject_mo_Stretch(CModelObject_* p);
SECAPI ULONG* CModelObject_mo_ColorMask(CModelObject_* p);
SECAPI INDEX* CModelObject_mo_iLastRenderMipLevel(CModelObject_* p);
SECAPI COLOR* CModelObject_mo_colBlendColor(CModelObject_* p);
SECAPI CListHead_* CModelObject_mo_lhAttachments(CModelObject_* p);
SECAPI void CModelObject_Copy(CModelObject_* p, CModelObject_* moOther);
SECAPI MEX CModelObject_GetWidth(CModelObject_* p);
SECAPI MEX CModelObject_GetHeight(CModelObject_* p);
SECAPI void CModelObject_GetModelInfo(CModelObject_* p, CModelInfo_* miInfo);
SECAPI BOOL CModelObject_IsModelVisible(CModelObject_* p, FLOAT fMipFactor);
SECAPI INDEX CModelObject_GetMipModel(CModelObject_* p, FLOAT fMipFactor);
SECAPI BOOL CModelObject_HasShadow(CModelObject_* p, INDEX iModelMip);
SECAPI FLOATaabbox3D_* CModelObject_GetFrameBBox(CModelObject_* p, INDEX iFrameNo);
SECAPI BOOL CModelObject_IsAutoMipModeling(CModelObject_* p);
SECAPI void CModelObject_AutoMipModelingOn(CModelObject_* p);
SECAPI void CModelObject_AutoMipModelingOff(CModelObject_* p);
SECAPI INDEX CModelObject_GetManualMipLevel(CModelObject_* p);
SECAPI void CModelObject_SetManualMipLevel(CModelObject_* p, INDEX iNewMipLevel);
SECAPI void CModelObject_PrevManualMipLevel(CModelObject_* p);
SECAPI void CModelObject_NextManualMipLevel(CModelObject_* p);
SECAPI void CModelObject_SetMipSwitchFactor(CModelObject_* p, INDEX iMipLevel, FLOAT fMipFactor);
SECAPI void CModelObject_GetCurrentFrameBBox(CModelObject_* p, FLOATaabbox3D_* MaxBB);
SECAPI void CModelObject_GetAllFramesBBox(CModelObject_* p, FLOATaabbox3D_* MaxBB);
SECAPI FLOAT3D_* CModelObject_GetCollisionBoxMin(CModelObject_* p, INDEX iCollisionBox);
SECAPI FLOAT3D_* CModelObject_GetCollisionBoxMax(CModelObject_* p, INDEX iCollisionBox);
SECAPI BOOL CModelObject_HasAlpha(CModelObject_* p);
SECAPI INDEX CModelObject_GetCollisionBoxDimensionEquality(CModelObject_* p, INDEX iCollisionBox);
SECAPI INDEX CModelObject_SurfacesCt(CModelObject_* p, INDEX iMipModel);
SECAPI INDEX CModelObject_PolygonsInSurfaceCt(CModelObject_* p, INDEX iMipModel, INDEX iSurface);
SECAPI COLOR CModelObject_GetSurfaceColor(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface);
SECAPI void CModelObject_SetSurfaceColor(CModelObject_* p, INDEX iCurrentMip, INDEX iSurface, COLOR colNewColorAndAlpha);
SECAPI void CModelObject_GetSurfaceRenderFlags(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType_* sstShading, SurfaceTranslucencyType_* sttTranslucency, ULONG* ulRenderingFlags);
SECAPI void CModelObject_SetSurfaceRenderFlags(CModelObject_* p, INDEX iCurrentMip, INDEX iCurrentSurface, SurfaceShadingType_ sstShading, SurfaceTranslucencyType_ sttTranslucency, ULONG ulRenderingFlags);
SECAPI CTString_* CModelObject_GetColorName(CModelObject_* p, INDEX iColor);
SECAPI void CModelObject_SetColorName(CModelObject_* p, INDEX iColor, CTString_* strNewName);
SECAPI ULONG CModelObject_GetPatchesMask(CModelObject_* p);
SECAPI void CModelObject_SetPatchesMask(CModelObject_* p, ULONG new_patches_mask);
SECAPI void CModelObject_UnpackVertex_rm(CModelObject_* p, CRenderModel_* rm, const INDEX iVertex, FLOAT3D_* vVertex);
SECAPI BOOL CModelObject_CreateAttachment(CModelObject_* p, CRenderModel_* rmMain, CAttachmentModelObject_* amo);
SECAPI void CModelObject_ResetAttachmentModelPosition(CModelObject_* p, INDEX iAttachedPosition);
SECAPI CAttachmentModelObject_* CModelObject_GetAttachmentModel(CModelObject_* p, INDEX iAttachedPosition);
SECAPI CAttachmentModelObject_* CModelObject_AddAttachmentModel(CModelObject_* p, INDEX iAttachedPosition);
SECAPI void CModelObject_RemoveAttachmentModel(CModelObject_* p, INDEX iAttachedPosition);
SECAPI void CModelObject_RemoveAllAttachmentModels(CModelObject_* p);
SECAPI void CModelObject_StretchModel(CModelObject_* p, const FLOAT3D_* vStretch);
SECAPI void CModelObject_StretchModelRelative(CModelObject_* p, const FLOAT3D_* vStretch);
SECAPI void CModelObject_StretchSingleModel(CModelObject_* p, const FLOAT3D_* vStretch);
SECAPI void CModelObject_SetupModelRendering(CModelObject_* p, CRenderModel_* rm);
SECAPI void CModelObject_RenderModel(CModelObject_* p, CRenderModel_* rm);
SECAPI void CModelObject_AddSimpleShadow(CModelObject_* p, CRenderModel_* rm, const FLOAT fIntensity,  const FLOATplane3D_* plShadowPlane);
SECAPI void CModelObject_RenderShadow(CModelObject_* p, CRenderModel_* rm, const CPlacement3D_* plLight, const FLOAT fFallOff, const FLOAT fHotSpot, const FLOAT fIntensity, const FLOATplane3D_* plShadowPlane);
SECAPI void CModelObject_GetModelVertices(CModelObject_* p, CStaticStackArray_FLOAT3D_* avVertices, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition, FLOAT fNormalOffset, FLOAT fMipFactor);
SECAPI void CModelObject_GetAttachmentMatrices(CModelObject_* p, CAttachmentModelObject_* pamo, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition);
SECAPI void CModelObject_GetAttachmentTransformations(CModelObject_* p, INDEX iAttachment, FLOATmatrix3D_* mRotation, FLOAT3D_* vPosition, BOOL bDummyAttachment);
SECAPI void CModelObject_ProjectFrameVertices(CModelObject_* p, CProjection3D_* pProjection, INDEX iMipModel);
SECAPI void CModelObject_ColorizeRegion(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D_* box, INDEX iChoosedColor, BOOL bOnColorMode);
SECAPI void CModelObject_ColorizePolygon(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iChoosedColor, BOOL bOnColorMode);
SECAPI void CModelObject_ApplySurfaceToPolygon(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX iSurface, COLOR colSurfaceColor);
SECAPI void CModelObject_ApplySurfaceToPolygonsInRegion(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIXaabbox2D_* box, INDEX iSurface, COLOR colSurfaceColor);
SECAPI void CModelObject_UnpackVertex(CModelObject_* p, INDEX iFrame, INDEX iVertex, FLOAT3D_* vVertex);
SECAPI CPlacement3D_* CModelObject_GetAttachmentPlacement(CModelObject_* p, CAttachmentModelObject_* amo);
SECAPI ModelPolygon_* CModelObject_PolygonHit(CModelObject_* p, CPlacement3D_* plRay, CPlacement3D_* plObject, INDEX iCurrentMip, FLOAT* fHitDistance);
SECAPI ModelPolygon_* CModelObject_PolygonHitModelData(CModelObject_* p, CModelData_* pMD, CPlacement3D_* plRay, CPlacement3D_* plObject, INDEX iCurrentMip, FLOAT* fHitDistance);
SECAPI void CModelObject_PickPolyColor(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, INDEX* iPickedColorNo, BOOL bOnColorMode);
SECAPI INDEX CModelObject_PickPolySurface(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1);
SECAPI INDEX CModelObject_PickVertexIndex(CModelObject_* p, CDrawPort_* pDP, CProjection3D_* projection, PIX x1, PIX y1, FLOAT3D_* vClosestVertex);
SECAPI void CModelObject_ShowPatch(CModelObject_* p, INDEX iMaskBit);
SECAPI void CModelObject_HidePatch(CModelObject_* p, INDEX iMaskBit);
SECAPI void CModelObject_Read_t(CModelObject_* p, CTStream_* istrFile);
SECAPI void CModelObject_Write_t(CModelObject_* p, CTStream_* ostrFile);
SECAPI void CModelObject_SetTextureData(CModelObject_* p, CTextureData_* ptdNewMainTexture);
SECAPI CTFileName_* CModelObject_GetName(CModelObject_* p);
SECAPI void CModelObject_AutoSetTextures(CModelObject_* p);
SECAPI void CModelObject_AutoSetAttachments(CModelObject_* p);
SECAPI void CModelObject_SetData_t(CModelObject_* p, const CTFileName_* fnmModel);
SECAPI void CModelObject_SetData(CModelObject_* p, CModelData_* pmd);
SECAPI CModelData_* CModelObject_GetData(CModelObject_* p);
SECAPI void CModelObject_Synchronize(CModelObject_* p, CModelObject_* moOther);
SECAPI SLONG CModelObject_GetUsedMemory(CModelObject_* p);

SECAPI CListNode_* CAttachmentModelObject_amo_lnInMain(CAttachmentModelObject_* p);
SECAPI INDEX* CAttachmentModelObject_amo_iAttachedPosition(CAttachmentModelObject_* p);
SECAPI CPlacement3D_* CAttachmentModelObject_amo_plRelative(CAttachmentModelObject_* p);
SECAPI CModelObject_* CAttachmentModelObject_amo_moModelObject(CAttachmentModelObject_* p);
SECAPI CRenderModel_** CAttachmentModelObject_amo_prm(CAttachmentModelObject_* p);

SECAPI CAttachmentModelObject_* CAttachmentModelObject_from_amo_lnInMain(CListNode_* p);

#ifdef __cplusplus
}
#endif

#endif
