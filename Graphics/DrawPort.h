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

#ifndef SECAPI_GRAPHICS_DRAW_PORT_H
#define SECAPI_GRAPHICS_DRAW_PORT_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

SECAPI CDrawPort_* CDrawPort_new(CRaster_* p);
SECAPI CDrawPort_* CDrawPort_new_cloned(CDrawPort_* p, DOUBLE minI, DOUBLE minJ, DOUBLE sizeI, DOUBLE sizeJ);
SECAPI CDrawPort_* CDrawPort_new_cloned_box(CDrawPort_* p, const PIXaabbox2D_* b);
SECAPI CDrawPort_* CDrawPort_new_cloned_dualhead(CDrawPort_* p, BOOL left);
SECAPI void CDrawPort_delete(CDrawPort_* p);
SECAPI CRaster_* CDrawPort_dp_Raster(CDrawPort_* p);
SECAPI CFontData_* CDrawPort_dp_FontData(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_Width(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_Height(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_MinI(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_MinJ(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_MaxI(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_MaxJ(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_ScissorMinI(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_ScissorMinJ(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_ScissorMaxI(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_ScissorMaxJ(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_pixTextCharSpacing(CDrawPort_* p);
SECAPI PIX* CDrawPort_dp_pixTextLineSpacing(CDrawPort_* p);
SECAPI FLOAT* CDrawPort_dp_fTextScaling(CDrawPort_* p);
SECAPI FLOAT* CDrawPort_dp_fTextAspect(CDrawPort_* p);
SECAPI INDEX* CDrawPort_dp_iTextMode(CDrawPort_* p);
SECAPI FLOAT* CDrawPort_dp_fWideAdjustment(CDrawPort_* p);
SECAPI BOOL* CDrawPort_dp_bRenderingOverlay(CDrawPort_* p);
SECAPI DOUBLE* CDrawPort_dp_SizeIOverRasterSizeI(CDrawPort_* p);
SECAPI DOUBLE* CDrawPort_dp_SizeJOverRasterSizeJ(CDrawPort_* p);
SECAPI DOUBLE* CDrawPort_dp_MinIOverRasterSizeI(CDrawPort_* p);
SECAPI DOUBLE* CDrawPort_dp_MinJOverRasterSizeJ(CDrawPort_* p);
SECAPI ULONG* CDrawPort_dp_ulBlendingRA(CDrawPort_* p);
SECAPI ULONG* CDrawPort_dp_ulBlendingGA(CDrawPort_* p);
SECAPI ULONG* CDrawPort_dp_ulBlendingBA(CDrawPort_* p);
SECAPI ULONG* CDrawPort_dp_ulBlendingA(CDrawPort_* p);
SECAPI void CDrawPort_SetOrtho(const CDrawPort_* p);
SECAPI void CDrawPort_SetProjection(const CDrawPort_* p, CAnyProjection3D_* apr);
SECAPI void CDrawPort_MakeWideScreen(CDrawPort_* a, CDrawPort_* b);
SECAPI BOOL CDrawPort_IsDualHead(CDrawPort_* p);
SECAPI BOOL CDrawPort_IsWideScreen(CDrawPort_* p);
SECAPI ULONG CDrawPort_GetID(CDrawPort_* p);
SECAPI void CDrawPort_SetFont(CDrawPort_* p, CFontData_* pfd);
SECAPI ULONG CDrawPort_GetTextWidth(const CDrawPort_* p, const CTString_* strText);
SECAPI void CDrawPort_PutText(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend);
SECAPI void CDrawPort_PutTextC(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend);
SECAPI void CDrawPort_PutTextCXY(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend);
SECAPI void CDrawPort_PutTextR(const CDrawPort_* p, const CTString_* strText, PIX pixX0, PIX pixY0, const COLOR colBlend);
SECAPI void CDrawPort_PutTexture_b(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const COLOR colBlend);
SECAPI void CDrawPort_PutTexture_cols(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR);
SECAPI void CDrawPort_PutTexture_box_b(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const MEXaabbox2D_* boxTexture, const COLOR colBlend);
SECAPI void CDrawPort_PutTexture_box_cols(const CDrawPort_* p, CTextureObject_* pTO, const PIXaabbox2D_* boxScreen, const MEXaabbox2D_* boxTexture, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR);
SECAPI void CDrawPort_InitTexture(const CDrawPort_* p, CTextureObject_* pTO, const BOOL bClamp);
SECAPI void CDrawPort_AddTexture_1(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const COLOR col); 
SECAPI void CDrawPort_AddTexture_2(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fU0, const FLOAT fV0, const FLOAT fU1, const FLOAT fV1, const COLOR col);
SECAPI void CDrawPort_AddTexture_3(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fU0, const FLOAT fV0, const COLOR col0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fU1, const FLOAT fV1, const COLOR col1, const FLOAT fI2, const FLOAT fJ2, const FLOAT fU2, const FLOAT fV2, const COLOR col2, const FLOAT fI3, const FLOAT fJ3, const FLOAT fU3, const FLOAT fV3, const COLOR col3);
SECAPI void CDrawPort_AddTriangle(const CDrawPort_* p, const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fI2, const FLOAT fJ2, const COLOR col);
SECAPI void CDrawPort_FlushRenderingQueue(const CDrawPort_* p);
SECAPI BOOL CDrawPort_Lock(CDrawPort_* p);
SECAPI void CDrawPort_Unlock(CDrawPort_* p);
SECAPI void CDrawPort_DrawPoint(const CDrawPort_* p, PIX pixI, PIX pixJ, COLOR col, PIX pixRadius);
SECAPI void CDrawPort_DrawPoint3D(const CDrawPort_* p, FLOAT3D_* v, COLOR col, FLOAT fRadius);
SECAPI void CDrawPort_DrawLine(const CDrawPort_* p, PIX pixI0, PIX pixJ0, PIX pixI1, PIX pixJ1, COLOR col, ULONG typ);
SECAPI void CDrawPort_DrawLine3D(const CDrawPort_* p, FLOAT3D_* v0, FLOAT3D_* v1, COLOR col);
SECAPI void CDrawPort_DrawBorder(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col, ULONG typ);
SECAPI void CDrawPort_Fill_1(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col);
SECAPI void CDrawPort_Fill_2(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR colUL, COLOR colUR, COLOR colDL, COLOR colDR);
SECAPI void CDrawPort_FillZBuffer_1(const CDrawPort_* p, PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, FLOAT zval);
SECAPI void CDrawPort_Fill_3(const CDrawPort_* p, COLOR col);
SECAPI void CDrawPort_FillZBuffer_2(const CDrawPort_* p, FLOAT zval);
SECAPI void CDrawPort_GrabScreen(const CDrawPort_* p, CImageInfo_* iiGrabbedImage, INDEX iGrabZBuffer);
SECAPI BOOL CDrawPort_IsPointVisible(const CDrawPort_* p, PIX pixI, PIX pixJ, FLOAT fOoK, INDEX iID, INDEX iMirrorLevel);
SECAPI void CDrawPort_RenderLensFlare(const CDrawPort_* p, CTextureObject_* pto, FLOAT fI, FLOAT fJ, FLOAT fSizeI, FLOAT fSizeJ, ANGLE aRotation, COLOR colLight);
SECAPI void CDrawPort_BlendScreen(CDrawPort_* p);

#define PBT_BLEND_ 0
#define PBT_ADD_ 1
#define PBT_MULTIPLY_ 2
#define PBT_ADDALPHA_ 3
#define PBT_FLEX_ 4
#define PBT_TRANSPARENT_ 5

SECAPI void Particle_PrepareSystem_(CDrawPort_* pdpDrawPort, CAnyProjection3D_* prProjection);
SECAPI void Particle_PrepareEntity_(FLOAT fMipFactor, BOOL bHasFog, BOOL bHasHaze, CEntity_* penViewer);
SECAPI void Particle_EndSystem_(BOOL bRestoreOrtho);
SECAPI FLOAT Particle_GetMipFactor_();
SECAPI INDEX Particle_GetDrawPortID_();
SECAPI CEntity_* Particle_GetViewer_();
SECAPI CProjection3D_* Particle_GetProjection_();
SECAPI void Particle_PrepareTexture_(CTextureObject_* pto, ParticleBlendType_ pbt);
SECAPI void Particle_SetTexturePart_(MEX mexWidth, MEX mexHeight, INDEX iCol, INDEX iRow);
SECAPI void Particle_RenderSquare_(const FLOAT3D_* vPos, FLOAT fSize, ANGLE aRotation, COLOR col, FLOAT fYRatio);
SECAPI void Particle_RenderQuad3D_(const FLOAT3D_* vPos0, const FLOAT3D_* vPos1, const FLOAT3D_* vPos2, const FLOAT3D_* vPos3, COLOR col);
SECAPI void Particle_RenderLine_(const FLOAT3D_* vPos0, const FLOAT3D_* vPos1, FLOAT fWidth, COLOR col);
SECAPI void Particle_Sort_(BOOL b3D);
SECAPI void Particle_Flush_();

#ifdef __cplusplus
}
#endif

#endif
