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

char* CLIStringToCharA(String^ str)
{
	if (String::IsNullOrEmpty(str) == true) return nullptr;
	char* result = new char[str->Length + 1];
	int i = 0;
	for (; i < str->Length; i++)
	{
		result[i] = str[i];
	}
	result[i + 1] = 0;
	return result;
}

String^ CharATOCLIString(char* str)
{
	if (str == nullptr) return nullptr;
	String^ result = "";
	for (int i = 0; str[i] != '\0'; i++)
	{
		result += str[i];
	}
	return result;
}
String^ CharATOCLIString(const char* str)
{
	if (str == nullptr) return nullptr;
	String^ result = "";
	for (int i = 0; str[i] != '\0'; i++)
	{
		result += str[i];
	}
	return result;
}
String^ CharATOCLIString(char* str, size_t l)
{
	if (str == nullptr) return nullptr;
	String^ result = "";
	for (int i = 0; i < l; i++)
	{
		result += str[i];
	}
	return result;
}
