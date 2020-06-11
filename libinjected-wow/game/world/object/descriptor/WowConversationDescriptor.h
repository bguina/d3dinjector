#pragma once
#include "WowObjectDescriptor.h"
#pragma pack(push, 1)

struct WowConversationDescriptor : WowObjectDescriptor
{
	uint32_t lastLineEndTime; // size 1 flags: MIRROR_VIEWER_DEPENDENT
};

struct WowConversationDynamicDescriptor : WowObjectDescriptor
{
	uint32_t actors; // size 1 flags: MIRROR_NONE
	uint32_t lines[256]; // size 256 flags: MIRROR_NONE
};
#pragma pack(pop)
