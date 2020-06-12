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

	enum NpcFlags
	{
		Gossip = (1 << 0),
		Quest = (1 << 1),
		Taxi = (1 << 3),
		Trainer = (1 << 4), // todo wrong? outdated? test me
		Healer = (1 << 5),
		Vendor = (1 << 7),
		GuildMaster = (1 << 9),
		TabardDesigner = (1 << 11),
		//Petition = (1 << 11),
		BattleMaster = (1 << 11),
		Innkeeper = (1 << 16),
		Banker = (1 << 17),
		Repairer = (1 << 18),
		Auctioneer = (1 << 21),
		StableMaster = (1 << 22),
	};
	virtual uint64_t getNpcFlags() const;
	virtual std::string getNpcFlagsLabel() const;

	virtual bool isNpcTrader() const;

	virtual float getHealthPercent() const;

	virtual int getEnergy() const;

	virtual int getMaxEnergy() const;

	virtual bool isInCombat() const;

	virtual const uint32_t* getRawFlags() const;
	virtual const uint32_t* getRawPower() const;
	virtual WowAura* getRawAuraByIndex(int index) const;
	
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

