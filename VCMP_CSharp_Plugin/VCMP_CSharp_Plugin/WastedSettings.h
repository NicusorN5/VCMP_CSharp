#pragma once
#include "Color.h"

namespace VCMPCSharpPlugin
{
	ref class WastedSettings
	{
	public:
		WastedSettings() : DeathTime(4096), FadeTime(2048), FadeInSpeed(2), FadeOutSpeed(3), FadeColor(gcnew Color(200, 200, 200)), CorpseFadeDelay(4000), CorpseFadeTime(2000) {};
		WastedSettings(int a,int b, float c, float d,Color ^ col,int e,int f): DeathTime(a), FadeTime(b), FadeInSpeed(c), FadeOutSpeed(d), FadeColor(col), CorpseFadeDelay(e), CorpseFadeTime(f) {};
		int DeathTime, FadeTime, CorpseFadeDelay, CorpseFadeTime;
		float FadeInSpeed, FadeOutSpeed;
		Color ^ FadeColor;
	};
}