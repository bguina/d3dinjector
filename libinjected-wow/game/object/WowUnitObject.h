#pragma once

#include "../dump/WowGameDescriptors.h"
#include "WowObject.h"

class WowGame;

class WowUnitObject : public WowObject
{
public:
	WowUnitObject(const uint8_t* baseAddress);

	virtual WowUnitClass getClass() const;

	virtual std::string getClassLabel() const;

	virtual WowUnitRace getRace() const;

	virtual int getLevel() const;

	virtual int getHealth() const;

	virtual int getMaxHealth() const;

	virtual bool isDead() const;
	
	virtual float getHealthPercent() const;

	virtual int getEnergy() const;

	virtual int getMaxEnergy() const;

	virtual bool isInCombat() const;

	virtual bool isLootable() const;
	
	virtual bool isTappedByOther() const;
	
	virtual bool isTappedByMe() const;

	virtual WowGuid128 getSummonedBy() const;

	virtual WowGuid128 getTargetGuid() const;

	virtual const WowGuid128* getTargetGuidPtr() const;

	virtual void moveTo(WowGame& game, const WowVector3f& destination);

	virtual bool evaluateAggroDistanceWith(const WowUnitObject& unit) const;

};

inline std::ostream& operator<<(
	std::ostream& out,
	const WowUnitObject& obj
	)
{
	out << (WowObject)obj
		<< ": [LVL" << obj.getLevel() << "]" << obj.getClassLabel()
		<< ": [SummonedBy Guid = " << obj.getSummonedBy().upper() << obj.getSummonedBy().lower()
		<< " health=" << obj.getHealth() << "/" << obj.getMaxHealth()
		<< " energy=" << obj.getEnergy() << "/" << obj.getMaxEnergy();
	return out;
}

