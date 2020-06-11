
#include "dump/WowGameOffsets.h"
#include "d3dutils.h"
#include "WowGame.h"

#include <utility>

#include "windowcontroller/PostMessageWindowController.h"
#include "observer/ARecurrentServerObserver.h"
#include "world/intersect/Intersect.h"

WowGame::WowGame(const long pid, const uint8_t* baseAddress) :
	AGame(pid, baseAddress),
	mDbg("WowGame"),
	mObjMgr((const uint8_t**)(getAddress() + WowGameOffsets::WowObjectManager::OffsetObjectManagerBase)),
	mSpellBook((const uint8_t*)(getAddress() + WowGameOffsets::OffsetSpellBookBase)),
	mNameCache((const uint8_t*)(getAddress() + WowGameOffsets::OffsetNameCacheBase)),
	mWindowController(std::make_unique<PostMessageWindowController>(FindMainWindow(pid)))
{
}

WowGame::~WowGame() = default;

uint64_t WowGame::getTime() const
{

	typedef int64_t(FrameTimeGetCurTimeMs)();
	const auto func(getFunction<FrameTimeGetCurTimeMs>(WowGameOffsets::FunctionFrameTime_GetCurTimeMs));
	return func();
}

bool WowGame::isLoggedIn() const
{
	return isInGameOrLoading() && !isLoading();  // fixme
}

bool WowGame::isLoading() const
{
	return *(uint32_t*)(getAddress() + WowGameOffsets::OffsetIsLoadingOrConnecting);
}

bool WowGame::isInGameOrLoading() const
{
	return nullptr != mObjMgr.getBaseAddress(); // fixme reliable?
}

void WowGame::update()
{
	mObjMgr.scan(*this);

	for (auto it = mObservers.begin(); it != mObservers.end(); ++it) 
	{
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
	return get<const uint32_t*>(WowGameOffsets::OffsetCameraBase);
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

const char* WowGame::getObjectName(const WowGuid128 & guid) const
{
	return mNameCache.getObjectName(guid);
}

const char* WowGame::getVersionBuild() const
{
	return (const char*)(getAddress() + WowGameOffsets::OffsetBuildVersion);
}

const char* WowGame::getReleaseDate() const
{
	return (const char*)(getAddress() + WowGameOffsets::OffsetReleaseDate);
}

const char* WowGame::getVersion() const
{
	return (const char*)(getAddress() + WowGameOffsets::OffsetVersion);
}

int WowGame::getInGameFlags() const
{
	return *(int*)(getAddress() + WowGameOffsets::OffsetInGameFlags);
}

bool WowGame::traceLine(const WowVector3f& from, const WowVector3f& to, WowVector3f* result) const
{
	Intersect intersect(*this, from, to);

	if (nullptr != result)
		return intersect.getCollision(*result);
	return intersect.collides();
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

bool WowGame::removeObserver(const std::string & name)
{
	const auto result = mObservers.find(name);

	if (result != mObservers.end()) 
	{
		mObservers.erase(result);
		mDbg.i("removed observer " + name);
		return true;
	}
	else 
	{
		mDbg.w("could not find observer " + name + " for removal");
		return false;
	}
}
