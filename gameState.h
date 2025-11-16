#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdbool.h>

#define N 24

typedef enum {
    Unassigned,
    Red,
    Black
} Player;

typedef struct {
    int row1, col1;
    int row2, col2;
    Player ownerOfTheLink;
} Link;

typedef struct Node {
    Link data;
    struct Node *next;    
} Node;

typedef struct {
    Player board[N][N];
    Node *links;
    Player currPlayer;
} gameState;


#endif