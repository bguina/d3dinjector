#include "WowGameObjectObject.h"

#include "../dump/WowGameOffsets.h"

WowGameObjectObject::WowGameObjectObject(const uint8_t* baseAddress) :
	WowObject(baseAddress)
{
}



const WowGameObjectDescriptor& WowGameObjectObject::getGameObjectData() const
{
	return get<WowGameObjectDescriptor>();
}

const WowGameObjectDynamicDescriptor& WowGameObjectObject::getGameObjectDynamicData() const
{
	return getDynamicData<WowGameObjectDynamicDescriptor>();
}
