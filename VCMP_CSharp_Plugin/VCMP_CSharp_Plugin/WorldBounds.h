#pragma once
namespace VCMPCSharpPlugin
{
	ref class WorldBounds
	{
	public:
		WorldBounds() : MinX(-5000), MaxX(5000), MinY(-5000), MaxY(5000) {};
		WorldBounds(float mx, float mX, float my, float mY) : MinX(mx), MaxX(mX), MinY(my), MaxY(mY) {};
		float MinX, MaxX, MinY, MaxY;
	};
}

