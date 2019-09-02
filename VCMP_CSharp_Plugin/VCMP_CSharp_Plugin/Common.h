#pragma once
#include "VCMP.h"
#include <windows.h>
#include <stdio.h>

#ifdef WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

constexpr int null = 0;

extern PluginFuncs *api;

extern PluginCallbacks *calls;

void PrintErrorColor();

void PrintInfoColor();

void PrintModuleColor();

WORD GetConsoleTextAttribute(HANDLE hCon);
