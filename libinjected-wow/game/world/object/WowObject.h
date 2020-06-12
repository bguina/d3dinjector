#pragma once

#include "WowGuid128.h"
#include "MemoryObject.h"
#include "../WowVector3f.h"

#include "../../dump/WowGameDescriptors.h"
#include "descriptor/WowObjectDescriptor.h"

class WowGame;
class WowGameObjectObject;

class WowObject : public MemoryObject<WowObjectStruct>
{
public:
	WowObject(const WowObjectStruct* baseAddress, WowGame& game);

	bool vanished() const;

	virtual const WowGuid128* getGuid() const;
	virtual uint32_t getDynamicFlags() const;

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

protected:
	WowGame& mGame;
	
	template<typename T>
	const T& getDescriptorData() const
	{
		return *(T*)get().descriptor;
	}

	template<typename T>
	T& getDescriptorData()
	{
		return *(T*)get().descriptor;
	}

private:
	const WowObjectDescriptor& getObjectData() const;
};

#include <sstream>

inline std::ostream& operator<<(std::ostream& out,const WowObject& obj)
{
	out << "[" << obj.getTypeLabel() << ":" << (void*)obj.getAddress()
		<< ":GUID " << obj.getGuid() << ":XY " << obj.getX() << "," << obj.getY() << "]";
	return out;
}
