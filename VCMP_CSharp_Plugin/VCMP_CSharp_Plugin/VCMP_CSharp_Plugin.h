#pragma once

#include <stdio.h>
#include "Common.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Collections::Generic;
using namespace System::CodeDom::Compiler;
using namespace System::CodeDom;

#pragma managed
namespace VCMPCSharpPlugin {
	public ref class ScriptCompiler
	{
	public:
		static List<String^> ^Files;
		static List<String^> ^Assemblies;
		String ^ClassName;
		ScriptCompiler();
		void Initialize();
		bool CompileAll();
		bool HasScripts;
	private:
		CodeDomProvider ^compiler;
		CompilerParameters ^params;
		CompilerResults ^results;
		Assembly ^compiledCode;
	};
}
char* CLIStringToCharA(String ^ str);
String^ CharATOCLIString(char *str);
