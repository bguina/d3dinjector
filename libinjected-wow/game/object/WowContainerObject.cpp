#include "WowContainerObject.h"


#include "descriptor/WowContainerDescriptor.h"
#include "descriptor/WowObjectDescriptor.h"

WowContainerObject::WowContainerObject(const uint8_t* baseAddress) :
	WowItemObject(baseAddress)
{
}

WowGuid128 WowContainerObject::getSlot(int index) const
{
	return getDynamicData<WowContainerDescriptor>().slots[index];
}

size_t WowContainerObject::getSlotsCount() const
{
	return getDynamicData<WowContainerDescriptor>().numSlots;
}

const WowContainerDescriptor& WowContainerObject::getContainerData() const
{
	return get<WowContainerDescriptor>();
}
