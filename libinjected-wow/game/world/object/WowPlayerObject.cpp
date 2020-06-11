#include "WowPlayerObject.h"

WowPlayerObject::WowPlayerObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowUnitObject(baseAddress, game)
{
}

const WowPlayerDescriptor& WowPlayerObject::getPlayerData() const
{
	return getDescriptorData<WowPlayerDescriptor>();
}

const WowPlayerDynamicDescriptor& WowPlayerObject::getPlayerDynamicData() const
{
	return getDescriptorData<WowPlayerDynamicDescriptor>();
}
