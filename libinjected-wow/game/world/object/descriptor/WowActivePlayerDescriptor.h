#pragma once

#include "WowPlayerDescriptor.h"

#pragma pack(push, 1)

struct WowActivePlayerDescriptor : WowPlayerDescriptor
{
	WowGuid128 invSlots[124]; // size 496 flags: MIRROR_ALL
	WowGuid128 farsightObject; // size 4 flags: MIRROR_ALL
	WowGuid128 comboTarget; // size 4 flags: MIRROR_ALL
	WowGuid128 summonedBattlePetGuid; // size 4 flags: MIRROR_ALL
	uint32_t knownTitles[12]; // size 12 flags: MIRROR_ALL
	uint32_t coinage[2]; // size 2 flags: MIRROR_ALL
	uint32_t xp; // size 1 flags: MIRROR_ALL
	uint32_t nextLevelXp; // size 1 flags: MIRROR_ALL
	uint32_t trialXp; // size 1 flags: MIRROR_ALL
	uint32_t skill[896]; // size 896 flags: MIRROR_ALL
	uint32_t characterPoints; // size 1 flags: MIRROR_ALL
	uint32_t maxTalentTiers; // size 1 flags: MIRROR_ALL
	uint32_t trackCreatureMask; // size 1 flags: MIRROR_ALL
	uint32_t trackResourceMask[2]; // size 2 flags: MIRROR_ALL
	uint32_t mainhandExpertise; // size 1 flags: MIRROR_ALL
	uint32_t offhandExpertise; // size 1 flags: MIRROR_ALL
	uint32_t rangedExpertise; // size 1 flags: MIRROR_ALL
	uint32_t combatRatingExpertise; // size 1 flags: MIRROR_ALL
	uint32_t blockPercentage; // size 1 flags: MIRROR_ALL
	uint32_t dodgePercentage; // size 1 flags: MIRROR_ALL
	uint32_t dodgePercentageFromAttribute; // size 1 flags: MIRROR_ALL
	uint32_t parryPercentage; // size 1 flags: MIRROR_ALL
	uint32_t parryPercentageFromAttribute; // size 1 flags: MIRROR_ALL
	uint32_t critPercentage; // size 1 flags: MIRROR_ALL
	uint32_t rangedCritPercentage; // size 1 flags: MIRROR_ALL
	uint32_t offhandCritPercentage; // size 1 flags: MIRROR_ALL
	uint32_t spellCritPercentage; // size 1 flags: MIRROR_ALL
	uint32_t shieldBlock; // size 1 flags: MIRROR_ALL
	uint32_t mastery; // size 1 flags: MIRROR_ALL
	uint32_t speed; // size 1 flags: MIRROR_ALL
	uint32_t avoidance; // size 1 flags: MIRROR_ALL
	uint32_t sturdiness; // size 1 flags: MIRROR_ALL
	uint32_t versatility; // size 1 flags: MIRROR_ALL
	uint32_t versatilityBonus; // size 1 flags: MIRROR_ALL
	uint32_t pvpPowerDamage; // size 1 flags: MIRROR_ALL
	uint32_t pvpPowerHealing; // size 1 flags: MIRROR_ALL
	uint32_t exploredZones[320]; // size 320 flags: MIRROR_ALL
	uint32_t restInfo[4]; // size 4 flags: MIRROR_ALL
	uint32_t modDamageDonePos[7]; // size 7 flags: MIRROR_ALL
	uint32_t modDamageDoneNeg[7]; // size 7 flags: MIRROR_ALL
	uint32_t modDamageDonePercent[7]; // size 7 flags: MIRROR_ALL
	uint32_t modHealingDonePos; // size 1 flags: MIRROR_ALL
	uint32_t modHealingPercent; // size 1 flags: MIRROR_ALL
	uint32_t modHealingDonePercent; // size 1 flags: MIRROR_ALL
	uint32_t modPeriodicHealingDonePercent; // size 1 flags: MIRROR_ALL
	uint32_t weaponDmgMultipliers[3]; // size 3 flags: MIRROR_ALL
	uint32_t weaponAtkSpeedMultipliers[3]; // size 3 flags: MIRROR_ALL
	uint32_t modSpellPowerPercent; // size 1 flags: MIRROR_ALL
	uint32_t modResiliencePercent; // size 1 flags: MIRROR_ALL
	uint32_t overrideSpellPowerByApPercent; // size 1 flags: MIRROR_ALL
	uint32_t overrideApBySpellPowerPercent; // size 1 flags: MIRROR_ALL
	uint32_t modTargetResistance; // size 1 flags: MIRROR_ALL
	uint32_t modTargetPhysicalResistance; // size 1 flags: MIRROR_ALL
	uint32_t localFlags; // size 1 flags: MIRROR_ALL
	uint32_t pvpMedals; // size 1 flags: MIRROR_ALL
	uint32_t buybackPrice[12]; // size 12 flags: MIRROR_ALL
	uint32_t buybackTimestamp[12]; // size 12 flags: MIRROR_ALL
	uint32_t sessionDishonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t yesterdayDishonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t lastWeekDishonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t thisWeekDishonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t thisWeekContribution; // size 1 flags: MIRROR_ALL
	uint32_t lifetimeHonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t lifetimeDishonorableKills; // size 1 flags: MIRROR_ALL
	uint32_t yesterdayContribution; // size 1 flags: MIRROR_ALL
	uint32_t lastWeekContribution; // size 1 flags: MIRROR_ALL
	uint32_t lastWeekRank; // size 1 flags: MIRROR_ALL
	uint32_t watchedFactionIndex; // size 1 flags: MIRROR_ALL
	uint32_t combatRatings[32]; // size 32 flags: MIRROR_ALL
	uint32_t pvpInfo[54]; // size 54 flags: MIRROR_ALL
	uint32_t maxLevel; // size 1 flags: MIRROR_ALL
	uint32_t scalingPlayerLevelDelta; // size 1 flags: MIRROR_ALL
	uint32_t maxCreatureScalingLevel; // size 1 flags: MIRROR_ALL
	uint32_t noReagentCostMask[4]; // size 4 flags: MIRROR_ALL
	uint32_t petSpellPower; // size 1 flags: MIRROR_ALL
	uint32_t professionSkillLine[2]; // size 2 flags: MIRROR_ALL
	uint32_t uiHitModifier; // size 1 flags: MIRROR_ALL
	uint32_t uiSpellHitModifier; // size 1 flags: MIRROR_ALL
	uint32_t homeRealmTimeOffset; // size 1 flags: MIRROR_ALL
	uint32_t modPetHaste; // size 1 flags: MIRROR_ALL
	uint32_t numBackpackSlots; // size 1 flags: MIRROR_ALL
	uint32_t overrideSpellsId; // size 1 flags: 
	uint32_t lfgBonusFactionId; // size 1 flags: MIRROR_ALL
	uint32_t lootSpecId; // size 1 flags: MIRROR_ALL
	uint32_t overrideZonePvpType; // size 1 flags: 
	uint32_t bagSlotFlags[4]; // size 4 flags: MIRROR_ALL
	uint32_t bankBagSlotFlags[6]; // size 6 flags: MIRROR_ALL
	uint32_t pvpRankProgress; // size 1 flags: MIRROR_ALL
};

struct CGActivePlayerDynamicDescriptor : WowObjectDescriptor
{
	uint32_t researchSites; // size 1 flags: MIRROR_NONE
	uint32_t researchSiteProgress; // size 1 flags: MIRROR_NONE
	uint32_t dailyQuestsCompleted; // size 1 flags: MIRROR_NONE
	uint32_t availableQuestLineXQuestIds; // size 1 flags: MIRROR_NONE
	uint32_t heirlooms; // size 1 flags: MIRROR_NONE
	uint32_t heirloomFlags; // size 1 flags: MIRROR_NONE
	uint32_t toys; // size 1 flags: MIRROR_NONE
	uint32_t transmog; // size 1 flags: MIRROR_NONE
	uint32_t conditionalTransmog; // size 1 flags: MIRROR_NONE
	uint32_t selfResSpells; // size 1 flags: MIRROR_NONE
	uint32_t characterRestrictions; // size 1 flags: MIRROR_NONE
	uint32_t spellPctModByLabel; // size 1 flags: MIRROR_NONE
	uint32_t spellFlatModByLabel; // size 1 flags: MIRROR_NONE
	uint32_t research; // size 1 flags: MIRROR_NONE
};

#pragma pack(pop)
