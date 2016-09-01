#include "Vision.h"
extern char maze[77][30];
extern double life;
extern SGameChar g_block;
WORD charColor1;
WORD charColor2;

void renderVision(SGameNPC _NPC[], Blocks _block[])
{
	if (g_eGameState = S_GAME)
	{

		int left = 50;//5
		int right = 50;//5
		int up = 30;//3
		int down = 30;//3
		if (life >= 0.9)
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
					if (_NPC[i].active)
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
				for (int i = 0; i < blockNum; i++)
				{
					if (!(c == _block[i].m_location.Y && r == _block[i].m_location.X)) //outside line of sight
						charColor2 = 0x00;
					else//inside line of sight
					{
						charColor2 = 0x0D;
						switch (currentlevel)
						{
						case 0://tutorial level
							g_Console.writeToBuffer(_block[0].m_location, '#', charColor2);
							break;
						case 1:
							g_Console.writeToBuffer(_block[1].m_location, '#', charColor2);
							break;
						case 2:
							g_Console.writeToBuffer(_block[2].m_location, '#', charColor2);
							break;
						case 3: 
							g_Console.writeToBuffer(_block[3].m_location, '#', charColor2);
							break;
						}
					}
				}
			}
		}
	}
}