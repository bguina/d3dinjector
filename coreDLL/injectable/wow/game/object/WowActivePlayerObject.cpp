#include "pch.h"

#include "WowActivePlayerObject.h"
#include "../WowGame.h"

#include "../dump/WowGameOffsets.h"

typedef char(__fastcall ActivePlayerCanAttack)(const uint8_t* self, const uint8_t* target, char unknown);
typedef bool(__fastcall ActivePlayerIsFriendlyWith)(const uint8_t* self, const uint8_t* target);
typedef uint64_t(__fastcall ActivePlayerInteract)(const WowGuid128* pTargetGuid);

WowActivePlayerObject::WowActivePlayerObject(const uint8_t* baseAddr) :
	WowPlayerObject(baseAddr)
{
}

const uint32_t* WowActivePlayerObject::getCamera(const WowGame& game) {
	return game.get<const uint32_t*>(0xD65D60);
}

char WowActivePlayerObject::canAttack(const WowGame& game, const WowUnitObject& target) const {
	return  game.get<ActivePlayerCanAttack>(0x8831E0)(getAddress(), target.getAddress(), 0);
}

bool WowActivePlayerObject::isFriendly(const WowGame& game, const WowUnitObject& target) const {
	return game.get<ActivePlayerIsFriendlyWith>(0x8A0FF0)(getAddress(), target.getAddress());
}

uint64_t  WowActivePlayerObject::interactWith(const WowGame& game, const WowGuid128* targetGuid) {
	return game.get<ActivePlayerInteract>(0xD65D60)(targetGuid);
}
