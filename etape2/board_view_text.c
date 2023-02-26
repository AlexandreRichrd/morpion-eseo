#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
  //Affchage d'un titre Morpion en ascii art
  
  printf("        :::   :::    ::::::::  :::::::::  ::::::::: ::::::::::: ::::::::  ::::    ::: \n");
  printf("      :+:+: :+:+:  :+:    :+: :+:    :+: :+:    :+:    :+:    :+:    :+: :+:+:   :+:  \n");
  printf("    +:+ +:+:+ +:+ +:+    +:+ +:+    +:+ +:+    +:+    +:+    +:+    +:+ :+:+:+  +:+   \n");
  printf("   +#+  +:+  +#+ +#+    +:+ +#++:++#:  +#++:++#+     +#+    +#+    +:+ +#+ +:+ +#+    \n");
  printf("  +#+       +#+ +#+    +#+ +#+    +#+ +#+           +#+    +#+    +#+ +#+  +#+#+#     \n");
  printf(" #+#       #+# #+#    #+# #+#    #+# #+#           #+#    #+#    #+# #+#   #+#+#      \n");
  printf("###       ###  ########  ###    ### ###       ########### ########  ###    #### 	    \n\n\n\n");

  // Affichage du plateau de jeu
  printf("                                 *************\n");
  printf("                                 *   |   |   *\n");
  printf("                                 *---+---+---*\n");
  printf("                                 *   |   |   *\n");
  printf("                                 *---+---+---*\n");
  printf("                                 *   |   |   *\n");
  printf("                                 *************\n");

  // for(int i = 0; i < 3; i++){
  //   for(int j = 0; j < 3; j++){
  //     printf(" ");
  //     if(j < 2){
  //       printf(" | ");
  //     }
  //   }
  //   printf("\n");
  // }
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
  // TODO: à compléter
  // Affichage du plateau de jeu
  printf("                                 *************\n");
  PieceType piece;
  for(int i = 0; i < 3; i++){
    printf("                                 * ");
    for(int j = 0; j < 3; j++){
      piece = Board_getSquareContent(i, j);
      if(j == 0 || j == 1){
        if(piece == NONE){
        printf("  | ");
        }else if(piece == CROSS){
          printf("X | ");
        }else if(piece == CIRCLE){
          printf("O | ");
        }else{
          printf("E | ");
        }
      } else{
        if(piece == NONE){
        printf("  *\n");
        }else if(piece == CROSS){
          printf("X *\n");
        }else if(piece == CIRCLE){
          printf("O *\n");
        }else{
          printf("E *\n");
        }
      }
      
      
    }
    if (i < 2)
    {
      printf("                                 *---+---+---*\n");
    }else{
      printf("                                 *************\n");
    }
    
  }
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  if(result == CROSS_WINS){
    printf("Le joueur X a gagné\n");
  }else if(result == CIRCLE_WINS){
    printf("Le joueur O a gagné\n");
  }else if(result == DRAW){
    printf("Match nul\n");
  }else{
    printf("Erreur\n");
  }
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  if(thisPlayer == CROSS){
    printf("Au tour du joueur X\n");
  }else{
    printf("Au tour du joueur O\n");
  }
}

void BoardView_sayCannotPutPiece (void)
{
  printf("Impossible de jouer ici\n");
}

#endif // defined CONFIG_TEXTUI
