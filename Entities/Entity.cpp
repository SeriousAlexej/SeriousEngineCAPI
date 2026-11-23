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

#include "Entity.h"

MEMBER_VAL_IMPL(CEntity, RenderType_, en_RenderType)
MEMBER_VAL_IMPL(CEntity, ULONG, en_ulPhysicsFlags)
MEMBER_VAL_IMPL(CEntity, ULONG, en_ulCollisionFlags)
MEMBER_VAL_IMPL(CEntity, ULONG, en_ulFlags)
MEMBER_VAL_IMPL(CEntity, ULONG, en_ulSpawnFlags)
MEMBER_VAL_IMPL(CEntity, ULONG, en_ulID)
MEMBER_VAL_IMPL(CEntity, CPlacement3D_, en_plPlacement)
MEMBER_VAL_IMPL(CEntity, FLOATmatrix3D_, en_mRotation)
MEMBER_PTR_IMPL(CEntity, CEntityClass_, en_pecClass)
MEMBER_PTR_IMPL(CEntity, CBrush3D_, en_pbrBrush)
MEMBER_PTR_IMPL(CEntity, CTerrain_, en_ptrTerrain)
MEMBER_PTR_IMPL(CEntity, CShadingInfo_, en_psiShadingInfo)
MEMBER_PTR_IMPL(CEntity, CWorld_, en_pwoWorld)
MEMBER_PTR_IMPL(CEntity, CEntity_, en_penParent)
MEMBER_VAL_IMPL(CEntity, CListHead_, en_rdSectors)

CEntity_* CEntity_from_en_rdSectors(CListHead_* p)
{
  CListHead& node = *((CListHead*)p);
  CEntity* res = ((CEntity*)(((UBYTE*)(&node)) - offsetof(CEntity, en_rdSectors)));
  return (CEntity_*)res;
}

MEMBER_VAL_IMPL(CEntity, CListNode_, en_lnInParent)
MEMBER_VAL_IMPL(CEntity, CListHead_, en_lhChildren)

CEntity_* CEntity_from_en_lnInParent(CListNode_* p)
{
  CListNode& node = *((CListNode*)p);
  CEntity* res = ((CEntity*)(((UBYTE*)(&node)) - offsetof(CEntity, en_lnInParent)));
  return (CEntity_*)res;
}

CEntityProperty_* CEntity_PropertyForName(CEntity_* p, const CTString_* s)
{
  return (CEntityProperty_*)(((CEntity*)p)->PropertyForName(*((const CTString*)s)));
}

BOOL CEntity_IsSelected(const CEntity_* p)
{
  return ((const CEntity*)p)->IsSelected(ENF_SELECTED);
}

void CEntity_Select(CEntity_* p)
{
  ((CEntity*)p)->Select(ENF_SELECTED);
}

void CEntity_Deselect(CEntity_* p)
{
  ((CEntity*)p)->Deselect(ENF_SELECTED);
}

void CEntity_CopyOneProperty(CEntity_* p, CEntityProperty_* epPropertySrc, CEntityProperty_* epPropertyDest, CEntity_* enOther, ULONG ulFlags)
{
  ((CEntity*)p)->CopyOneProperty(*((CEntityProperty*)epPropertySrc), *((CEntityProperty*)epPropertyDest), *((CEntity*)enOther), ulFlags);
}

static void sehCEntity_Reinitialize(CEntity_* p)
{
  SECAPI_TRY
  ((CEntity*)p)->Reinitialize();
  SECAPI_CATCH
}

void CEntity_Reinitialize(CEntity_* p)
{
  STREAM_TRY
  sehCEntity_Reinitialize(p);
  STREAM_CATCH
}

static void sehCEntity_HandleSentEvents()
{
  SECAPI_TRY
  CEntity::HandleSentEvents();
  SECAPI_CATCH
}

void CEntity_HandleSentEvents()
{
  STREAM_TRY
  sehCEntity_HandleSentEvents();
  STREAM_CATCH
}

static void sehCEntity_Initialize(CEntity_* p)
{
  SECAPI_TRY
  ((CEntity*)p)->Initialize();
  SECAPI_CATCH
}

void CEntity_Initialize(CEntity_* p)
{
  STREAM_TRY
  sehCEntity_Initialize(p);
  STREAM_CATCH
}

static void sehCEntity_End(CEntity_* p)
{
  SECAPI_TRY
  ((CEntity*)p)->End();
  SECAPI_CATCH
}

void CEntity_End(CEntity_* p)
{
  STREAM_TRY
  sehCEntity_End(p);
  STREAM_CATCH
}

static void sehCEntity_Destroy(CEntity_* p)
{
  SECAPI_TRY
  ((CEntity*)p)->Destroy();
  SECAPI_CATCH
}

void CEntity_Destroy(CEntity_* p)
{
  STREAM_TRY
  sehCEntity_Destroy(p);
  STREAM_CATCH
}

void CEntity_SetPlacement(CEntity_* p, const CPlacement3D_* plNew)
{
  ((CEntity*)p)->SetPlacement(*((const CPlacement3D*)plNew));
}

void CEntity_FallDownToFloor(CEntity_* p)
{
  ((CEntity*)p)->FallDownToFloor();
}

CBrushSector_* CEntity_GetFirstSector(CEntity_* p)
{
  return (CBrushSector_*)(((CEntity*)p)->GetFirstSector());
}

