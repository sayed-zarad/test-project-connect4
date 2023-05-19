#include "Game.h"
volatile int col = 0;
volatile int g;
volatile int sw1_pressed = 0;
volatile int sw2_pressed = 0;


void startingScreen()
{
	int w; 
	Nokia5110_SetCursor(0,0);
	Nokia5110_ClearBuffer();
	
	Nokia5110_DisplayBuffer();
	Nokia5110_SetCursor(2,2);
	Nokia5110_OutString("Welcome!  connect4");

		
	TIMER_INIT( 2,20,"Seconds","periodic","32");
	for(w=0 ; w<7 ; w++)
	{
		Nokia5110_SetCursor(0,w);
		Nokia5110_OutString("           ");
	TIMER_INIT( 2,40,"Seconds","periodic","32");
	}

}
void printBoard(char *board){
   int row, col;
	Nokia5110_ClearBuffer();
   for(row = 0; row < BOARD_ROWS; row++){
      for(col = 0; col < BOARD_COLS; col++){
				Nokia5110_SetCursorChar( col ,row,board[BOARD_COLS*row+col]);
      }
   }
}




