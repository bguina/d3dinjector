#pragma once

#include "AGame.h"
#include "world/SpellBook.h"
#include "world/ObjectManager.h"

class WowVector3f;
typedef uint64_t WowGameTime;

class IWindowController;

class IWowGame
{
public:
	virtual ~IWowGame() = default;
	
	virtual const IWindowController* getWindowController() const = 0;
	virtual IWindowController* getWindowController() = 0;

	virtual long long getSystemTime() const = 0;
	virtual uint64_t getFrameTime() const = 0;
	virtual void update() = 0;

	virtual bool isLoggedIn() const = 0;
	virtual bool isLoading() const = 0;
	virtual bool isInGameOrLoading() const = 0;
	
	virtual const uint32_t* getCamera() const = 0;

	virtual const ObjectManager& getObjectManager() const = 0;

	virtual ObjectManager& getObjectManager() = 0;

	virtual const SpellBook& getSpellBook() const = 0;

	virtual SpellBook& getSpellBook() = 0;

	virtual const char* getVersionBuild() const = 0;

	virtual const char* getReleaseDate() const = 0;

	virtual const char* getVersion() const = 0;

	virtual int getInGameFlags() const = 0;

	virtual bool traceLine(const WowVector3f& from, const WowVector3f& to, WowVector3f* result) const = 0;
};

