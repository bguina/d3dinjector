#pragma once

#include "WowGuid128.h"
#include "MemoryObject.h"

#include "../WowVector3f.h"
#include "../dump/WowGameDescriptors.h"

class WowObject : public MemoryObject
{
public:
	WowObject(const uint8_t* baseAddress);

	template<class T>
	const T& downcast() const {
		return static_cast<const T&>(*this);
	}

	template<class T>
	T& downcast() {
		return static_cast<T&>(*this);
	}

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

	// Position helpers
	virtual float getDistanceTo(const WowObject& object) const;
	virtual float getFlightDistanceTo(const WowObject& object) const;

	virtual int getFacingDegreesTo(const WowObject& object) const;
	virtual int getFacingDeltaDegrees(const WowObject& object) const;

	bool operator==(const WowObject& other) const { return other.getGuid() == getGuid(); }
	bool operator!=(const WowObject& other) const { return !(other == *this); }

protected:
	const uint8_t* getDescriptor() const;

	void* vtableAt(unsigned index);
};

#include <sstream>

inline std::ostream& operator<<(
	std::ostream& out,
	const WowObject& obj
	)
{
	out << "[" << obj.getTypeLabel() << ":" << (void*)obj.getAddress() << ":GUID " << obj.getGuid().upper() << obj.getGuid().lower() << ":Pos" << obj.getX() << "," << obj.getY() << "]";
	return out;
}
