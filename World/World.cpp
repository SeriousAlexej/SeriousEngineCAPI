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

#include "World.h"

CWorld_* CWorld_new()
{
  return (CWorld_*)(new CWorld());
}

static void sehCWorld_delete(CWorld_* p)
{
  SECAPI_TRY
  delete ((CWorld*)p);
  SECAPI_CATCH
}

void CWorld_delete(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_delete(p);
  STREAM_CATCH
}

MEMBER_VAL_IMPL(CWorld, CStaticArray_CTextureTransformation_, wo_attTextureTransformations)
MEMBER_VAL_IMPL(CWorld, CStaticArray_CTextureBlending_, wo_atbTextureBlendings)
MEMBER_VAL_IMPL(CWorld, CStaticArray_CSurfaceType_, wo_astSurfaceTypes)
MEMBER_VAL_IMPL(CWorld, CStaticArray_CContentType_, wo_actContentTypes)
MEMBER_VAL_IMPL(CWorld, CStaticArray_CEnvironmentType_, wo_aetEnvironmentTypes)
MEMBER_VAL_IMPL(CWorld, CStaticArray_CIlluminationType_, wo_aitIlluminationTypes)
MEMBER_VAL_IMPL(CWorld, COLOR, wo_colBackground)
MEMBER_VAL_IMPL(CWorld, CTString_, wo_strBackdropUp)
MEMBER_VAL_IMPL(CWorld, CTString_, wo_strBackdropFt)
MEMBER_VAL_IMPL(CWorld, CTString_, wo_strBackdropRt)
MEMBER_VAL_IMPL(CWorld, CTString_, wo_strBackdropObject)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fUpW)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fUpL)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fUpCX)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fUpCZ)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fFtW)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fFtH)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fFtCX)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fFtCY)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fRtL)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fRtH)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fRtCZ)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fRtCY)
MEMBER_VAL_IMPL(CWorld, CPlacement3D_, wo_plFocus)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fTargetDistance)
MEMBER_VAL_IMPL(CWorld, CPlacement3D_, wo_plThumbnailFocus)
MEMBER_VAL_IMPL(CWorld, FLOAT, wo_fThumbnailTargetDistance)
MEMBER_VAL_IMPL(CWorld, CTFileName_, wo_fnmFileName)
MEMBER_VAL_IMPL(CWorld, CDynamicContainer_CEntity_, wo_cenEntities)

static void sehCWorld_UntargetEntity(CWorld_* p, CEntity_* penToUntarget)
{
  SECAPI_TRY
  ((CWorld*)p)->UntargetEntity((CEntity*)penToUntarget);
  SECAPI_CATCH
}
void CWorld_UntargetEntity(CWorld_* p, CEntity_* penToUntarget)
{
  STREAM_TRY
  sehCWorld_UntargetEntity(p, penToUntarget);
  STREAM_CATCH
}

static void sehCWorld_TriangularizePolygons(CWorld_* p, CDynamicContainer_CBrushPolygon_* dcPolygons)
{
  SECAPI_TRY
  ((CWorld*)p)->TriangularizePolygons(*((CDynamicContainer<CBrushPolygon>*)dcPolygons));
  SECAPI_CATCH
}
void CWorld_TriangularizePolygons(CWorld_* p, CDynamicContainer_CBrushPolygon_* dcPolygons)
{
  STREAM_TRY
  sehCWorld_TriangularizePolygons(p, dcPolygons);
  STREAM_CATCH
}

static void sehCWorld_Clear(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->Clear();
  SECAPI_CATCH
}
void CWorld_Clear(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_Clear(p);
  STREAM_CATCH
}

static CEntity_* sehCWorld_CreateEntity_t(CWorld_* p, const CPlacement3D_* plPlacement, const CTFileName_* fnmClass)
{
  CEntity_* res = NULL;
  SECAPI_TRY
  res = (CEntity_*)(((CWorld*)p)->CreateEntity_t(*((const CPlacement3D*)plPlacement), *((const CTFileName*)fnmClass)));
  SECAPI_CATCH
  return res;
}
CEntity_* CWorld_CreateEntity_t(CWorld_* p, const CPlacement3D_* plPlacement, const CTFileName_* fnmClass)
{
  CEntity_* res = NULL;
  STREAM_TRY
  res = sehCWorld_CreateEntity_t(p, plPlacement, fnmClass);
  STREAM_CATCH
  return res;
}

