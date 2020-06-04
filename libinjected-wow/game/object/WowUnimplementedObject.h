#pragma once

#include "WowObject.h"

class WowUnimplementedObject : public WowObject
{
public:
	WowUnimplementedObject(const uint8_t* baseAddress);
};

inline std::ostream& operator<<(
	std::ostream& out,
	const WowUnimplementedObject& obj
	)
{
	out << (WowObject)obj;
	return out;
}
