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

#include "RenderModel.h"

CModelRenderPrefs_* CModelRenderPrefs_new()
{
  return (CModelRenderPrefs_*)(new CModelRenderPrefs());
}

CModelRenderPrefs_* CModelRenderPrefs_clone(const CModelRenderPrefs_* p)
{
  return (CModelRenderPrefs_*)(new CModelRenderPrefs(*((const CModelRenderPrefs*)p)));
}

void CModelRenderPrefs_delete(CModelRenderPrefs_* p)
{
  delete ((CModelRenderPrefs*)p);
}

void CModelRenderPrefs_copy(CModelRenderPrefs_* a, const CModelRenderPrefs_* b)
{
  *((CModelRenderPrefs*)a) = *((const CModelRenderPrefs*)b);
}

void CModelRenderPrefs_SetRenderType(CModelRenderPrefs_* p, ULONG rtNew)
{
  ((CModelRenderPrefs*)p)->SetRenderType(rtNew);
}

void CModelRenderPrefs_SetTextureType(CModelRenderPrefs_* p, ULONG rtNew)
{
  ((CModelRenderPrefs*)p)->SetTextureType(rtNew);
}

void CModelRenderPrefs_SetShadingType(CModelRenderPrefs_* p, ULONG rtNew)
{
  ((CModelRenderPrefs*)p)->SetShadingType(rtNew);
}

void CModelRenderPrefs_SetShadowQuality(CModelRenderPrefs_* p, INDEX iNew)
{
  ((CModelRenderPrefs*)p)->SetShadowQuality(iNew);
}

void CModelRenderPrefs_DesreaseShadowQuality(CModelRenderPrefs_* p)
{
  ((CModelRenderPrefs*)p)->DesreaseShadowQuality();
}

void CModelRenderPrefs_IncreaseShadowQuality(CModelRenderPrefs_* p)
{
  ((CModelRenderPrefs*)p)->IncreaseShadowQuality();
}

void CModelRenderPrefs_SetWire(CModelRenderPrefs_* p, BOOL bWireOn)
{
  ((CModelRenderPrefs*)p)->SetWire(bWireOn);
}

void CModelRenderPrefs_SetHiddenLines(CModelRenderPrefs_* p, BOOL bHiddenLinesOn)
{
  ((CModelRenderPrefs*)p)->SetHiddenLines(bHiddenLinesOn);
}

BOOL CModelRenderPrefs_BBoxFrameVisible(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->BBoxFrameVisible();
}

BOOL CModelRenderPrefs_BBoxAllVisible(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->BBoxAllVisible();
}

BOOL CModelRenderPrefs_WireOn(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->WireOn();
}

BOOL CModelRenderPrefs_HiddenLines(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->HiddenLines();
}

void CModelRenderPrefs_SetInkColor(CModelRenderPrefs_* p, COLOR clrNew)
{
  ((CModelRenderPrefs*)p)->SetInkColor(clrNew);
}

COLOR CModelRenderPrefs_GetInkColor(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->GetInkColor();
}

void CModelRenderPrefs_SetPaperColor(CModelRenderPrefs_* p, COLOR clrNew)
{
  ((CModelRenderPrefs*)p)->SetPaperColor(clrNew);
}

COLOR CModelRenderPrefs_GetPaperColor(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->GetPaperColor();
}

void CModelRenderPrefs_BBoxFrameShow(CModelRenderPrefs_* p, BOOL bShow)
{
  ((CModelRenderPrefs*)p)->BBoxFrameShow(bShow);
}

void CModelRenderPrefs_BBoxAllShow(CModelRenderPrefs_* p, BOOL bShow)
{
  ((CModelRenderPrefs*)p)->BBoxAllShow(bShow);
}

ULONG CModelRenderPrefs_GetRenderType(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->GetRenderType();
}

INDEX CModelRenderPrefs_GetShadowQuality(CModelRenderPrefs_* p)
{
  return ((CModelRenderPrefs*)p)->GetShadowQuality();
}

static void sehCModelRenderPrefs_Read_t(CModelRenderPrefs_* p, CTStream_* s)
{
  SECAPI_TRY
  CModelRenderPrefs& d = *(CModelRenderPrefs*)p;
  CTStream& ss = *(CTStream*)s;
	BOOL rp_BBoxFrameVisible;
	BOOL rp_BBoxAllVisible;
  COLOR rp_InkColor;
  COLOR rp_PaperColor;
  ULONG rp_RenderType;
	INDEX rp_ShadowQuality;
  ss >> rp_BBoxFrameVisible;
  ss >> rp_BBoxAllVisible;
  ss >> rp_InkColor;
  ss >> rp_PaperColor;
  ss >> rp_RenderType;
  ss >> rp_ShadowQuality;
  d.BBoxFrameShow(rp_BBoxFrameVisible);
  d.BBoxAllShow(rp_BBoxAllVisible);
  d.SetInkColor(rp_InkColor);
  d.SetPaperColor(rp_PaperColor);
  d.SetRenderType(rp_RenderType);
  d.SetShadowQuality(rp_ShadowQuality);
  SECAPI_CATCH
}

