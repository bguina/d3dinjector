
#include "WowActivePlayerObject.h"
#include "../WowGame.h"

#include "../dump/WowGameOffsets.h"
#include "descriptor/WowActivePlayerDescriptor.h"

WowActivePlayerObject::WowActivePlayerObject(const uint8_t* baseAddress) :
	WowPlayerObject(baseAddress)
{
}

bool WowActivePlayerObject::canAttack(const WowGame& game, const WowUnitObject& target) const {
	typedef char(__fastcall ActivePlayerCanAttack)(const uint8_t* self, const uint8_t* target, char unknown);
	return game.getFunction<ActivePlayerCanAttack>(WowGameOffsets::WowGame::FunctionUnit_CanAttack)(getAddress(), target.getAddress(), 0);
}

bool WowActivePlayerObject::isFriendly(const WowGame& game, const WowUnitObject& target) const {
	typedef bool(__fastcall ActivePlayerIsFriendlyWith)(const uint8_t* self, const uint8_t* target);
	return game.getFunction<ActivePlayerIsFriendlyWith>(WowGameOffsets::WowGame::FunctionUnit_IsFriendly)(getAddress(), target.getAddress());
}

uint64_t WowActivePlayerObject::interactWith(const WowGame& game, const WowGuid128* targetGuid) {
	typedef uint64_t(__fastcall ActivePlayerInteract)(const WowGuid128* pTargetGuid);
	return game.getFunction<ActivePlayerInteract>(WowGameOffsets::WowGame::FunctionUnit_Interact)(targetGuid);
}

const WowActivePlayerDescriptor& WowActivePlayerObject::getActivePlayerData() const
{
	return get<WowActivePlayerDescriptor>();
}

const CGActivePlayerDynamicDescriptor& WowActivePlayerObject::getActivePlayerDynamicData() const
{
	return getDynamicData<CGActivePlayerDynamicDescriptor>();
}
