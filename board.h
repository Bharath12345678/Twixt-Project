#ifndef BOARD_H
#define BOARD_H

#include "gameState.h"

void initBoard(gameState *state);
bool validPlacement(gameState *state, int row, int col, Player player);
bool placePeg(gameState *state, int row, int col);

#endif