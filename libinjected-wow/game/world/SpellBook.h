#pragma once

#include <cstdint>
#include <iostream>

#include "object/WowGuid128.h"

class WowGame;

struct SpellbookDescriptor {
	uint32_t flags;
	uint32_t id;
};

class SpellBook
{
public:
	SpellBook(const uint8_t* baseAddress);

	bool isKnown(int spellId) const;
	bool isLearnt(int spellId) const;

	int64_t getSpellCooldown(const WowGame& game, int spellId) const;

	bool castSpell(const WowGame& game, const uint32_t spellId, const uint128_t* target);
	uint64_t* petInfoFindSpellById(const WowGame& game, const uint32_t petSpellId);
	void petInfoSendPetAction(const WowGame& game, uint64_t* spell, const WowGuid128* target);
	bool orderPetToAttackTarget(const WowGame& game, const WowGuid128* target);

private:
	const SpellbookDescriptor* const* getSpellArray() const;
	int getSpellIndex(uint32_t spellId) const;
	const SpellbookDescriptor* getSpell(uint32_t spellId) const;

	uint32_t getSpellBookCount() const;
	const uint8_t* mPointerAddress;
};


inline std::ostream& operator<<(
	std::ostream& out,
	const SpellBook& spellBookMgr
	)
{
	out << "[SpellBook@]" << std::endl;

	return out;
}

