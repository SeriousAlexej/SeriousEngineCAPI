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

#include "Stock_CEntityClass.h"
#include <Engine/Templates/Stock_CEntityClass.h>

static CEntityClass_* seh_pEntityClassStock_Obtain_t_(const CTFileName_* f)
{
  CEntityClass* res = NULL;
  SECAPI_TRY
  res = _pEntityClassStock->Obtain_t(*((const CTFileName*)f));
  SECAPI_CATCH
  return (CEntityClass_*)res;
}

CEntityClass_* _pEntityClassStock_Obtain_t_(const CTFileName_* f)
{
  CEntityClass_* res = NULL;
  STREAM_TRY
  res = seh_pEntityClassStock_Obtain_t_(f);
  STREAM_CATCH
  return res;
}

static void seh_pEntityClassStock_Release_(CEntityClass_* p)
{
  SECAPI_TRY
  _pEntityClassStock->Release((CEntityClass*)p);
  SECAPI_CATCH
}

void _pEntityClassStock_Release_(CEntityClass_* p)
{
  STREAM_TRY
  seh_pEntityClassStock_Release_(p);
  STREAM_CATCH
}

static void seh_pEntityClassStock_FreeUnused()
{
  SECAPI_TRY
  _pEntityClassStock->FreeUnused();
  SECAPI_CATCH
}

void _pEntityClassStock_FreeUnused()
{
  STREAM_TRY
  seh_pEntityClassStock_FreeUnused();
  STREAM_CATCH
}
