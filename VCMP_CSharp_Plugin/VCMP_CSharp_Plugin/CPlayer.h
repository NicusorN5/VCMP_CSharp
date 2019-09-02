#pragma once
#include"Common.h"
#include "VCMP_CSharp_Plugin.h"

using namespace System;
namespace VCMPCSharpPlugin
{
	public ref class CPlayer
	{
	public:
		property String^ Name 
		{
			void set(String^ value) 
			{
				api->SetPlayerName(this->ID, CLIStringToCharA(value));
			}
			String^ get() { return this->Name; }
		}
		property int ID {int get() { return this->ID; }}
		property PlayerState Action 
		{
			PlayerState get()
			{
				return (PlayerState)api->GetPlayerAction(this->ID);
			}
		}
	};
	public enum class PlayerState
	{
		None = 0,
		Normal = 1,
		Aim = 2,
		Driver = 3,
		Passenger = 4,
		EnterDriver = 5,
		EnterPassenger = 6,
		Exit = 7,
		Unspawned = 8,
	} ;
}
