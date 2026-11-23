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

#include "Stock_CAnimData.h"
#include <Engine/Templates/Stock_CAnimData.h>

static CAnimData_* seh_pAnimStock_Obtain_t_(const CTFileName_* f)
{
  CAnimData* res = NULL;
  SECAPI_TRY
  res = _pAnimStock->Obtain_t(*((const CTFileName*)f));
  SECAPI_CATCH
  return (CAnimData_*)res;
}

CAnimData_* _pAnimStock_Obtain_t_(const CTFileName_* f)
{
  CAnimData_* res = NULL;
  STREAM_TRY
  res = seh_pAnimStock_Obtain_t_(f);
  STREAM_CATCH
  return res;
}

static void seh_pAnimStock_Release(CAnimData_* p)
{
  SECAPI_TRY
  _pAnimStock->Release((CAnimData*)p);
  SECAPI_CATCH
}

void _pAnimStock_Release(CAnimData_* p)
{
  STREAM_TRY
  seh_pAnimStock_Release(p);
  STREAM_CATCH
}

static void seh_pAnimStock_FreeUnused()
{
  SECAPI_TRY
  _pAnimStock->FreeUnused();
  SECAPI_CATCH
}

void _pAnimStock_FreeUnused()
{
  STREAM_TRY
  seh_pAnimStock_FreeUnused();
  STREAM_CATCH
}
