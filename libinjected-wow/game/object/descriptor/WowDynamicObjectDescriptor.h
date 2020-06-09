#pragma once

#include "WowObjectDescriptor.h"
#pragma pack(push, 1)

struct WowDynamicObjectDescriptor : WowObjectDescriptor
{
	WowGuid128 caster; // size 4 flags: MIRROR_ALL
	uint32_t type; // size 1 flags: MIRROR_ALL
	uint32_t spellXSpellVisualID; // size 1 flags: MIRROR_ALL
	uint32_t spellID; // size 1 flags: MIRROR_ALL
	uint32_t radius; // size 1 flags: MIRROR_ALL
	uint32_t castTime; // size 1 flags: MIRROR_ALL
};
#pragma pack(pop)
