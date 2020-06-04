#pragma once

#include "game/WowGame.h"

/*
	Helpful reminder
	https://stackoverflow.com/questions/10334915/interface-vs-composition
*/

#include "bot/IWowBot.h"

#include "plugin/IPlugin.h"

class WowGame;
class Client;

class WowPlugin : public IPlugin
{
public:
	WowPlugin();
	virtual ~WowPlugin();

	virtual std::string getTag() const override;

	virtual void attachBot(IWowBot* bot);
	virtual bool onD3dRender() override;

protected:
	bool read_server_messages();

	std::unique_ptr<Client> mClient;
	std::shared_ptr<WowGame> mGame;
	FileLogger mDbg;
	std::unique_ptr<IWowBot> mBot;
	bool mBotPause;
};

inline std::ostream& operator<<(std::ostream& out, const class WowPlugin& obj) {
	out << "[WowPlugin@"<< &obj << "]";
	return out;
}
