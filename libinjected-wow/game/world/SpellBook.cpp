
#include "SpellBook.h"
#include "../WowGame.h"
#include "../dump/WowGameOffsets.h"

SpellBook::SpellBook(const uint8_t* baseAddress) :
	mPointerAddress(baseAddress)
{
}

bool SpellBook::isKnown(int spellId) const
{
	const auto* const spell = getSpell(spellId);
	return nullptr != spell && spell->flags & Isknown;
}

bool SpellBook::isLearnt(int spellId) const
{
	const auto* const spell = getSpell(spellId);
	return nullptr != spell && spell->flags & IsLearnt;
}

int64_t SpellBook::getSpellCooldown(const WowGame& game, int spellId) const
{
	using SpellGetSpellCooldown = bool(__fastcall)(unsigned int idx, unsigned int someBool, int a3Flags, int64_t* pResDuration, int64_t* pResStart, int64_t* a60, int32_t* a70, uint64_t* a8, int32_t* aNullable);
	int64_t start = 0;
	int64_t duration = 0;
	uint64_t someRes(0);
	const auto res(game.getFunction<SpellGetSpellCooldown>(WowGameOffsets::FunctionSpell_GetSpellCooldown)(spellId, false, 0, &duration, &start, nullptr, nullptr, &someRes, nullptr));

	return res;
}

bool SpellBook::castSpell(const WowGame& game, const uint32_t spellId, const uint128_t* target)
{
	using SpellBookCastSpell = void(__fastcall)(int spell, int itemId, const uint128_t* pGuid128, unsigned __int8 isTrade, char padArg);
	const auto spellIdx(getSpellIndex(spellId));

	if (spellIdx < 0) return false;
	game.getFunction<SpellBookCastSpell>(WowGameOffsets::FunctionSpellBook_CastSpell)(spellIdx, 0, target, 0, 0);
	return true;
}

const SpellbookDescriptor* const* SpellBook::getSpellArray() const
{
	return *(SpellbookDescriptor***)(mPointerAddress - 0x20);;
}

int SpellBook::getSpellIndex(uint32_t spellId) const
{
	const auto* const ptrArray = getSpellArray();
	const auto totalSpell = (int)getSpellBookCount();

	for (auto i = 0; ptrArray && i < totalSpell; i++) {
		const auto* entry = ptrArray[i];

		if (nullptr == entry || (uint64_t)entry & 1)
			break;

		if (entry->id == spellId)
			return i;
	}
	return -1;
}

const SpellbookDescriptor* SpellBook::getSpell(const uint32_t spellId) const
{
	const auto spellIdx(getSpellIndex(spellId));

	if (spellIdx < 0) return nullptr;
	return getSpellArray()[spellIdx];
}


uint64_t* SpellBook::petInfoFindSpellById(const WowGame& game, const uint32_t petSpellId)
{
	typedef uint64_t* (__fastcall PetInfo_FindSpellById)(uint32_t spellId);

	return game.getFunction<PetInfo_FindSpellById>(WowGameOffsets::FunctionPetInfo_FindSpellById)(petSpellId);
}

void SpellBook::petInfoSendPetAction(const WowGame& game, uint64_t* spell, const WowGuid128* target)
{
	typedef void(__fastcall PetInfo_SendPetAction)(uint64_t* spell, const WowGuid128* target, uint32_t unknown, uint128_t* unkwown2);
	uint128_t tmp = 0;
	return game.getFunction<PetInfo_SendPetAction>(WowGameOffsets::FunctionPetInfo_SendPetAction)(spell, target, 0, &tmp);
}

//This function is a tool to find the Pet Attack Spell
// - Search spell by 0 -> Get the ptr of the end of the pet spellbook array
// - Iterate back by 0x04 until we can find the spell id 2 which match with the Pet Attack (store as a short at the beginning)
bool SpellBook::orderPetToAttackTarget(const WowGame& game, const WowGuid128* target)
{
	uint64_t* ptrTmp = petInfoFindSpellById(game, 0);

	bool found = false;
	while (*(uint16_t*)ptrTmp != 2)
	{
		ptrTmp = (uint64_t*)((uint8_t*)ptrTmp - 0x04);
		found = true;
	}
	//mDbg << FileLogger::info << "[Spell Pet Attack at : " << ptrTmp << " id == " << 0 << FileLogger::normal << std::endl;
	//mDbg << FileLogger::info << "[Spell Pet Attack at : " << ptrTmp - 0x14 << " id == " << 0 << FileLogger::normal << std::endl;
	if (found)
	{
		petInfoSendPetAction(game, ptrTmp, target);
	}
	return found;

}

uint32_t SpellBook::getSpellBookCount() const
{
	return *(uint32_t*)(mPointerAddress - 0x28);
}
