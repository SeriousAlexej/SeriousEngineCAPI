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

#ifndef SECAPI_ENTITIES_ENTITY_H
#define SECAPI_ENTITIES_ENTITY_H
#include "../Base/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SERIOUSENGINECAPI_EXPORTS
/*
 * Flags determining whether some entity is active in some game type or difficulty level.
 */
// difficulty levels
#define SPF_EASY        (1L<<0)       // active at easy difficulty
#define SPF_NORMAL      (1L<<1)       // active at normal difficulty
#define SPF_HARD        (1L<<2)       // active at hard difficulty
#define SPF_EXTREME     (1L<<3)       // active at extreme difficulty
#define SPF_TOURIST     (1L<<4)       // active at tourist difficulty

#define SPF_MASK_DIFFICULTY 0x0000FFFFL    // mask for difficulty level flags

// game types
#define SPF_SINGLEPLAYER  (1L<<16)    // active in single player mode
#define SPF_DEATHMATCH    (1L<<17)    // active in deathmatch mode
#define SPF_COOPERATIVE   (1L<<18)    // active in cooperative mode
#define SPF_FLYOVER       (1L<<19)    // active in flyover (camera) mode

#define SPF_MASK_GAMEMODE 0xFFFF0000L    // mask for game type flags

/*
 * Various other entity flags
 */
#define ENF_SELECTED          (1L<< 0)  // set if selected
#define ENF_ZONING            (1L<< 1)  // brush that defines spatial classification
#define ENF_DELETED           (1L<< 2)  // set if the entity does not exist anymore
#define ENF_ALIVE             (1L<< 3)  // set if the entity is currently a living being
#define ENF_INRENDERING       (1L<< 4)  // set if the entity is currently active in rendering
#define ENF_VALIDSHADINGINFO  (1L<< 5)  // set if shading info is valid
#define ENF_SEETHROUGH        (1L<< 6)  // set if cast ray can see through
#define ENF_FOUNDINGRIDSEARCH (1L<< 7)  // set if the entity is already found in grid search
#define ENF_CLUSTERSHADOWS    (1L<< 8)  // model that has cluster shadows
#define ENF_BACKGROUND        (1L<< 9)  // brush or model that is used for background rendering
#define ENF_ANCHORED          (1L<<10)  // set if cannot be moved in editor without special allowance
#define ENF_HASPARTICLES      (1L<<11)  // entity renders particles
#define ENF_INVISIBLE         (1L<<12)  // entity is invisible (for AI purposes)
#define ENF_DYNAMICSHADOWS    (1L<<13)  // moving brush that causes automatic shadow recalculation
#define ENF_NOTIFYLEVELCHANGE (1L<<14)  // entity is notified when level is changed
#define ENF_CROSSESLEVELS     (1L<<15)  // entity must be carried when level is changed
#define ENF_PREDICTABLE       (1L<<16)  // this entity can be predicted
#define ENF_PREDICTOR         (1L<<17)  // this entity is predictor for another entity
#define ENF_PREDICTED         (1L<<18)  // this entity has its predictor
#define ENF_WILLBEPREDICTED   (1L<<19)  // this entity will be predicted
#define ENF_TEMPPREDICTOR     (1L<<20)  // predictor that was spawned during prediction (doesn't have a predictor)
#define ENF_HIDDEN            (1L<<21)  // set if the entity is hidden (for editing)
#define ENF_NOSHADINGINFO     (1L<<22)  // the entity doesn't need FindShadingInfo(), it will set its own shading
  
#define RT_ILLEGAL_ 1
#define RT_NONE_ 2
#define RT_MODEL_ 3
#define RT_BRUSH_ 4
#define RT_EDITORMODEL_ 5
#define RT_VOID_ 7
#define RT_FIELDBRUSH_ 8
#define RT_SKAMODEL_ 9
#define RT_SKAEDITORMODEL_ 10
#define RT_TERRAIN_ 11

