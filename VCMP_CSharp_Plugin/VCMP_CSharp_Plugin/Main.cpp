#include "stdafx.h"
#include "Common.h"
#include <Windows.h>
#include <stdio.h>
#include <cstring>
#include "VCMP_CSharp_Plugin.h"

PluginFuncs *api;

PluginCallbacks *calls;

char * PluginName = "C# for VC:MP";

using namespace VCMPCSharpPlugin;

extern "C" DLL_EXPORT unsigned int VcmpPluginInit(PluginFuncs* pluginFuncs, PluginCallbacks* pluginCalls, PluginInfo* pluginInfo)
{
	api = pluginFuncs;
	calls = pluginCalls;
	pluginInfo->apiMajorVersion = PLUGIN_API_MAJOR;
	pluginInfo->apiMinorVersion = PLUGIN_API_MINOR;
	strcpy_s(pluginInfo->name, PluginName);
	PrintModuleColor();
	printf(" Loaded C# plugin by Athanatos [This is only a experimental build.] \r\n");
	ScriptCompiler ^compiler = gcnew ScriptCompiler();
	if (compiler->HasScripts == false) return 0;
	return 1;
}

#pragma unmanaged
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
