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

#ifndef SECAPI_BASE_ONE_ANIM_H
#define SECAPI_BASE_ONE_ANIM_H

class COneAnim
{
public:
  inline COneAnim()
  {
    oa_FrameIndices = NULL;
  }
  inline ~COneAnim()
  {
    ASSERT(oa_FrameIndices != NULL);
    FreeMemory( oa_FrameIndices);
    oa_FrameIndices = NULL;
  }
  inline COneAnim& operator=(const COneAnim& oaAnim)
  {
    ASSERT( oaAnim.oa_NumberOfFrames > 0);
    strcpy(oa_Name, oaAnim.oa_Name);
    oa_SecsPerFrame = oaAnim.oa_SecsPerFrame;
    oa_NumberOfFrames = oaAnim.oa_NumberOfFrames;
    if( oa_FrameIndices != NULL)
    {
      FreeMemory(oa_FrameIndices);
    }
    oa_FrameIndices = (INDEX *) AllocMemory( sizeof(INDEX) * oa_NumberOfFrames);
    for( INDEX iFrame = 0; iFrame<oa_NumberOfFrames; iFrame++)
    {
      oa_FrameIndices[ iFrame] = oaAnim.oa_FrameIndices[ iFrame];
    }
    return *this;
  }
private:
  COneAnim(const COneAnim&);
public:
  NAME oa_Name;
  TIME oa_SecsPerFrame;
  INDEX oa_NumberOfFrames;
  INDEX* oa_FrameIndices;
};

#endif
