#pragma once

#include "WowObjectDescriptor.h"

#pragma pack(push, 1)

//https://www.ownedcore.com/forums/world-of-warcraft/world-of-warcraft-bots-programs/wow-memory-editing/839080-classic-1-13-3-32887-a.html
// Jadd's answer
struct WowUnitDescriptor : WowObjectDescriptor	// = 0x1C
{
	uint32_t charm[4]; // size 4 flags: MIRROR_ALL
	uint32_t summon[4]; // size 4 flags: MIRROR_ALL
	uint32_t critter[4]; // size 4 flags: MIRROR_SELF
	WowGuid128 charmedBy; // size 4 flags: MIRROR_ALL
	WowGuid128 summonedBy; // 0x5C size 4 flags: MIRROR_ALL
	WowGuid128 createdBy; // size 4 flags: MIRROR_ALL
	WowGuid128 demonCreator; // size 4 flags: MIRROR_ALL
	WowGuid128 lookAtControllerTarget; // size 4 flags: MIRROR_ALL
	WowGuid128 target; // 0x9C size 4 flags: MIRROR_ALL
	WowGuid128 battlePetCompanionGuid; // size 4 flags: MIRROR_ALL
	uint64_t battlePetDatabaseId; // size 2 flags: MIRROR_ALL
	uint32_t channelData[2]; // size 2 flags: 
	uint32_t summonedByHomeRealm; // size 1 flags: MIRROR_ALL
	uint8_t race; // size 1 flags: MIRROR_ALL
	uint8_t classId; // size 1 flags: MIRROR_ALL
	uint8_t playerClassId; // size 1 flags: MIRROR_ALL
	uint8_t sex; // size 1 flags: MIRROR_ALL
	uint32_t displayPower; // size 1 flags: MIRROR_ALL
	uint32_t overrideDisplayPowerId; // size 1 flags: MIRROR_ALL
	uint64_t health; // size 2 flags: MIRROR_VIEWER_DEPENDENT
	uint64_t power[3]; // size 6 flags: 
	uint64_t maxHealth; // size 2 flags: MIRROR_VIEWER_DEPENDENT  // 0xFC ?
	uint64_t maxPower[3]; // size 6 flags: MIRROR_ALL
	uint64_t modPowerRegen[3]; // size 6 flags: 
	uint32_t level; // size 1 flags: MIRROR_ALL
	uint32_t effectiveLevel; // size 1 flags: MIRROR_ALL
	uint32_t contentTuningId; // size 1 flags: MIRROR_ALL
	uint32_t scalingLevelMin; // size 1 flags: MIRROR_ALL
	uint32_t scalingLevelMax; // size 1 flags: MIRROR_ALL
	uint32_t scalingLevelDelta; // size 1 flags: MIRROR_ALL
	uint32_t scalingFactionGroup; // size 1 flags: MIRROR_ALL
	uint32_t scalingHealthItemLevelCurveId; // size 1 flags: MIRROR_ALL
	uint32_t scalingDamageItemLevelCurveId; // size 1 flags: MIRROR_ALL
	uint32_t factionTemplate; // size 1 flags: MIRROR_ALL
	uint32_t virtualItems[6]; // size 6 flags: MIRROR_ALL
	uint32_t flags; // size 1 flags: 
	uint32_t flags2; // size 1 flags: 
	uint32_t flags3; // size 1 flags: 
	uint32_t auraState; // size 1 flags: MIRROR_ALL
	uint32_t attackRoundBaseTime[2]; // size 2 flags: MIRROR_ALL
	uint32_t rangedAttackRoundBaseTime; // size 1 flags: MIRROR_SELF
	uint32_t boundingRadius; // size 1 flags: MIRROR_ALL
	uint32_t combatReach; // size 1 flags: MIRROR_ALL
	uint32_t displayId; // size 1 flags: 
	uint32_t displayScale; // size 1 flags: 
	uint32_t nativeDisplayId; // size 1 flags: 
	uint32_t nativeXDisplayScale; // size 1 flags: 
	uint32_t mountDisplayId; // size 1 flags: 
	uint32_t minDamage; // size 1 flags: 
	uint32_t maxDamage; // size 1 flags: 
	uint32_t minOffHandDamage; // size 1 flags: 
	uint32_t maxOffHandDamage; // size 1 flags: 
	uint32_t animTier; // size 1 flags: MIRROR_ALL
	uint32_t petNumber; // size 1 flags: MIRROR_ALL
	uint32_t petNameTimestamp; // size 1 flags: MIRROR_ALL
	uint32_t petExperience; // size 1 flags: MIRROR_OWNER
	uint32_t petNextLevelExperience; // size 1 flags: MIRROR_OWNER
	uint32_t modCastingSpeed; // size 1 flags: MIRROR_ALL
	uint32_t modSpellHaste; // size 1 flags: MIRROR_ALL
	uint32_t modHaste; // size 1 flags: MIRROR_ALL
	uint32_t modRangedHaste; // size 1 flags: MIRROR_ALL
	uint32_t modHasteRegen; // size 1 flags: MIRROR_ALL
	uint32_t modTimeRate; // size 1 flags: MIRROR_ALL
	uint32_t createdBySpell; // size 1 flags: MIRROR_ALL
	uint64_t npcFlags; // size 2 flags:							// 0x1EC	CGUnitData::npcFlags
	uint32_t emoteState; // size 1 flags: MIRROR_ALL
	uint32_t trainingPointsTotal; // size 1 flags: MIRROR_OWNER
	uint32_t stats[5]; // size 5 flags: 
	uint32_t statPosBuff[5]; // size 5 flags: 
	uint32_t statNegBuff[5]; // size 5 flags: 
	uint32_t resistances[7]; // size 7 flags: 
	uint32_t resistanceBuffModsPositive[7]; // size 7 flags: 
	uint32_t resistanceBuffModsNegative[7]; // size 7 flags: 
	uint32_t baseMana; // size 1 flags: MIRROR_ALL
	uint32_t baseHealth; // size 1 flags: 
	uint32_t shapeshiftForm; // size 1 flags: MIRROR_ALL
	uint32_t attackPower; // size 1 flags: 
	uint32_t attackPowerModPos; // size 1 flags: 
	uint32_t attackPowerModNeg; // size 1 flags: 
	uint32_t attackPowerMultiplier; // size 1 flags: 
	uint32_t rangedAttackPower; // size 1 flags: 
	uint32_t rangedAttackPowerModPos; // size 1 flags: 
	uint32_t rangedAttackPowerModNeg; // size 1 flags: 
	uint32_t rangedAttackPowerMultiplier; // size 1 flags: 
	uint32_t mainHandWeaponAttackPower; // size 1 flags: 
	uint32_t offHandWeaponAttackPower; // size 1 flags: 
	uint32_t rangedWeaponAttackPower; // size 1 flags: 
	uint32_t setAttackSpeedAura; // size 1 flags: 
	uint32_t lifesteal; // size 1 flags: 
	uint32_t minRangedDamage; // size 1 flags: 
	uint32_t maxRangedDamage; // size 1 flags: 
	uint32_t powerCostModifier[7]; // size 7 flags: 
	uint32_t powerCostMultiplier[7]; // size 7 flags: 
	uint32_t maxHealthModifier; // size 1 flags: 
	uint32_t hoverHeight; // size 1 flags: MIRROR_ALL
	uint32_t minItemLevelCutoff; // size 1 flags: MIRROR_ALL
	uint32_t minItemLevel; // size 1 flags: MIRROR_ALL
	uint32_t maxItemLevel; // size 1 flags: MIRROR_ALL
	uint32_t wildBattlePetLevel; // size 1 flags: MIRROR_ALL
	uint32_t battlePetCompanionNameTimestamp; // size 1 flags: MIRROR_ALL
	uint32_t interactSpellId; // size 1 flags: MIRROR_ALL
	uint32_t stateSpellVisualId; // size 1 flags: 
	uint32_t stateAnimId; // size 1 flags: 
	uint32_t stateAnimKitId; // size 1 flags: 
	uint32_t stateWorldEffectId[4]; // size 4 flags: 
	uint32_t scaleDuration; // size 1 flags: MIRROR_ALL
	uint32_t looksLikeMountId; // size 1 flags: MIRROR_ALL
	uint32_t looksLikeCreatureId; // size 1 flags: MIRROR_ALL
	uint32_t lookAtControllerId; // size 1 flags: MIRROR_ALL
	WowGuid128 guildGuid; // size 4 flags: MIRROR_ALL
};

struct WowUnitDynamicData : WowObjectDescriptor
{
	uint32_t passiveSpells[513]; // size 513 flags: MIRROR_NONE
	uint32_t worldEffects[513]; // size 513 flags: MIRROR_NONE
	uint32_t channelObjects[513]; // size 513 flags: MIRROR_NONE
};

#pragma pack(pop)
