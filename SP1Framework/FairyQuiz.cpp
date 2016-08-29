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

void FairyQuiz(Fairy *_fairy, Console *g_Console)
{
	if ((*_fairy).fairyTrigger == true)
	{
		COORD c = (*g_Console).getConsoleSize();
		c.X = (c.X / 2) - 8;
		c.Y = 20;

		switch ((*_fairy).currentQuestionNum) //add bool for reset to map1, and set requirements REMEMBER
		{
		case 0://QUESTION 1
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]);//draw question
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check player input
			{
			case 1://correct ans
				(*_fairy).currentQuestionNum++;
				break;
			case 2: //wrong ans
			case 3:
			case 4:
				(*_fairy).wrongAns = true;
			}
			break;
		case 1://QUESTION 2
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]); //draw question 2
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check input
			{
			case 4: //correct ans
				(*_fairy).currentQuestionNum++;
				break;
			case 1://wrong ans
			case 2:
			case 3:
				(*_fairy).wrongAns = true;
			}
			break;
		case 2://QUESTION 3
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]);// draw question 3
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check input
			{
			case 4://correct ans
				(*_fairy).currentQuestionNum++;
				break;
			case 1://wrong ans
			case 2:
			case 3:
				(*_fairy).wrongAns = true;
			}
			break;
		case 3: //QUESTION 4
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]);//draw question 4
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check input
			{
			case 1://correct ans
				(*_fairy).currentQuestionNum++;
				break;
			case 2://wrong ans
			case 3:
			case 4:
				(*_fairy).wrongAns = true;
			}
			break;
		case 4:// QUESTION 5
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]);//draw question 5
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check input
			{
			case 1://correct ans
				(*_fairy).currentQuestionNum++;
				break;
			case 2://wrong ans
			case 3:
			case 4:
				(*_fairy).wrongAns = true;
			}
			break;
		case 5://QUESTION 6
			(*g_Console).writeToBuffer(c, (*_fairy).question[(*_fairy).currentQuestionNum]);//draw question 6
			for (int i = 0; i < 4; i++)//draw answers 
			{
				c.Y++;
				(*g_Console).writeToBuffer(c, (*_fairy).ans[i]);
			}
			switch ((*_fairy).playerInput)//check input
			{
			case 1://correct ans
				   //inset something that tells you finished the game
				break;
			case 2://wrong ans
			case 3:
			case 4:
				(*_fairy).wrongAns = true;
			}
			break;
		}
	}
	if ((*_fairy).wrongAns == true)
	{
		/*currentlevel = 1;
		(*_fairy).currentQuestionNum = 0;
		(*_fairy).wrongAns = false;*/
	}
}