static CEntity_* sehCWorld_CopyOneEntity(CWorld_* p, CEntity_* enToCopy, const CPlacement3D_* plOtherSystem)
{
  CEntity_* res = NULL;
  SECAPI_TRY
  res = (CEntity_*)(((CWorld*)p)->CopyOneEntity(*((CEntity*)enToCopy), *((const CPlacement3D*)plOtherSystem)));
  SECAPI_CATCH
  return res;
}
CEntity_* CWorld_CopyOneEntity(CWorld_* p, CEntity_* enToCopy, const CPlacement3D_* plOtherSystem)
{
  CEntity_* res = NULL;
  STREAM_TRY
  res = sehCWorld_CopyOneEntity(p, enToCopy, plOtherSystem);
  STREAM_CATCH
  return res;
}

static void sehCWorld_CopyEntities(CWorld_* p, CWorld_* woOther, CDynamicContainer_CEntity_* cenToCopy, CEntitySelection_* senCopied, const CPlacement3D_* plOtherSystem)
{
  SECAPI_TRY
  ((CWorld*)p)->CopyEntities(*((CWorld*)woOther), *((CDynamicContainer<CEntity>*)cenToCopy), *((CEntitySelection*)senCopied), *((const CPlacement3D*)plOtherSystem));
  SECAPI_CATCH
}
void CWorld_CopyEntities(CWorld_* p, CWorld_* woOther, CDynamicContainer_CEntity_* cenToCopy, CEntitySelection_* senCopied, const CPlacement3D_* plOtherSystem)
{
  STREAM_TRY
  sehCWorld_CopyEntities(p, woOther, cenToCopy, senCopied, plOtherSystem);
  STREAM_CATCH
}

static CEntity_* sehCWorld_CopyEntityInWorld(CWorld_* p, CEntity_* enOriginal, const CPlacement3D_* plOtherEntity, BOOL bWithDescendants)
{
  CEntity_* res = NULL;
  SECAPI_TRY
  res = (CEntity_*)(((CWorld*)p)->CopyEntityInWorld(*((CEntity*)enOriginal), *((const CPlacement3D*)plOtherEntity), bWithDescendants));
  SECAPI_CATCH
  return res;
}
CEntity_* CWorld_CopyEntityInWorld(CWorld_* p, CEntity_* enOriginal, const CPlacement3D_* plOtherEntity, BOOL bWithDescendants)
{
  CEntity_* res = NULL;
  STREAM_TRY
  res = sehCWorld_CopyEntityInWorld(p, enOriginal, plOtherEntity, bWithDescendants);
  STREAM_CATCH
  return res;
}

static void sehCWorld_DestroyEntities(CWorld_* p, CEntitySelection_* senToDestroy)
{
  SECAPI_TRY
  ((CWorld*)p)->DestroyEntities(*((CEntitySelection*)senToDestroy));
  SECAPI_CATCH
}
void CWorld_DestroyEntities(CWorld_* p, CEntitySelection_* senToDestroy)
{
  STREAM_TRY
  sehCWorld_DestroyEntities(p, senToDestroy);
  STREAM_CATCH
}

static void sehCWorld_DestroyOneEntity(CWorld_* p, CEntity_* penToDestroy)
{
  SECAPI_TRY
  ((CWorld*)p)->DestroyOneEntity((CEntity*)penToDestroy);
  SECAPI_CATCH
}
void CWorld_DestroyOneEntity(CWorld_* p, CEntity_* penToDestroy)
{
  STREAM_TRY
  sehCWorld_DestroyOneEntity(p, penToDestroy);
  STREAM_CATCH
}

void CWorld_CastRay(CWorld_* p, CCastRay_* crRay)
{
  ((CWorld*)p)->CastRay(*((CCastRay*)crRay));
}

void CWorld_ContinueCast(CWorld_* p, CCastRay_* crRay)
{
  ((CWorld*)p)->ContinueCast(*((CCastRay*)crRay));
}

void CWorld_SetBackgroundColor(CWorld_* p, COLOR colBackground)
{
  ((CWorld*)p)->SetBackgroundColor(colBackground);
}

COLOR CWorld_GetBackgroundColor(CWorld_* p)
{
  return (COLOR)(((CWorld*)p)->GetBackgroundColor());
}

CEntity_* CWorld_GetBackgroundViewer(CWorld_* p)
{
  return (CEntity_*)(((CWorld*)p)->GetBackgroundViewer());
}

