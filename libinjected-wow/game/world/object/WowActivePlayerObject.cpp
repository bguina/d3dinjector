
#include "WowActivePlayerObject.h"
#include "../../WowGame.h"

#include "../../dump/WowGameOffsets.h"
#include "descriptor/WowActivePlayerDescriptor.h"

WowActivePlayerObject::WowActivePlayerObject(const WowObjectStruct* baseAddress, WowGame& game) :
	WowPlayerObject(baseAddress, game)
{
}

bool WowActivePlayerObject::canAttack(const WowUnitObject& target) const {
	typedef char(__fastcall ActivePlayerCanAttack)(const uint8_t* self, const uint8_t* unit, char unknown);
	return mGame.getFunction<ActivePlayerCanAttack>(WowGameOffsets::FunctionUnit_CanAttack)(getAddress(), target.getAddress(), 0);
}

bool WowActivePlayerObject::isFriendly(const WowUnitObject& target) const {
	typedef bool(__fastcall ActivePlayerIsFriendlyWith)(const uint8_t* self, const uint8_t* unit);
	return mGame.getFunction<ActivePlayerIsFriendlyWith>(WowGameOffsets::FunctionUnit_IsFriendly)(getAddress(), target.getAddress());
}

bool WowActivePlayerObject::jump()
{
	mGame.getWindowController()->pressKey(WinVirtualKey::WVK_SPACE, true);
	mGame.getWindowController()->pressKey(WinVirtualKey::WVK_SPACE, false);
	return true;
}

bool WowActivePlayerObject::sitDown()
{
	mGame.getWindowController()->pressKey(WinVirtualKey::WVK_X, true);
	mGame.getWindowController()->pressKey(WinVirtualKey::WVK_X, false);
	return true;
}

uint64_t WowActivePlayerObject::interactWith(const WowGuid128* targetGuid) {
	typedef uint64_t(__fastcall ActivePlayerInteract)(const WowGuid128* pTargetGuid);
	return mGame.getFunction<ActivePlayerInteract>(WowGameOffsets::FunctionUnit_Interact)(targetGuid);
}

const WowActivePlayerDescriptor& WowActivePlayerObject::getActivePlayerData() const
{
	return getDescriptorData<WowActivePlayerDescriptor>();
}

const CGActivePlayerDynamicDescriptor& WowActivePlayerObject::getActivePlayerDynamicData() const
{
	return getDescriptorData<CGActivePlayerDynamicDescriptor>();
}
