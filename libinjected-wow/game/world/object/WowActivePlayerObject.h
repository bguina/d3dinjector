#pragma once

#include "WowPlayerObject.h"
#include "descriptor/WowActivePlayerDescriptor.h"

class WowGame;

class WowActivePlayerObject : public WowPlayerObject
{
public:
	WowActivePlayerObject(const WowObjectStruct* baseAddress, WowGame& game);

	virtual bool canAttack(const WowUnitObject& target) const;

	virtual bool isFriendly(const WowUnitObject& target) const;

	uint64_t interactWith(const WowGuid128* targetGuid);

	const WowActivePlayerDescriptor& getActivePlayerData() const;
	const CGActivePlayerDynamicDescriptor& getActivePlayerDynamicData() const;
	
protected:
};

inline std::ostream& operator<<(std::ostream& out,const WowActivePlayerObject& obj)
{
	out << (WowPlayerObject)obj;
	return out;
}

