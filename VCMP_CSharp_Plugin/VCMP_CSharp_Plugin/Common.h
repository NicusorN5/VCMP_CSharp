#pragma once
#include "VCMP.h"
#include <windows.h>
#include <stdio.h>

using namespace System;

#ifdef WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif


//The line below might fuck up the entire compilation and etc... Macros suck.
#undef PlaySound 


constexpr int null = 0;

extern PluginFuncs *api;

extern PluginCallbacks *calls;

void PrintErrorColor();

void PrintInfoColor();

void PrintModuleColor();

WORD GetConsoleTextAttribute(HANDLE hCon);

String^ CharATOCLIString(char* str, size_t l);
String^ CharATOCLIString(char* str);
String^ CharATOCLIString(const char* str);
char* CLIStringToCharA(String^ str);