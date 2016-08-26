#pragma once
#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"

using namespace std;

extern double g_dBounceTime;
extern bool g_abKeyPressed[K_COUNT];
extern SGameChar g_sChar;
extern SGameChar g_block;
extern Console g_Console;
extern SGameNPC _NPC[npcNum];

void movemaze3(); //movement for maze 3
