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

#include "Anim.h"
#include "OneAnim.h"

CAnimInfo_* CAnimInfo_new()
{
  return (CAnimInfo_*)(new CAnimInfo());
}

CAnimInfo_* CAnimInfo_clone(const CAnimInfo_* p)
{
  return (CAnimInfo_*)(new CAnimInfo(*((const CAnimInfo*)p)));
}

void CAnimInfo_delete(CAnimInfo_* p)
{
  delete ((CAnimInfo*)p);
}

void CAnimInfo_copy(CAnimInfo_* a, const CAnimInfo_* b)
{
  *((CAnimInfo*)a) = *((const CAnimInfo*)b);
}

char* CAnimInfo_ai_AnimName(CAnimInfo_* p)
{
  CAnimInfo& a = *((CAnimInfo*)p);
  return a.ai_AnimName;
}

TIME* CAnimInfo_ai_SecsPerFrame(CAnimInfo_* p)
{
  CAnimInfo& a = *((CAnimInfo*)p);
  return &(a.ai_SecsPerFrame);
}

INDEX* CAnimInfo_ai_NumberOfFrames(CAnimInfo_* p)
{
  CAnimInfo& a = *((CAnimInfo*)p);
  return &(a.ai_NumberOfFrames);
}


COneAnim_* COneAnim_new()
{
  return (COneAnim_*)(new COneAnim());
}

COneAnim_* COneAnim_clone(const COneAnim_* p)
{
  COneAnim* pNew = new COneAnim();
  *pNew = *((const COneAnim*)p);
  return (COneAnim_*)pNew;
}

void COneAnim_delete(COneAnim_* p)
{
  delete ((COneAnim*)p);
}

void COneAnim_copy(COneAnim_* a, const COneAnim_* b)
{
  *((COneAnim*)a) = *((const COneAnim*)b);
}

char* COneAnim_oa_Name(COneAnim_* p)
{
  COneAnim& a = *((COneAnim*)p);
  return a.oa_Name;
}

TIME* COneAnim_oa_SecsPerFrame(COneAnim_* p)
{
  COneAnim& a = *((COneAnim*)p);
  return &(a.oa_SecsPerFrame);
}

INDEX* COneAnim_oa_NumberOfFrames(COneAnim_* p)
{
  COneAnim& a = *((COneAnim*)p);
  return &(a.oa_NumberOfFrames);
}

INDEX** COneAnim_oa_FrameIndices(COneAnim_* p)
{
  COneAnim& a = *((COneAnim*)p);
  return &(a.oa_FrameIndices);
}

CAnimData_* CAnimData_new()
{
  return (CAnimData_*)(new CAnimData());
}

void CAnimData_delete(CAnimData_* p)
{
  delete ((CAnimData*)p);
}

INDEX* CAnimData_ad_NumberOfAnims(CAnimData_* p)
{
  CAnimData& d = *((CAnimData*)p);
  return &(d.ad_NumberOfAnims);
}

COneAnim_* CAnimData_ad_Anims(CAnimData_* p, INDEX i)
{
  CAnimData& d = *((CAnimData*)p);
  return (COneAnim_*)(&(d.ad_Anims[i]));
}

void CAnimData_CreateAnimations(CAnimData_* p, INDEX ct, CTString_* s, INDEX defframe, TIME speed)
{
  ((CAnimData*)p)->CreateAnimations(ct, *((CTString*)s), defframe, speed);
}

void CAnimData_SetFrames(CAnimData_* p, INDEX ianim, INDEX ct, INDEX* frames)
{
  ((CAnimData*)p)->SetFrames(ianim, ct, frames);
}

void CAnimData_SetName(CAnimData_* p, INDEX ianim, CTString_* s)
{
  ((CAnimData*)p)->SetName(ianim, *((CTString*)s));
}

void CAnimData_SetSpeed(CAnimData_* p, INDEX ianim, TIME speed)
{
  ((CAnimData*)p)->SetSpeed(ianim, speed);
}

INDEX CAnimData_GetFrame(CAnimData_* p, INDEX ianim, INDEX iframe)
{
  return ((CAnimData*)p)->GetFrame(ianim, iframe);
}

void CAnimData_SetFrame(CAnimData_* p, INDEX ianim, INDEX iframe, INDEX inewframe)
{
  ((CAnimData*)p)->SetFrame(ianim, iframe, inewframe);
}

void CAnimData_DefaultAnimation(CAnimData_* p)
{
  ((CAnimData*)p)->DefaultAnimation();
}

void CAnimData_GetAnimInfo(const CAnimData_* p, INDEX ianim, CAnimInfo_* info)
{
  ((const CAnimData*)p)->GetAnimInfo(ianim, *((CAnimInfo*)info));
}

void CAnimData_AddAnimation(CAnimData_* p)
{
  ((CAnimData*)p)->AddAnimation();
}

void CAnimData_DeleteAnimation(CAnimData_* p, INDEX ianim)
{
  ((CAnimData*)p)->DeleteAnimation(ianim);
}

INDEX CAnimData_GetAnimsCt(const CAnimData_* p)
{
  return ((const CAnimData*)p)->GetAnimsCt();
}

CAnimObject_* CAnimObject_new()
{
  return (CAnimObject_*)(new CAnimObject());
}

void CAnimObject_delete(CAnimObject_* p)
{
  delete ((CAnimObject*)p);
}

TIME* CAnimObject_ao_tmAnimStart(CAnimObject_* p)
{
  CAnimObject& o = *((CAnimObject*)p);
  return &(o.ao_tmAnimStart);
}

