#include "switches.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern char maze[77][30];

void switches()
{
	COORD c = g_Console.getConsoleSize();

	//when character stands on switch
	if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '/')
	{
		for (int y = 0; y < 30; y++)
		{
			c.Y = y;
			for (int x = 0; x < 77; x++)
			{
				if (maze[x][y] == 'X')
				{
					maze[x][y] = ' ';
				}
				c.X = x;
			}
		}
	}
}