#pragma once

#include "WowGuid128.h"
#include "MemoryObject.h"
#include "../WowVector3f.h"

#include "../dump/WowGameDescriptors.h"
#include "descriptor/WowObjectDescriptor.h"

class WowGameObjectObject;

class WowObject : public MemoryObject
{
public:
	WowObject(const uint8_t* baseAddress);

	bool vanished() const;

	virtual WowGuid128 getGuid() const;
	virtual const WowGuid128* getGuidPtr() const;

	//		StorageField = 0x10,//good-33526
	//		ObjectType = 0x20,//good-33526
	//		NextObject = 0x70,//good-33526
	//		FirstObject = 0x18,//good-33526
	//		LocalGUID = 0x58, //good-33526

	virtual WowObjectType getType() const;
	virtual std::string getTypeLabel() const;

	virtual const WowVector3f& getPosition() const;
	virtual float getX() const;
	virtual float getY() const;
	virtual float getZ() const;

	virtual float getFacingRadians() const;
	virtual int getFacingDegrees() const;
	
	// Position shortcuts
	virtual float getDistanceTo(const WowObject& object) const;
	virtual float getFlightDistanceTo(const WowObject& object) const;

	virtual int getFacingDegreesTo(const WowObject& object) const;
	virtual int getFacingDeltaDegrees(const WowObject& object) const;
	
	// data fields
	virtual bool isLootable() const;
	virtual bool isTappedByOthers() const;
	virtual bool isTappedByMe() const;
	virtual bool isTappedByAllThreatList() const;
	virtual bool isInvisible() const;

	// operators
	bool operator==(const WowObject& other) const { return other.getGuid() == getGuid(); }
	bool operator!=(const WowObject& other) const { return !(other == *this); }

	// protected
	virtual uint64_t* getVirtualTable() const;
	virtual const WowObjectStruct& getObjectData() const;
	virtual const uint8_t* getDynamicDataAddress() const;

protected:

	template<typename T>
	const T& getDynamicData() const
	{
		return *get<T*>((uint64_t)getDynamicDataAddress());
	}

	template<typename T>
	T& getDynamicData()
	{
		return *get<T*>((uint64_t)getDynamicDataAddress());
	}
};

#include <sstream>

inline std::ostream& operator<<(std::ostream& out,const WowObject& obj)
{
	out << "[" << obj.getTypeLabel() << ":" << (void*)obj.getAddress()
		<< ":GUID " << obj.getGuid() << ":XY " << obj.getX() << "," << obj.getY() << "]";
	return out;
}
