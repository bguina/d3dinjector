#pragma once

#include "Client.h"

#include "../../../injected/observer/ARecurrentServerObserver.h"

class Client;
class WowGame;

class AWowGameObserver : public ARecurrentServerObserver<WowGame> {
protected:
	AWowGameObserver(const std::string& tag, Client& client, unsigned long periodMs);

protected:
	Client& mClient;
};