#include "../../dump/WowGameDescriptors.h"
#include "../../dump/WowGameOffsets.h"

#include "WowObject.h"

WowObject::WowObject(const WowObjectStruct* baseAddress, WowGame& game) :
	MemoryObject<WowObjectStruct>(baseAddress),
	mGame(game)
{
}

bool WowObject::vanished() const
{
	return nullptr == getAddress();
}

const WowGuid128* WowObject::getGuid() const
{
	return &get().guid;
}

uint32_t WowObject::getDynamicFlags() const
{
	return getObjectData().dynamicFlags;
}

//		StorageField = 0x10,//good-33526
//		ObjectType = 0x20,//good-33526
//		NextObject = 0x70,//good-33526
//		FirstObject = 0x18,//good-33526
//		LocalGUID = 0x58, //good-33526

WowObjectType WowObject::getType() const
{
	return get().type;
}

std::string WowObject::getTypeLabel() const
{
	switch (getType()) {
	case WowObjectType::Object:return  "Object";
	case WowObjectType::Item:return "Item";
	case WowObjectType::Container:return  "Container";
	case WowObjectType::AzeriteEmpoweredItem: return "AzeriteEmpoweredItem";
	case WowObjectType::AzeriteItem: return "AzeriteItem";
	case WowObjectType::Unit:return  "Unit";
	case WowObjectType::Player:return  "Player";
	case WowObjectType::ActivePlayer:return  "ActivePlayer";
	case WowObjectType::GameObject:return  "GameObject";
	case WowObjectType::DynamicObject: return "DynamicObject";
	case WowObjectType::Corpse:return  "Corpse";
	case WowObjectType::AreaTrigger: return "AreaTrigger";
	case WowObjectType::Scene:return  "Scene";
	case WowObjectType::Conversation: return  "Conversation";
	case WowObjectType::AiGroup: return  "AiGroup";
	case WowObjectType::Scenario: return  "Scenario";
	case WowObjectType::Loot: return  "Loot";
	case WowObjectType::Invalid: return  "Invalid";
	default: return "Unknown";
	}
}

const WowVector3f& WowObject::getPosition() const
{
	return get().position;
}

float WowObject::getX() const
{
	return getPosition().position.x;
}

float WowObject::getY() const
{
	return getPosition().position.y;
}

float WowObject::getZ() const
{
	return getPosition().position.z;
}

float WowObject::getFacingRadians() const
{
	return get().facing;
}

int WowObject::getFacingDegrees() const
{
	return (int)(getFacingRadians() * 180 / PI);
}

// Position shortcuts
float WowObject::getDistanceTo(const WowObject& object) const
{
	return getPosition().getDistanceTo(object.getPosition());
}

float WowObject::getFlightDistanceTo(const WowObject& object) const
{
	return getPosition().getFlightDistanceTo(object.getPosition());
}

int WowObject::getFacingDegreesTo(const WowObject& object) const
{
	return getPosition().getFacingDegreesTo(object.getPosition());
}

int WowObject::getFacingDeltaDegrees(const WowObject& object) const
{
	return getPosition().getFacingDeltaDegrees(getFacingDegrees(), object.getPosition());
}

bool WowObject::isLootable() const
{
	return getObjectData().dynamicFlags & uint32_t(WowObjectDynamicFlags::Lootable);
}

bool WowObject::isTappedByOthers() const
{
	return getObjectData().dynamicFlags & uint32_t(WowObjectDynamicFlags::Tapped);
}

bool WowObject::isTappedByMe() const
{
	return isLootable() || getObjectData().dynamicFlags & uint32_t(WowObjectDynamicFlags::TappedByMe);
}

bool WowObject::isTappedByAllThreatList() const
{
	return getObjectData().dynamicFlags & (uint32_t(WowObjectDynamicFlags::Lootable) | uint32_t(WowObjectDynamicFlags::IsTappedByAllThreatList));
}

bool WowObject::isInvisible() const
{
	return getObjectData().dynamicFlags & uint32_t(WowObjectDynamicFlags::Invisible);
}

uint64_t* WowObject::getVirtualTable() const
{
	return *(uint64_t**)getAddress();
}

const WowObjectDescriptor& WowObject::getObjectData() const
{
	return getDescriptorData<WowObjectDescriptor>();
}
