#pragma once

#include <cstdint>

struct WowGameOffsets {
		static const uint64_t OffsetBuildVersion = 0x1C453EC;
		static const uint64_t OffsetReleaseDate = 0x1C453F8;
		static const uint64_t OffsetVersion = 0x1C453E4;
		static const uint64_t OffsetInGameFlags = 0x25ADF00;
		static const uint64_t OffsetIsLoadingOrConnecting = 0x2279D30;
		
		static const uint64_t OffsetCameraBase = 0x25AEA40;
		static const uint64_t OffsetSpellBookBase = 0x25AED38;
		static const uint64_t OffsetNameCacheBase = 0x1FB4B18;
		
		static const uint64_t FunctionFrameTime_GetCurTimeMs = 0x2A5CB0;
		
		static const uint64_t FunctionFrameScript_ExecuteBuffer = 0x31F360;	// uint64_t(__fastcall FrameScript_ExecuteBuffer)(const char* script, const char* script, uint64_t arg0)
		
		static const uint64_t FunctionUnit_Interact = 0xD72750;				// uint64_t(__fastcall ActivePlayerInteract)(const WowGuid128* pTargetGuid)
		static const uint64_t FunctionUnit_CanAttack = 0x889740;
		static const uint64_t FunctionUnit_IsFriendly = 0x8A7490;
		
		static const uint64_t FunctionPetInfo_FindSpellById = 0xF03B20;
		static const uint64_t FunctionPetInfo_SendPetAction = 0xF14330;
		static const uint64_t FunctionSpellBook_CastSpell = 0xDC95C0;		// void(__fastcall) (int spellId, int itemId, const uint128_t* targetGuid, unsigned __int8 isTrade, char padArg0)
		//static const uint64_t FunctionSpell_ClickSpell = 0x76DC00;		// unused see CastSpell
		static const uint64_t FunctionSpell_GetSpellCooldown = 0x774520;	// todo
		static const uint64_t FunctionSpellDBGetRow = 0x190AF60;			// __int64 (__fastcall)(unsigned int spellId)
		
		static const uint64_t FunctionWorldFrame_Intersect = 0x1158A00;		// uint32_t(__fastcall)(const float* end, const float* start, float* result, const float* distance1, uint32_t flags, uint32_t opt0)

	struct WowObjectManager {
		static const uint64_t OffsetObjectManagerBase = 0x238BD08;
		static const uint64_t OffsetFirstObject = 0x18;
	};

	struct WowObject {
		static const uint64_t DescriptorOffsetObjectDynamicflags = 0x14;
	};

	struct WowUnitObject {
		static const uint64_t DescriptorOffsetSummonedBy = 0x5C;
		static const uint64_t DescriptorOffsetTargetGuid = 0x9C;
		static const uint64_t DescriptorOffsetClass = 0xD1;
		static const uint64_t DescriptorOffsetHealth = 0xDC;
		static const uint64_t DescriptorOffsetEnergy = 0xE4;
		static const uint64_t DescriptorOffsetMaxHealth = 0xFC;
		
		static const uint64_t DescriptorOffsetMaxEnergy = 0x104;
		
		static const uint64_t DescriptorOffsetLevel = 0x134;
		static const uint64_t DescriptorOffsetRace = 0x158;
		static const uint64_t DescriptorOffsetUnitDynamicflags = 0x174;

	};
};
