# DllCore - run arbitrary dlls in d3d hkpresent

- [dll_core](dll/) built dll that runs a thread to hook D3D hkPresent.
- [injector](injector/) dll injection tools remotely injecting our built "core" dll.

Built on VS2017. Requires Windows.h and d3d -> you need the Windows SDK configured.

### Most needed features
[x] Injector: Configurable injected .dll path
[x] Dll: Real-time logs (hardcoded "D:\\mylogs.txt" for now)
[x] Dll: Not recompiling / reinjecting for every small edit ([IPC](https://docs.microsoft.com/en-us/windows/win32/ipc/interprocess-communications) or [ingame console library](https://github.com/cegui/cegui/tree/v0) or from-scratch d2d/d3d rendering)
[x] Dll: A successful pointer read (build ver, isLoggedIn, character class)
[x] Dll: A successful exe function call (search ClickToMove or CTM with buildNum on OwnedCore)
- A pattern scanner to keep references up-to-date through Wow.exe updates (TODO lookup for existing implementation on gh)
- More external references to features we might implement

### External references

[Original repository for Injector](https://github.com/namreeb/crappy-esp)

[Original repository for Dll](https://github.com/guided-hacking/GH_D3D11_Hook)

[Recommended process explorer](https://kb.froglogic.com/misc/getting-list-of-loaded-dlls/)

