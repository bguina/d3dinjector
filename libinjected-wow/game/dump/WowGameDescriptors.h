#pragma once

#include <cstdint>

enum class WowObjectType : uint8_t {
	Object = 0,
	Item = 1,
	Container = 2,
	AzeriteEmpoweredItem = 3,
	AzeriteItem = 4,
	Unit = 5,
	Player = 6,
	ActivePlayer = 7,
	GameObject = 8,
	DynamicObject = 9,
	Corpse = 10,
	AreaTrigger = 11,
	Scene = 12,
	Conversation = 13,
	AiGroup = 14,
	Scenario = 15,
	Loot = 16,
	Invalid = 17
};

enum class WowObjectDynamicFlags : uint32_t {
	Invisible = (1 << 0),
	Lootable = (1 << 2), 
	TrackUnit = (1 << 3),
	Tapped = (1 << 4),
	TappedByMe = (1 << 5),
	Dead = (1 << 26),
	ReferAFriendLinked = (1 << 7),
	IsTappedByAllThreatList = (1 << 8),
};

//https://www.ownedcore.com/forums/world-of-warcraft/world-of-warcraft-bots-programs/wow-memory-editing/839080-classic-1-13-3-32887-a.html
//check here for me info about "isTaggedByMe"

enum class WowUnitClass : uint8_t {
	None = 0,
	Warrior = 1,
	Paladin = 2,
	Hunter = 3,
	Rogue = 4,
	Priest = 5,
	DeathKnight = 6,
	Shaman = 7,
	Mage = 8,
	Warlock = 9,
	Druid = 11
};

enum class WowUnitRace : uint8_t {
	None = 0,

};

enum class WowUnitFlags : uint32_t {
	isInCombat = 0x0080000,
};

enum SpellbookSpellFlags : uint32_t {
	IsLearnt = 1,
	Isknown = 2,
};