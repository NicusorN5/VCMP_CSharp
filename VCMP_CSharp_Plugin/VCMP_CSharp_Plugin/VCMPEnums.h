#pragma once

namespace VCMPCSharpPlugin
{
	public enum class PlayerState : int
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
	};
	public enum class DisconnectReason
	{
		Timeout = 0,
		Quit = 1,
		Kick = 2,
		Crash = 3,
		AntiCheat = 4,
	};
	public enum class BodyPart
	{
		Body = 0,
		Torso = 1,
		LeftArm = 2,
		RightArm = 3,
		LeftLeg = 4,
		RightLeg = 5,
		Head = 6,
		InVehicle = 7,
	};
	public enum class PlayerUpdate
	{
		Normal = 0,
		Aiming = 1,
		Driver = 2,
		Passenger = 3,
	};
	public enum class VehicleUpdate
	{
		DriverSync = 0,
		OtherSync = 1,
		Position = 2,
		Health = 4,
		Colour = 5,
		Rotation = 6,
	};
}