#include "stdafx.h"
#include "Common.h"

void PrintErrorColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("[ERROR]");
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void PrintInfoColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("[INFO]");
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void PrintModuleColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("[MODULE]");
	SetConsoleTextAttribute(hConsole, saved_colors);
}
WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}