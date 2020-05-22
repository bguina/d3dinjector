#pragma once

#include "../AGame.h"

#include "../../debugger/FileDebugger.h"
#include "../observers/IGameObserver.h"
#include "objectmanager/ObjectManager.h"
#include "spellbook/SpellBookManager.h"

class IWindowController;

class WowGame : public AGame
{
public:
	WowGame(const uint8_t* baseAddr);
	~WowGame();

	virtual const IWindowController* getWindowController() const override;
	virtual IWindowController* getWindowController() override;

	void update();

	bool isObjectManagerActive() const;

	const ObjectManager& getObjectManager() const;

	ObjectManager& getObjectManager();

	const SpellBookManager& getSpellBookManager() const;

	const char* getVersionBuild() const;

	const char* getReleaseDate() const;

	const char* getVersion() const;

	int getInGameFlags() const;

	int getIsLoadingOrConnecting() const;

	bool traceLine(const WowVector3f& from, const WowVector3f& to, uint64_t flags) const;

	bool addObserver(const std::string& name, const std::shared_ptr<IGameObserver<WowGame>>& observer);
	bool removeObserver(const std::string& name);

private:
	FileDebugger mDbg;
	std::map<std::string, std::shared_ptr<IGameObserver<WowGame>>> mObservers;
	ObjectManager mObjMgr;
	SpellBookManager mSpellBookMgr;
	std::unique_ptr<IWindowController> mWindowController;
};

inline std::ostream& operator<<(
	std::ostream& out,
	const class WowGame& obj
	)
{
	out << "[WowGame@" << (void*)obj.getAddress() << "]" << std::endl;
	ObjectManager objMgr = obj.getObjectManager();
	out << objMgr;

	if (obj.isObjectManagerActive()) {
		SpellBookManager spellBookMgr = obj.getSpellBookManager();
		out << spellBookMgr;
	}
	return out;
}