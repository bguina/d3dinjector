#include "WowItemObject.h"

#include "descriptor/WowItemDescriptor.h"

WowItemObject::WowItemObject(const uint8_t* baseAddress) :
	WowObject(baseAddress)
{

}

const WowItemData& WowItemObject::getItemData() const
{
	return get<WowItemData>();
}

const WowItemDynamicData& WowItemObject::getItemDynamicData() const
{
	return getDynamicData<WowItemDynamicData>();
}