void CWorld_SetDescription(CWorld_* p, const CTString_* strDescription)
{
  ((CWorld*)p)->SetDescription(*((const CTString*)strDescription));
}

CTString_* CWorld_GetDescription(CWorld_* p)
{
  const CTString res = ((CWorld*)p)->GetDescription();
  return (CTString_*)(new CTString(res));
}

void CWorld_SetName(CWorld_* p, const CTString_* strName)
{
  ((CWorld*)p)->SetName(*((const CTString*)strName));
}

CTString_* CWorld_GetName(CWorld_* p)
{
  const CTString res = ((CWorld*)p)->GetName();
  return (CTString_*)(new CTString(res));
}

void CWorld_SetSpawnFlags(CWorld_* p, ULONG ulFlags)
{
  ((CWorld*)p)->SetSpawnFlags(ulFlags);
}

ULONG CWorld_GetSpawnFlags(CWorld_* p)
{
  return ((CWorld*)p)->GetSpawnFlags();
}

static void sehCWorld_Save_t(CWorld_* p, const CTFileName_* fnmWorld)
{
  SECAPI_TRY
  ((CWorld*)p)->Save_t(*((const CTFileName*)fnmWorld));
  SECAPI_CATCH
}
void CWorld_Save_t(CWorld_* p, const CTFileName_* fnmWorld)
{
  STREAM_TRY
  sehCWorld_Save_t(p, fnmWorld);
  STREAM_CATCH
}

static void sehCWorld_Load_t(CWorld_* p, const CTFileName_* fnmWorld)
{
  SECAPI_TRY
  ((CWorld*)p)->Load_t(*((const CTFileName*)fnmWorld));
  SECAPI_CATCH
}
void CWorld_Load_t(CWorld_* p, const CTFileName_* fnmWorld)
{
  STREAM_TRY
  sehCWorld_Load_t(p, fnmWorld);
  STREAM_CATCH
}

static void sehCWorld_ReinitializeEntities(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->ReinitializeEntities();
  SECAPI_CATCH
}
void CWorld_ReinitializeEntities(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_ReinitializeEntities(p);
  STREAM_CATCH
}

static void sehCWorld_Read_t(CWorld_* p, CTStream_* pistrm)
{
  SECAPI_TRY
  ((CWorld*)p)->Read_t((CTStream*)pistrm);
  SECAPI_CATCH
}
void CWorld_Read_t(CWorld_* p, CTStream_* pistrm)
{
  STREAM_TRY
  sehCWorld_Read_t(p, pistrm);
  STREAM_CATCH
}

static void sehCWorld_Write_t(CWorld_* p, CTStream_* postrm)
{
  SECAPI_TRY
  ((CWorld*)p)->Write_t((CTStream*)postrm);
  SECAPI_CATCH
}
void CWorld_Write_t(CWorld_* p, CTStream_* postrm)
{
  STREAM_TRY
  sehCWorld_Write_t(p, postrm);
  STREAM_CATCH
}

static void sehCWorld_UpdateSectorsAfterVertexChange(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  SECAPI_TRY
  ((CWorld*)p)->UpdateSectorsAfterVertexChange(*((CBrushVertexSelection*)selVertex));
  SECAPI_CATCH
}
void CWorld_UpdateSectorsAfterVertexChange(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  STREAM_TRY
  sehCWorld_UpdateSectorsAfterVertexChange(p, selVertex);
  STREAM_CATCH
}

static void sehCWorld_UpdateSectorsDuringVertexChange(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  SECAPI_TRY
  ((CWorld*)p)->UpdateSectorsDuringVertexChange(*((CBrushVertexSelection*)selVertex));
  SECAPI_CATCH
}
void CWorld_UpdateSectorsDuringVertexChange(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  STREAM_TRY
  sehCWorld_UpdateSectorsDuringVertexChange(p, selVertex);
  STREAM_CATCH
}

static void sehCWorld_TriangularizeForVertices(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  SECAPI_TRY
  ((CWorld*)p)->TriangularizeForVertices(*((CBrushVertexSelection*)selVertex));
  SECAPI_CATCH
}
void CWorld_TriangularizeForVertices(CWorld_* p, CBrushVertexSelection_* selVertex)
{
  STREAM_TRY
  sehCWorld_TriangularizeForVertices(p, selVertex);
  STREAM_CATCH
}

