#pragma once

#include "WowUnitObject.h"
#include "descriptor/WowPlayerDescriptor.h"

class WowPlayerObject : public WowUnitObject
{
public:
	WowPlayerObject(const uint8_t* baseAddress);
	const WowPlayerDescriptor& getPlayerData() const;
	const WowPlayerDynamicDescriptor& getPlayerDynamicData() const;

protected:
};

inline std::ostream& operator<<(std::ostream& out,const WowPlayerObject& obj)
{
	out << (WowUnitObject)obj;
	return out;
}

