#pragma once

#include "WowObject.h"
#include "descriptor/WowItemDescriptor.h"

class WowItemObject : public WowObject
{
public:
	WowItemObject(const uint8_t* baseAddress);

	
	const WowItemData& getItemData() const;
	const WowItemDynamicData& getItemDynamicData() const;
protected:

};

inline std::ostream& operator<<(std::ostream& out, const WowItemObject& obj)
{
	out << (WowObject)obj;
	return out;
}
