/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"


SquareChangeCallback Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent){
  
}


EndOfGameCallback Game_EndOfGameCallback(GameResult result){

}




void Game_init (void)
{
  // TODO: initialiser tous les modules
  Board_init(&Game_SquareChangeCallback, &Game_EndOfGameCallback);

}

void Game_free (void)
{
  // TODO: libérer tous les modules
}

void Game_loop (void)
{
	// TODO: à compléter
}
