#include "ObjectManager.h"

#include "FileLogger.h"
#include "../dump/WowGameDescriptors.h"
#include "../dump/WowGameOffsets.h"

#include "WowObjects.h"
#include "object/WowUnimplementedObject.h"

ObjectManager::ObjectManager(const uint8_t** baseAddress) :
	mPointerAddr(baseAddress),
	mDbg("ObjectManager")
{}

bool ObjectManager::isEnabled() const {
	return nullptr != getBaseAddress();
}

void ObjectManager::scan(WowGame& game) {

	
	if (isEnabled()) 
	{
		FileLogger dbg(mDbg, "scan");
		//std::set<WowGuid128> oldGuids;

		/*
		for (std::map<WowGuid128, std::shared_ptr<WowObject>>::const_iterator it = mObjects.begin();
			it != mObjects.end(); ++it) {
			oldGuids.insert(it->first);
		}
		*/
		mObjects.clear();

		// Manually walk through the native ObjectManager linked list
		for (WowObjectStruct* pObj = *(WowObjectStruct**)(getBaseAddress() + 0x18);
			nullptr != pObj && !((uint64_t)pObj & 1);
			pObj = pObj->pNext)
		{
			WowObject thisObj = WowObject(pObj, game);
			//std::map<WowGuid128, std::shared_ptr<WowObject>>::const_iterator oldObjInstance = mObjects.find(thisObj.getGuid());

			//if (oldObjInstance == mObjects.end()) {
				std::shared_ptr<WowObject> finalObj = nullptr;

				switch (thisObj.getType()) {
				case WowObjectType::Object:
					finalObj = std::make_shared<WowObject>(pObj, game);
					break;
				case WowObjectType::Item:
					finalObj = std::make_shared<WowItemObject>(pObj, game);
					break;
				case WowObjectType::Container:
					finalObj = std::make_shared<WowContainerObject>(pObj, game);
					break;
				case WowObjectType::Unit:
					finalObj = std::make_shared<WowUnitObject>(pObj, game);
					break;
				case WowObjectType::Player:
					finalObj = std::make_shared<WowPlayerObject>(pObj, game);
					break;
				case WowObjectType::ActivePlayer:
					finalObj = std::make_shared<WowActivePlayerObject>(pObj, game);
					break;
				case WowObjectType::Corpse:
					finalObj = std::make_shared<WowCorpseObject>(pObj, game);
					break;
				case WowObjectType::Loot:
				case WowObjectType::GameObject:
				case WowObjectType::DynamicObject:
				case WowObjectType::Conversation:
				case WowObjectType::Invalid: // Type "Invalid"? based on what? wtf Blizzard
					finalObj = nullptr;//std::make_shared<WowUnimplementedObject>(pObj, game);
					break;
				default:
					// Invalid WowObject enum value!!
					break;
				}

				if (nullptr != finalObj) {
					mObjects.insert(std::pair<WowGuid128, std::shared_ptr<WowObject>>(*finalObj->getGuid(), finalObj));
				}
			//}
				/*
			else {
				// WowObject still present in memory, rebase to found address
				// TODO: Define WHEN/HOW a same object would be rebase, when we immediately clear any missing previous object?
				// in current implementation, we don't persist objects went missing so this currently has no real purpose.
				oldObjInstance->second->rebase(pObj);
				oldGuids.erase(oldObjInstance->second->getGuid());
			}
			*/
		}

		/*
		for (std::set<WowGuid128>::const_iterator it = oldGuids.begin(); it != oldGuids.end(); ++it) {
			mObjects.erase(*it);
		}
		*/

		dbg << dbg.e() << "count= " << mObjects.size() << dbg.endl();

	}
	else 
	{
		mObjects.clear();
	}
}

const uint8_t* ObjectManager::getBaseAddress() const {
	return *mPointerAddr;
}

std::map<WowGuid128, std::shared_ptr<WowObject>>::const_iterator ObjectManager::begin() const {
	return mObjects.begin();
}

std::map<WowGuid128, std::shared_ptr<WowObject>>::iterator ObjectManager::begin() {
	return mObjects.begin();
}

std::map<WowGuid128, std::shared_ptr<WowObject>>::const_iterator ObjectManager::end() const {
	return mObjects.end();
}

std::map<WowGuid128, std::shared_ptr<WowObject>>::iterator ObjectManager::end() {
	return mObjects.end();
}

const std::shared_ptr<const WowActivePlayerObject> ObjectManager::getActivePlayer() const {
	return anyOfType<const WowActivePlayerObject>(WowObjectType::ActivePlayer);
}

std::shared_ptr<WowActivePlayerObject> ObjectManager::getActivePlayer() {
	return anyOfType<WowActivePlayerObject>(WowObjectType::ActivePlayer);
}

size_t ObjectManager::getObjectsCount() const {
	return mObjects.size();
}