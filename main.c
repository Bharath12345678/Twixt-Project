#include "stdio.h"
#include "stdlib.h"
#include "board.h"
#include "gameState.h"
#include "interface.h"


int main() {
    gameState state;

    initBoard(&state);
    state.currPlayer = Red;

    printf("----------Twixt----------\n");
    printf("commands:\n\t1. to place a peg: place \n r c\n\t2. to end game before winning: quit\n");

    while (true) {
        printBoard(&state);
        
        if(state.currPlayer == Red) {
            printf("--- Red's turn ---\n");
        }
        else {
            printf("--- Black's turn ---\n");
        }

        if(!commands(&state)) {
            printf("--- GAME ENDED ---\n");
            break;
        }

        if(state.currPlayer == Red) {
            state.currPlayer = Black;
        }
        else {
            state.currPlayer = Red;
        }

    }  
    
    return 0;
}
