#include <stdio.h>
#include "board.h"

void afficher_plateau(board jeu) {
    printf("\n  0 1 2\n");
    for (int i = 0; i < DIMENSIONS; i++) {
        printf("%d ", i);
        for (int j = 0; j < DIMENSIONS; j++) {
            player p = get_place_holder(jeu, i, j);
            size s = get_piece_size(jeu, i, j);
            char symbole = '.';
            if (p == PLAYER_1) {
                symbole = (s == SMALL) ? 'a' : (s == MEDIUM) ? 'b' : 'c';
            } else if (p == PLAYER_2) {
                symbole = (s == SMALL) ? 'x' : (s == MEDIUM) ? 'y' : 'z';
            }
            printf("%c ", symbole);
        }
        printf("\n");
    }
}

void afficher_maisons(board jeu) {
    for (int p = PLAYER_1; p <= PLAYER_2; p++) {
        printf("Joueur %d : ", p);
        for (int s = SMALL; s <= LARGE; s++) {
            printf("%d x %s ", get_nb_piece_in_house(jeu, p, s),
                   (s == SMALL) ? "petite" : (s == MEDIUM) ? "moyenne" : "grande");
        }
        printf("\n");
    }
}

int main() {
    board jeu = new_game();
    player joueur = PLAYER_1;

    while (get_winner(jeu) == NO_PLAYER) {
        printf("\n===== Tour du Joueur %d =====\n", joueur);
        afficher_plateau(jeu);
        afficher_maisons(jeu);

        int choix;
        printf("Choisissez une action :\n1 - Placer une pièce\n2 - Déplacer une pièce\n> ");
        scanf("%d", &choix);

        if (choix == 1) {
            int taille, ligne, colonne;
            printf("Taille (1=petite, 2=moyenne, 3=grande) : ");
            scanf("%d", &taille);
            printf("Position (ligne colonne) : ");
            scanf("%d %d", &ligne, &colonne);
            int res = place_piece(jeu, joueur, taille, ligne, colonne);
            if (res != 0) printf("Erreur (%d) lors du placement.\n", res);
        } else if (choix == 2) {
            int l1, c1, l2, c2;
            printf("De (ligne colonne) : ");
            scanf("%d %d", &l1, &c1);
            printf("Vers (ligne colonne) : ");
            scanf("%d %d", &l2, &c2);
            int res = move_piece(jeu, l1, c1, l2, c2);
            if (res != 0) printf("Erreur (%d) lors du déplacement.\n", res);
        } else {
            printf("Action invalide.\n");
        }

        joueur = next_player(joueur);
    }

    printf("\n\U0001F389 Le joueur %d a gagné ! \U0001F389\n", get_winner(jeu));
    destroy_game(jeu);
    return 0;
}
