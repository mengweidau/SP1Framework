#include "movemaze1.h"

void movemaze1()
{
	bool bSomethingHappened = false;
	bool slowingdwn = false;

	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '|')
			if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != 'X')
				if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != 'T')
				{
					if (g_sChar.m_cLocation.X == g_block.m_cLocation.X &&
						g_sChar.m_cLocation.Y - 1 == g_block.m_cLocation.Y)
					{
						g_block.m_cLocation.Y--;
						bSomethingHappened = true;
					}
					if (maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] == '|')
					{
						g_block.m_cLocation.X = 35;
						g_block.m_cLocation.Y = 7;
					}

					if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
					{
						bSomethingHappened = false;
						slowingdwn = true;
						g_sChar.m_cLocation.Y--;
					}
					else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '.')
					{
						bSomethingHappened = true;
						slowingdwn = false;
						g_sChar.m_cLocation.Y--;
					}
				}
	}

	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '|')
			if (maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != 'X')
				if (maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != 'T')
				{
					if (g_sChar.m_cLocation.X - 1 == g_block.m_cLocation.X &&
						g_sChar.m_cLocation.Y == g_block.m_cLocation.Y)
					{
						g_block.m_cLocation.X--;
						bSomethingHappened = true;
					}
					if (maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] == '|')
					{
						g_block.m_cLocation.X = 35;
						g_block.m_cLocation.Y = 7;
					}

					if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
					{
						bSomethingHappened = false;
						slowingdwn = true;
						g_sChar.m_cLocation.X--;
					}
					else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '.')
					{
						bSomethingHappened = true;
						slowingdwn = false;
						g_sChar.m_cLocation.X--;
					}
				}
	}

	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '|')
			if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != 'X')
				if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != 'T')
				{
					if (g_sChar.m_cLocation.X == g_block.m_cLocation.X &&
						g_sChar.m_cLocation.Y + 1 == g_block.m_cLocation.Y)
					{
						g_block.m_cLocation.Y++;
						bSomethingHappened = true;
					}
					if (maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] == '|')
					{
						g_block.m_cLocation.X = 35;
						g_block.m_cLocation.Y = 7;
					}

					if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
					{
						bSomethingHappened = false;
						slowingdwn = true;
						g_sChar.m_cLocation.Y++;
					}
					else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '.')
					{
						bSomethingHappened = true;
						slowingdwn = false;
						g_sChar.m_cLocation.Y++;
					}
				}
	}

	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '|')
			if (maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != 'X')
				if (maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != 'T')
				{
					if (g_sChar.m_cLocation.X + 1 == g_block.m_cLocation.X &&
						g_sChar.m_cLocation.Y == g_block.m_cLocation.Y)
					{
						g_block.m_cLocation.X++;
						bSomethingHappened = true;
					}
					if (maze[g_block.m_cLocation.X][g_block.m_cLocation.Y] == '|')
					{
						g_block.m_cLocation.X = 35;
						g_block.m_cLocation.Y = 7;
					}

					if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
					{
						bSomethingHappened = false;
						slowingdwn = true;
						g_sChar.m_cLocation.X++;
					}
					else if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '.')
					{
						bSomethingHappened = true;
						slowingdwn = false;
						g_sChar.m_cLocation.X++;
					}
				}
	}

	for (int i = 0; i < npcNum; i++)
	{
		if (!(g_sChar.m_cLocation.X >(_NPC[i].m_cLocation.X) + 1) && !(g_sChar.m_cLocation.X < (_NPC[i].m_cLocation.X) - 1) && //check horizontal by 1 and vertical by 1
			!(g_sChar.m_cLocation.Y >(_NPC[i].m_cLocation.Y) + 1) && !(g_sChar.m_cLocation.Y < (_NPC[i].m_cLocation.Y) - 1))
		{
			if (g_abKeyPressed[K_SPACE])
			{
				waitTime = g_dElapsedTime + 6.0; //sets waitTime with current elapsedTime + delay
				bSomethingHappened = true;
				_NPC[i].talked = true; //sets NPC bool to true, increment tolerance by 1
				_NPC[i].tolerance++;
			}
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.07; // 125ms should be enough
	}
	if (slowingdwn)
	{
		g_dBounceTime = g_dElapsedTime + 0.325;
	}
}