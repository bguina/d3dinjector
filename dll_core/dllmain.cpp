// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <sstream>

#include "d3dutils.h"
#include "FileLogger.h"

#include "DllCore.h"
#include "plugin/DllFolderPlugin.h"

static bool gShouldStop = false;

/// <summary>
/// CAREFUL: Do NOT use a C++ object that might get destructed after gShouldStop is being set to true.
/// `gShouldStop=true` must be the last instruction to prevent Render() still being executed when MainThread frees self module handle.
/// </summary>
void Render(IDXGISwapChain* pThis, UINT syncInterval, UINT flags)
{
	static DllCore* sandbox = nullptr;

	if (!gShouldStop)
	{
		FileLogger dbg("render");

		if (nullptr == sandbox)
		{
			const auto keepAlive = true;
			auto* plugin = new DllFolderPlugin("DllFolderPlugin", keepAlive);
			const std::wstring folder(L"D:\\myplugins");
			plugin->loadFolder(folder);
			sandbox = new DllCore(plugin);
		}

		drawSomeTriangle();
		
		if (!sandbox->onFrameRender())
		{
			delete sandbox;

			gShouldStop = true;
		}
	}
}

void MainThread(void* pHandle)
{

	if (HookD3D(&Render)) {
		while (!gShouldStop && !GetAsyncKeyState(VK_END)) {

		}
	}

	UnhookD3D(pHandle);
}

BOOL WINAPI DllMain(const HINSTANCE hInstDll, const DWORD fdwReason, LPVOID)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hInstDll);
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hInstDll, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:;
	}
	return TRUE;
}

