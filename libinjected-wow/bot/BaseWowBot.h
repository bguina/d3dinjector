#pragma once

#include "FileLogger.h"

#include "IWowBot.h"
#include "../game/WowGame.h"
#include "../game/object/WowGuid128.h"

class BaseWowBot : public IWowBot
{
public:
	BaseWowBot(const std::string& tag);
	virtual ~BaseWowBot();

	bool attach(std::shared_ptr<WowGame> game) override;

	const std::string& getTag() const override;

protected:
	virtual void _logDebug() const;

	std::shared_ptr<WowGame> mGame;
	mutable FileLogger mDbg;
};

inline std::ostream& operator<<(std::ostream& out, const class IWowBot& obj) {
	out << "[IWowBot:" << obj.getTag() << "]";
	return out;
}
