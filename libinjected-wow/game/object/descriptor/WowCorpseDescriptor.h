#pragma once

#include "WowObjectDescriptor.h"

#pragma pack(push, 1)

struct WowCorpseDescriptor : WowObjectDescriptor
{
	WowGuid128 owner; // size 4 flags: MIRROR_ALL
	WowGuid128 partyGUID; // size 4 flags: MIRROR_ALL
	WowGuid128 guildGUID; // size 4 flags: MIRROR_ALL
	uint32_t displayID; // size 1 flags: MIRROR_ALL
	uint32_t items[19]; // size 19 flags: MIRROR_ALL
	uint32_t skinID; // size 1 flags: MIRROR_ALL
	uint32_t facialHairStyleID; // size 1 flags: MIRROR_ALL
	uint32_t flags; // size 1 flags: MIRROR_ALL
	uint32_t dynamicFlags; // size 1 flags: MIRROR_VIEWER_DEPENDENT
	uint32_t factionTemplate; // size 1 flags: MIRROR_ALL
	uint32_t customDisplayOption; // size 1 flags: MIRROR_ALL
};

#pragma pack(pop)
