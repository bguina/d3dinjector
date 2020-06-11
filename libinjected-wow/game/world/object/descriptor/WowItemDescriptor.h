#pragma once

#include "WowObjectDescriptor.h"
#pragma pack(push, 1)

struct WowItemData : WowObjectDescriptor
{
	WowGuid128 owner; // size 4 flags: MIRROR_ALL
	WowGuid128 containedIn; // size 4 flags: MIRROR_ALL
	WowGuid128 creator; // size 4 flags: MIRROR_ALL
	WowGuid128 giftCreator; // size 4 flags: MIRROR_ALL
	uint32_t stackCount; // size 1 flags: MIRROR_OWNER
	uint32_t expiration; // size 1 flags: MIRROR_OWNER
	uint32_t spellCharges[5]; // size 5 flags: MIRROR_OWNER
	uint32_t dynamicFlags; // size 1 flags: MIRROR_ALL
	uint32_t enchantment[39]; // size 39 flags: MIRROR_ALL
	uint32_t propertySeed; // size 1 flags: MIRROR_ALL
	uint32_t randomPropertiesId; // size 1 flags: MIRROR_ALL
	uint32_t durability; // size 1 flags: MIRROR_OWNER
	uint32_t maxDurability; // size 1 flags: MIRROR_OWNER
	uint32_t createPlayedTime; // size 1 flags: MIRROR_ALL
	uint32_t modifiersMask; // size 1 flags: MIRROR_OWNER
	uint32_t context; // size 1 flags: MIRROR_ALL
	uint32_t artifactXp[2]; // size 2 flags: MIRROR_OWNER
	uint32_t itemAppearanceModId = 72; // size 1 flags: MIRROR_OWNER
};

struct WowItemDynamicData : WowObjectDescriptor
{
	uint32_t modifiers[4]; // size 4 flags: MIRROR_NONE
	uint32_t bonusListIDs[260]; // size 260 flags: MIRROR_NONE
	uint32_t artifactPowers[4]; // size 4 flags: MIRROR_NONE
	uint32_t gems[4]; // size 4 flags: MIRROR_NONE
};

#pragma pack(pop)
