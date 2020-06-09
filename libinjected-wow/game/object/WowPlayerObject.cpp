#include "WowPlayerObject.h"

WowPlayerObject::WowPlayerObject(const uint8_t* baseAddress) :
	WowUnitObject(baseAddress)
{
}

const WowPlayerDescriptor& WowPlayerObject::getPlayerData() const
{
	return get<WowPlayerDescriptor>();

}

const WowPlayerDynamicDescriptor& WowPlayerObject::getPlayerDynamicData() const
{
	return get<WowPlayerDynamicDescriptor>();
}
