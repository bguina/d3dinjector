#pragma once

#include "WowItemObject.h"
#include "descriptor/WowContainerDescriptor.h"
#include "descriptor/WowObjectDescriptor.h"

class WowContainerObject : public WowItemObject
{
public:
	WowContainerObject(const WowObjectStruct* baseAddress, WowGame& game);

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
