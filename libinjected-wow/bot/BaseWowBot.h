#pragma once

#include "FileLogger.h"

#include "IWowBot.h"
#include "../game/WowGame.h"

class BaseWowBot : public IWowBot
{
public:
	BaseWowBot(const std::string& tag);
	virtual ~BaseWowBot();

	void attach(std::shared_ptr<WowGame> game) override;

	const std::string& getTag() const override;

	void onResume() override;
	bool onEvaluate() override;
	void onPause() override;
	bool handleWowMessage(ServerWowMessage& cl) override;
	
protected:
	virtual void _logDebug() const;

	std::shared_ptr<WowGame> mGame;
	mutable FileLogger mLog;
};

inline std::ostream& operator<<(std::ostream& out, const class IWowBot& obj) {
	out << "[IWowBot:" << obj.getTag() << "]";
	return out;
}
