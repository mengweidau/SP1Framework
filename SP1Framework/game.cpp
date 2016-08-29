// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include "dialogue.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "pressureplate.h"
#include "Battery.h"
#include "Vision.h"
#include "Leaderboard.h"
#include "blocks.h"
using namespace std;

char maze[77][30];
ESCENES currentScene = SCENE1;

double  g_dElapsedTime;
double g_dElapsedTimeSec = g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
double waitTime = 0.0;
double delayFor = 0.0;
bool canPress = true;
bool newMap = true;
int currentlevel = 1;

// Game specific variables here
SGameChar   g_sChar;
Blocks _block[blockNum];
SGameNPC _NPC[npcNum];
Fairy _fairy;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once


// Console object
 Console g_Console(77, 25, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
 void init(void)
 {
	 // Set precision for floating point output
	 g_dElapsedTime = 0.0;
	 g_dBounceTime = 0.0;

	 // sets the initial state for the game
	 g_eGameState = S_SPLASHSCREEN;
	 PlaySound(TEXT("playMUSIC/Music/MainMenusnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	 g_sChar.m_cLocation.X = 45;
	 g_sChar.m_cLocation.Y = 2;

	 // sets the width, height and the font name to use in the console
	 g_Console.setConsoleFont(0, 16, L"");
	 beginningcutscene();
 }

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{    
    g_abKeyPressed[K_UP]     = isKeyPressed(VK_UP);
    g_abKeyPressed[K_DOWN]   = isKeyPressed(VK_DOWN);
    g_abKeyPressed[K_LEFT]   = isKeyPressed(VK_LEFT);
    g_abKeyPressed[K_RIGHT]  = isKeyPressed(VK_RIGHT);

	g_abKeyPressed[K_SELECTUP] = isKeyPressed(0x57);
	g_abKeyPressed[K_SELECTDOWN] = isKeyPressed(0x53);
	g_abKeyPressed[K_FLASH] = isKeyPressed(0x46);

    g_abKeyPressed[K_SPACE]  = isKeyPressed(VK_SPACE);
    g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_ENTER] = isKeyPressed(VK_RETURN);

	g_abKeyPressed[K_1] = isKeyPressed(VK_1);
	g_abKeyPressed[K_2] = isKeyPressed(VK_2);
	g_abKeyPressed[K_3] = isKeyPressed(VK_3);
	g_abKeyPressed[K_4] = isKeyPressed(VK_4);
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
	g_dDeltaTime = dt;
	g_dElapsedTimeSec += dt;

    switch (g_eGameState)
    {
		case S_BEGIN: beginningcutscene();//to show cutscene
			break;
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
		case S_SPLASHSCREEN2 : splashScreenWait2(); // game logic for the splash screen (lea)
			break;
		case S_SPLASHSCREEN3: splashScreenWait3(); // game logic for the splash screen (credits)
			break;
		case S_SPLASHSCREEN4: splashScreenWait4(); // game logic for the splash screen (credits)
			break;
		case S_SELECTLEA: renderLeaderboardlogic(); //game logic for the leaderboard screen
			break;
		case S_SELECTCRE: renderCreditsLogic(); //game logic for the credits
			break;
		case S_SELECTMODE:  renderSelectmodeLogic();//game logic for the select mode
			break;
		case S_SELECTMODE2:  renderSelectmode2Logic();//game logic for the select mode
			break;
		case S_SELECTMODE3:  renderSelectmode3Logic();//game logic for the select mode
			break;
		case S_SELECTMODE4:  renderSelectmode4Logic();//game logic for the select mode
			break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
    }

	if (maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '*')
	{
		currentlevel++;
		newMap = true;
	}
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
		case S_BEGIN: rendercutscene();
			break;
        case S_SPLASHSCREEN: renderSplashScreen();
            break;
		case S_SPLASHSCREEN2 : renderSplashScreen2();
			break;
		case S_SPLASHSCREEN3: renderSplashScreen3();
			break;
		case S_SPLASHSCREEN4: renderSplashScreen4();
			break;
		case S_SELECTMODE: renderSelectmode();
			break;
		case S_SELECTMODE2: renderSelectmode2();
			break;
		case S_SELECTMODE3: renderSelectmode3();
			break;
		case S_SELECTMODE4: renderSelectmode4();
			break;
		case S_SELECTLEA: renderLeaderboard();
			break;
		case S_SELECTCRE: renderCredits();
			break;
        case S_GAME: renderGame();
            break;
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void setBounceTime(float delay)
{
	g_dBounceTime = g_dElapsedTime + delay;
}

void splashScreenWait()    //for the options on the splashscreen
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE;
	}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN2;
	}
}

