#pragma once
#include "WowObjectDescriptor.h"
#pragma pack(push, 1)

struct WowAreaTriggerDescriptor : WowObjectDescriptor
{
	uint32_t overrideScaleCurve[7]; // size 7 flags: 
	uint32_t extraScaleCurve[7]; // size 7 flags: 
	WowGuid128 caster; // size 4 flags: MIRROR_ALL
	uint32_t duration; // size 1 flags: MIRROR_ALL
	uint32_t timeToTarget; // size 1 flags: 
	uint32_t timeToTargetScale; // size 1 flags: 
	uint32_t timeToTargetExtraScale; // size 1 flags: 
	uint32_t spellID; // size 1 flags: MIRROR_ALL
	uint32_t spellForVisuals; // size 1 flags: MIRROR_ALL
	uint32_t spellXSpellVisualID; // size 1 flags: MIRROR_ALL
	uint32_t boundsRadius2D; // size 1 flags: 
	uint32_t decalPropertiesID; // size 1 flags: MIRROR_ALL
	WowGuid128 creatingEffectGUID; // size 4 flags: MIRROR_ALL
};
#pragma pack(pop)
