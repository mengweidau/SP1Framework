#include "game.h"

void NpcPatrol(SGameNPC _NPC[], SGameChar g_sChar)
{
	srand(time(NULL));
	for (int i = 0; i < npcNum; i++)
	{
		if (_NPC[i].moveCount == 0)
		{
			_NPC[i].dirChoice = rand() % 4 + 1; //set randrange from 1 to 4
			_NPC[i].moveCount = 3; //reset moveCount to 3

			switch (_NPC[i].dirChoice)
			{
			case 1:
				_NPC[i].right = true;
				break;
			case 2:
				_NPC[i].left = true;
				break;
			case 3:
				_NPC[i].up = true;
				break;
			case 4:
				_NPC[i].down = true;
				break;
			}
		}
		/*--------------------RIGHT-----------------------*/
		if (_NPC[i].right == true && _NPC[i].moveCount > 0) //move when right is true AND move count is more than 0
		{
			if (maze[_NPC[i].m_cLocation.X + 1][_NPC[i].m_cLocation.Y] == '|') //if wall on right, right = false
			{
				_NPC[i].right = false;
				_NPC[i].moveCount = 0;
			}
			else if (!(maze[_NPC[i].m_cLocation.X + 1][_NPC[i].m_cLocation.Y] == '|') && //when npc.location.x + 1 NOT equal to wall OR player position CAN move
				!(_NPC[i].m_cLocation.X + 1 == g_sChar.m_cLocation.X && _NPC[i].m_cLocation.Y == g_sChar.m_cLocation.Y)) 
			{
				_NPC[i].m_cLocation.X++; //move once
				_NPC[i].moveCount--;	//subtract move count once
				if (_NPC[i].moveCount == 0)	//when movecount = 0, right = false
				{
					_NPC[i].right = false;
				}
			}
		}
		/*--------------------LEFT-----------------------*/
		if (_NPC[i].left == true && _NPC[i].moveCount > 0) 
		{
			if (maze[_NPC[i].m_cLocation.X - 1][_NPC[i].m_cLocation.Y] == '|') 
			{
				_NPC[i].left = false;
				_NPC[i].moveCount = 0;
			}
			else if (!(maze[_NPC[i].m_cLocation.X - 1][_NPC[i].m_cLocation.Y] == '|') && 
				!(_NPC[i].m_cLocation.X - 1 == g_sChar.m_cLocation.X && _NPC[i].m_cLocation.Y == g_sChar.m_cLocation.Y))
			{
				_NPC[i].m_cLocation.X--; //move once
				_NPC[i].moveCount--;	//subtract move count once
				if (_NPC[i].moveCount == 0)	
				{
					_NPC[i].left = false;
				}
			}
		}
		/*--------------------UP-----------------------*/
		if (_NPC[i].up == true && _NPC[i].moveCount > 0) 
		{
			if (maze[_NPC[i].m_cLocation.X][_NPC[i].m_cLocation.Y - 1] == '|')
			{
				_NPC[i].up = false;
				_NPC[i].moveCount = 0;
			}
			else if (!(maze[_NPC[i].m_cLocation.X][_NPC[i].m_cLocation.Y - 1] == '|') && 
				!(_NPC[i].m_cLocation.Y - 1 == g_sChar.m_cLocation.Y && _NPC[i].m_cLocation.X == g_sChar.m_cLocation.X))
			{
				_NPC[i].m_cLocation.Y--; //move once
				_NPC[i].moveCount--;	//subtract move count once
				if (_NPC[i].moveCount == 0)	
				{
					_NPC[i].up = false;
				}
			}
		}
		/*--------------------DOWN-----------------------*/
		if (_NPC[i].down == true && _NPC[i].moveCount > 0) 
		{
			if (maze[_NPC[i].m_cLocation.X][_NPC[i].m_cLocation.Y + 1] == '|') 
			{
				_NPC[i].down = false;
				_NPC[i].moveCount = 0;
			}
			else if (!(maze[_NPC[i].m_cLocation.X][_NPC[i].m_cLocation.Y + 1] == '|') && 
				!(_NPC[i].m_cLocation.Y + 1 == g_sChar.m_cLocation.Y && _NPC[i].m_cLocation.X == g_sChar.m_cLocation.X))
			{
				_NPC[i].m_cLocation.Y++; //move once
				_NPC[i].moveCount--;	//subtract move count once
				if (_NPC[i].moveCount == 0)	
				{
					_NPC[i].down = false;
				}
			}
		}
	}
}