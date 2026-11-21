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

#ifndef SECAPI_BASE_ANIM_H
#define SECAPI_BASE_ANIM_H
#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SERIOUSENGINECAPI_EXPORTS
#define NAME_SIZE 32
#define PATH_MAX 260
#endif

SECAPI CAnimInfo_* CAnimInfo_new();
SECAPI CAnimInfo_* CAnimInfo_clone(const CAnimInfo_* p);
SECAPI void CAnimInfo_delete(CAnimInfo_* p);
SECAPI void CAnimInfo_copy(CAnimInfo_* a, const CAnimInfo_* b);
SECAPI char* CAnimInfo_ai_AnimName(CAnimInfo_* p);
SECAPI TIME* CAnimInfo_ai_SecsPerFrame(CAnimInfo_* p);
SECAPI INDEX* CAnimInfo_ai_NumberOfFrames(CAnimInfo_* p);

SECAPI char* COneAnim_oa_Name(COneAnim_* p);
SECAPI TIME* COneAnim_oa_SecsPerFrame(COneAnim_* p);
SECAPI INDEX* COneAnim_oa_NumberOfFrames(COneAnim_* p);
SECAPI INDEX** COneAnim_oa_FrameIndices(COneAnim_* p);

SECAPI CAnimData_* CAnimData_new();
SECAPI void CAnimData_delete(CAnimData_* p);
SECAPI INDEX* CAnimData_ad_NumberOfAnims(CAnimData_* p);
SECAPI COneAnim_* CAnimData_ad_Anims(CAnimData_* p, INDEX i);
SECAPI void CAnimData_CreateAnimations(CAnimData_* p, INDEX ct, CTString_* s, INDEX defframe, TIME speed);
SECAPI void CAnimData_SetFrames(CAnimData_* p, INDEX ianim, INDEX ct, INDEX* frames);
SECAPI void CAnimData_SetName(CAnimData_* p, INDEX ianim, CTString_* s);
SECAPI void CAnimData_SetSpeed(CAnimData_* p, INDEX ianim, TIME speed);
SECAPI INDEX CAnimData_GetFrame(CAnimData_* p, INDEX ianim, INDEX iframe);
SECAPI void CAnimData_SetFrame(CAnimData_* p, INDEX ianim, INDEX iframe, INDEX inewframe);
SECAPI void CAnimData_DefaultAnimation(CAnimData_* p);
SECAPI void CAnimData_GetAnimInfo(const CAnimData_* p, INDEX ianim, CAnimInfo_* info);
SECAPI void CAnimData_AddAnimation(CAnimData_* p);
SECAPI void CAnimData_DeleteAnimation(CAnimData_* p, INDEX ianim);
SECAPI INDEX CAnimData_GetAnimsCt(const CAnimData_* p);

#ifndef SERIOUSENGINECAPI_EXPORTS
#define AOF_PAUSED        (1L<<0)     // current animation is paused
#define AOF_LOOPING       (1L<<1)     // anim object is playing a looping animation
#define AOF_NORESTART     (1L<<2)     // don't restart anim (used for PlayAnim())
#define AOF_SMOOTHCHANGE  (1L<<3)     // smoothly change between anims
#endif

SECAPI CAnimObject_* CAnimObject_new();
SECAPI void CAnimObject_delete(CAnimObject_* p);
SECAPI TIME* CAnimObject_ao_tmAnimStart(CAnimObject_* p);
SECAPI INDEX* CAnimObject_ao_iCurrentAnim(CAnimObject_* p);
SECAPI ULONG* CAnimObject_ao_ulFlags(CAnimObject_* p);
SECAPI INDEX* CAnimObject_ao_iLastAnim(CAnimObject_* p);
SECAPI CAnimData_* CAnimObject_ao_AnimData(CAnimObject_* p);
SECAPI void CAnimObject_Copy(CAnimObject_* a, CAnimObject_* b);
SECAPI void CAnimObject_Synchronize(CAnimObject_* a, CAnimObject_* b);
SECAPI void CAnimObject_NextAnim(CAnimObject_* p);
SECAPI void CAnimObject_PrevAnim(CAnimObject_* p);
SECAPI void CAnimObject_NextFrame(CAnimObject_* p);
SECAPI void CAnimObject_PrevFrame(CAnimObject_* p);
SECAPI void CAnimObject_SelectFrameInTime(CAnimObject_* p, TIME t);
SECAPI void CAnimObject_FirstFrame(CAnimObject_* p);
SECAPI void CAnimObject_LastFrame(CAnimObject_* p);
SECAPI BOOL CAnimObject_IsUpToDate(const CAnimObject_* p, const CUpdateable_* u);
SECAPI void CAnimObject_GetAnimInfo(const CAnimObject_* p, INDEX ianim, CAnimInfo_* info);
SECAPI void CAnimObject_SetData(CAnimObject_* p, CAnimData_* d);
SECAPI void CAnimObject_SetData_t(CAnimObject_* p, const CTFileName_* f);
SECAPI FLOAT CAnimObject_GetCurrentAnimLength(const CAnimObject_* p);
SECAPI FLOAT CAnimObject_GetAnimLength(const CAnimObject_* p, INDEX ianim);
SECAPI INDEX CAnimObject_GetAnimsCt(const CAnimObject_* p);
SECAPI BOOL CAnimObject_IsAnimFinished(const CAnimObject_* p);
SECAPI TIME CAnimObject_GetPassedTime(const CAnimObject_* p);
SECAPI void CAnimObject_StartAnim(CAnimObject_* p, INDEX i);
SECAPI void CAnimObject_PlayAnim(CAnimObject_* p, INDEX i, ULONG flags);
SECAPI void CAnimObject_SwitchToAnim(CAnimObject_* p, INDEX i);
SECAPI void CAnimObject_SetAnim(CAnimObject_* p, INDEX i);
SECAPI void CAnimObject_ResetAnim(CAnimObject_* p);
SECAPI void CAnimObject_PauseAnim(CAnimObject_* p);
SECAPI void CAnimObject_ContinueAnim(CAnimObject_* p);
SECAPI void CAnimObject_OffsetPhase(CAnimObject_* p, TIME t);
SECAPI BOOL CAnimObject_IsPaused(CAnimObject_* p);
SECAPI INDEX CAnimObject_GetAnim(const CAnimObject_* p);
SECAPI INDEX CAnimObject_GetFrame(const CAnimObject_* p);
SECAPI INDEX CAnimObject_GetFramesInCurrentAnim(const CAnimObject_* p);
SECAPI void CAnimObject_GetFrameIndices(const CAnimObject_* p, INDEX* i0, INDEX* i1, FLOAT* f);

#ifdef __cplusplus
}
#endif

#endif
