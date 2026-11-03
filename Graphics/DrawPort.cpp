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

#include "DrawPort.h"

CDrawPort_* CDrawPort_new(CRaster_* p)
{
  return (CDrawPort_*)(new CDrawPort((CRaster*)p));
}

CDrawPort_* CDrawPort_new_cloned(CDrawPort_* p, DOUBLE minI, DOUBLE minJ, DOUBLE sizeI, DOUBLE sizeJ)
{
  return (CDrawPort_*)(new CDrawPort((CDrawPort*)p, minI, minJ, sizeI, sizeJ));
}

CDrawPort_* CDrawPort_new_cloned_box(CDrawPort_* p, const PIXaabbox2D_* b)
{
  return (CDrawPort_*)(new CDrawPort((CDrawPort*)p, *((const PIXaabbox2D*)b)));
}

CDrawPort_* CDrawPort_new_cloned_dualhead(CDrawPort_* p, BOOL left)
{
  return (CDrawPort_*)(new CDrawPort((CDrawPort*)p, left));
}

void CDrawPort_delete(CDrawPort_* p)
{
  delete ((CDrawPort*)p);
}

CRaster_* CDrawPort_dp_Raster(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return (CRaster_*)(d.dp_Raster);
}

CFontData_* CDrawPort_dp_FontData(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return (CFontData_*)(d.dp_FontData);
}

PIX* CDrawPort_dp_Width(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_Width);
}

PIX* CDrawPort_dp_Height(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_Height);
}

PIX* CDrawPort_dp_MinI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MinI);
}

PIX* CDrawPort_dp_MinJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MinJ);
}

PIX* CDrawPort_dp_MaxI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MaxI);
}

PIX* CDrawPort_dp_MaxJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MaxJ);
}

PIX* CDrawPort_dp_ScissorMinI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ScissorMinI);
}

PIX* CDrawPort_dp_ScissorMinJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ScissorMinJ);
}

PIX* CDrawPort_dp_ScissorMaxI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ScissorMaxI);
}

PIX* CDrawPort_dp_ScissorMaxJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ScissorMaxJ);
}

PIX* CDrawPort_dp_pixTextCharSpacing(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_pixTextCharSpacing);
}

PIX* CDrawPort_dp_pixTextLineSpacing(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_pixTextLineSpacing);
}

FLOAT* CDrawPort_dp_fTextScaling(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_fTextScaling);
}

FLOAT* CDrawPort_dp_fTextAspect(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_fTextAspect);
}

INDEX* CDrawPort_dp_iTextMode(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_iTextMode);
}

FLOAT* CDrawPort_dp_fWideAdjustment(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_fWideAdjustment);
}

BOOL* CDrawPort_dp_bRenderingOverlay(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_bRenderingOverlay);
}

DOUBLE* CDrawPort_dp_SizeIOverRasterSizeI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_SizeIOverRasterSizeI);
}

DOUBLE* CDrawPort_dp_SizeJOverRasterSizeJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_SizeJOverRasterSizeJ);
}

DOUBLE* CDrawPort_dp_MinIOverRasterSizeI(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MinIOverRasterSizeI);
}

DOUBLE* CDrawPort_dp_MinJOverRasterSizeJ(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_MinJOverRasterSizeJ);
}

ULONG* CDrawPort_dp_ulBlendingRA(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ulBlendingRA);
}

ULONG* CDrawPort_dp_ulBlendingGA(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ulBlendingGA);
}

ULONG* CDrawPort_dp_ulBlendingBA(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ulBlendingBA);
}

ULONG* CDrawPort_dp_ulBlendingA(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return &(d.dp_ulBlendingA);
}

void CDrawPort_SetOrtho(const CDrawPort_* p)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.SetOrtho();
}

void CDrawPort_SetProjection(const CDrawPort_* p, CAnyProjection3D_* apr)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.SetProjection(*((CAnyProjection3D*)apr));
}

void CDrawPort_MakeWideScreen(CDrawPort_* a, CDrawPort_* b)
{
  CDrawPort& d = *((CDrawPort*)a);
  d.MakeWideScreen((CDrawPort*)b);
}

BOOL CDrawPort_IsDualHead(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return d.IsDualHead();
}

BOOL CDrawPort_IsWideScreen(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return d.IsWideScreen();
}

ULONG CDrawPort_GetID(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  return d.GetID();
}

void CDrawPort_SetFont(CDrawPort_* p, CFontData_* pfd)
{
  STREAM_TRY
  CDrawPort& d = *((CDrawPort*)p);
  d.SetFont((CFontData*)pfd);
  STREAM_CATCH
}

ULONG CDrawPort_GetTextWidth(const CDrawPort_* p, const CTString_* strText)
{
  ULONG res = 0;
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  res = d.GetTextWidth(*((const CTString*)strText));
  STREAM_CATCH
  return res;
}

