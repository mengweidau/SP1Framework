#include "Battery.h"
double life = 20, timer = 0;
void renderBattery()
{
	COORD c;
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << life << "Battery Life";
	c.X = g_Console.getConsoleSize().X;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());
}
void Batterylife()
{
	if (life < 20.0 && !g_abKeyPressed[K_FLASH])
	{
		if (timer == 0)
			timer = g_dElapsedTimeSec;

		if (g_dElapsedTimeSec > timer + 1) // if 1 second has passed
		{
			life += 0.2;
			//regen battery
			timer = g_dElapsedTimeSec; // to reset , so game time wont be faster then timer.
		}
	}
	if (life >= 1 && g_abKeyPressed[K_FLASH])
	{
		if (timer == 0)
		{
		timer = g_dElapsedTimeSec;
		}
		if (g_dElapsedTimeSec > timer + 1) // if 1 second has passed
		{
			life -= 1;
			//minus battery
			timer = g_dElapsedTimeSec; // to reset , so game time wont be faster then timer.
		}
	}
}