#include "game.h"

void Npc(SGameNPC _NPC[])//edited
{
	COORD randomPos[npcNum];
	srand(time(NULL));

	for (int i = 0; i < npcNum; i++) //set random spawn for npcs
	{
		if (currentMap == Map1) //map 1 creates npc 1, 2
		{
			if (i == 0)
			{	//set randrange for npc1
				randomPos[i].X = rand() % 20 + 22;
				randomPos[i].Y = rand() % 4 + 1;

				//set position for npc1
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				_NPC[i].str1 = "ENVY : I  wish I had PRIDE popularity, I think it would be great to have so much attention from everyone. I also want to be able to eat as much as GLUTTONY and not get fat after so much food...But I would want SLOTHs ability to just laze around because I am always so stressed all the time!!";
				_NPC[i].str2 = "ENVY : Go away, you have nothing i want.";
				_NPC[i].talked = false;
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
			if (i == 1)
			{	//set randrange for npc2
				randomPos[i].X = rand() % 4 + 1;
				randomPos[i].Y = (rand() % 2 + 1) + 9;

				//set position for npc2
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				
				_NPC[i].str1 = "SLOTH : I had always been lazy and took the chance to slack off whenever I had the chance to, or in some cases, procrastinating to do my Ruby programming and wait until the day of the deadline. Maybe I should also try to work my way out of this labyrinth… Right after this nap...";
				_NPC[i].str2 = "SLOTH : Zzzz...";
				_NPC[i].talked = false;
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
		}

		else if (currentMap == Map2)//map 2 creates npc 3
		{
			if (i == 2)
			{	//set randrange for npc3
				randomPos[i].X = (rand() % 9 + 1) + 52;
				randomPos[i].Y = (rand() % 2 + 1) + 6;

				//set position for npc3
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				_NPC[i].str1 = "GREED : I always liked to have many things to myself, especially my hard-earned money $$$. I never liked to share my own possessions, even if it’s just a few cents. My measly income of $22.5k/month isn’t going to let me live a comfortable life.";
				_NPC[i].str2 = "GREED : Any more information about me is gonna cost you $$$.";
				_NPC[i].talked = false;
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
		}

		else if (currentMap == Map3)//map 2 creates npc 4,5,6
		{
			if (i == 3)
			{	//set randrange for npc4
				randomPos[i].X = (rand() % 6 + 1) + 18;
				randomPos[i].Y = (rand() % 3 + 1) + 5;

				//set position for npc4 // left
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				
				_NPC[i].str1 = "GLUTTONY : I love to go around to different restaurants in my town to eat various gourmet food ranging from cheesecakes to steak ~! Maybe I should visit Cornerstone,that restaurant PRIDE posted on his Facebook after I get out of this labyrinth…";
				_NPC[i].str2 = "GLUTTONY : I’m too hungry to talk to you…";
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
			if (i == 4)
			{	//set randrange for npc5
				randomPos[i].X = (rand() % 8 + 1) + 63;
				randomPos[i].Y = (rand() % 1) + 4;

				//set position for npc5 //right
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				
				_NPC[i].str1 = "LUST : I always desire to have so many things to myself, like that sleek new Bugatti which I saw on the street the other day… Or maybe the new IPhone that came out just a few days ago… Better yet, I also would like PRIDE’s new partner… heh…";
				_NPC[i].str2 = "LUST : Among all the things I want, talking to you is not one of them.";
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
			if (i == 5)
			{	//set randrange for npc6 //mid
				randomPos[i].X = (rand() % 14 + 1) + 48;
				randomPos[i].Y = (rand() % 1) + 11;

				//set position for npc6
				_NPC[i].m_cLocation.X = randomPos[i].X;
				_NPC[i].m_cLocation.Y = randomPos[i].Y;
				
				_NPC[i].str1 = "PRIDE : I was an avid Instagrammer as well as a regular Facebook poster. I had 36948 friends and 64268 followers on my social media so I don’t know why I’m punished even though I’m so popular!";
				_NPC[i].str2 = "PRIDE : I have no more time for you, I need to make sure I get out of here.";
				//set npc movement
				_NPC[i].right = true;
				_NPC[i].left = false;
				_NPC[i].up = false;
				_NPC[i].down = false;
				_NPC[i].moveCount = 3;
			}
		}
	}
}