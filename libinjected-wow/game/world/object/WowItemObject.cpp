#include "WowItemObject.h"

#include "descriptor/WowItemDescriptor.h"

WowItemObject::WowItemObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowObject(baseAddress, game)
{

}

const WowItemData& WowItemObject::getItemData() const
{
	return getDescriptorData<WowItemData>();
}

const WowItemDynamicData& WowItemObject::getItemDynamicData() const
{
	return getDescriptorData<WowItemDynamicData>();
}
