#pragma once
#include "game.h"
#include "Framework\console.h"

using namespace std;

void blocks(Blocks _block[]);			//logic for the blocks
void moveBlocks(Blocks _block[], SGameChar g_sChar);
void respawnBlocks(Blocks _block[]);