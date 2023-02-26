/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"
#include <stdio.h>


void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent){
}


void Game_EndOfGameCallback(GameResult result){
}



  typedef struct {
    Coordinate x;
    Coordinate y;
    PieceType piece;
  } Coups;

  

void Game_init (void)
{
  // TODO: initialiser tous les modules
  Board_init(&Game_SquareChangeCallback, &Game_EndOfGameCallback);
  BoardView_init();
  PlayerManager_init();

}

void Game_free (void)
{
  // TODO: libérer tous les modules
  Board_free();
  BoardView_free();
  PlayerManager_free();
}

void Game_loop (void)
{
	// TODO: à compléter
  int cpt = 0;
  bool GameFinished = false;
  while(!GameFinished && cpt < 9){
    PlayerManager_oneTurn();
    cpt++;
  }
    
}
