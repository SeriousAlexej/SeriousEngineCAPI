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

#ifndef SECAPI_MODELS_RENDER_MODEL_H
#define SECAPI_MODELS_RENDER_MODEL_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI CModelRenderPrefs_* CModelRenderPrefs_new();
SECAPI CModelRenderPrefs_* CModelRenderPrefs_clone(const CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_delete(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_copy(CModelRenderPrefs_* a, const CModelRenderPrefs_* b);
SECAPI void CModelRenderPrefs_SetRenderType(CModelRenderPrefs_* p, ULONG rtNew);
SECAPI void CModelRenderPrefs_SetTextureType(CModelRenderPrefs_* p, ULONG rtNew);
SECAPI void CModelRenderPrefs_SetShadingType(CModelRenderPrefs_* p, ULONG rtNew);
SECAPI void CModelRenderPrefs_SetShadowQuality(CModelRenderPrefs_* p, INDEX iNew);
SECAPI void CModelRenderPrefs_DesreaseShadowQuality(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_IncreaseShadowQuality(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_SetWire(CModelRenderPrefs_* p, BOOL bWireOn);
SECAPI void CModelRenderPrefs_SetHiddenLines(CModelRenderPrefs_* p, BOOL bHiddenLinesOn);
SECAPI BOOL CModelRenderPrefs_BBoxFrameVisible(CModelRenderPrefs_* p);
SECAPI BOOL CModelRenderPrefs_BBoxAllVisible(CModelRenderPrefs_* p);
SECAPI BOOL CModelRenderPrefs_WireOn(CModelRenderPrefs_* p);
SECAPI BOOL CModelRenderPrefs_HiddenLines(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_SetInkColor(CModelRenderPrefs_* p, COLOR clrNew);
SECAPI COLOR CModelRenderPrefs_GetInkColor(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_SetPaperColor(CModelRenderPrefs_* p, COLOR clrNew);
SECAPI COLOR CModelRenderPrefs_GetPaperColor(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_BBoxFrameShow(CModelRenderPrefs_* p, BOOL bShow);
SECAPI void CModelRenderPrefs_BBoxAllShow(CModelRenderPrefs_* p, BOOL bShow);
SECAPI ULONG CModelRenderPrefs_GetRenderType(CModelRenderPrefs_* p);
SECAPI INDEX CModelRenderPrefs_GetShadowQuality(CModelRenderPrefs_* p);
SECAPI void CModelRenderPrefs_Read_t(CModelRenderPrefs_* p, CTStream_* s);
SECAPI void CModelRenderPrefs_Write_t(CModelRenderPrefs_* p, CTStream_* s);

SECAPI CModelRenderPrefs_* _mrpModelRenderPrefs_();
SECAPI CTextureObject_* _toSimpleModelShadow_();

SECAPI void BeginModelRenderingView_(CAnyProjection3D_* prProjection, CDrawPort_* pdp);
SECAPI void EndModelRenderingView_(BOOL bRestoreOrtho);
SECAPI void BeginModelRenderingMask_(CAnyProjection3D_* prProjection, UBYTE* pubMask, SLONG slMaskWidth, SLONG slMaskHeight);
SECAPI void EndModelRenderingMask_();

#ifndef SERIOUSENGINECAPI_EXPORTS
#define RMF_ATTACHMENT          (1UL<<0)    // set for attachment render models
#define RMF_FOG                 (1UL<<1)    // render in fog
#define RMF_HAZE                (1UL<<2)    // render in haze
#define RMF_SPECTATOR           (1UL<<3)    // model will not be rendered but shadows might
#define RMF_INVERTED            (1UL<<4)    // stretch is inverted
#define RMF_BBOXSET             (1UL<<5)    // bounding box has been calculated
#define RMF_INSIDE              (1UL<<6)    // doesn't need clipping to frustum
#define RMF_INMIRROR            (1UL<<7)    // doesn't need clipping to mirror/warp plane
#define RMF_WEAPON              (1UL<<8)    // TEMP: weapon model is rendering so don't use ATI's Truform!
#endif

SECAPI CRenderModel_* CRenderModel_new();
SECAPI void CRenderModel_delete(CRenderModel_* p);
SECAPI void CRenderModel_copy(CRenderModel_* a, const CRenderModel_* b);
SECAPI FLOAT3D_* CRenderModel_rm_vObjectPosition(CRenderModel_* p);
SECAPI FLOATmatrix3D_* CRenderModel_rm_mObjectRotation(CRenderModel_* p);
SECAPI ULONG* CRenderModel_rm_ulFlags(CRenderModel_* p);
SECAPI COLOR* CRenderModel_rm_colBlend(CRenderModel_* p);
SECAPI FLOAT* CRenderModel_rm_fDistanceFactor(CRenderModel_* p);
SECAPI FLOAT* CRenderModel_rm_fMipFactor(CRenderModel_* p);
SECAPI FLOAT3D_* CRenderModel_rm_vLightDirection(CRenderModel_* p);
SECAPI COLOR* CRenderModel_rm_colLight(CRenderModel_* p);
SECAPI COLOR* CRenderModel_rm_colAmbient(CRenderModel_* p);
SECAPI void CRenderModel_SetObjectPlacement_pl(CRenderModel_* p, const CPlacement3D_* pl);
SECAPI void CRenderModel_SetObjectPlacement(CRenderModel_* p, const FLOAT3D_* v, const FLOATmatrix3D_* m);

#ifdef __cplusplus
}
#endif

#endif