static void sehCWorld_CSGAdd(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  SECAPI_TRY
  ((CWorld*)p)->CSGAdd(*((CEntity*)enThis), *((CWorld*)woOther), *((CEntity*)enOther), *((const CPlacement3D*)plOther));
  SECAPI_CATCH
}
void CWorld_CSGAdd(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  STREAM_TRY
  sehCWorld_CSGAdd(p, enThis, woOther, enOther, plOther);
  STREAM_CATCH
}

static void sehCWorld_CSGAddReverse(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  SECAPI_TRY
  ((CWorld*)p)->CSGAddReverse(*((CEntity*)enThis), *((CWorld*)woOther), *((CEntity*)enOther), *((const CPlacement3D*)plOther));
  SECAPI_CATCH
}
void CWorld_CSGAddReverse(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  STREAM_TRY
  sehCWorld_CSGAddReverse(p, enThis, woOther, enOther, plOther);
  STREAM_CATCH
}

static void sehCWorld_CSGRemove(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  SECAPI_TRY
  ((CWorld*)p)->CSGRemove(*((CEntity*)enThis), *((CWorld*)woOther), *((CEntity*)enOther), *((const CPlacement3D*)plOther));
  SECAPI_CATCH
}
void CWorld_CSGRemove(CWorld_* p, CEntity_* enThis, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  STREAM_TRY
  sehCWorld_CSGRemove(p, enThis, woOther, enOther, plOther);
  STREAM_CATCH
}

static void sehCWorld_SplitSectors(CWorld_* p, CEntity_* enThis, CBrushSectorSelection_* selbscSectorsToSplit, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  SECAPI_TRY
  ((CWorld*)p)->SplitSectors(*((CEntity*)enThis), *((CBrushSectorSelection*)selbscSectorsToSplit), *((CWorld*)woOther), *((CEntity*)enOther), *((const CPlacement3D*)plOther));
  SECAPI_CATCH
}
void CWorld_SplitSectors(CWorld_* p, CEntity_* enThis, CBrushSectorSelection_* selbscSectorsToSplit, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  STREAM_TRY
  sehCWorld_SplitSectors(p, enThis, selbscSectorsToSplit, woOther, enOther, plOther);
  STREAM_CATCH
}

BOOL CWorld_CanJoinSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToJoin)
{
  return (BOOL)(((CWorld*)p)->CanJoinSectors(*((CBrushSectorSelection*)selbscSectorsToJoin)));
}

static void sehCWorld_JoinSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToJoin)
{
  SECAPI_TRY
  ((CWorld*)p)->JoinSectors(*((CBrushSectorSelection*)selbscSectorsToJoin));
  SECAPI_CATCH
}
void CWorld_JoinSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToJoin)
{
  STREAM_TRY
  sehCWorld_JoinSectors(p, selbscSectorsToJoin);
  STREAM_CATCH
}

static void sehCWorld_SplitPolygons(CWorld_* p, CEntity_* enThis, CBrushPolygonSelection_* selbpoPolygonsToSplit, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  SECAPI_TRY
  ((CWorld*)p)->SplitPolygons(*((CEntity*)enThis), *((CBrushPolygonSelection*)selbpoPolygonsToSplit), *((CWorld*)woOther), *((CEntity*)enOther), *((const CPlacement3D*)plOther));
  SECAPI_CATCH
}
void CWorld_SplitPolygons(CWorld_* p, CEntity_* enThis, CBrushPolygonSelection_* selbpoPolygonsToSplit, CWorld_* woOther, CEntity_* enOther, const CPlacement3D_* plOther)
{
  STREAM_TRY
  sehCWorld_SplitPolygons(p, enThis, selbpoPolygonsToSplit, woOther, enOther, plOther);
  STREAM_CATCH
}

static void sehCWorld_JoinPolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin)
{
  SECAPI_TRY
  ((CWorld*)p)->JoinPolygons(*((CBrushPolygonSelection*)selbpoPolygonsToJoin));
  SECAPI_CATCH
}
void CWorld_JoinPolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin)
{
  STREAM_TRY
  sehCWorld_JoinPolygons(p, selbpoPolygonsToJoin);
  STREAM_CATCH
}

BOOL CWorld_CanJoinPolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin)
{
  return (BOOL)(((CWorld*)p)->CanJoinPolygons(*((CBrushPolygonSelection*)selbpoPolygonsToJoin)));
}

