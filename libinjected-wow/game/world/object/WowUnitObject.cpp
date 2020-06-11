
#include "WowUnitObject.h"
#include "../../dump/WowGameOffsets.h"
#include "../../WowGame.h"
#include "windowcontroller/WinVirtualKey.h"

WowUnitObject::WowUnitObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowObject(baseAddress, game)
{
}

WowUnitClass WowUnitObject::getClass() const
{
	return (WowUnitClass)getUnitData().classId;
}

std::string WowUnitObject::getClassLabel() const
{
	switch (getClass())
	{
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
	default:;
	}
	return "";
}

WowUnitRace WowUnitObject::getRace() const
{
	return (WowUnitRace)getUnitData().race;
}

int WowUnitObject::getLevel() const
{
	return getUnitData().level;
}

int WowUnitObject::getHealth() const
{
	return getUnitData().health;
}

int WowUnitObject::getMaxHealth() const
{
	return getUnitData().maxHealth;
}

float WowUnitObject::getHealthPercent() const
{
	return getHealth() * 100.00f / getMaxHealth();
}

bool WowUnitObject::isDead() const
{
	return *reinterpret_cast<const uint32_t*>((getDynamicDataAddress() + WowGameOffsets::WowObject::DescriptorOffsetObjectDynamicflags)) & uint32_t(WowObjectDynamicFlags::Dead);
}

uint64_t WowUnitObject::getNpcFlags() const
{
	return getUnitData().npcFlags;
}

std::string WowUnitObject::getNpcFlagsLabel() const
{
	std::stringstream ss;
	const auto flags(getNpcFlags());

	ss << "[";
	if (flags & Gossip) ss << "Gossip";
	if (flags & Quest) ss << "Quest";
	if (flags & Vendor) ss << "Vendor";
	if (flags & Taxi) ss << "Taxi";
	if (flags & Trainer) ss << "Trainer";
	if (flags & Healer) ss << "Healer";
	if (flags & Innkeeper) ss << "Innkeeper";
	if (flags & Banker) ss << "Banker";
	if (flags & GuildMaster) ss << "GuildMaster";
	if (flags & TabardDesigner) ss << "TabardDesigner";
	//if (flags & Petition) ss << "Petition";
	if (flags & BattleMaster) ss << "BattleMaster";
	if (flags & Auctioneer) ss << "Auctioneer";
	if (flags & StableMaster) ss << "StableMaster";
	if (flags & Repairer) ss << "Repairer";
	ss << "]";
	return ss.str();
}

bool WowUnitObject::isNpcTrader() const
{
	return getNpcFlags() & (Vendor | Repairer);
}

int WowUnitObject::getEnergy() const
{
	return *reinterpret_cast<const uint32_t*>(getDynamicDataAddress() + WowGameOffsets::WowUnitObject::DescriptorOffsetEnergy);
}

int WowUnitObject::getMaxEnergy() const
{
	return *reinterpret_cast<const uint32_t*>((getDynamicDataAddress() + WowGameOffsets::WowUnitObject::DescriptorOffsetMaxEnergy));
}

bool WowUnitObject::isInCombat() const
{
	return *reinterpret_cast<const uint32_t*>((getDynamicDataAddress() + WowGameOffsets::WowUnitObject::DescriptorOffsetUnitDynamicflags)) & uint32_t(WowUnitDynamicFlags::isInCombat);
}

WowAura* WowUnitObject::getAuraByIndex(const int index) const
{
	typedef WowAura* (__fastcall UnitGetAuraByIndex)(const uint8_t* self, uint32_t idx);
	return mGame.getFunction<UnitGetAuraByIndex>(0x7625E0)(getAddress(), index);
}

bool WowUnitObject::hasAura(const unsigned int spellId) const
{
	for (auto i = 0; ; ++i)
	{
		auto* aura = getAuraByIndex(i);
		if (nullptr == aura) break;
		if (spellId == aura->spellId) return true;
	}
	return false;
}

WowGuid128  WowUnitObject::getSummonedBy() const
{
	return *(WowGuid128*)(getDynamicDataAddress() + WowGameOffsets::WowUnitObject::DescriptorOffsetSummonedBy);
}

const WowGuid128* WowUnitObject::getTargetGuid() const
{
	return (WowGuid128*)(getDynamicDataAddress() + WowGameOffsets::WowUnitObject::DescriptorOffsetTargetGuid);
}

void WowUnitObject::moveTo(WowGame& game, const WowVector3f& destination)
{
	const auto delta = getPosition().getFacingDeltaDegrees(getFacingDegrees(), destination);
	const auto anglePrecision = 10;

	auto* windowController = game.getWindowController();

	windowController->pressKey(WinVirtualKey::WVK_A, delta > anglePrecision);
	windowController->pressKey(WinVirtualKey::WVK_D, delta < -anglePrecision);
	// move forward if approximately on the right facing
	windowController->pressKey(WinVirtualKey::WVK_W, abs(delta) < anglePrecision * 2);
}

float WowUnitObject::evaluateAggroDistanceWith(const WowUnitObject& unit) const
{
	const auto levelDifference(getLevel() - unit.getLevel());

	// https://wowwiki.fandom.com/wiki/Aggro_radius
	return 22 + (levelDifference * 1.0f);
}

const WowUnitDescriptor& WowUnitObject::getUnitData() const
{
	return getDescriptorData<WowUnitDescriptor>();
}

const WowUnitDynamicData& WowUnitObject::getUnitDynamicData() const
{
	return getDescriptorData<WowUnitDynamicData>();
}
