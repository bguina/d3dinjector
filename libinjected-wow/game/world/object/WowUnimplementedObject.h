#pragma once

#include "WowObject.h"

class WowUnimplementedObject : public WowObject
{
public:
	WowUnimplementedObject(const WowObjectStruct* baseAddress, WowGame& game);
};

inline std::ostream& operator<<(
	std::ostream& out,
	const WowUnimplementedObject& obj
	)
{
	out << (WowObject)obj;
	return out;
}
