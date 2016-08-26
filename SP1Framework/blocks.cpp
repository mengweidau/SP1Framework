#include "blocks.h"
#include "pressureplate.h"

extern Console g_Console;

extern SGameChar g_block;

void renderblocks()
{
	g_Console.writeToBuffer(g_block.m_cLocation, "#",0x00);

	if (currentMap == Map4)
	{
		g_Console.writeToBuffer(g_block.m_cLocation, "#", 0x00);
	}
}
	

void blocks()
{
	/*COORD c = g_Console.getConsoleSize();

	if (currentMap == Map1)
	{
		g_block.m_cLocation.X = 35;
		g_block.m_cLocation.Y = 7;
	}

	else if (currentMap == Map2)
	{
		g_block.m_cLocation.X = 31;
		g_block.m_cLocation.Y = 14;
	}

	else if (currentMap == Map3)
	{
		g_block.m_cLocation.X = 75;
		g_block.m_cLocation.Y = 10;
	}*/
	
}