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

#include "Stock_CSoundData.h"
#include <Engine/Templates/Stock_CSoundData.h>

static CSoundData_* seh_pSoundStock_Obtain_t_(const CTFileName_* f)
{
  CSoundData* res = NULL;
  SECAPI_TRY
  res = _pSoundStock->Obtain_t(*((const CTFileName*)f));
  SECAPI_CATCH
  return (CSoundData_*)res;
}

CSoundData_* _pSoundStock_Obtain_t_(const CTFileName_* f)
{
  CSoundData_* res = NULL;
  STREAM_TRY
  res = seh_pSoundStock_Obtain_t_(f);
  STREAM_CATCH
  return res;
}

static void seh_pSoundStock_Release(CSoundData_* p)
{
  SECAPI_TRY
  _pSoundStock->Release((CSoundData*)p);
  SECAPI_CATCH
}

void _pSoundStock_Release_(CSoundData_* p)
{
  STREAM_TRY
  seh_pSoundStock_Release(p);
  STREAM_CATCH
}

static void seh_pSoundStock_FreeUnused()
{
  SECAPI_TRY
  _pSoundStock->FreeUnused();
  SECAPI_CATCH
}

void _pSoundStock_FreeUnused_()
{
  STREAM_TRY
  seh_pSoundStock_FreeUnused();
  STREAM_CATCH
}