void splashScreenWait2()    //for the options on the splashscreen
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTLEA;
	}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN3;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN;
	}
}

void splashScreenWait3()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTCRE;
	}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN4;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN2;
	}
}

void splashScreenWait4()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_bQuitGame = true;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN3;
	}
}

void gameplay()         // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter(_block);    // moves the character, collision detection, physics, etc
	timeDelay(_NPC);
	Batterylife();
	moveBlocks(_block, g_sChar);
	respawnBlocks(_block);
	//NpcPatrol(_NPC, g_sChar);
	switches();			// so it can always update 
	pressureplate(_block);	// plates updated continuously for the true and false conditions
}

void moveCharacter(Blocks _block[])
{
	bool bSomethingHappened = false;
	bool slowingdwn = false;

	if (g_dBounceTime > g_dElapsedTime)
		return;

	
		if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0) //press up
		{
			if (!(maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '|' || // NO Walls or Gates in the way
				maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'X' ||	// '|' are walls, 'X' & 'T' are Gates
				maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' ))
			{
				g_sChar.moveUp = true;
			}
			for (int i = 0; i < npcNum; i++)
			{
				if (g_sChar.m_cLocation.X == _NPC[i].m_cLocation.X && g_sChar.m_cLocation.Y - 1 == _NPC[i].m_cLocation.Y)
				{
					g_sChar.moveUp = false;
				}
			}
		}

		if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0) //press left
		{
			if (!(maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '|' || // NO Walls or Gates in the way
				maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'X' ||
				maze[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T'))
			{
				g_sChar.moveLeft = true; // then CAN move
			}
			for (int i = 0; i < npcNum; i++)
			{
				if (g_sChar.m_cLocation.X - 1 == _NPC[i].m_cLocation.X && g_sChar.m_cLocation.Y == _NPC[i].m_cLocation.Y)
				{
					g_sChar.moveLeft = false;
				}
			}
		}

		if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1) //press down
		{
			if (!(maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '|' ||	// NO Walls or Gates in the way
				maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'X' ||
				maze[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T'))
			{
				g_sChar.moveDown = true; // then CAN move
			}
			for (int i = 0; i < npcNum; i++)
			{
				if (g_sChar.m_cLocation.X == _NPC[i].m_cLocation.X && g_sChar.m_cLocation.Y + 1 == _NPC[i].m_cLocation.Y)
				{
					g_sChar.moveDown = false;
				}
			}
		}

		if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1) //press right
		{
			if (!(maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '|' ||	// NO Walls or Gates in the way
				maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'X' ||
				maze[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T'))
			{
				g_sChar.moveRight = true; // then CAN move
			}
			for (int i = 0; i < npcNum; i++)
			{
				if (g_sChar.m_cLocation.X + 1 == _NPC[i].m_cLocation.X && g_sChar.m_cLocation.Y == _NPC[i].m_cLocation.Y)
				{
					g_sChar.moveRight = false;
				}
			}
		}
		for (int i = 0; i < npcNum; i++)
		{
			if (!(g_sChar.m_cLocation.X >(_NPC[i].m_cLocation.X) + 1) && !(g_sChar.m_cLocation.X < (_NPC[i].m_cLocation.X) - 1) && //check horizontal by 1 and vertical by 1
				!(g_sChar.m_cLocation.Y >(_NPC[i].m_cLocation.Y) + 1) && !(g_sChar.m_cLocation.Y < (_NPC[i].m_cLocation.Y) - 1))
			{
				if (g_abKeyPressed[K_SPACE] && _NPC[i].talked == false)
				{
					waitTime = g_dElapsedTime + 6.0; //sets waitTime with current elapsedTime + delay
					bSomethingHappened = true;
					_NPC[i].talked = true; //sets NPC bool to true, increment tolerance by 1
					_NPC[i].tolerance++;
				}
			}
		}
		
	
	//Charcter struct has new booleans added
	if (g_sChar.moveUp == true) // When CHARACTER's moveUp == true
	{
		g_sChar.m_cLocation.Y--;// Can move up, and something happened = true
		g_sChar.lastKnownMove = 1;
		bSomethingHappened = true;
	}
	if (g_sChar.moveDown == true) // When CHARACTER's moveDown == true
	{
		g_sChar.m_cLocation.Y++;// Can move down, and something happened = true
		g_sChar.lastKnownMove = 2;
		bSomethingHappened = true;
	}
	if (g_sChar.moveRight == true)// When CHARACTER's moveRight == true
	{
		g_sChar.m_cLocation.X++;// Can move right, and something happened = true
		g_sChar.lastKnownMove = 3;
		bSomethingHappened = true;
	}
	if (g_sChar.moveLeft == true)// When CHARACTER's moveLeft == true
	{
		g_sChar.m_cLocation.X--;// Can move left, and something happened = true
		g_sChar.lastKnownMove = 4;
		bSomethingHappened = true;
	}

	if (bSomethingHappened) //if somethingHappened == true
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough      <---- Delay Input
		g_sChar.moveUp = false;					// Set ALL move bool to false
		g_sChar.moveRight = false;
		g_sChar.moveLeft = false;
		g_sChar.moveDown = false;
	}
	if (slowingdwn)
	{
		g_dBounceTime = g_dElapsedTime + 0.325;
	}
}

void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
		if (g_dElapsedTimeSec != 0)
		{
			leaderboard(to_string(g_dElapsedTimeSec));
		}
	}
}
void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x40);
}

void renderSplashScreen()  // renders the splash screen (title screen)
{
	/*rendercutscene();
*/
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 25;

	string line;
	ifstream myfile("main_menu.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 27;
	g_Console.writeToBuffer(c, "Start game", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Leaderboard", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Credits", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 4;
	g_Console.writeToBuffer(c, "Quit", 0x47);

	c.Y += 5;
	c.X = g_Console.getConsoleSize().X / 2 - 15;
	g_Console.writeToBuffer(c, "w - select up, s - select down", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 10;
	g_Console.writeToBuffer(c, "enter - select option", 0x47);
}

void renderSplashScreen2()  // renders the splash screen (title screen)
{
	/*rendercutscene();*/

	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 25;

	string line;
	ifstream myfile("main_menu.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 27;
	g_Console.writeToBuffer(c, "Start game", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Leaderboard", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Credits", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 4;
	g_Console.writeToBuffer(c, "Quit", 0x47);

	c.Y += 5;
	c.X = g_Console.getConsoleSize().X / 2 - 15;
	g_Console.writeToBuffer(c, "w - select up, s - select down", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 10;
	g_Console.writeToBuffer(c, "enter - select option", 0x47);
}

void  renderSplashScreen3()
{
	/*rendercutscene();
*/
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 25;

	string line;
	ifstream myfile("main_menu.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 27;
	g_Console.writeToBuffer(c, "Start game", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Leaderboard", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Credits", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 4;
	g_Console.writeToBuffer(c, "Quit", 0x47);

	c.Y += 5;
	c.X = g_Console.getConsoleSize().X / 2 - 15;
	g_Console.writeToBuffer(c, "w - select up, s - select down", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 10;
	g_Console.writeToBuffer(c, "enter - select option", 0x47);
}

void  renderSplashScreen4()
{
	/*rendercutscene();*/

	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 25;

	string line;
	ifstream myfile("main_menu.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 27;
	g_Console.writeToBuffer(c, "Start game", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Leaderboard", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Credits", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 4;
	g_Console.writeToBuffer(c, "Quit", 0x74);

	c.Y += 5;
	c.X = g_Console.getConsoleSize().X / 2 - 15;
	g_Console.writeToBuffer(c, "w - select up, s - select down", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 10;
	g_Console.writeToBuffer(c, "enter - select option", 0x47);
}

void renderSelectmode()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 18;

	string line;
	ifstream myfile("selectmode.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 23;
	g_Console.writeToBuffer(c, "Story", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Level editor", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "Quit", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Back", 0x47);
}

void renderSelectmode2()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 18;

	string line;
	ifstream myfile("selectmode.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 23;
	g_Console.writeToBuffer(c, "Story", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Level editor", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "Quit", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Back", 0x47);
}

void renderSelectmode3()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 18;

	string line;
	ifstream myfile("selectmode.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 23;
	g_Console.writeToBuffer(c, "Story", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Level editor", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "Quit", 0x74);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Back", 0x47);
}

void renderSelectmode4()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 18;

	string line;
	ifstream myfile("selectmode.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}

	c.Y += 3;
	c.X = c.X / 2 + 23;
	g_Console.writeToBuffer(c, "Story", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Level editor", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "Quit", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Back", 0x74);
}

void renderSelectmodeLogic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_eGameState = S_GAME;
		g_dElapsedTimeSec = 0;
		g_dBounceTime = 0;
	}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE2;
	}
}

void renderSelectmode2Logic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	//if (g_abKeyPressed[K_ENTER]) // when enter go to LEVEL EDITOR screen
	//{
	//	setBounceTime(0.3);
	//	g_eGameState = S_GAME;
	//}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE3;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE;
	}
}

void renderSelectmode3Logic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when ENTER ,QUIT
	{
		setBounceTime(0.3f);
		g_bQuitGame = true; ;
	}
	if (g_abKeyPressed[K_SELECTDOWN])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE4;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE2;
	}
}

void renderSelectmode4Logic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER]) // when enter go to select screen
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN;
	}
	if (g_abKeyPressed[K_SELECTUP])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SELECTMODE3;
	}
}

void renderLeaderboardlogic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN;
	}
}

