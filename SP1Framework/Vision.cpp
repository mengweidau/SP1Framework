#include "Vision.h"
extern char maze[77][30];
extern double life;
WORD charColor1;

void renderVision(SGameNPC _NPC[])
{
	if (g_eGameState = S_GAME)
	{

		int left = 5;
		int right = 5;
		int up = 3;
		int down = 3;
		if (life >= 1)
		{
			if (g_abKeyPressed[K_FLASH])
			{
				if (g_abKeyPressed[K_LEFT])
				{
					left = 15;
				}
				else if (g_abKeyPressed[K_RIGHT])
				{
					right = 15;
				}
				else if (g_abKeyPressed[K_UP])
				{
					up = 8;
				}
				else if (g_abKeyPressed[K_DOWN])
				{
					down = 8;
				}
			}
		}
		for (int r = g_sChar.m_cLocation.X + right; r > g_sChar.m_cLocation.X - left; r--)
		{
			for (int c = g_sChar.m_cLocation.Y + down; c > g_sChar.m_cLocation.Y - up; c--)
			{
				if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
					;
				else
				{
					g_Console.writeToBuffer(r, c, maze[r][c]);
				}
				for (int i = 0; i < npcNum; i++)
				{
					if (!(c == _NPC[i].m_cLocation.Y && r == _NPC[i].m_cLocation.X)) //outside line of sight
						charColor1 = 0x00;
					else//inside line of sight
					{
						charColor1 = 0x0D;
						// Draw the location of the Npc
						g_Console.writeToBuffer(_NPC[i].m_cLocation, (char)2, charColor1);
					}
				}	
			}
		}
	}
}

		/*for (int r = g_sChar.m_cLocation.X + 5; r > g_sChar.m_cLocation.X - 5; r--)
		{
			for (int c = g_sChar.m_cLocation.Y + 3; c > g_sChar.m_cLocation.Y - 3; c--)
			{
				if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
					;
				else
					g_Console.writeToBuffer(r, c, maze[r][c]);
			}
			if (g_abKeyPressed[K_FLASH])
			{
				if (g_abKeyPressed[K_LEFT])
				{
					for (int r = g_sChar.m_cLocation.X + 5; r > g_sChar.m_cLocation.X - 15; r--)
					{
						for (int c = g_sChar.m_cLocation.Y + 3; c > g_sChar.m_cLocation.Y - 3; c--)
						{
							if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
								;
							else
								g_Console.writeToBuffer(r, c, maze[r][c]);
						}
					}
				}
				else if (g_abKeyPressed[K_RIGHT])
				{
					for (int r = g_sChar.m_cLocation.X + 15; r > g_sChar.m_cLocation.X - 5; r--)
					{
						for (int c = g_sChar.m_cLocation.Y + 3; c > g_sChar.m_cLocation.Y - 3; c--)
						{
							if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
								;
							else
								g_Console.writeToBuffer(r, c, maze[r][c]);
						}
					}
				}
				else if (g_abKeyPressed[K_DOWN])
				{
					for (int r = g_sChar.m_cLocation.X + 5; r > g_sChar.m_cLocation.X - 5; r--)
					{
						for (int c = g_sChar.m_cLocation.Y + 8; c > g_sChar.m_cLocation.Y - 3; c--)
						{
							if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
								;
							else
								g_Console.writeToBuffer(r, c, maze[r][c]);
						}
					}
				}
				else if (g_abKeyPressed[K_UP])
				{
					for (int r = g_sChar.m_cLocation.X + 5; r > g_sChar.m_cLocation.X - 5; r--)
					{
						for (int c = g_sChar.m_cLocation.Y + 3; c > g_sChar.m_cLocation.Y - 8; c--)
						{
							if (c == g_sChar.m_cLocation.Y && r == g_sChar.m_cLocation.X)
								;
							else
								g_Console.writeToBuffer(r, c, maze[r][c]);
						}
					}
				}
			}
		}*/