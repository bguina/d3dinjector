#pragma once

#include "WowObject.h"
#include "descriptor/WowItemDescriptor.h"

class WowItemObject : public WowObject
{
public:
	WowItemObject(const WowObjectStruct* baseAddress, WowGame& game);

	
	const WowItemData& getItemData() const;
	const WowItemDynamicData& getItemDynamicData() const;
protected:

};

inline std::ostream& operator<<(std::ostream& out, const WowItemObject& obj)
{
	out << (WowObject)obj;
	return out;
}
