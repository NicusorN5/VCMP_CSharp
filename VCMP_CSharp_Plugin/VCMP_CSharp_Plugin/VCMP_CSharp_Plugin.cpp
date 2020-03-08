#include "stdafx.h"

#include "VCMP_CSharp_Plugin.h"

VCMPCSharpPlugin::ScriptCompiler::ScriptCompiler()
{
	//Read configuration
	int files_counter = 0;
	array<String^> ^Scripts2Compile = File::ReadAllLines(L"server.cfg");
	Assemblies = gcnew List<String^>();
	HasScripts = false;
	//Get scripts to compile and assemblies to load
	for (int i = 0; i < Scripts2Compile->Length; i++)
	{
		array<String^> ^Data = Scripts2Compile[i]->Split(' ');
		if (Data[0] == L"cs_file")
		{
			String^ path = "";
			for (int j = 1; j < Data->Length; j++)
			{
				path += Data[j]+ ' ';
				HasScripts = true;
			}
			char* pathp = CLIStringToCharA(path);
			PrintInfoColor();
			printf("Loaded file: ");
			printf(pathp);
			printf("\r\n");
			delete pathp;
			Files->Add(path);
			files_counter += 1;
		}
		if (Data[0] == L"cs_asm")
		{
			String^ path = "";
			for (int j = 1; j < Data->Length; j++)
			{
				path += Data[j]+' ';
			}
			char* pathp = CLIStringToCharA(path);
			PrintInfoColor();
			printf("Loaded assembly: ");
			printf(pathp);
			printf("\r\n");
			delete pathp;
			Assemblies->Add(path);
			files_counter += 1;
		}
		if (Data[0] == "classname")
		{
			ClassName = Data[1];
		}
	}
	Assemblies->Add("mscorlib.dll");
	Assemblies->Add("System.dll");
	PrintInfoColor();
	printf("Loaded default assembly: mscorlib.dll \r\n");
	PrintInfoColor();
	printf("Loaded default assembly: System.dll \r\n");
	if (files_counter == 0) {
		PrintErrorColor();
		printf("No scripts were loaded... \r\n");
	}
	else printf("Files loaded: %i", files_counter);
}
void VCMPCSharpPlugin::ScriptCompiler::Initialize()
{

}
bool VCMPCSharpPlugin::ScriptCompiler::CompileAll()
{
	params = gcnew CompilerParameters(Assemblies->ToArray());
	params->GenerateInMemory = true;
	params->MainClass = ClassName;
	params->GenerateExecutable = false;
	compiler = CodeDomProvider::CreateProvider("CSharp");
	results = compiler->CompileAssemblyFromFile(params, Files->ToArray());
	if (results->Errors->HasErrors)
	{
		for (int i = 0; i < results->Errors->Count; i++)
		{
			PrintErrorColor();
			printf("Error %d.) %s Line %d Column %d \r\n", i, CLIStringToCharA(results->Errors[i]->ErrorText), results->Errors[i]->Line,results->Errors[i]->Column);
		}
		PrintInfoColor();
		printf("Since compilation failed, this plugin's execution will terminate...");
		return false;
	}
	else
	{
		PrintInfoColor();
		printf("Compilation succeded!");
		compiledCode = results->CompiledAssembly;
		return true;
	}
}
char* CLIStringToCharA(String ^ str)
{
	if (String::IsNullOrEmpty(str) == true) return nullptr;
	char *result = new char[str->Length + 1];
	int i = 0;
	for (; i < str->Length; i++)
	{
		result[i] = str[i];
	}
	result[i + 1] = 0;
	return result;
}

String ^ CharATOCLIString(char * str)
{
	if (str == nullptr) return nullptr;
	String^ result = "";
	for (int i = 0; str[i] != '\0'; i++)
	{
		result += str[i];
	}
	return result;
}