static void sehCWorld_JoinAllPossiblePolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin, BOOL bPreserveTextures, INDEX iTexture)
{
  SECAPI_TRY
  ((CWorld*)p)->JoinAllPossiblePolygons(*((CBrushPolygonSelection*)selbpoPolygonsToJoin), bPreserveTextures, iTexture);
  SECAPI_CATCH
}
void CWorld_JoinAllPossiblePolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin, BOOL bPreserveTextures, INDEX iTexture)
{
  STREAM_TRY
  sehCWorld_JoinAllPossiblePolygons(p, selbpoPolygonsToJoin, bPreserveTextures, iTexture);
  STREAM_CATCH
}

BOOL CWorld_CanJoinAllPossiblePolygons(CWorld_* p, CBrushPolygonSelection_* selbpoPolygonsToJoin)
{
  return (BOOL)(((CWorld*)p)->CanJoinAllPossiblePolygons(*((CBrushPolygonSelection*)selbpoPolygonsToJoin)));
}

BOOL CWorld_CanCopySectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToCopy)
{
  return (BOOL)(((CWorld*)p)->CanCopySectors(*((CBrushSectorSelection*)selbscSectorsToCopy)));
}

static void sehCWorld_CopySectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToCopy, CEntity_* penTarget, BOOL bWithEntities)
{
  SECAPI_TRY
  ((CWorld*)p)->CopySectors(*((CBrushSectorSelection*)selbscSectorsToCopy), (CEntity*)penTarget, bWithEntities);
  SECAPI_CATCH
}
void CWorld_CopySectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToCopy, CEntity_* penTarget, BOOL bWithEntities)
{
  STREAM_TRY
  sehCWorld_CopySectors(p, selbscSectorsToCopy, penTarget, bWithEntities);
  STREAM_CATCH
}

static void sehCWorld_DeleteSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToDelete, BOOL bClearPortalFlags)
{
  SECAPI_TRY
  ((CWorld*)p)->DeleteSectors(*((CBrushSectorSelection*)selbscSectorsToDelete), bClearPortalFlags);
  SECAPI_CATCH
}
void CWorld_DeleteSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToDelete, BOOL bClearPortalFlags)
{
  STREAM_TRY
  sehCWorld_DeleteSectors(p, selbscSectorsToDelete, bClearPortalFlags);
  STREAM_CATCH
}

static void sehCWorld_CopyPolygonInWorld(CWorld_* p, CBrushPolygon_* bpoSrc, CBrushSector_* bsc, INDEX iPol, INDEX* iEdg, INDEX* iVtx)
{
  SECAPI_TRY
  ((CWorld*)p)->CopyPolygonInWorld(*((CBrushPolygon*)bpoSrc), *((CBrushSector*)bsc), iPol, *iEdg, *iVtx);
  SECAPI_CATCH
}
void CWorld_CopyPolygonInWorld(CWorld_* p, CBrushPolygon_* bpoSrc, CBrushSector_* bsc, INDEX iPol, INDEX* iEdg, INDEX* iVtx)
{
  STREAM_TRY
  sehCWorld_CopyPolygonInWorld(p, bpoSrc, bsc, iPol, iEdg, iVtx);
  STREAM_CATCH
}

static void sehCWorld_CopyPolygonsToBrush(CWorld_* p, CBrushPolygonSelection_* selPolygons, CEntity_* penbr)
{
  SECAPI_TRY
  ((CWorld*)p)->CopyPolygonsToBrush(*((CBrushPolygonSelection*)selPolygons), (CEntity*)penbr);
  SECAPI_CATCH
}
void CWorld_CopyPolygonsToBrush(CWorld_* p, CBrushPolygonSelection_* selPolygons, CEntity_* penbr)
{
  STREAM_TRY
  sehCWorld_CopyPolygonsToBrush(p, selPolygons, penbr);
  STREAM_CATCH
}

static void sehCWorld_DeletePolygons(CWorld_* p, CDynamicContainer_CBrushPolygon_* dcPolygons)
{
  SECAPI_TRY
  ((CWorld*)p)->DeletePolygons(*((CDynamicContainer<CBrushPolygon>*)dcPolygons));
  SECAPI_CATCH
}
void CWorld_DeletePolygons(CWorld_* p, CDynamicContainer_CBrushPolygon_* dcPolygons)
{
  STREAM_TRY
  sehCWorld_DeletePolygons(p, dcPolygons);
  STREAM_CATCH
}

