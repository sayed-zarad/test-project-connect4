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

int changeBoard(char *board,int player , const char *PIECES , int col  )
{
	int row ;
   for(row = BOARD_ROWS - 1; row >= 0; row--){
      if(board[BOARD_COLS * row + col] == ' '){
         board[BOARD_COLS * row + col] = PIECES[player];
         return 1;
      }
   }
	 return 0 ;
}

int hasEmptyCol(char *board, int col  )
{
	int row ;
   for(row = BOARD_ROWS - 1; row >= 0; row--){
      if(board[BOARD_COLS * row + col] == ' '){
         return 1;
      }
   }
	 return 0 ;
}
int checkWin(char *board){
    return (horizontalCheck(board) || verticalCheck(board) || diagonalCheck(board));
}

int horizontalCheck(char *board){
    int row, col, idx;
    const int WIDTH = 1;

    for(row = 0; row < BOARD_ROWS; row++){
       for(col = 0; col < BOARD_COLS - 3; col++){
          idx = BOARD_COLS * row + col;
          if(checkFour(board, idx, idx + WIDTH, idx + WIDTH * 2, idx + WIDTH * 3)){
             return 1;
          }
       }
    }
    return 0;

}
int verticalCheck(char *board){
    int row, col, idx;
    const int HEIGHT = 7;

    for(row = 0; row < BOARD_ROWS - 3; row++){
       for(col = 0; col < BOARD_COLS; col++){
          idx = BOARD_COLS * row + col;
          if(checkFour(board, idx, idx + HEIGHT, idx + HEIGHT * 2, idx + HEIGHT * 3)){
              return 1;
          }
       }
    }
    return 0;

}

int diagonalCheck(char *board){
   int row, col, idx, count = 0;
   const int DIAG_RGT = 6, DIAG_LFT = 8;

   for(row = 0; row < BOARD_ROWS - 3; row++){
      for(col = 0; col < BOARD_COLS; col++){
         idx = BOARD_COLS * row + col;
         if((count <= 3 && checkFour(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2, idx + DIAG_LFT * 3)) || (count >= 3 && checkFour(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2, idx + DIAG_RGT * 3))){
            return 1;
         }
         count++;
      }
      count = 0;
   }
   return 0;
}




