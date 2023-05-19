#ifndef Game
#define Game

#include "Nokia5110.h"
#include "GPTM_Driver.h"


#define BOARD_ROWS 6
#define BOARD_COLS 7

extern volatile int col;
extern volatile int g;
extern volatile int sw1_pressed ;
extern volatile int sw2_pressed ;


void printBoard(char *board);
int takeTurn(char *board, int player, const char*);




#endif

