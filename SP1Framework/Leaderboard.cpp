#include "Leaderboard.h"
#include <vector>
extern Console g_Console;

void leaderboard(string recordtime)
{
	fstream myfile;
	myfile.open("leaderboard.txt", fstream::app);
	myfile << recordtime << "\n";
}
void renderLeaderboard()
{
	COORD c = g_Console.getConsoleSize();
	c.Y = 0;
	c.X = c.X / 2 - 25;

	string line;
	ifstream myFile("leaderboardtitle.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line,0x37);
		}
		myFile.close();
	}
	double topscores[10] = { 0.0, }; // to contain the top 10 scores to print out in leaderboards.
	double possiblescores[500] = { 0.0, }; // to contain all possible scores (can increase array size to fit more than 150 entries).

	int i = 0;

	ifstream myfile("leaderboard.txt");
	if (myfile.is_open())
	{		
		while (getline(myfile, line))
		{	
			possiblescores[i] = atof(line.c_str()); // after getting all the timings from txt file , convert it from string to double value
			i++; // check how many timings you have in total
		}	
		myfile.close();
	}
	for (int topscoresCount = 0; topscoresCount < 10; topscoresCount++)	// runs 10 times for 10 highscores
	{
		double topScore = 0;	
		for (int a = 0; a < i; a++) // runs for every timing in the txt file
		{	
			if (topScore == 0) // this is to set the highest possible timing when leaderboard resets
			{	
				topScore = 99999999; // sets the benchmark for timing
			}
			if (topScore > possiblescores[a]) //checks if the highscore is slower than the possiblescores recorded
			{	
				bool inArray = false; // makes boolean false
				for (int c = 0; c < 10; c++) // checks all the topscores in highscore to check if the time that was faster than the highscore is not already in the topscores
				{	
					if (topscores[c] == possiblescores[a])
					{
						inArray = true; // makes boolean true if there is alreaady the timing in the topscores
					}
				}
				if (!inArray)	// if the timing is not already recorded , it takes over the current highscore 
				{
					topScore = possiblescores[a];
				}
			}
		}
		topscores[topscoresCount] = topScore;
	}

	for (int b = 0; b < i && b < 10; b++)
	{
		std::string str;
		char digits[50];
		str = to_string(topscores[b]);

		std::strcpy(digits, str.c_str());

		/*
		to_string() function coverts your double data type to string.
		str.c_str() inside the strcpy makes your string data type into char array digits[].

		std::strcpy(digits, str.c_str()) copies the 'str' into char array digits[].
		
		*/

		c.X = g_Console.getConsoleSize().X / 2 -10;
		c.Y += 1;
		g_Console.writeToBuffer(c, digits , 0x47);
		COORD secsCoord;
		secsCoord.X = g_Console.getConsoleSize().X / 2;
		secsCoord.Y = c.Y;
		g_Console.writeToBuffer(secsCoord, " secs",0x47);
	}
	c.Y = 22;
	c.X = 70;
	g_Console.writeToBuffer(c, "Back", 0x74);

}
