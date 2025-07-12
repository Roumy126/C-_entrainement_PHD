#include <stdio.h>
#include "board.h"

/**
 * @file main_example.c
 * @brief a simple illustration of how to include and use board.h and board.o.
 */
int main(int args, char **argv){
	board game = new_game();
	printf("Un plateau est créé.\n");
	int res = place_piece(game, PLAYER_1, SMALL, 0, 2);
	if(res == 0){
		printf("La piece a été placée avec succès.\n");
	}
	else {
		printf("Un problème a eu lieu lors du placement, numéro %d\n", res);
	}
	destroy_game(game);
	printf("suppression du plateau et sortie\n");	
	return 0;
}


