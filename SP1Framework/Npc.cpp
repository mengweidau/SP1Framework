#include "game.h"

void Npc(SGameNPC _NPC[])//edited
{
	COORD randomPos[npcNum];
	srand(time(NULL));

	for (int i = 0; i < npcNum; i++)
	{
		switch (currentlevel)
		{
		case 1: //level 1
			switch (i)
			{
			case 0://npc 1
				randomPos[i].X = rand() % 20 + 22;
				randomPos[i].Y = rand() % 4 + 1;

				_NPC[i].str1 = "ENVY : I  wish I had PRIDE popularity, I think it would be great to have so much attention from everyone. I also want to be able to eat as much as GLUTTONY and not get fat after so much food...But I would want SLOTHs ability to just laze around because I am always so stressed all the time!!";
				_NPC[i].str2 = "ENVY : Go away, you have nothing i want.";
				_NPC[i].talked = false;
				break;
			case 1://npc 2
				randomPos[i].X = rand() % 4 + 1;
				randomPos[i].Y = (rand() % 2 + 1) + 9;

				_NPC[i].str1 = "SLOTH : I had always been lazy and took the chance to slack off whenever I had the chance to, or in some cases, procrastinating to do my Ruby programming and wait until the day of the deadline. Maybe I should also try to work my way out of this labyrinth… Right after this nap...";
				_NPC[i].str2 = "SLOTH : Zzzz...";
				_NPC[i].talked = false;
				break;
			}
			break;
		case 2: //level 2
			switch (i)
			{
			case 2://npc 3
				randomPos[i].X = (rand() % 9 + 1) + 52;
				randomPos[i].Y = (rand() % 2 + 1) + 6;

				_NPC[i].str1 = "GREED : I always liked to have many things to myself, especially my hard-earned money $$$. I never liked to share my own possessions, even if it’s just a few cents. My measly income of $22.5k/month isn’t going to let me live a comfortable life.";
				_NPC[i].str2 = "GREED : Any more information about me is gonna cost you $$$.";
				_NPC[i].talked = false;
				break;
			}
			break;
		case 3: //level 3
			switch (i)
			{
			case 3://npc 4
				randomPos[i].X = (rand() % 6 + 1) + 18;
				randomPos[i].Y = (rand() % 3 + 1) + 5;

				_NPC[i].str1 = "GLUTTONY : I love to go around to different restaurants in my town to eat various gourmet food ranging from cheesecakes to steak ~! Maybe I should visit Cornerstone,that restaurant PRIDE posted on his Facebook after I get out of this labyrinth…";
				_NPC[i].str2 = "GLUTTONY : I’m too hungry to talk to you…";
				break;
			case 4://npc 5
				randomPos[i].X = (rand() % 8 + 1) + 63;
				randomPos[i].Y = (rand() % 1) + 4;

				_NPC[i].str1 = "LUST : I always desire to have so many things to myself, like that sleek new Bugatti which I saw on the street the other day… Or maybe the new IPhone that came out just a few days ago… Better yet, I also would like PRIDE’s new partner… heh…";
				_NPC[i].str2 = "LUST : Among all the things I want, talking to you is not one of them.";
				break;
			case 5://npc 6
				randomPos[i].X = (rand() % 14 + 1) + 48;
				randomPos[i].Y = (rand() % 1) + 11;

				_NPC[i].str1 = "PRIDE : I was an avid Instagrammer as well as a regular Facebook poster. I had 36948 friends and 64268 followers on my social media so I don’t know why I’m punished even though I’m so popular!";
				_NPC[i].str2 = "PRIDE : I have no more time for you, I need to make sure I get out of here.";
				break;
			}
			break;
		}
		_NPC[i].m_cLocation.X = randomPos[i].X;
		_NPC[i].m_cLocation.Y = randomPos[i].Y;
	}
}