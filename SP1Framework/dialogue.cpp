#include "dialogue.h"
#include "game.h"

string dialogue(int tolerance, SGameNPC _NPC[])
{
	string toReturn;

	if (_NPC[0].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: 
			toReturn = _NPC[0].str1;
			break;
		default:
			toReturn = _NPC[0].str2;
			break;
		}
	}
	if (_NPC[1].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			toReturn = _NPC[1].str1;
			break;
		default:
			toReturn = _NPC[1].str2;
			break;
		}
	}
	if (_NPC[2].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			toReturn = _NPC[2].str1;
			break;
		default:
			toReturn = _NPC[2].str2;
			break;
		}
	}
	if (_NPC[3].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			toReturn = _NPC[3].str1;
			break;
		default:
			toReturn = _NPC[3].str2;
			break;
		}
	}
	if (_NPC[4].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			toReturn = _NPC[4].str1;
			break;
		default:
			toReturn = _NPC[4].str2;
			break;
		}
	}
	if (_NPC[5].talked == true)
	{
		switch (tolerance)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			toReturn = _NPC[5].str1;
			break;
		default:
			toReturn = _NPC[5].str2;
			break;
		}
	}

	return toReturn;
}