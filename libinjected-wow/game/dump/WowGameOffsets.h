#pragma once

#include <cstdint>

struct WowGameOffsets {
	struct WowGame {
		static const uint64_t OffsetCameraBase = 0x2595A80;

		static const uint64_t FunctionFrameScript_ExecuteBuffer = 0x31F580;

	};

	struct WowCamera {
		static const uint64_t OffsetCameraBase = 0x2595A80;
	};

	struct WowObjectManager {
		static const uint64_t OffsetObjectManagerBase = 0x238BD08;
		static const uint64_t OffsetFirstObject = 0x18;
		static const uint64_t OffsetNextObject = 0x70;
	};

	struct WowObject {
		static const uint64_t OffsetDescriptorPointer = 0x10;
		static const uint64_t OffsetType = 0x20;
		static const uint64_t OffsetGuid = 0x58;
		static const uint64_t OffsetPosition = 0x1600;
		static const uint64_t OffsetFacing = 0x1610;
		static const uint64_t DescriptorOffsetObjectDynamicflags = 0x14;
	};

	struct WowUnitObject {
		static const uint64_t DescriptorOffsetClass = 0xD1;
		static const uint64_t DescriptorOffsetRace = 0x158;
		static const uint64_t DescriptorOffsetLevel = 0x134;
		static const uint64_t DescriptorOffsetHealth = 0xDC;
		static const uint64_t DescriptorOffsetMaxHealth = 0xFC;
		static const uint64_t DescriptorOffsetEnergy = 0xE4;
		static const uint64_t DescriptorOffsetMaxEnergy = 0x104;
		static const uint64_t DescriptorOffsetTargetGuid = 0x9C;
		static const uint64_t DescriptorOffsetSummonedBy = 0x5C;
		static const uint64_t DescriptorOffsetUnitDynamicflags = 0x174;
	};

	struct WowSpellBook {
		static const uint64_t OffsetSpellBookBase = 0x25AED38;
		static const uint64_t FunctionCastSpell =  0xDC95C0;
		static const uint64_t FunctionClickSpell = 0x76DC00;
	};
};
