#pragma once

#include "WowObjectDescriptor.h"
#pragma pack(push, 1)

struct WowGameObjectDescriptor : WowObjectDescriptor
{
	WowGuid128 createdBy; // size 4 flags: MIRROR_ALL
	WowGuid128 guildGuid; // size 4 flags: MIRROR_ALL
	uint32_t displayId; // size 1 flags: 
	uint32_t flags; // size 1 flags: 
	uint32_t parentRotation[4]; // size 4 flags: MIRROR_ALL
	uint32_t factionTemplate; // size 1 flags: MIRROR_ALL
	uint32_t level; // size 1 flags: MIRROR_ALL
	uint32_t percentHealth; // size 1 flags: 
	uint32_t spellVisualId; // size 1 flags: 
	uint32_t stateSpellVisualId; // size 1 flags: 
	uint32_t spawnTrackingStateAnimId; // size 1 flags: 
	uint32_t spawnTrackingStateAnimKitId; // size 1 flags: 
	uint32_t stateWorldEffectId[4]; // size 4 flags: 
	uint32_t customParam; // size 1 flags: 
};

struct WowGameObjectDynamicDescriptor : WowObjectDescriptor
{
	uint32_t enableDoodadSets; // size 1 flags: MIRROR_NONE
};

#pragma pack(pop)
