#include "WowGameObjectObject.h"

#include "../../dump/WowGameOffsets.h"

WowGameObjectObject::WowGameObjectObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowObject(baseAddress, game)
{
}



const WowGameObjectDescriptor& WowGameObjectObject::getGameObjectData() const
{
	return getDescriptorData<WowGameObjectDescriptor>();
}

const WowGameObjectDynamicDescriptor& WowGameObjectObject::getGameObjectDynamicData() const
{
	return getDescriptorData<WowGameObjectDynamicDescriptor>();
}