CBrushSector_* CEntity_GetFirstSectorWithName(CEntity_* p)
{
  return (CBrushSector_*)(((CEntity*)p)->GetFirstSectorWithName());
}

void CEntity_SetFlags(CEntity_* p, ULONG ulFlags)
{
  ((CEntity*)p)->SetFlags(ulFlags);
}

void CEntity_SetSpawnFlags(CEntity_* p, ULONG ulFlags)
{
  ((CEntity*)p)->SetSpawnFlags(ulFlags);
}

void CEntity_SetPhysicsFlags(CEntity_* p, ULONG ulFlags)
{
  ((CEntity*)p)->SetPhysicsFlags(ulFlags);
}

void CEntity_SetCollisionFlags(CEntity_* p, ULONG ulFlags)
{
  ((CEntity*)p)->SetCollisionFlags(ulFlags);
}

void CEntity_SetParent(CEntity_* p, CEntity_* penNewParent)
{
  ((CEntity*)p)->SetParent((CEntity*)penNewParent);
}

BOOL CEntity_IsEmptyBrush(const CEntity_* p)
{
  return ((CEntity*)p)->IsEmptyBrush();
}

void CEntity_GetSize(CEntity_* p, FLOATaabbox3D_* box)
{
  ((CEntity*)p)->GetSize(*((FLOATaabbox3D*)box));
}

CTString_* CEntity_GetName(const CEntity_* p)
{
  const CTString& res = ((CEntity*)p)->GetName();
  return (CTString_*)(new CTString(res));
}

CTString_* CEntity_GetDescription(const CEntity_* p)
{
  const CTString& res = ((CEntity*)p)->GetDescription();
  return (CTString_*)(new CTString(res));
}

BOOL CEntity_IsTargetable(const CEntity_* p)
{
  return ((CEntity*)p)->IsTargetable();
}

BOOL CEntity_IsMarker(const CEntity_* p)
{
  return ((CEntity*)p)->IsMarker();
}

BOOL CEntity_IsImportant(const CEntity_* p)
{
  return ((CEntity*)p)->IsImportant();
}

BOOL CEntity_MovesByTargetedRoute(const CEntity_* p, CTString_* strTargetProperty)
{
  return ((CEntity*)p)->MovesByTargetedRoute(*((CTString*)strTargetProperty));
}

BOOL CEntity_DropsMarker(const CEntity_* p, CTFileName_* fnmMarkerClass, CTString_* strTargetProperty)
{
  return ((CEntity*)p)->DropsMarker(*((CTFileName*)fnmMarkerClass), *((CTString*)strTargetProperty));
}

CLightSource_* CEntity_GetLightSource(CEntity_* p)
{
  return (CLightSource_*)(((CEntity*)p)->GetLightSource());
}

BOOL CEntity_IsTargetValid(CEntity_* p, SLONG slPropertyOffset, CEntity_* penTarget)
{
  return ((CEntity*)p)->IsTargetValid(slPropertyOffset, (CEntity*)penTarget);
}

CTString_* CEntity_GetForceName(CEntity_* p, INDEX iForce)
{
  const CTString& res = ((CEntity*)p)->GetForceName(iForce);
  return (CTString_*)(new CTString(res));
}

CTString_* CEntity_GetFogName(CEntity_* p, INDEX iFog)
{
  const CTString& res = ((CEntity*)p)->GetFogName(iFog);
  return (CTString_*)(new CTString(res));
}

CTString_* CEntity_GetHazeName(CEntity_* p, INDEX iHaze)
{
  const CTString& res = ((CEntity*)p)->GetHazeName(iHaze);
  return (CTString_*)(new CTString(res));
}

CTString_* CEntity_GetMirrorName(CEntity_* p, INDEX iMirror)
{
  const CTString& res = ((CEntity*)p)->GetMirrorName(iMirror);
  return (CTString_*)(new CTString(res));
}

CTString_* CEntity_GetGradientName(CEntity_* p, INDEX iGradient)
{
  const CTString& res = ((CEntity*)p)->GetGradientName(iGradient);
  return (CTString_*)(new CTString(res));
}

CAnimData_* CEntity_GetAnimData(CEntity_* p, SLONG slPropertyOffset)
{
  return (CAnimData_*)(((CEntity*)p)->GetAnimData(slPropertyOffset));
}

void CEntity_MirrorAndStretch(CEntity_* p, FLOAT fStretch, BOOL bMirrorX)
{
  ((CEntity*)p)->MirrorAndStretch(fStretch, bMirrorX);
}

void CEntity_SendEvent(CEntity_* p, const CEntityEvent_* ee)
{
  ((CEntity*)p)->SendEvent(*((const CEntityEvent*)ee));
}

void CEntity_TerrainChangeNotify(CEntity_* p)
{
  ((CEntity*)p)->TerrainChangeNotify();
}

BOOL IsOfClass_(CEntity_* pen, const char* pstrClassName)
{
  return IsOfClass((CEntity*)pen, pstrClassName);
}

BOOL IsOfSameClass_(CEntity_* pen1, CEntity_* pen2)
{
  return IsOfSameClass((CEntity*)pen1, (CEntity*)pen2);
}

BOOL IsDerivedFromClass_(CEntity_* pen, const char* pstrClassName)
{
  return IsDerivedFromClass((CEntity*)pen, pstrClassName);
}
