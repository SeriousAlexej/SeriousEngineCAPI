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

#include "Types.h"

static char g_exceptionBuffer[257];
static bool g_hasException = false;

BOOL HasException()
{
  return g_hasException ? TRUE : FALSE;
}

char* GrabException()
{
  g_hasException = false;
  return g_exceptionBuffer;
}

void SetException(char* s)
{
  const size_t len = min(256, strlen(s));
  memcpy(g_exceptionBuffer, s, len);
  g_exceptionBuffer[len] = '\0';
  g_hasException = true;
}
