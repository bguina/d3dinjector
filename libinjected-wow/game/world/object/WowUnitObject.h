#pragma once

#include "../../dump/WowGameDescriptors.h"
#include "WowObject.h"
#include "descriptor/WowUnitAura.h"
#include "descriptor/WowUnitDescriptor.h"

class WowGame;

class WowUnitObject : public WowObject
{
public:
	WowUnitObject(const WowObjectStruct* baseAddress, WowGame& game);

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
	
	virtual WowAura* getAuraByIndex(int index) const;
	virtual bool hasAura(unsigned int spellId) const;

	virtual WowGuid128 getSummonedBy() const;

	virtual const WowGuid128* getTargetGuid() const;

	virtual void moveTo(WowGame& game, const WowVector3f& destination);

	virtual float evaluateAggroDistanceWith(const WowUnitObject& unit) const;
	
	const WowUnitDescriptor& getUnitData() const;
	const WowUnitDynamicData& getUnitDynamicData() const;

protected:
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