static void sehCWorld_CreatePolygon(CWorld_* p, CBrushVertexSelection_* selVtx)
{
  SECAPI_TRY
  ((CWorld*)p)->CreatePolygon(*((CBrushVertexSelection*)selVtx));
  SECAPI_CATCH
}
void CWorld_CreatePolygon(CWorld_* p, CBrushVertexSelection_* selVtx)
{
  STREAM_TRY
  sehCWorld_CreatePolygon(p, selVtx);
  STREAM_CATCH
}

static void sehCWorld_FlipPolygon(CWorld_* p, CBrushPolygon_* bpo)
{
  SECAPI_TRY
  ((CWorld*)p)->FlipPolygon(*((CBrushPolygon*)bpo));
  SECAPI_CATCH
}
void CWorld_FlipPolygon(CWorld_* p, CBrushPolygon_* bpo)
{
  STREAM_TRY
  sehCWorld_FlipPolygon(p, bpo);
  STREAM_CATCH
}

static void sehCWorld_MirrorAndStretch(CWorld_* p, CWorld_* woOriginal, FLOAT fStretch, WorldMirrorType_ wmt)
{
  SECAPI_TRY
  ((CWorld*)p)->MirrorAndStretch(*((CWorld*)woOriginal), fStretch, (WorldMirrorType)wmt);
  SECAPI_CATCH
}
void CWorld_MirrorAndStretch(CWorld_* p, CWorld_* woOriginal, FLOAT fStretch, WorldMirrorType_ wmt)
{
  STREAM_TRY
  sehCWorld_MirrorAndStretch(p, woOriginal, fStretch, wmt);
  STREAM_CATCH
}

void CWorld_HideSelectedEntities(CWorld_* p, CDynamicContainer_CEntity_* selenEntitiesToHide)
{
  ((CWorld*)p)->HideSelectedEntities(*((CEntitySelection*)selenEntitiesToHide));
}

void CWorld_HideUnselectedEntities(CWorld_* p)
{
  ((CWorld*)p)->HideUnselectedEntities();
}

void CWorld_ShowAllEntities(CWorld_* p)
{
  ((CWorld*)p)->ShowAllEntities();
}

void CWorld_HideSelectedSectors(CWorld_* p, CBrushSectorSelection_* selbscSectorsToHide)
{
  ((CWorld*)p)->HideSelectedSectors(*((CBrushSectorSelection*)selbscSectorsToHide));
}

void CWorld_HideUnselectedSectors(CWorld_* p)
{
  ((CWorld*)p)->HideUnselectedSectors();
}

void CWorld_ShowAllSectors(CWorld_* p)
{
  ((CWorld*)p)->ShowAllSectors();
}

static void sehCWorld_CalculateDirectionalShadows(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->CalculateDirectionalShadows();
  SECAPI_CATCH
}

void CWorld_CalculateDirectionalShadows(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_CalculateDirectionalShadows(p);
  STREAM_CATCH
}

static void sehCWorld_CalculateNonDirectionalShadows(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->CalculateNonDirectionalShadows();
  SECAPI_CATCH
}

void CWorld_CalculateNonDirectionalShadows(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_CalculateNonDirectionalShadows(p);
  STREAM_CATCH
}

static void sehCWorld_FindShadowLayers(CWorld_* p, const FLOATaabbox3D_* boxNear, BOOL bSelectedOnly, BOOL bDirectional)
{
  SECAPI_TRY
  ((CWorld*)p)->FindShadowLayers(*((const FLOATaabbox3D*)boxNear), bSelectedOnly, bDirectional);
  SECAPI_CATCH
}

void CWorld_FindShadowLayers(CWorld_* p, const FLOATaabbox3D_* boxNear, BOOL bSelectedOnly, BOOL bDirectional)
{
  STREAM_TRY
  sehCWorld_FindShadowLayers(p, boxNear, bSelectedOnly, bDirectional);
  STREAM_CATCH
}

static void sehCWorld_DiscardAllShadows(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->DiscardAllShadows();
  SECAPI_CATCH
}

void CWorld_DiscardAllShadows(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_DiscardAllShadows(p);
  STREAM_CATCH
}

static void sehCWorld_RebuildLinks(CWorld_* p)
{
  SECAPI_TRY
  ((CWorld*)p)->RebuildLinks();
  SECAPI_CATCH
}

void CWorld_RebuildLinks(CWorld_* p)
{
  STREAM_TRY
  sehCWorld_RebuildLinks(p);
  STREAM_CATCH
}
