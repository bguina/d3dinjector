#pragma once

#include "WowItemObject.h"
#include "descriptor/WowContainerDescriptor.h"
#include "descriptor/WowObjectDescriptor.h"

class WowContainerObject : public WowItemObject
{
public:
	WowContainerObject(const uint8_t* baseAddress);

	WowGuid128 getSlot(int index) const;
	size_t getSlotsCount() const;
	const WowContainerDescriptor& getContainerData() const;

protected:
};

inline std::ostream& operator<<(std::ostream& out, const WowContainerObject& obj)
{
	out << (WowItemObject)obj;
	return out;
}
