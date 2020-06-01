
#include "d3dutils.h"
#include "WowGame.h"

#include "windowcontroller/PostMessageWindowController.h"
#include "observer/ARecurrentServerObserver.h"

WowGame::WowGame(long pid, const uint8_t* baseAddr) :
	AGame(pid, baseAddr),
	mDbg("WowGame"),
	mObjMgr((const uint8_t**)(getAddress() + 0x2372D48)),
	mSpellBook((const uint8_t*)(getAddress() + 0x2595D78)),
	mWindowController(std::make_unique<PostMessageWindowController>(FindMainWindow(pid)))
{

}

WowGame::~WowGame() {

}

bool WowGame::isLoggedIn() const {
	return isInGame() && !isLoading();  // fixme
}

bool WowGame::isLoading() const {
	return *(int*)(getAddress() + 0x2260D50);
}

bool WowGame::isInGame() const {
	return NULL != mObjMgr.getBaseAddress(); // fixme reliable?
}

void WowGame::update() {

	mObjMgr.scan();

	mDbg << mObjMgr << std::endl;

	//mDbg << mSpellBookMgr << "\n";

	for (auto it = mObservers.begin(); it != mObservers.end(); ++it) {
		it->second->capture(*this);
		mDbg.i("GameObserver: capture of " + it->first);
	}

}

const IWindowController* WowGame::getWindowController() const {
	return mWindowController.get();
}

IWindowController* WowGame::getWindowController() {
	return mWindowController.get();
}

const ObjectManager& WowGame::getObjectManager() const {
	return mObjMgr;
}

ObjectManager& WowGame::getObjectManager() {
	return mObjMgr;
}

const SpellBook& WowGame::getSpellBook() const {
	return mSpellBook;
}

SpellBook& WowGame::getSpellBook() {
	return mSpellBook;
}

const char* WowGame::getVersionBuild() const {
	return (const char*)(getAddress() + 0x1C3531C);
}

const char* WowGame::getReleaseDate() const {
	return (const char*)(getAddress() + 0x1C3531C);
}

const char* WowGame::getVersion() const {
	return (const char*)(getAddress() + 0x1C35314);
}

int  WowGame::getInGameFlags() const {
	return *(int*)(getAddress() + 0x2594F40);
}



typedef char(__fastcall* Intersect) (const WowVector3f*, const WowVector3f*, WowVector3f*, __int64, int);

bool WowGame::traceLine(const WowVector3f& from, const WowVector3f& to, uint64_t flags) const {
	Intersect intersect = (Intersect)(getAddress() + 0x114AC10);
	WowVector3f collision = WowVector3f();

	return intersect(&to, &from, &collision, flags, 0);
}

bool WowGame::addObserver(const std::string& name, const std::shared_ptr<ARecurrentServerObserver<WowGame>>& observer) {
	auto result = mObservers.find(name);

	if (result == mObservers.end()) {
		mDbg.i("added observer " + name);
		mObservers.insert(std::pair<std::string, std::shared_ptr<ARecurrentServerObserver<WowGame>>>(name, observer));
		return true;
	}
	mDbg.w("could not add observer " + name);
	return false;
}

bool WowGame::removeObserver(const std::string& name) {
	auto result = mObservers.find(name);

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