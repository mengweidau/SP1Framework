#include "game.h"
#include "Framework\console.h"


void FairyQuestion(Fairy *_fairy, SGameChar *g_sChar, Console *g_Console)
{
	if ((*_fairy).currentQuestionNum == 0)//question 1 //set answers for each questions
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "How many Facebook friends does PRIDE have?";
		(*_fairy).ans[0] = "1. 39648";
		(*_fairy).ans[1] = "2. 36948";
		(*_fairy).ans[2] = "3. 36498";
		(*_fairy).ans[3] = "4. 34986";
	}
	if ((*_fairy).currentQuestionNum == 1)//question 2
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "Who did ENVY not mention in her dialogue?";
		(*_fairy).ans[0] = "1. SLOTH";
		(*_fairy).ans[1] = "2. PRIDE";
		(*_fairy).ans[2] = "3. GLUTTONY";
		(*_fairy).ans[3] = "4. LUST";
	}
	if ((*_fairy).currentQuestionNum == 2)//question 3
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "Where did GLUTTONY want to eat at?";
		(*_fairy).ans[0] = "1. Cornerstreet";
		(*_fairy).ans[1] = "2. Cornerstand";
		(*_fairy).ans[2] = "3. Cornerstop";
		(*_fairy).ans[3] = "4. Cornerstone";
	}
	if ((*_fairy).currentQuestionNum == 3)//question 4
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "What brand of car did LUST want?";
		(*_fairy).ans[0] = "1. Bugatti";
		(*_fairy).ans[1] = "2. Jaguar";
		(*_fairy).ans[2] = "3. Porsche";
		(*_fairy).ans[3] = "4. Bentley";
	}
	if ((*_fairy).currentQuestionNum == 4)//question 5
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "What programming language did SLOTH learn?";
		(*_fairy).ans[0] = "1. Ruby";
		(*_fairy).ans[1] = "2. Python";
		(*_fairy).ans[2] = "3. Java";
		(*_fairy).ans[3] = "4. Brainf***";
	}
	if ((*_fairy).currentQuestionNum == 5)//question 6
	{
		(*_fairy).question[(*_fairy).currentQuestionNum] = "How much money does GREED make in a year?";
		(*_fairy).ans[0] = "1. 270K";
		(*_fairy).ans[1] = "2. 254K";
		(*_fairy).ans[2] = "3. 258K";
		(*_fairy).ans[3] = "4. 264K";
	}

	//if player is more than fairy position.x, fairy trigger = true
	if (currentlevel == 4)
	{
		(*_fairy).fairyPos = (*g_Console).getConsoleSize();
		(*_fairy).fairyPos.X = (*_fairy).fairyPos.X / 2;  //fairy trigger coord = consoleSize.x / 2 

		if ((*g_sChar).m_cLocation.X > (*_fairy).fairyPos.X) // player enters across fairy trigger coord, trigger = true
		{
			(*_fairy).fairyTrigger = true;
		}
	}
}
