#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "Framework\console.h"
#include "Framework\timer.h"

#define VK_1	0x31
#define VK_2	0x32
#define VK_3	0x33
#define VK_4	0x34

using namespace std;

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;
const unsigned int npcNum = 6; 
const unsigned int blockNum = 4;

extern double  g_dElapsedTime;
extern double waitTime;
extern char maze[77][30];
extern int currentlevel;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_SELECTUP,
	K_SELECTDOWN,
	K_ESCAPE,
	K_SPACE,
	K_ENTER,
	K_START,
	K_BACK,
	K_LEADERBOARD,
	K_CREDITS,
	K_FLASH,
	K_1,
	K_2,
	K_3,
	K_4,
	K_COUNT,
};

//Enumeration for the different animation scenes
enum ESCENES
{
	SCENE1,
	SCENE2,
	SCENE3,
	SCENE4,
	SCENE5,
	SCENE6,
	SCENE7,
	SCENE8,
	SCENE9,
	SCENE10,
	SCENE11,
	SCENE12,
	SCENE13,
};

// Enumeration for the different screen states
enum EGAMESTATES
{
	S_BEGIN,
	S_SPLASHSCREEN,
	S_GAME,
	S_SELECTMODE,
	S_SELECTLEA,
	S_SELECTCRE,
	S_CONGRATZ,
    S_COUNT
};

//Enumeration for the title screen selection
enum EMENU
{
	K_STARTGAME,
	K_QUIT
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;

	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;
	int lastKnownMove;
};

// struct for npc
struct SGameNPC
{
	COORD m_cLocation;
	int tolerance = 0;
	string str1;
	string str2;
	bool talked;
	bool active;
	bool right;
	bool left;
	bool up;
	bool down;

	bool somethingHappened;
	double movedelay;
	int moveCount = 3;
	int dirChoice;
	bool inTalkingRange = false;
};

struct Blocks
{
	COORD m_location;
	COORD respawn;
};

struct Fairy
{
	COORD fairyPos;
	string ans[4];
	string question[6];
	int currentQuestionNum = 0;

	bool fairyTrigger = false;
	bool wrongAns = false;
	int playerInput = 0;
	bool canPress = true;
};

// struct for the switches
struct Sswitches
{
	COORD m_cLocation;
};

// struct for the pressure plate
struct PressurePlate 
{
	COORD m_cLocation;
};

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter(Blocks _block[], Fairy *_fairy);       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen (START GAME)
void renderSelectmode();	// render the select mode menu (STORY)
void renderSelectmodeLogic(); // update theselect mode menu (STORY)

void renderCredits();		//render the credits
void renderCreditsLogic();	// update the credits

void renderLeaderboard();	//render the leaderbroad
void renderLeaderboardlogic(); // update the leaderbroad

void renderGame();          // renders the game stuff
void renderMap(int level);           // renders the map to the buffer first
void maps(int level);				//maps to be put into renderMap and renderGame

void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void renderDialogue(Fairy *_fairy);		//render the dialouge of the npc
void Npc(SGameNPC _NPC[]);					//game logic for the npc
void timeDelay(SGameNPC _NPC[]);			//duration of the dialogue
void renderblocks();		//render the blocks in game
void blocks();				//game logic for moving the blocks
void beginningcutscene();	//logic for cutscene at start
void rendercutscene();		//rendering of animation
void switches();			//switches
void renderSwitches();		//render switches
void pressureplate();//game logic
void renderplate();//rendering of the presure plate
void NpcPatrol(SGameNPC _NPC[], SGameChar g_sChar);
void FairyQuestion(Fairy *_fairy, SGameChar *g_sChar, Console *g_Console);
void rendercongratz();
void congratz();
void lastmap();

#endif // _GAME_H