void renderCredits()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 0;
	c.X = c.X / 2 - 20;

	string line;
	ifstream myfile("credits.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line, 0x37);
			c.Y++;
		}
		myfile.close();
	}
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, " ", 0x47); 
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, " ", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Done by : ", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, " ", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Wafieqa", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Jolyn", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Brandon", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Meng Wei", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, " ", 0x47);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 6;
	g_Console.writeToBuffer(c, "Back", 0x74);
}

void renderCreditsLogic()
{
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_ENTER])
	{
		setBounceTime(0.3f);
		g_eGameState = S_SPLASHSCREEN;
	}
}

void renderGame()
{
    renderMap(currentlevel);        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
	renderVision(_NPC, _block); // Fog Of War
	renderBattery(); // Flashlight battery
	renderDialogue(&_fairy);	//render dialogues
}

void maps(int level)
{
	COORD c = g_Console.getConsoleSize();
	int height = 0;
	int width = 0;

	string mapname = " ";

	switch (level)
	{
	case 0:
		mapname = "tutorial.txt";
		//PlaySound(TEXT("playMUSIC/Music/Mapsnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		break;
	case 1:
		mapname = "map1.txt";
		//PlaySound(TEXT("playMUSIC/Music/Mapsnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		break;
	case 2:
		mapname = "map2.txt";
		break;
	case 3:
		mapname = "map3.txt";
		break;
	case 4:
		mapname = "fairymap.txt";
		break;
	}

	ifstream file(mapname);
	if (file.is_open())
	{
		blocks(_block);
		Npc(_NPC);
		while (height < 30)
		{
			while (width < 77)
			{
				file >> maze[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	////tutorial stage
	//if (g_abKeyPressed[K_ENTER] && currentMap == Map0)
	//{
	//	currentMap = Map0; //Map0, tutorial.txt
	//	ifstream file("tutorial.txt");
	//	if (file.is_open())
	//	{
	//		blocks(_block);
	//		PlaySound(TEXT("playMUSIC/Music/Mapsnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> maze[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	////start
	//if (currentMap== Map0)
	//{
	//	if (g_sChar.m_cLocation.X == 32 && g_sChar.m_cLocation.Y == 2)
	//	{
	//		currentMap = Map1;
	//		ifstream file("map1.txt");
	//		if (file.is_open())
	//		{	//This is still counted as Map0
	//			PlaySound(TEXT("playMUSIC/Music/Mapsnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//			while (height < 30)
	//			{
	//				while (width < 77)
	//				{
	//					file >> maze[width][height];
	//					width++;
	//				}
	//				width = 0;
	//				height++;
	//			}
	//			file.close();
	//		}
	//	}
	//}

	////goto the maps

	//if (currentMap == Map1)
	//{
	//	Npc(_NPC);
	//	_NPC[0].tolerance = 0;
	//	_NPC[1].tolerance = 0;
	//	//towards
	//	if (g_sChar.m_cLocation.X == 75 && g_sChar.m_cLocation.Y == 9)
	//	{
	//		currentMap = Map2;
	//		ifstream file("map2.txt");
	//		if (file.is_open())
	//		{
	//			//spawn npc positions
	//			Npc(_NPC);
	//			//set new position for npc1,2 to avoid collision 
	//			_NPC[0].m_cLocation.X = 0;
	//			_NPC[0].m_cLocation.Y = 0;
	//			_NPC[1].m_cLocation.X = 0;
	//			_NPC[1].m_cLocation.Y = 0;
	//			while (height < 30)
	//			{
	//				while (width < 77)
	//				{
	//					file >> maze[width][height];
	//					width++;
	//				}
	//				width = 0;
	//				height++;
	//			}
	//			file.close();
	//		}
	//	}
	//}

	//if (currentMap == Map2)
	//{
	//	//towards
	//	if (g_sChar.m_cLocation.X == 1 && g_sChar.m_cLocation.Y == 4)
	//	{
	//		currentMap = Map3;
	//		ifstream file("map3.txt");
	//		if (file.is_open())
	//		{
	//			//spawn npc positions
	//			Npc(_NPC);
	//			//set new position for npc3 to avoid collision 
	//			_NPC[2].m_cLocation.X = 0;
	//			_NPC[2].m_cLocation.Y = 0;
	//			while (height < 19)
	//			{
	//				while (width < 77)
	//				{
	//					file >> maze[width][height];
	//					width++;
	//				}
	//				width = 0;
	//				height++;
	//			}
	//			file.close();
	//		}
	//	}
	//}

	//if (currentMap == Map3)
	//{
	//	if (g_sChar.m_cLocation.X == 3 && g_sChar.m_cLocation.Y == 9)
	//	{
	//		currentMap = Map4;
	//		ifstream file("fairymap.txt");
	//		if (file.is_open())
	//		{
	//			//spawn npc positions
	//			Npc(_NPC);
	//			//set new position for npc4,5,6 to avoid collision
	//			_NPC[3].m_cLocation.X = 0;
	//			_NPC[3].m_cLocation.Y = 0;
	//			_NPC[4].m_cLocation.X = 0;
	//			_NPC[4].m_cLocation.Y = 0;
	//			_NPC[5].m_cLocation.X = 0;
	//			_NPC[5].m_cLocation.Y = 0;
	//			PlaySound(TEXT("playMUSIC/Music/Fairysnd.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//			while (height < 19)
	//			{
	//				while (width < 77)
	//				{
	//					file >> maze[width][height];
	//					width++;
	//				}
	//				width = 0;
	//				height++;
	//			}
	//			file.close();
	//		}
	//	}
	//}
}

void renderMap(int level)
{
	COORD c = g_Console.getConsoleSize();

	if (newMap)
	{
		newMap = false;
		maps(level);
	}

	for (int y = 0; y < 19; y++)
	{
		c.Y = y;
		for (int x = 0; x < 77; x++)
		{

			if (maze[x][y] == '0')
			{
				maze[x][y] = ' ';
			}

			if (maze[x][y] == 'E')
			{
				maze[x][y] = '*';
			}
			c.X = x;
			if (currentlevel != 0 || currentlevel != 4)
			{
				g_Console.writeToBuffer(c, maze[x][y], 0x00);
			}
			else
			{
				g_Console.writeToBuffer(c, maze[x][y]);
			}
		}
	}

	c.Y += 1;
	c.X = 0;
	g_Console.writeToBuffer(c, "*TALK TO NPCS!!!", 0x74);

}

void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x0F;
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)65, charColor);
}

void renderFramerate()
{
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / g_dDeltaTime << "fps";
	c.X = g_Console.getConsoleSize().X - 9;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	// displays the elapsed time
	if (g_eGameState == S_GAME)
	{
		ss.str("");
		ss << " " << g_dElapsedTimeSec << "secs ";
		c.X = c.X / 2 - 4;
		c.Y = 24;
		g_Console.writeToBuffer(c, ss.str(), 0x70);
	}
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

//interaction with the npc and fairy
void renderDialogue(Fairy *_fairy)
{
	//npc dialogue position
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = (c.Y / 2) + 8;
	string value;

	//checks each npc's condition
	for (int i = 0; i < npcNum; i++)
	{
		if (_NPC[i].talked == true)
		{
			value = dialogue(_NPC[i].tolerance, _NPC);
			g_Console.writeToBuffer(c, value);
		}
	}
}

void beginningcutscene() //beginning cutscence 
{
	//COORD c = g_Console.getConsoleSize();

	//int height = 0;
	//int width = 0;

	////1st frame 
	//if (currentScene == SCENE1)
	//{
	//	ifstream file("animate/frame_1st.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	////2nd frame 
	//if (g_dElapsedTime >= 3.0 && g_dElapsedTime < 6.0)
	//{
	//	currentScene = SCENE2;

	//	ifstream file("animate/frame_2nd.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 6.0 && g_dElapsedTime < 9.0)
	//{
	//	currentScene = SCENE3;

	//	ifstream file("animate/frame_3rd.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}
	//
	//if (g_dElapsedTime >= 9.0 && g_dElapsedTime < 14.0)
	//{
	//	currentScene = SCENE4;

	//	ifstream file("animate/frame_4th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 14.0 && g_dElapsedTime < 17.0)
	//{
	//	currentScene = SCENE5;

	//	ifstream file("animate/frame_5th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 17.0 && g_dElapsedTime < 19.0)
	//{
	//	currentScene = SCENE6;

	//	ifstream file("animate/frame_6th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 19.0 && g_dElapsedTime < 21.0)
	//{
	//	currentScene = SCENE7;

	//	ifstream file("animate/frame_7th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 21.0 && g_dElapsedTime < 23.0)
	//{
	//	currentScene = SCENE8;

	//	ifstream file("animate/frame_8th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 23.0 && g_dElapsedTime < 25.0)
	//{
	//	currentScene = SCENE9;

	//	ifstream file("animate/frame_9th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 25.0 && g_dElapsedTime < 27.0)
	//{
	//	currentScene = SCENE10;

	//	ifstream file("animate/frame_10th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 27.0 && g_dElapsedTime < 30.0)
	//{
	//	currentScene = SCENE11;

	//	ifstream file("animate/frame_11th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 30.0 && g_dElapsedTime < 33.0)
	//{
	//	currentScene = SCENE12;

	//	ifstream file("animate/frame_12th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 33.0 && g_dElapsedTime < 37.0)
	//{
	//	currentScene = SCENE13;

	//	ifstream file("animate/frame_13th.txt");
	//	if (file.is_open())
	//	{
	//		while (height < 19)
	//		{
	//			while (width < 77)
	//			{
	//				file >> ani[width][height];
	//				width++;
	//			}
	//			width = 0;
	//			height++;
	//		}
	//		file.close();
	//	}
	//}

	//if (g_dElapsedTime >= 37.0)
	//{
	//	g_eGameState = S_SPLASHSCREEN;
	//}
}


void rendercutscene()
{
	/*COORD c = g_Console.getConsoleSize();

	for (int y = 0; y < 19; y++)
	{
		c.Y = y;
		for (int x = 0; x < 77; x++)
		{

			if (ani[x][y] == '0')
			{
				ani[x][y] = ' ';
			}

			c.X = x;
			g_Console.writeToBuffer(c, ani[x][y]);
		}
	}

	if (currentScene == SCENE4)
	{
		for (int y = 0; y < 19; y++)
		{
			c.Y = y;
			for (int x = 0; x < 77; x++)
			{
				if (ani[x][y] == '0')
				{
					ani[x][y] = ' ';
				}
				if (ani[x][y] == 'K')
				{
					ani[x][y] = '?';
				}
				if (ani[x][y] == 'J')
				{
					ani[x][y] = '!';
				}

				c.X = x;
				g_Console.writeToBuffer(c, ani[x][y]);
			}
		}

		c.Y += 1;
		c.X = g_Console.getConsoleSize().X / 2 - 13;
		g_Console.writeToBuffer(c, "Get lost old hag", 0x74);

	}

	if (currentScene == SCENE13)
	{
		for (int y = 0; y < 19; y++)
		{
			c.Y = y;
			for (int x = 0; x < 77; x++)
			{
				if (ani[x][y] == '0')
				{
					ani[x][y] = ' ';
				}
				c.X = x;
				g_Console.writeToBuffer(c, ani[x][y]);
			}
		}

		c.Y += 1;
		c.X = g_Console.getConsoleSize().X / 2 - 37;
		g_Console.writeToBuffer(c, "Kekeke...lets see if he can...", 0x74);
	}*/
}