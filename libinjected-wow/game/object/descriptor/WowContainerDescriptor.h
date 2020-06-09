#pragma once

#include "WowItemDescriptor.h"
#pragma pack(push, 1)

struct WowContainerDescriptor : WowItemData
{
	WowGuid128 slots[18]; // size 144 flags: MIRROR_ALL
	uint32_t numSlots; // size 1 flags: MIRROR_ALL
};

#pragma pack(pop)
