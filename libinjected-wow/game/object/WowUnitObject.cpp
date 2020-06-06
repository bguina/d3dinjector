#include "../dump/WowGameOffsets.h"
#include "../WowGame.h"

#include "WowUnitObject.h"

WowUnitObject::WowUnitObject(const uint8_t* baseAddress) :
	WowObject(baseAddress)
{
}

WowUnitClass WowUnitObject::getClass() const {
	return *reinterpret_cast<const WowUnitClass*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetClass);
}

std::string WowUnitObject::getClassLabel() const {
	switch (getClass()) {
	case WowUnitClass::Warrior: return "Warrior";
	case WowUnitClass::Paladin: return "Paladin";
	case WowUnitClass::Hunter: return "Hunter";
	case WowUnitClass::Rogue: return "Rogue";
	case WowUnitClass::Priest: return "Priest";
	case WowUnitClass::DeathKnight: return "DeathKnight";
	case WowUnitClass::Shaman: return "Shaman";
	case WowUnitClass::Mage: return "Mage";
	case WowUnitClass::Warlock: return "Warlock";
	case WowUnitClass::Druid: return "Druid";
	default: return "Unit";
	}
}

WowUnitRace WowUnitObject::getRace() const {
	return *reinterpret_cast<const WowUnitRace*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetRace);
}

int WowUnitObject::getLevel() const {
	return *(getDescriptor() + 0x134);
}

int WowUnitObject::getHealth() const {
	return *reinterpret_cast<const uint32_t*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetHealth);
}

int WowUnitObject::getMaxHealth() const {
	return *reinterpret_cast<const uint32_t*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetMaxHealth);
}

float WowUnitObject::getHealthPercent() const {
	uint32_t currentHealth = *reinterpret_cast<const uint32_t*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetHealth);
	uint32_t maxHealth = *reinterpret_cast<const uint32_t*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetMaxHealth);
	return (currentHealth * 100.00f / maxHealth);
}

bool WowUnitObject::isDead() const {
	return 1 > getHealth();
}

int WowUnitObject::getEnergy() const {
	return *reinterpret_cast<const uint32_t*>(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetEnergy);
}

int WowUnitObject::getMaxEnergy() const {
	return *reinterpret_cast<const uint32_t*>((getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetMaxEnergy));
}

bool WowUnitObject::isInCombat() const {
	return *reinterpret_cast<const uint32_t*>((getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetUnitDynamicflags)) & uint32_t(WowUnitDynamicFlags::isInCombat);
}

bool WowUnitObject::isLootable() const {
	return *reinterpret_cast<const uint32_t*>((getDescriptor() + WowGameOffsets::WowObject::DescriptorOffsetObjectDynamicflags)) & uint32_t(WowObjectDynamicFlags::Lootable);
}

bool WowUnitObject::isTappedByOther() const
{
	return *reinterpret_cast<const uint32_t*>((getDescriptor() + WowGameOffsets::WowObject::DescriptorOffsetObjectDynamicflags)) & uint32_t(WowObjectDynamicFlags::Tapped);
}

bool WowUnitObject::isTappedByMe() const
{
	return *reinterpret_cast<const uint32_t*>((getDescriptor() + WowGameOffsets::WowObject::DescriptorOffsetObjectDynamicflags)) & (uint32_t(WowObjectDynamicFlags::Lootable) | uint32_t(WowObjectDynamicFlags::TappedByMe));
}

WowGuid128  WowUnitObject::getSummonedBy() const {
	return ((WowGuid128*)(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetSummonedBy))[0];
}

WowGuid128 WowUnitObject::getTargetGuid() const {
	return ((WowGuid128*)(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetTargetGuid))[0];
}

const WowGuid128* WowUnitObject::getTargetGuidPtr() const {
	return ((WowGuid128*)(getDescriptor() + WowGameOffsets::WowUnitObject::DescriptorOffsetTargetGuid));
}

void WowUnitObject::moveTo(WowGame& game, const WowVector3f& destination) {
	int delta = getPosition().getFacingDeltaDegrees(getFacingDegrees(), destination);
	int anglePrecision = 10;

	auto windowController = game.getWindowController();

	windowController->pressKey(WinVirtualKey::WVK_A, delta > anglePrecision);
	windowController->pressKey(WinVirtualKey::WVK_D, delta < -anglePrecision);
	// move forward if approximately on the right facing
	windowController->pressKey(WinVirtualKey::WVK_W, abs(delta) < anglePrecision * 2);
}

bool WowUnitObject::evaluateAggroDistanceWith(const WowUnitObject& unit) const
{
	auto levelDifference(getLevel() - unit.getLevel());
	
	// https://wowwiki.fandom.com/wiki/Aggro_radius
	return 22 + (levelDifference * 1.0f);
}