void CDrawPort_PutText(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutText(*((const CTString*)strText), pixX0, pixY0, colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTextC(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTextC(*((const CTString*)strText), pixX0, pixY0, colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTextCXY(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTextCXY(*((const CTString*)strText), pixX0, pixY0, colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTextR(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTextR(*((const CTString*)strText), pixX0, pixY0, colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTexture_b(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTexture((CTextureObject*)pTO, *((const PIXaabbox2D*)boxScreen), colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTexture_cols(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTexture((CTextureObject*)pTO, *((const PIXaabbox2D*)boxScreen), colUL, colUR, colDL, colDR);
  STREAM_CATCH
}

void CDrawPort_PutTexture_box_b(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const MEXaabbox2D_* boxTexture, const COLOR colBlend)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTexture((CTextureObject*)pTO, *((const PIXaabbox2D*)boxScreen), *((const MEXaabbox2D*)boxTexture), colBlend);
  STREAM_CATCH
}

void CDrawPort_PutTexture_box_cols(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const MEXaabbox2D_* boxTexture, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.PutTexture((CTextureObject*)pTO, *((const PIXaabbox2D*)boxScreen), *((const MEXaabbox2D*)boxTexture), colUL, colUR, colDL, colDR);
  STREAM_CATCH
}

void CDrawPort_InitTexture(const CDrawPort_* p, CTextureObject_* pTO, const BOOL bClamp)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.InitTexture((CTextureObject*)pTO, bClamp);
  STREAM_CATCH
}

void CDrawPort_AddTexture_1(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const COLOR col)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.AddTexture(fI0, fJ0, fI1, fJ1, col);
  STREAM_CATCH
}
 
void CDrawPort_AddTexture_2(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fU0, const FLOAT fV0, const FLOAT fU1, const FLOAT fV1, const COLOR col)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.AddTexture(fI0, fJ0, fI1, fJ1, fU0, fV0, fU1, fV1, col);
  STREAM_CATCH
}

void CDrawPort_AddTexture_3(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fU0, const FLOAT fV0, const COLOR col0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fU1, const FLOAT fV1, const COLOR col1, const FLOAT fI2, const FLOAT fJ2, const FLOAT fU2, const FLOAT fV2, const COLOR col2, const FLOAT fI3, const FLOAT fJ3, const FLOAT fU3, const FLOAT fV3, const COLOR col3)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.AddTexture(fI0, fJ0, fU0, fV0, col0, fI1, fJ1, fU1, fV1, col1, fI2, fJ2, fU2, fV2, col2, fI3, fJ3, fU3, fV3, col3);
  STREAM_CATCH
}

void CDrawPort_AddTriangle(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fI2, const FLOAT fJ2, const COLOR col)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.AddTriangle(fI0, fJ0, fI1, fJ1, fI2, fJ2, col);
  STREAM_CATCH
}

void CDrawPort_FlushRenderingQueue(const CDrawPort_* p)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.FlushRenderingQueue();
  STREAM_CATCH
}

BOOL CDrawPort_Lock(CDrawPort_* p)
{
  BOOL res = FALSE;
  STREAM_TRY
  CDrawPort& d = *((CDrawPort*)p);
  res = d.Lock();
  STREAM_CATCH
  return res;
}

void CDrawPort_Unlock(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  d.Unlock();
}

void CDrawPort_DrawPoint(const CDrawPort_* p, PIX pixI, PIX pixJ, COLOR col, PIX pixRadius)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.DrawPoint(pixI, pixJ, col, pixRadius);
}

void CDrawPort_DrawPoint3D(const CDrawPort_* p, FLOAT3D_* v, COLOR col, FLOAT fRadius)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.DrawPoint3D(*((FLOAT3D*)v), col, fRadius);
}

void CDrawPort_DrawLine(const CDrawPort_* p, PIX pixI0, PIX pixJ0, PIX pixI1, PIX pixJ1, COLOR col, ULONG typ)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.DrawLine(pixI0, pixJ0, pixI1, pixJ1, col, typ);
}

void CDrawPort_DrawLine3D(const CDrawPort_* p, FLOAT3D_* v0, FLOAT3D_* v1, COLOR col)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.DrawLine3D(*((FLOAT3D*)v0), *((FLOAT3D*)v1), col);
}

void CDrawPort_DrawBorder(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col, ULONG typ)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.DrawBorder(pixI, pixJ, pixWidth, pixHeight, col, typ);
}

void CDrawPort_Fill_1(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.Fill(pixI, pixJ, pixWidth, pixHeight, col);
}

void CDrawPort_Fill_2(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR colUL, COLOR colUR, COLOR colDL, COLOR colDR)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.Fill(pixI, pixJ, pixWidth, pixHeight, colUL, colUR, colDL, colDR);
}

