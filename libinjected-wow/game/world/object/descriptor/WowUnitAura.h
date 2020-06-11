#pragma once

#include "WowObjectDescriptor.h"

#pragma pack(push, 1)

struct WowAura	// = 0x74
{
	uint32_t unk[34];	// 0x00	+ 4 * 34 flags: MIRROR_ALL
	uint32_t spellId;	// 0x88	+ 4								// spell_id is at 0x88
	uint32_t u[7];		// 0x8C + 4 * 7
}; // size 168 = 0xA8

/*
public ulong CreatorGuid;
public int AuraId;
public byte Flags;
public byte Level;
// Note: This can be a byte array, but the 2nd byte is always 00, so we might as well just do it this way.
public ushort StackCount;
public uint Duration;
public uint EndTime;

 */
#pragma pack(pop)
