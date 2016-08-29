#include "blocks.h"

//initialize blocks position for each map, check bool for block respawn
void blocks(Blocks _block[])
{
	for (int i = 0; i < blockNum; i++)
	{
		switch (i)
		{
		case 0:
			if (currentlevel == 0) //tutorial
			{
				_block[i].m_location.X = 44;
				_block[i].m_location.Y = 2;
			}
			break;
		case 1:
			if (currentlevel == 1) //map1
			{
				_block[i].m_location.X = 35; 
				_block[i].m_location.Y = 7;
			}
			break;
		case 2:
			if (currentlevel == 2) //map2
			{
				_block[i].m_location.X = 31;
				_block[i].m_location.Y = 14;
			}
			break;
		case 3:
			if (currentlevel == 3) //map3
			{
				_block[i].m_location.X = 74;
				_block[i].m_location.Y = 10;
			}
			break;
		}
		_block[i].respawn.X = _block[i].m_location.X;
		_block[i].respawn.Y = _block[i].m_location.Y;
	}
}

void moveBlocks(Blocks _block[], SGameChar g_sChar)
{
	for (int i = 0; i < blockNum; i++)
	{
		if ((g_sChar.m_cLocation.Y == _block[i].m_location.Y && g_sChar.m_cLocation.X == _block[i].m_location.X)) //character pos is on block pos
		{
			switch (g_sChar.lastKnownMove) //check the characters last known move
			{
			case 1: //if 1, move up, AND set lastknowmove to 0, to avoid moving constantly
				_block[i].m_location.Y--;
				g_sChar.lastKnownMove = 0;
				break;
			case 2: //if 2, move down
				_block[i].m_location.Y++;
				g_sChar.lastKnownMove = 0;
				break;
			case 3://if 2, move right
				_block[i].m_location.X++;
				g_sChar.lastKnownMove = 0;
				break;
			case 4://if 2, move left
				_block[i].m_location.X--;
				g_sChar.lastKnownMove = 0;
				break;
			}
		}
	}
}

void respawnBlocks(Blocks _block[])
{
	for (int i = 0; i < blockNum; i++)
	{
		if (maze[_block[i].m_location.X][_block[i].m_location.Y] == '|' ||
			maze[_block[i].m_location.X][_block[i].m_location.Y] == 'X' ||
			maze[_block[i].m_location.X][_block[i].m_location.Y] == 'T')
		{
			_block[i].m_location.X = _block[i].respawn.X;
			_block[i].m_location.Y = _block[i].respawn.Y;
		}
	}	
}