void CModelRenderPrefs_Read_t(CModelRenderPrefs_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelRenderPrefs_Read_t(p, s);
  STREAM_CATCH
}

static void sehCModelRenderPrefs_Write_t(CModelRenderPrefs_* p, CTStream_* s)
{
  SECAPI_TRY
  CModelRenderPrefs& d = *(CModelRenderPrefs*)p;
  CTStream& ss = *(CTStream*)s;
  ss << d.BBoxFrameVisible();
  ss << d.BBoxAllVisible();
  ss << d.GetInkColor();
  ss << d.GetPaperColor();
  ss << d.GetRenderType();
  ss << d.GetShadowQuality();
  SECAPI_CATCH
}

void CModelRenderPrefs_Write_t(CModelRenderPrefs_* p, CTStream_* s)
{
  STREAM_TRY
  sehCModelRenderPrefs_Write_t(p, s);
  STREAM_CATCH
}

CModelRenderPrefs_* _mrpModelRenderPrefs_()
{
  return (CModelRenderPrefs_*)(&_mrpModelRenderPrefs);
}

CTextureObject_* _toSimpleModelShadow_()
{
  return (CTextureObject_*)(&_toSimpleModelShadow);
}

void BeginModelRenderingView_(CAnyProjection3D_* prProjection, CDrawPort_* pdp)
{
  STREAM_TRY
  BeginModelRenderingView(*((CAnyProjection3D*)prProjection), (CDrawPort*)pdp);
  STREAM_CATCH
}

void EndModelRenderingView_(BOOL bRestoreOrtho)
{
  STREAM_TRY
  EndModelRenderingView(bRestoreOrtho);
  STREAM_CATCH
}

void BeginModelRenderingMask_(CAnyProjection3D_* prProjection, UBYTE* pubMask, SLONG slMaskWidth, SLONG slMaskHeight)
{
  STREAM_TRY
  BeginModelRenderingMask(*((CAnyProjection3D*)prProjection), pubMask, slMaskWidth, slMaskHeight);
  STREAM_CATCH
}

void EndModelRenderingMask_()
{
  STREAM_TRY
  EndModelRenderingMask();
  STREAM_CATCH
}

CRenderModel_* CRenderModel_new()
{
  return (CRenderModel_*)(new CRenderModel());
}

void CRenderModel_delete(CRenderModel_* p)
{
  delete ((CRenderModel*)p);
}

void CRenderModel_copy(CRenderModel_* a, const CRenderModel_* b)
{
  *((CRenderModel*)a) = *((const CRenderModel*)b);
}

FLOAT3D_* CRenderModel_rm_vObjectPosition(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return (FLOAT3D_*)(&(r.rm_vObjectPosition));
}

FLOATmatrix3D_* CRenderModel_rm_mObjectRotation(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return (FLOATmatrix3D_*)(&(r.rm_mObjectRotation));
}

ULONG* CRenderModel_rm_ulFlags(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_ulFlags);
}

COLOR* CRenderModel_rm_colBlend(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_colBlend);
}

FLOAT* CRenderModel_rm_fDistanceFactor(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_fDistanceFactor);
}

FLOAT* CRenderModel_rm_fMipFactor(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_fMipFactor);
}

FLOAT3D_* CRenderModel_rm_vLightDirection(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return (FLOAT3D_*)(&(r.rm_vLightDirection));
}

COLOR* CRenderModel_rm_colLight(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_colLight);
}

COLOR* CRenderModel_rm_colAmbient(CRenderModel_* p)
{
  CRenderModel& r = *((CRenderModel*)p);
  return &(r.rm_colAmbient);
}

void CRenderModel_SetObjectPlacement_pl(CRenderModel_* p, const CPlacement3D_* pl)
{
  ((CRenderModel*)p)->SetObjectPlacement(*((const CPlacement3D*)pl));
}

void CRenderModel_SetObjectPlacement(CRenderModel_* p, const FLOAT3D_* v, const FLOATmatrix3D_* m)
{
  ((CRenderModel*)p)->SetObjectPlacement(*((const FLOAT3D*)v), *((const FLOATmatrix3D*)m));
}
