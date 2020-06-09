#pragma once

#include "../WowGuid128.h"

#include <cstdint>
#pragma pack(push, 1)


struct WowObjectDescriptor
{
	WowGuid128 guid;
	uint32_t entryId;
	uint32_t dynamicFlags;
	uint32_t scale;
};


static const uint64_t OffsetType = 0x20;
static const uint64_t OffsetGuid = 0x58;
static const uint64_t OffsetPosition = 0x1600;
static const uint64_t OffsetFacing = 0x1610;
struct WowObjectStruct
{
	uint32_t padToDescriptor[4];		// = 0		+ 4*4		unknown
	WowObjectDescriptor* descriptor;			// = 0x10	+ 4*2		OffsetDescriptorPointer = 0x10
	uint32_t padToType[2];				// = 0x18	+ 4*2		unknown


	uint8_t type;						// = 0x20	+ 1			OffsetType = 0x20
	uint8_t paddedType[3];				// = 0x21	+ 3			unknown
	uint32_t padToGuid[13];				// = 0x24	+ 4*13		unknown

	WowGuid128 guid;					// = 0x58	+ 4*4		OffsetGuid = 0x58
	uint32_t padToNextObj[2];			// = 0x68	+ 4*2
	WowObjectStruct* pNext;					// = 0x70	+ 4*2		OffsetNextObject = 0x70

	uint32_t padToPosition[1378];		// = 0x78	+ 4*1378
	WowVector3f position;				// = 0x1600 + 4*3		OffsetPosition = 0x1600
	uint32_t padToFacing;				// = 0x160C + 4
	float facing;						// = 0x1610 + 4			OffsetFacing = 0x1610
};

#pragma pack(pop)
