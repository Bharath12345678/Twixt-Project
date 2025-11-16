#include "interface.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBoard(gameState *state) {
    printf("\n");
    for(int col = 0; col < N; col++) {
        printf("%-2d", col);
    }
    printf("\n");

    for(int row = 0; row < N; row++) {
        printf("%-2d ", row);

        for(int col = 0; col < N; col++) {
            char peg = '.';
            if(state->board[row][col] == Red) peg = 'R';
            if(state->board[row][col] == Black) peg = 'B';
            printf("%-2c", peg);
        }
        printf("\n");
    }  
}

bool commands(gameState *state) {
    char command[10];
    int r, c;

    while (true) {
        printf(">>");
        
        scanf("%s", command);
// initial error was that commands is the address of the first letter of the string, so command == "place" is an invalid syntax. So here use strcmp{string compare} to compare the strings, so if str1 = str2, then strcmp(str1, str2) = 0
        if(strcmp(command,"place") == 0) {
            scanf("%d %d", &r, &c);

            if(placePeg(state, r, c)) return true;
        }
        else if(strcmp(command,"quit") == 0) return false;
        else printf("Unknown command\n");
    }    
}