INDEX* CAnimObject_ao_iCurrentAnim(CAnimObject_* p)
{
  CAnimObject& o = *((CAnimObject*)p);
  return &(o.ao_iCurrentAnim);
}

ULONG* CAnimObject_ao_ulFlags(CAnimObject_* p)
{
  CAnimObject& o = *((CAnimObject*)p);
  return &(o.ao_ulFlags);
}

INDEX* CAnimObject_ao_iLastAnim(CAnimObject_* p)
{
  CAnimObject& o = *((CAnimObject*)p);
  return &(o.ao_iLastAnim);
}

CAnimData_* CAnimObject_ao_AnimData(CAnimObject_* p)
{
  CAnimObject& o = *((CAnimObject*)p);
  return (CAnimData_*)(o.ao_AnimData);
}

void CAnimObject_Copy(CAnimObject_* a, CAnimObject_* b)
{
  ((CAnimObject*)a)->Copy(*((CAnimObject*)b));
}

void CAnimObject_Synchronize(CAnimObject_* a, CAnimObject_* b)
{
  ((CAnimObject*)a)->Synchronize(*((CAnimObject*)b));
}

void CAnimObject_NextAnim(CAnimObject_* p)
{
  ((CAnimObject*)p)->NextAnim();
}

void CAnimObject_PrevAnim(CAnimObject_* p)
{
  ((CAnimObject*)p)->PrevAnim();
}

void CAnimObject_NextFrame(CAnimObject_* p)
{
  ((CAnimObject*)p)->NextFrame();
}

void CAnimObject_PrevFrame(CAnimObject_* p)
{
  ((CAnimObject*)p)->PrevFrame();
}

void CAnimObject_SelectFrameInTime(CAnimObject_* p, TIME t)
{
  ((CAnimObject*)p)->SelectFrameInTime(t);
}

void CAnimObject_FirstFrame(CAnimObject_* p)
{
  ((CAnimObject*)p)->FirstFrame();
}

void CAnimObject_LastFrame(CAnimObject_* p)
{
  ((CAnimObject*)p)->LastFrame();
}

BOOL CAnimObject_IsUpToDate(const CAnimObject_* p, const CUpdateable_* u)
{
  return ((const CAnimObject*)p)->IsUpToDate(*((const CUpdateable*)u));
}

void CAnimObject_GetAnimInfo(const CAnimObject_* p, INDEX ianim, CAnimInfo_* info)
{
  ((const CAnimObject*)p)->GetAnimInfo(ianim, *((CAnimInfo*)info));
}

void CAnimObject_SetData(CAnimObject_* p, CAnimData_* d)
{
  ((CAnimObject*)p)->SetData((CAnimData*)d);
}

static void SetData_t(CAnimObject_* p, const CTFileName_* f)
{
  SECAPI_TRY
  ((CAnimObject*)p)->SetData_t(*((const CTFileName*)f));
  SECAPI_CATCH
}

void CAnimObject_SetData_t(CAnimObject_* p, const CTFileName_* f)
{
  STREAM_TRY
  SetData_t(p, f);
  STREAM_CATCH
}

FLOAT CAnimObject_GetCurrentAnimLength(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetCurrentAnimLength();
}

FLOAT CAnimObject_GetAnimLength(const CAnimObject_* p, INDEX ianim)
{
  return ((const CAnimObject*)p)->GetAnimLength(ianim);
}

INDEX CAnimObject_GetAnimsCt(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetAnimsCt();
}

BOOL CAnimObject_IsAnimFinished(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->IsAnimFinished();
}

TIME CAnimObject_GetPassedTime(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetPassedTime();
}

void CAnimObject_StartAnim(CAnimObject_* p, INDEX i)
{
  ((CAnimObject*)p)->StartAnim(i);
}

void CAnimObject_PlayAnim(CAnimObject_* p, INDEX i, ULONG flags)
{
  ((CAnimObject*)p)->PlayAnim(i, flags);
}

void CAnimObject_SwitchToAnim(CAnimObject_* p, INDEX i)
{
  ((CAnimObject*)p)->SwitchToAnim(i);
}

void CAnimObject_SetAnim(CAnimObject_* p, INDEX i)
{
  ((CAnimObject*)p)->SetAnim(i);
}

void CAnimObject_ResetAnim(CAnimObject_* p)
{
  ((CAnimObject*)p)->ResetAnim();
}

void CAnimObject_PauseAnim(CAnimObject_* p)
{
  ((CAnimObject*)p)->PauseAnim();
}

void CAnimObject_ContinueAnim(CAnimObject_* p)
{
  ((CAnimObject*)p)->ContinueAnim();
}

void CAnimObject_OffsetPhase(CAnimObject_* p, TIME t)
{
  ((CAnimObject*)p)->OffsetPhase(t);
}

BOOL CAnimObject_IsPaused(CAnimObject_* p)
{
  return ((CAnimObject*)p)->IsPaused();
}

INDEX CAnimObject_GetAnim(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetAnim();
}

INDEX CAnimObject_GetFrame(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetFrame();
}

INDEX CAnimObject_GetFramesInCurrentAnim(const CAnimObject_* p)
{
  return ((const CAnimObject*)p)->GetFramesInCurrentAnim();
}

void CAnimObject_GetFrameIndices(const CAnimObject_* p, INDEX* i0, INDEX* i1, FLOAT* f)
{
  ((const CAnimObject*)p)->GetFrame(*i0, *i1, *f);
}
