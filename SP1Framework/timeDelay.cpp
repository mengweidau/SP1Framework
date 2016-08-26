#include "game.h"

void timeDelay(SGameNPC _NPC[])//edited
{
	//delay for dialogue
	for (int i = 0; i < npcNum; i++)
	{
		if (_NPC[i].talked == true)
		{
			if (g_dElapsedTime > waitTime)
			{
				_NPC[i].talked = false;
			}
		}
	}
}