/* Entity physics flags. */
#define EPF_ORIENTEDBYGRAVITY     (1UL<<0) // set if gravity influences its orientation
#define EPF_TRANSLATEDBYGRAVITY   (1UL<<1) // set if gravity can move it
#define EPF_PUSHABLE              (1UL<<2) // set if can be pushed by other objects
#define EPF_STICKYFEET            (1UL<<3) // entity always falls to nearest surface
#define EPF_RT_SYNCHRONIZED       (1UL<<4) // set if rotation and translation are synchronized
#define EPF_ABSOLUTETRANSLATE     (1UL<<5) // set if entity is translated absolute and not relative to its position
#define EPF_NOACCELERATION        (1UL<<6) // set if entity can change its speed immediately
#define EPF_HASLUNGS              (1UL<<7) // set if entity has lungs
#define EPF_HASGILLS              (1UL<<8) // set if entity has gills
#define EPF_MOVABLE               (1UL<<9) // set if derived from CMovableEntity
#define EPF_NOIMPACT              (1UL<<10)// entities are not damaged when hitting this one
#define EPF_NOIMPACTTHISTICK      (1UL<<11)// this one is not damaged by impact this tick
#define EPF_CANFADESPINNING       (1UL<<12)// desired rotation can be reduced by contents (like water)
#define EPF_ONSTEEPSLOPE          (1UL<<13)// while sliding down a steep slope (valid only if entity has reference)
#define EPF_ORIENTINGTOGRAVITY    (1UL<<14)// while beeing re-oriented by gravity
#define EPF_FLOATING              (1UL<<15)// while bouyancy causes floating in fluid
#define EPF_FORCEADDED            (1UL<<16)// set if force-added to movers

// what to do when colliding
#define EPF_ONBLOCK_MASK            (7UL<<29)
#define EPF_ONBLOCK_STOP            (0UL<<29)  // stop moving
#define EPF_ONBLOCK_SLIDE           (1UL<<29)  // slide along
#define EPF_ONBLOCK_CLIMBORSLIDE    (2UL<<29)  // clim up a stair or slide along
#define EPF_ONBLOCK_BOUNCE          (3UL<<29)  // bounce off
#define EPF_ONBLOCK_PUSH            (4UL<<29)  // push the obstacle
#define EPF_ONBLOCK_STOPEXACT       (5UL<<29)  // stop moving, but exactly at collision position

// entity collision flags are divided in 3 groups
#define ECB_COUNT 10    // max number of flags per group
#define ECF_MASK  ((1<<ECB_COUNT)-1)  // mask for one group
// what an entity is
#define ECB_IS      0
#define ECF_ISMASK  (ECF_MASK<<ECB_IS)
// which other entities to test with
#define ECB_TEST    10
#define ECF_TESTMASK  (ECF_MASK<<ECB_TEST)
// which tested entities to pass through
#define ECB_PASS    20
#define ECF_PASSMASK  (ECF_MASK<<ECB_PASS)

// optimizations to completely ignore some types of entities
#define ECF_IGNOREBRUSHES  (1UL<<30)
#define ECF_IGNOREMODELS   (1UL<<31)

#endif

