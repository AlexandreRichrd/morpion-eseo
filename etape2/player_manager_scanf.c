/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>

int idPlayer = 0;

#if defined CONFIG_PLAYER_MANAGER_SCANF

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  // TODO: à compléter
  // On demande au joueur de saisir une case avec les coordonnees x et y
  // On demande au joueur de saisir le type de piece a jouer
  int x, y;
  PutPieceResult result;
  do{
    if (idPlayer == 0){
      BoardView_displayPlayersTurn(CIRCLE);
    }else{
      BoardView_displayPlayersTurn(CROSS);
    }
    printf("Entrez les coordonnees de la case a jouer (x, y): \n");
    printf("x : ");
    scanf("%d", &x);
    printf("\ny : ");
    scanf("%d", &y);
    if(x < 0 || x > 2 || y < 0 || y > 2){
      printf("\nLes coordonnees x et y doivent etre comprises entre 0 et 2 !\n");
    }else{
      if(idPlayer == 0){
        result = Board_putPiece(x, y, CIRCLE);
      }else{
        result = Board_putPiece(x, y, CROSS);
      }

      if(result == SQUARE_IS_NOT_EMPTY){
        printf("La case doit etre vide !\n");
        //on reboucle
        x = 5;
      }
    }
  }while (x < 0 || x > 2 || y < 0 || y > 2);
  
  idPlayer = (idPlayer + 1) % 2;
  BoardView_displayAll();
  
}

#endif // defined CONFIG_PLAYER_MANAGER_SCANF
