#include "WowContainerObject.h"


#include "descriptor/WowContainerDescriptor.h"
#include "descriptor/WowObjectDescriptor.h"

WowContainerObject::WowContainerObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowItemObject(baseAddress, game)
{
}

WowGuid128 WowContainerObject::getSlot(int index) const
{
	return getDescriptorData<WowContainerDescriptor>().slots[index];
}

size_t WowContainerObject::getSlotsCount() const
{
	return getDescriptorData<WowContainerDescriptor>().numSlots;
}

const WowContainerDescriptor& WowContainerObject::getContainerData() const
{
	return getDescriptorData<WowContainerDescriptor>();
}
