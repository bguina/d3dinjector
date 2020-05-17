// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <sstream>

#include "ServerSDK.h"
#include "d3d/d3d.h"
#include "Debugger.h"
#include "WowGame.h"
#include "WowNavigator.h"
#include "Sandbox.h"

static BOOL shouldStop = false;

bool readMessageAvailable(ServerSDK* serverSDK) {
	std::list<std::string> messages = serverSDK->getMessageAvailable();
	for (std::list<std::string>::iterator it = messages.begin(); it != messages.end(); it++)
	{
		switch (serverSDK->getMessageManager().getMessageType((*it)))
		{
		case MessageType::START_SUBSCRIBE: {

			std::list<std::string> toSubscribe = serverSDK->getMessageManager().getSubcribeObject(*it);
			bool found = (std::find(toSubscribe.begin(), toSubscribe.end(), "position") != toSubscribe.end());
			if (found)
				serverSDK->sendMessage(serverSDK->getMessageManager().builResponseInfo("position", "X,Y,Z"));

			break;
		}
		case MessageType::STOP_SUBSCRIBE: {
			std::list<std::string> toSubscribe = serverSDK->getMessageManager().getSubcribeObject(*it);
			break;
		}
		case MessageType::DEINJECT: {
			return false;
			break;
		}
		default:
			break;
		}
	}
	return true;
}

void MainThread(void* pHandle) {


	if (HookD3D()) {
		while (!shouldStop && !GetAsyncKeyState(VK_END)) {

		}

	}

	deinject(pHandle);
}

void Render()
{
	static ServerSDK* serverSDK = NULL;
	if (serverSDK == NULL)
	{
		serverSDK = new ServerSDK();
		if (serverSDK->connectToServer())
			serverSDK->sendMessage(serverSDK->getMessageManager().builRequestdDLLInjectedMessage(GetCurrentProcessId()));
	}

	if (serverSDK->getConnectionStatus() && readMessageAvailable(serverSDK)) {
		drawSomeTriangle();

		Sandbox& sandbox = Sandbox::getInstance();

		if (!sandbox.isOverHeating())
			sandbox.run();
	}
	else {
		serverSDK->disconnect();
		delete serverSDK;
		shouldStop = true;
	}


}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hinstDLL, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