SECAPI MEMBER_VAL_DECL(CEntity, RenderType_, en_RenderType)
SECAPI MEMBER_VAL_DECL(CEntity, ULONG, en_ulPhysicsFlags)
SECAPI MEMBER_VAL_DECL(CEntity, ULONG, en_ulCollisionFlags)
SECAPI MEMBER_VAL_DECL(CEntity, ULONG, en_ulFlags)
SECAPI MEMBER_VAL_DECL(CEntity, ULONG, en_ulSpawnFlags)
SECAPI MEMBER_VAL_DECL(CEntity, ULONG, en_ulID)
SECAPI MEMBER_VAL_DECL(CEntity, CPlacement3D_, en_plPlacement)
SECAPI MEMBER_VAL_DECL(CEntity, FLOATmatrix3D_, en_mRotation)
SECAPI MEMBER_PTR_DECL(CEntity, CEntityClass_, en_pecClass)
SECAPI MEMBER_PTR_DECL(CEntity, CBrush3D_, en_pbrBrush)
SECAPI MEMBER_PTR_DECL(CEntity, CTerrain_, en_ptrTerrain)
SECAPI MEMBER_PTR_DECL(CEntity, CShadingInfo_, en_psiShadingInfo)
SECAPI MEMBER_PTR_DECL(CEntity, CWorld_, en_pwoWorld)
SECAPI MEMBER_PTR_DECL(CEntity, CEntity_, en_penParent)
SECAPI MEMBER_VAL_DECL(CEntity, CListHead_, en_rdSectors)
SECAPI CEntity_* CEntity_from_en_rdSectors(CListHead_* p);
SECAPI MEMBER_VAL_DECL(CEntity, CListNode_, en_lnInParent)
SECAPI MEMBER_VAL_DECL(CEntity, CListHead_, en_lhChildren)
SECAPI CEntity_* CEntity_from_en_lnInParent(CListNode_* p);
SECAPI CEntityProperty_* CEntity_PropertyForName(CEntity_* p, const CTString_* s);
SECAPI BOOL CEntity_IsSelected(const CEntity_* p);
SECAPI void CEntity_Select(CEntity_* p);
SECAPI void CEntity_Deselect(CEntity_* p);
SECAPI void CEntity_CopyOneProperty(CEntity_* p, CEntityProperty_* epPropertySrc, CEntityProperty_* epPropertyDest, CEntity_* enOther, ULONG ulFlags);
SECAPI void CEntity_Reinitialize(CEntity_* p);
SECAPI void CEntity_HandleSentEvents();
SECAPI void CEntity_Initialize(CEntity_* p);
SECAPI void CEntity_End(CEntity_* p);
SECAPI void CEntity_Destroy(CEntity_* p);
SECAPI void CEntity_SetPlacement(CEntity_* p, const CPlacement3D_* plNew);
SECAPI void CEntity_FallDownToFloor(CEntity_* p);
SECAPI CBrushSector_* CEntity_GetFirstSector(CEntity_* p);
SECAPI CBrushSector_* CEntity_GetFirstSectorWithName(CEntity_* p);
SECAPI void CEntity_SetFlags(CEntity_* p, ULONG ulFlags);
SECAPI void CEntity_SetSpawnFlags(CEntity_* p, ULONG ulFlags);
SECAPI void CEntity_SetPhysicsFlags(CEntity_* p, ULONG ulFlags);
SECAPI void CEntity_SetCollisionFlags(CEntity_* p, ULONG ulFlags);
SECAPI void CEntity_SetParent(CEntity_* p, CEntity_* penNewParent);
SECAPI BOOL CEntity_IsEmptyBrush(const CEntity_* p);
SECAPI void CEntity_GetSize(CEntity_* p, FLOATaabbox3D_* box);
SECAPI CTString_* CEntity_GetName(const CEntity_* p);
SECAPI CTString_* CEntity_GetDescription(const CEntity_* p);
SECAPI BOOL CEntity_IsTargetable(const CEntity_* p);
SECAPI BOOL CEntity_IsMarker(const CEntity_* p);
SECAPI BOOL CEntity_IsImportant(const CEntity_* p);
SECAPI BOOL CEntity_MovesByTargetedRoute(const CEntity_* p, CTString_* strTargetProperty);
SECAPI BOOL CEntity_DropsMarker(const CEntity_* p, CTFileName_* fnmMarkerClass, CTString_* strTargetProperty);
SECAPI CLightSource_* CEntity_GetLightSource(CEntity_* p);
SECAPI BOOL CEntity_IsTargetValid(CEntity_* p, SLONG slPropertyOffset, CEntity_* penTarget);
SECAPI CTString_* CEntity_GetForceName(CEntity_* p, INDEX iForce);
SECAPI CTString_* CEntity_GetFogName(CEntity_* p, INDEX iFog);
SECAPI CTString_* CEntity_GetHazeName(CEntity_* p, INDEX iHaze);
SECAPI CTString_* CEntity_GetMirrorName(CEntity_* p, INDEX iMirror);
SECAPI CTString_* CEntity_GetGradientName(CEntity_* p, INDEX iGradient);
SECAPI CAnimData_* CEntity_GetAnimData(CEntity_* p, SLONG slPropertyOffset);
SECAPI void CEntity_MirrorAndStretch(CEntity_* p, FLOAT fStretch, BOOL bMirrorX);
SECAPI void CEntity_SendEvent(CEntity_* p, const CEntityEvent_* ee);
SECAPI void CEntity_TerrainChangeNotify(CEntity_* p);

SECAPI BOOL IsOfClass_(CEntity_* pen, const char* pstrClassName);
SECAPI BOOL IsOfSameClass_(CEntity_* pen1, CEntity_* pen2);
SECAPI BOOL IsDerivedFromClass_(CEntity_* pen, const char* pstrClassName);

#ifdef __cplusplus
}
#endif

#endif
