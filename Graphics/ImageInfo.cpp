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

#include "ImageInfo.h"

CImageInfo_* CImageInfo_new()
{
  return (CImageInfo_*)(new CImageInfo());
}

void CImageInfo_delete(CImageInfo_* p)
{
  delete ((CImageInfo*)p);
}

PIX* CImageInfo_ii_Width(CImageInfo_* p)
{
  CImageInfo& i = *((CImageInfo*)p);
  return &(i.ii_Width);
}

PIX* CImageInfo_ii_Height(CImageInfo_* p)
{
  CImageInfo& i = *((CImageInfo*)p);
  return &(i.ii_Height);
}

SLONG* CImageInfo_ii_BitsPerPixel(CImageInfo_* p)
{
  CImageInfo& i = *((CImageInfo*)p);
  return &(i.ii_BitsPerPixel);
}

UBYTE** CImageInfo_ii_Picture(CImageInfo_* p)
{
  CImageInfo& i = *((CImageInfo*)p);
  return &(i.ii_Picture);
}

static void sehCImageInfo_Read_t(CImageInfo_* p, CTStream_* s)
{
  SECAPI_TRY
  ((CImageInfo*)p)->Read_t((CTStream*)s);
  SECAPI_CATCH
}

void CImageInfo_Read_t(CImageInfo_* p, CTStream_* s)
{
  STREAM_TRY
  sehCImageInfo_Read_t(p, s);
  STREAM_CATCH
}

static void sehCImageInfo_Write_t(const CImageInfo_* p, CTStream_* s)
{
  SECAPI_TRY
  ((const CImageInfo*)p)->Write_t((CTStream*)s);
  SECAPI_CATCH
}

void CImageInfo_Write_t(const CImageInfo_* p, CTStream_* s)
{
  STREAM_TRY
  sehCImageInfo_Write_t(p, s);
  STREAM_CATCH
}

void CImageInfo_Attach(CImageInfo_* p, UBYTE* pic, PIX wid, PIX hei, SLONG bpp)
{
  ((CImageInfo*)p)->Attach(pic, wid, hei, bpp);
}

void CImageInfo_Detach(CImageInfo_* p)
{
  ((CImageInfo*)p)->Detach();
}

void CImageInfo_Clear(CImageInfo_* p)
{
  ((CImageInfo*)p)->Clear();
}

void CImageInfo_ExpandEdges(CImageInfo_* p, INDEX passes)
{
  ((CImageInfo*)p)->ExpandEdges(passes);
}

static INDEX sehCImageInfo_GetGfxFileInfo_t(CImageInfo_* p, const CTFileName_* f)
{
  INDEX res = 0;
  SECAPI_TRY
  res = ((CImageInfo*)p)->GetGfxFileInfo_t(*((const CTFileName*)f));
  SECAPI_CATCH
  return res;
}

INDEX CImageInfo_GetGfxFileInfo_t(CImageInfo_* p, const CTFileName_* f)
{
  INDEX res;
  STREAM_TRY
  res = sehCImageInfo_GetGfxFileInfo_t(p, f);
  STREAM_CATCH
  return res;
}

static void sehCImageInfo_LoadAnyGfxFormat_t(CImageInfo_* p, const CTFileName_* f)
{
  SECAPI_TRY
  ((CImageInfo*)p)->LoadAnyGfxFormat_t(*((const CTFileName*)f));
  SECAPI_CATCH
}

void CImageInfo_LoadAnyGfxFormat_t(CImageInfo_* p, const CTFileName_* f)
{
  STREAM_TRY
  sehCImageInfo_LoadAnyGfxFormat_t(p, f);
  STREAM_CATCH
}

static void sehCImageInfo_SaveTGA_t(const CImageInfo_* p, const CTFileName_* f)
{
  SECAPI_TRY
  ((const CImageInfo*)p)->SaveTGA_t(*((const CTFileName*)f));
  SECAPI_CATCH
}

void CImageInfo_SaveTGA_t(const CImageInfo_* p, const CTFileName_* f)
{
  STREAM_TRY
  sehCImageInfo_SaveTGA_t(p, f);
  STREAM_CATCH
}
