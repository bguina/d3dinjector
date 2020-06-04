#pragma once

#include "WowUnitObject.h"

class WowPlayerObject : public WowUnitObject
{
public:
	WowPlayerObject(const uint8_t* baseAddress);
};

inline std::ostream& operator<<(
	std::ostream& out,
	const WowPlayerObject& obj
	)
{
	out << (WowUnitObject)obj;
	return out;
}

