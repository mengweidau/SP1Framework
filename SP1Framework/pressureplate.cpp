#include "pressureplate.h"
#include "game.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern SGameChar g_block;

const unsigned int plates = 2;
bool underpressure = false;

extern char maze[77][30];

void pressureplate()
{
	COORD c = g_Console.getConsoleSize();

	if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'P')
	{
		underpressure = true;
	}
	else if (maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] == 'P')
	{
		underpressure = true;
	}
	else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != 'P' &&
		maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] != 'P')
	{
		underpressure = false;
	}
	
	//when true
	if (underpressure)
	{
		for (int y = 0; y < 19; y++)
		{
			c.Y = y;
			for (int x = 0; x < 77; x++)
			{
				if (maze[x][y] == 'T')
				{
					maze[x][y] = (char)0;
				}
				//else if (maze[x][y] == 'T' && !(underpressure))
				//{
				//	maze[x][y] = 'T';
				//}
				c.X = x;
			}
		}
	}
	if (!(underpressure))
	{
		for (int y = 0; y < 19; y++)
		{
			c.Y = y;
			for (int x = 0; x < 77; x++)
			{
				if (maze[x][y] == (char)0)
				{
					maze[x][y] = 'T';
				}
				c.X = x;
			}
		}
	}
	
}