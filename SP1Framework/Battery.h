#include "game.h"
#include "Framework\console.h"

extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern double g_dElapsedTimeSec;
extern bool    g_abKeyPressed[K_COUNT];
using namespace std;

void renderBattery();
void Batterylife();