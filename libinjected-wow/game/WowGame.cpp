
#include "dump/WowGameOffsets.h"
#include "d3dutils.h"
#include "WowGame.h"

#include <utility>

#include "windowcontroller/PostMessageWindowController.h"
#include "observer/ARecurrentServerObserver.h"

WowGame::WowGame(long pid, const uint8_t* baseAddress) :
	AGame(pid, baseAddress),
	mDbg("WowGame"),
	mObjMgr((const uint8_t**)(getAddress() + WowGameOffsets::WowObjectManager::OffsetObjectManagerBase)),
	mSpellBook((const uint8_t*)(getAddress() + WowGameOffsets::WowGame::OffsetSpellBookBase)),
	mNameCache((const uint8_t*)(getAddress() + WowGameOffsets::WowGame::OffsetNameCacheBase)),
	mWindowController(std::make_unique<PostMessageWindowController>(FindMainWindow(pid)))
{
}

WowGame::~WowGame() = default;

long long WowGame::getTime() const
{
	return GetTickCount64();
}

bool WowGame::isLoggedIn() const
{
	return isInGameOrLoading() && !isLoading();  // fixme
}

bool WowGame::isLoading() const
{
	return *(uint32_t*)(getAddress() + WowGameOffsets::WowGame::OffsetIsLoadingOrConnecting);
}

bool WowGame::isInGameOrLoading() const
{
	return nullptr != mObjMgr.getBaseAddress(); // fixme reliable?
}

void WowGame::update()
{
	mObjMgr.scan();

	for (auto it = mObservers.begin(); it != mObservers.end(); ++it) {
		it->second->capture(*this);
		mDbg.i("GameObserver: capture of " + it->first);
	}
}

const IWindowController* WowGame::getWindowController() const
{
	return mWindowController.get();
}

IWindowController* WowGame::getWindowController()
{
	return mWindowController.get();
}

const uint32_t* WowGame::getCamera() const
{
	return get<const uint32_t*>(WowGameOffsets::WowCamera::OffsetCameraBase);
}

const ObjectManager& WowGame::getObjectManager() const
{
	return mObjMgr;
}

ObjectManager& WowGame::getObjectManager()
{
	return mObjMgr;
}

const SpellBook& WowGame::getSpellBook() const
{
	return mSpellBook;
}

SpellBook& WowGame::getSpellBook() {
	return mSpellBook;
}

const char* WowGame::getObjectName(const WowGuid128& guid) const
{
	return mNameCache.getObjectName(guid);
}

const char* WowGame::getVersionBuild() const
{
	return (const char*)(getAddress() + WowGameOffsets::WowGame::OffsetBuildVersion);
}

const char* WowGame::getReleaseDate() const
{
	return (const char*)(getAddress() + WowGameOffsets::WowGame::OffsetReleaseDate);
}

const char* WowGame::getVersion() const
{
	return (const char*)(getAddress() + WowGameOffsets::WowGame::OffsetVersion);
}

int  WowGame::getInGameFlags() const
{
	return *(int*)(getAddress() + WowGameOffsets::WowGame::OffsetInGameFlags);
}

typedef char(__fastcall* Intersect) (const WowVector3f*, const WowVector3f*, WowVector3f*, __int64, int);

bool WowGame::traceLine(const WowVector3f& from, const WowVector3f& to, uint64_t flags) const
{
	const Intersect intersect = (Intersect)(getAddress() + WowGameOffsets::WowGame::FunctionWorldFrame_Intersect);
	WowVector3f collision = WowVector3f();

	return intersect(&to, &from, &collision, flags, 0);
}

bool WowGame::addObserver(const std::string& name, const std::shared_ptr<ARecurrentServerObserver<WowGame>>& observer)
{
	const auto result = mObservers.find(name);

	if (result == mObservers.end()) 
	{
		mDbg.i("added observer " + name);
		mObservers.insert(std::pair<std::string, std::shared_ptr<ARecurrentServerObserver<WowGame>>>(name, observer));
		return true;
	}
	mDbg.w("could not add observer " + name);
	return false;
}

bool WowGame::removeObserver(const std::string& name)
{
	const auto result = mObservers.find(name);

	if (result != mObservers.end()) {
		mObservers.erase(result);
		mDbg.i("removed observer " + name);
		return true;
	}
	else {
		mDbg.w("could not find observer " + name + " for removal");
		return false;
	}
}
