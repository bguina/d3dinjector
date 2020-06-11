#pragma once

#include "observer/ARecurrentServerObserver.h"

#include "FileLogger.h"
#include "world/NameCache.h"
#include "world/ObjectManager.h"
#include "world/SpellBook.h"

#include "AGame.h"
#include "IWowGame.h"

typedef uint64_t WowGameTime;

class IWindowController;

class WowGame final : public AGame, public IWowGame
{
public:
	WowGame(long pid, const uint8_t* baseAddress);
	~WowGame();
	
	uint64_t getTime() const override;

	const IWindowController* getWindowController() const override;
	IWindowController* getWindowController() override;

	void update() override;

	bool isLoggedIn() const override;
	bool isLoading() const override;
	bool isInGameOrLoading() const override;
	
	const uint32_t* getCamera() const override;

	const ObjectManager& getObjectManager() const override;
	ObjectManager& getObjectManager() override;

	const SpellBook& getSpellBook() const override;
	SpellBook& getSpellBook() override;
	
	const char* getObjectName(const WowGuid128& guid) const;
	
	const char* getVersionBuild() const override;
	const char* getReleaseDate() const override;
	const char* getVersion() const override;

	int getInGameFlags() const override;

	bool traceLine(const WowVector3f& from, const WowVector3f& to, WowVector3f* result) const override;
	
	bool addObserver(const std::string& name, const std::shared_ptr<ARecurrentServerObserver<WowGame>>& observer);
	bool removeObserver(const std::string& name);

	template<typename U>
	const U& getFunction(const uint64_t offset) const {
		return *reinterpret_cast<U*>(getAddress() + offset);
	}
	
private:
	FileLogger mDbg;
	std::map<std::string, std::shared_ptr<ARecurrentServerObserver<WowGame>>> mObservers;
	ObjectManager mObjMgr;
	SpellBook mSpellBook;
	NameCache mNameCache;
	std::unique_ptr<IWindowController> mWindowController;
};

inline std::ostream& operator<<(std::ostream& out,const class WowGame& obj)
{
	out << "[WowGame@" << (void*)obj.getAddress() << "]" << std::endl;

	//if (obj.isInGameOrLoading()) {
	//	const auto& spellBookMgr = obj.getSpellBook();
	//	const auto& objMgr = obj.getObjectManager();
	//	out << spellBookMgr;
	//	out << objMgr;
	//}

	return out;
}
