#include "board.h"
#include <assert.h>

PieceType board[3][3];

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
  if(boardSquares[lastChangeY][0] == boardSquares[lastChangeY][1] && boardSquares[lastChangeY][1] == boardSquares[lastChangeY][2])
  {
    if(boardSquares[lastChangeY][0] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[lastChangeY][0] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  if(boardSquares[0][lastChangeX] == boardSquares[1][lastChangeX] && boardSquares[1][lastChangeX] == boardSquares[2][lastChangeX])
  {
    if(boardSquares[0][lastChangeX] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
      return true;
    }
    else if(boardSquares[0][lastChangeX] == CROSS)
    {
      *gameResult = CROSS_WINS;
      return true;
    }
  }
  if(boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2])
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
  if(boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0])
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
  // Vérifier si le plateau est plein
  int cptNone = 0;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(boardSquares[i][j] == NONE)
      {
        cptNone++;
      }
    }
  }
  // Si le plateau est plein, c'est un match nul
  if(cptNone == 0)
  {
    *gameResult = DRAW;
    return true;
  }

  // Si on arrive ici, c'est que le jeu n'est pas fini
  return false;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{ 
  // On initialise le board
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      board[i][j] = NONE;
    }
  }
}

void Board_free ()
{
  // On détruit le board
  
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
  if(x < 0 || x > 2 || y < 0 || y > 2) // On vérifie si les cooredonnées sont bien dans la gille
  {
    return SQUARE_IS_NOT_EMPTY;
  }
  else if(board[x][y] != NONE) // On vérifie si la piece placée est dans une case vide
  {
    return SQUARE_IS_NOT_EMPTY;
  }
  else // Si tout est bon, on place la pièce
  {
    board[x][y] = kindOfPiece;
    onSquareChange(x, y, kindOfPiece);

    GameResult* gameResult;

    if(isGameFinished(board, x, y, &gameResult))
    {
      onEndOfGame(gameResult);
    }
    return PIECE_IN_PLACE;
  }
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  if(x > 0 && x < 2 && y > 0 && y < 2) // On vérifie si les cooredonnées sont bien dans la gille
  {
    // On récupère le contenu de la case
    return board[x][y];
  }
  
}
