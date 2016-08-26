#include "game.h"
#include "Framework\console.h"
#include "Battery.h"
extern bool    g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern  SGameChar g_sChar;
extern Console g_Console;
using namespace std;

void renderVision();
