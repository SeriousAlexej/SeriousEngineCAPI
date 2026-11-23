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

#include "Stock_CModelData.h"
#include <Engine/Templates/Stock_CModelData.h>

static CModelData_* seh_pModelStock_Obtain_t_(const CTFileName_* f)
{
  CModelData* res = NULL;
  SECAPI_TRY
  res = _pModelStock->Obtain_t(*((const CTFileName*)f));
  SECAPI_CATCH
  return (CModelData_*)res;
}

CModelData_* _pModelStock_Obtain_t_(const CTFileName_* f)
{
  CModelData_* res = NULL;
  STREAM_TRY
  res = seh_pModelStock_Obtain_t_(f);
  STREAM_CATCH
  return res;
}

static void seh_pModelStock_Release(CModelData_* p)
{
  SECAPI_TRY
  _pModelStock->Release((CModelData*)p);
  SECAPI_CATCH
}

void _pModelStock_Release(CModelData_* p)
{
  STREAM_TRY
  seh_pModelStock_Release(p);
  STREAM_CATCH
}

static void seh_pModelStock_FreeUnused()
{
  SECAPI_TRY
  _pModelStock->FreeUnused();
  SECAPI_CATCH
}

void _pModelStock_FreeUnused()
{
  STREAM_TRY
  seh_pModelStock_FreeUnused();
  STREAM_CATCH
}
