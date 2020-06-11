#pragma once

#include "WowObject.h"
#include "descriptor/WowGameObjectDescriptor.h"

class WowGameObjectObject : public WowObject
{
public:
	WowGameObjectObject(const WowObjectStruct* baseAddress, WowGame& game);

	//		StorageFieldx10,//good-33526
	//		ObjectTypex20,//good-33526
	//		NextObjectx70,//good-33526
	//		FirstObjectx18,//good-33526
	//		LocalGUIDx58, //good-33526

	const WowGameObjectDescriptor& getGameObjectData() const;
	const WowGameObjectDynamicDescriptor& getGameObjectDynamicData() const;
protected:


};

#include <sstream>

inline std::ostream& operator<<(std::ostream& out,const WowGameObjectObject& obj)
{
	out << (WowObject)obj;
	return out;
}
