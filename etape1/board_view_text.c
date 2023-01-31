#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf(" ");
      if(j < 2){
        printf(" | ");
      }
    }
    printf("\n");
  }
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
  // TODO: à compléter
  PieceType piece;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      piece = Board_getSquareContent(i, j);
      if(piece == NONE){
        printf(" ");
      }else if(piece == CROSS){
        printf("X");
      }else if(piece == CIRCLE){
        printf("O");
      }
    }
    printf("\n");
  }
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  // TODO: à compléter
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  // TODO: à compléter
}

void BoardView_sayCannotPutPiece (void)
{
  // TODO: à compléter
}

#endif // defined CONFIG_TEXTUI
