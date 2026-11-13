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

#include "ErrorReporting.h"

// The SDK functions interpret their first argument as a printf-style format, so
// the consumer text is escaped ('%' -> '%%') and passed with no varargs.
static char* EscapeFormat(const char* strText)
{
  INDEX ctLen = (INDEX)strlen(strText);
  char* strEscaped = new char[2 * ctLen + 1];
  char* pOut = strEscaped;
  for (const char* p = strText; *p != 0; p++)
  {
    if (*p == '%')
      *pOut++ = '%';
    *pOut++ = *p;
  }
  *pOut++ = 0;
  return strEscaped;
}

void ThrowF_t_(char* error)
{
  char* strEscaped = EscapeFormat(error);
  SECAPI_TRY
  ThrowF_t(strEscaped);
  SECAPI_CATCH
  delete[] strEscaped;
}

void FatalError_(const char* error)
{
  char* strEscaped = EscapeFormat(error);
  FatalError(strEscaped);
  delete[] strEscaped; // unreached - FatalError terminates the process
}

void WarningMessage_(const char* error)
{
  char* strEscaped = EscapeFormat(error);
  WarningMessage(strEscaped);
  delete[] strEscaped;
}

void InfoMessage_(const char* error)
{
  char* strEscaped = EscapeFormat(error);
  InfoMessage(strEscaped);
  delete[] strEscaped;
}

CTString_* GetWindowsError_(DWORD error)
{
  CTString res = GetWindowsError(error);
  return (CTString_*)(new CTString(res));
}
