/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
  Coordinate x;
  Coordinate y;
  PieceType piece;
} Coups;

Coups coups[9];

int idTour = 0;

#if defined CONFIG_PLAYER_MANAGER_MOCK
  

void PlayerManager_init (void)
{
  Coups initCoups[9] = {
    {0, 0, CIRCLE},
    {0, 1, CROSS},
    {0, 2, CIRCLE},
    {1, 0, CROSS},
    {1, 1, CIRCLE},
    {1, 2, CROSS},
    {2, 0, CIRCLE},
    {2, 1, CROSS},
    {2, 2, CIRCLE}
  };
  
  for(int cpt = 0; cpt < 9; cpt++){
    coups[cpt] = initCoups[cpt];
  }
  
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  /* TODO: à compléter */
  // On simule un tour de jeu en faisant un coup predefini
  // On fait un coup sur la case 0,0
    printf("\nTour %d\n", idTour+1);
    Board_putPiece(coups[idTour].x, coups[idTour].y, coups[idTour].piece);
    BoardView_displayAll();

    

    idTour++;
  


}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK
