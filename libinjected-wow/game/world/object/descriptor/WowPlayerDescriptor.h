#pragma once
#include "WowUnitDescriptor.h"
#pragma pack(push, 1)

struct WowPlayerDescriptor : WowUnitDescriptor
{
	WowGuid128 duelArbiter; // size 4 flags: MIRROR_ALL
	WowGuid128 wowAccount; // size 4 flags: MIRROR_ALL
	WowGuid128 lootTargetGUID; // size 4 flags: MIRROR_ALL
	uint32_t playerFlags; // size 1 flags: MIRROR_ALL
	uint32_t playerFlagsEx; // size 1 flags: MIRROR_ALL
	uint32_t guildRankID; // size 1 flags: MIRROR_ALL
	uint32_t guildDeleteDate; // size 1 flags: MIRROR_ALL
	uint32_t guildLevel; // size 1 flags: MIRROR_ALL
	uint32_t hairColorID; // size 1 flags: MIRROR_ALL
	uint32_t customDisplayOption; // size 1 flags: MIRROR_ALL
	uint32_t inebriation; // size 1 flags: MIRROR_ALL
	uint32_t pvpRank; // size 1 flags: MIRROR_ALL
	uint32_t duelTeam; // size 1 flags: MIRROR_ALL
	uint32_t guildTimeStamp; // size 1 flags: MIRROR_ALL
	uint32_t questLog[320]; // size 320 flags: MIRROR_PARTY
	uint32_t visibleItems[38]; // size 38 flags: MIRROR_ALL
	uint32_t playerTitle; // size 1 flags: MIRROR_ALL
	uint32_t fakeInebriation; // size 1 flags: MIRROR_ALL
	uint32_t virtualPlayerRealm; // size 1 flags: MIRROR_ALL
	uint32_t currentSpecID; // size 1 flags: MIRROR_ALL
	uint32_t taxiMountAnimKitID; // size 1 flags: MIRROR_ALL
	uint32_t avgItemLevel[4]; // size 4 flags: MIRROR_ALL
	uint32_t currentBattlePetBreedQuality; // size 1 flags: MIRROR_ALL
	uint32_t honorLevel; // size 1 flags: MIRROR_ALL
};

struct WowPlayerDynamicDescriptor : WowObjectDescriptor
{
	uint32_t arenaCooldowns; // size 1 flags: MIRROR_NONE
};

#pragma pack(pop)
