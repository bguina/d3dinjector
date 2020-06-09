#pragma once
#include <cstdint>


#include "MemoryObject.h"
#include "object/WowGuid128.h"

// DOES NOT WORK YET
class NameCache : public MemoryObject
{
public:
	NameCache(const uint8_t* baseAddress) :
		MemoryObject(baseAddress)
	{
	}
	
	unsigned long nameMaskOffset = 0x024;  // Offset for the mask used with GUID to select a linked list
	unsigned long nameBaseOffset = 0x01c;  // Offset for the start of the name linked list
	unsigned long nameStringOffset = 0x020;  // Offset to the C string in a name structure

	// DOES NOT WORK YET
	const char* getObjectName(const WowGuid128& guid) const
	{
		uint64_t mask, lowGuid, currentGuid, offset;
		uint8_t* base;
		uint8_t* current;
		mask = *(getAddress() + nameMaskOffset);
		base = *(uint8_t**)(getAddress() + nameBaseOffset);

		lowGuid = guid.lower();  // Only half the guid is used to check for a hit
		if (mask == 0xffffffff) { return ""; }

		offset = 12 * (mask & lowGuid);  // select the appropriate linked list
		current = *(uint8_t**)(base + offset + 8);  // first element
		offset = *(base + offset);  // this plus 4 is the offset for the next element
		if (current == 0 or ((uint64_t)current & 0x1)) { return ""; }
		currentGuid = *(uint64_t*)(current);
		while (currentGuid != lowGuid)
		{
			current = *(uint8_t**)(current + offset + 4);
			if (current == 0 || ((uint64_t)current & 0x1)) { return ""; }
			currentGuid = *(uint64_t*)current;
		}
		return (const char*)(current + nameStringOffset);
	}
};

