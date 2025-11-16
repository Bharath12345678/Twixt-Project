#include "board.h"
#include <stdio.h>

void initBoard(gameState *state) {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            state->board[row][col] = Unassigned;
        }
    }
}

bool validPlacement(gameState *state, int row, int col, Player player) {
    if(row < 0 || row >= N || col < 0 || col >= N) {
        printf("error\n");
        return false;
    }

    if(state->board[row][col] != Unassigned) {
        printf("Occupied");
        return false;
    }
// initially made a mistake of not placing the player at the position
    if(player == Red) {
        if(row == 0 || row == (N-1)) {
            printf("Not in opponent's place");
            return false;
        }
    }
    else if(player == Black) {
        if(col == 0 || col == (N-1)) {
            printf("Not in opponent's boundary");
            return false;
        }
    }

    return true;
}

bool placePeg(gameState *state, int row, int col) {
    if(validPlacement(state, row, col, state->currPlayer)) {
        state->board[row][col] = state->currPlayer;
        return true;
    }
    return false;
}