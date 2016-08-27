#include "pressureplate.h"
#include "game.h"

extern Console g_Console;
extern SGameChar g_sChar;

const unsigned int plates = 2;
bool underpressure = false;

extern char maze[77][30];

void pressureplate(Blocks _block[])
{
	COORD c = g_Console.getConsoleSize();
	for (int i = 0; i < blockNum; i++)
	{
		if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'P')
		{
			underpressure = true;
		}
		else if (maze[_block[i].m_location.X][_block[i].m_location.Y] == 'P')
		{
			underpressure = true;
		}
		else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != 'P' &&
			maze[_block[i].m_location.X][_block[i].m_location.Y] != 'P')
		{
			underpressure = false;
		}
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
					maze[x][y] = ' ';
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