void CDrawPort_FillZBuffer_1(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, FLOAT zval)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.FillZBuffer(pixI, pixJ, pixWidth, pixHeight, zval);
}

void CDrawPort_Fill_3(const CDrawPort_* p, COLOR col)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.Fill(col);
}

void CDrawPort_FillZBuffer_2(const CDrawPort_* p, FLOAT zval)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.FillZBuffer(zval);
}

void CDrawPort_GrabScreen(const CDrawPort_* p, CImageInfo_* iiGrabbedImage, INDEX iGrabZBuffer)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  d.GrabScreen(*((CImageInfo*)iiGrabbedImage), iGrabZBuffer);
}

BOOL CDrawPort_IsPointVisible(const CDrawPort_* p, PIX pixI, PIX pixJ, FLOAT fOoK, INDEX iID, INDEX iMirrorLevel)
{
  const CDrawPort& d = *((const CDrawPort*)p);
  return d.IsPointVisible(pixI, pixJ, fOoK, iID, iMirrorLevel);
}

void CDrawPort_RenderLensFlare(const CDrawPort_* p, CTextureObject_* pto, FLOAT fI, FLOAT fJ, FLOAT fSizeI, FLOAT fSizeJ, ANGLE aRotation, COLOR colLight)
{
  STREAM_TRY
  const CDrawPort& d = *((const CDrawPort*)p);
  d.RenderLensFlare((CTextureObject*)pto, fI, fJ, fSizeI, fSizeJ, aRotation, colLight);
  STREAM_CATCH
}

void CDrawPort_BlendScreen(CDrawPort_* p)
{
  CDrawPort& d = *((CDrawPort*)p);
  d.BlendScreen();
}

void Particle_PrepareSystem_(CDrawPort_* pdpDrawPort, CAnyProjection3D_* prProjection)
{
  STREAM_TRY
  Particle_PrepareSystem((CDrawPort*)pdpDrawPort, *((CAnyProjection3D*)prProjection));
  STREAM_CATCH
}

void Particle_PrepareEntity_(FLOAT fMipFactor, BOOL bHasFog, BOOL bHasHaze, CEntity_* penViewer)
{
  STREAM_TRY
  Particle_PrepareEntity(fMipFactor, bHasFog, bHasHaze, (CEntity*)penViewer);
  STREAM_CATCH
}

void Particle_EndSystem_(BOOL bRestoreOrtho)
{
  Particle_EndSystem(bRestoreOrtho);
}

FLOAT Particle_GetMipFactor_()
{
  return Particle_GetMipFactor();
}

INDEX Particle_GetDrawPortID_()
{
  return Particle_GetDrawPortID();
}

CEntity_* Particle_GetViewer_()
{
  return (CEntity_*)Particle_GetViewer();
}

CProjection3D_* Particle_GetProjection_()
{
  static const int enginedllBaseAddress = reinterpret_cast<int>(&CEntity::HandleSentEvents) - 0xFEC80;
  static CProjection3D** ppProjection = reinterpret_cast<CProjection3D**>(enginedllBaseAddress + 0x1F64C8);
  return (CProjection3D_*)(*ppProjection);
}

void Particle_PrepareTexture_(CTextureObject_* pto, ParticleBlendType_ pbt)
{
  STREAM_TRY
  Particle_PrepareTexture((CTextureObject*)pto, (ParticleBlendType)pbt);
  STREAM_CATCH
}

void Particle_SetTexturePart_(MEX mexWidth, MEX mexHeight, INDEX iCol, INDEX iRow)
{
  Particle_SetTexturePart(mexWidth, mexHeight, iCol, iRow);
}

void Particle_RenderSquare_(const FLOAT3D_* vPos, FLOAT fSize, ANGLE aRotation, COLOR col, FLOAT fYRatio)
{
  Particle_RenderSquare(*((const FLOAT3D*)vPos), fSize, aRotation, col, fYRatio);
}

void Particle_RenderQuad3D_(const FLOAT3D_* vPos0, const FLOAT3D_* vPos1, const FLOAT3D_* vPos2, const FLOAT3D_* vPos3, COLOR col)
{
  Particle_RenderQuad3D(*((const FLOAT3D*)vPos0), *((const FLOAT3D*)vPos1), *((const FLOAT3D*)vPos2), *((const FLOAT3D*)vPos3), col);
}

void Particle_RenderLine_(const FLOAT3D_* vPos0, const FLOAT3D_* vPos1, FLOAT fWidth, COLOR col)
{
  Particle_RenderLine(*((const FLOAT3D*)vPos0), *((const FLOAT3D*)vPos1), fWidth, col);
}

void Particle_Sort_(BOOL b3D)
{
  Particle_Sort(b3D);
}

void Particle_Flush_()
{
  Particle_Flush();
}

