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

#ifndef SECAPI_GRAPHICS_VERTEX_H
#define SECAPI_GRAPHICS_VERTEX_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif
  
SECAPI GFXTexCoord_* GFXTexCoord_new();
SECAPI GFXTexCoord_* GFXTexCoord_clone(const GFXTexCoord_* p);
SECAPI void GFXTexCoord_delete(GFXTexCoord_* p);
SECAPI void GFXTexCoord_copy(GFXTexCoord_* a, const GFXTexCoord_* b);
SECAPI FLOAT* GFXTexCoord_u(GFXTexCoord_* p);
SECAPI FLOAT* GFXTexCoord_v(GFXTexCoord_* p);
SECAPI FLOAT* GFXTexCoord_s(GFXTexCoord_* p);
SECAPI FLOAT* GFXTexCoord_t(GFXTexCoord_* p);

SECAPI GFXTexCoord4_* GFXTexCoord4_new();
SECAPI GFXTexCoord4_* GFXTexCoord4_clone(const GFXTexCoord4_* p);
SECAPI void GFXTexCoord4_delete(GFXTexCoord4_* p);
SECAPI void GFXTexCoord4_copy(GFXTexCoord4_* a, const GFXTexCoord4_* b);
SECAPI FLOAT* GFXTexCoord4_s(GFXTexCoord4_* p);
SECAPI FLOAT* GFXTexCoord4_t(GFXTexCoord4_* p);
SECAPI FLOAT* GFXTexCoord4_r(GFXTexCoord4_* p);
SECAPI FLOAT* GFXTexCoord4_q(GFXTexCoord4_* p);

SECAPI GFXColor_* GFXColor_new();
SECAPI GFXColor_* GFXColor_new_col(COLOR col);
SECAPI GFXColor_* GFXColor_clone(const GFXColor_* p);
SECAPI void GFXColor_delete(GFXColor_* p);
SECAPI void GFXColor_copy(GFXColor_* a, const GFXColor_* b);
SECAPI void GFXColor_Set(GFXColor_* p, COLOR col);
SECAPI void GFXColor_MultiplyRGBA(GFXColor_* p, const GFXColor_* c1, const GFXColor_* c2);
SECAPI void GFXColor_MultiplyRGB(GFXColor_* p, const GFXColor_* c1, const GFXColor_* c2);
SECAPI void GFXColor_MultiplyRGBCopyA1(GFXColor_* p, const GFXColor_* c1, const GFXColor_* c2);
SECAPI void GFXColor_AttenuateRGB(GFXColor_* p, ULONG a);
SECAPI void GFXColor_AttenuateA(GFXColor_* p, ULONG a);
SECAPI UBYTE* GFXColor_r(GFXColor_* p);
SECAPI UBYTE* GFXColor_g(GFXColor_* p);
SECAPI UBYTE* GFXColor_b(GFXColor_* p);
SECAPI UBYTE* GFXColor_a(GFXColor_* p);
SECAPI ULONG* GFXColor_abgr(GFXColor_* p);

SECAPI GFXVertex3_* GFXVertex3_new();
SECAPI GFXVertex3_* GFXVertex3_clone(const GFXVertex3_* p);
SECAPI void GFXVertex3_delete(GFXVertex3_* p);
SECAPI void GFXVertex3_copy(GFXVertex3_* a, const GFXVertex3_* b);
SECAPI FLOAT* GFXVertex3_x(GFXVertex3_* p);
SECAPI FLOAT* GFXVertex3_y(GFXVertex3_* p);
SECAPI FLOAT* GFXVertex3_z(GFXVertex3_* p);

SECAPI GFXVertex4_* GFXVertex4_new();
SECAPI GFXVertex4_* GFXVertex4_clone(const GFXVertex4_* p);
SECAPI void GFXVertex4_delete(GFXVertex4_* p);
SECAPI void GFXVertex4_copy(GFXVertex4_* a, const GFXVertex4_* b);
SECAPI FLOAT* GFXVertex4_x(GFXVertex4_* p);
SECAPI FLOAT* GFXVertex4_y(GFXVertex4_* p);
SECAPI FLOAT* GFXVertex4_z(GFXVertex4_* p);
SECAPI GFXColor_* GFXVertex4_col(GFXVertex4_* p);
SECAPI SLONG* GFXVertex4_shade(GFXVertex4_* p);

SECAPI GFXNormal3_* GFXNormal3_new();
SECAPI GFXNormal3_* GFXNormal3_clone(const GFXNormal3_* p);
SECAPI void GFXNormal3_delete(GFXNormal3_* p);
SECAPI void GFXNormal3_copy(GFXNormal3_* a, const GFXNormal3_* b);
SECAPI FLOAT* GFXNormal3_nx(GFXNormal3_* p);
SECAPI FLOAT* GFXNormal3_ny(GFXNormal3_* p);
SECAPI FLOAT* GFXNormal3_nz(GFXNormal3_* p);

SECAPI GFXNormal4_* GFXNormal4_new();
SECAPI GFXNormal4_* GFXNormal4_clone(const GFXNormal4_* p);
SECAPI void GFXNormal4_delete(GFXNormal4_* p);
SECAPI void GFXNormal4_copy(GFXNormal4_* a, const GFXNormal4_* b);
SECAPI FLOAT* GFXNormal4_nx(GFXNormal4_* p);
SECAPI FLOAT* GFXNormal4_ny(GFXNormal4_* p);
SECAPI FLOAT* GFXNormal4_nz(GFXNormal4_* p);
SECAPI ULONG* GFXNormal4_ul(GFXNormal4_* p);

#ifdef __cplusplus
}
#endif

#endif
