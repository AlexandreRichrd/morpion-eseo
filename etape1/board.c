#include "board.h"
#include <assert.h>

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
  // Vérifier les possibilités de victoire

  if(boardSquares[lastChangeX][0] == boardSquares[lastChangeX][1] && boardSquares[lastChangeX][1] == boardSquares[lastChangeX][2])
  {
    if(boardSquares[lastChangeX][0] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[lastChangeX][0] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  else if(boardSquares[0][lastChangeY] == boardSquares[1][lastChangeY] && boardSquares[1][lastChangeY] == boardSquares[2][lastChangeY])
  {
    if(boardSquares[0][lastChangeY] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[0][lastChangeY] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  else if(boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2])
  {
    if(boardSquares[0][0] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[0][0] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  else if(boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0])
  {
    if(boardSquares[0][2] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[0][2] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  else
  {
    return false;
  }
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{ 
  // On initialise le board
  
  
}

void Board_free ()
{
  // On détruit le board
  
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
  // if(x < 0 || x > 2 || y < 0 || y > 2) // On vérifie si les cooredonnées sont bien dans la gille
  // {
  //   return OUT_OF_BOARD;
  // }
  // else if(boardSquares[x][y] != NONE) // On vérifie si la piece placée est dans une case vide
  // {
  //   return SQUARE_ALREADY_USED;
  // }
  // else // Si tout est bon, on place la pièce
  // {
  //   boardSquares[x][y] = kindOfPiece;
  //   lastChangeX = x;
  //   lastChangeY = y;
  //   onSquareChange(x, y, kindOfPiece);
  //   if(isGameFinished(boardSquares, lastChangeX, lastChangeY, &gameResult))
  //   {
  //     onEndOfGame(gameResult);
  //   }
  //   return OK;
  // }
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  // On récupère le contenu de la case
  
  //return boardSquares[x][y];
}
