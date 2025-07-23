#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "board.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

class MoveException : public std::runtime_error {
public:
    MoveException(const std::string& msg) : std::runtime_error(msg) {}
};

void saveWinner(Player winner) {
    ofstream file("score.txt", ios::app);
    if (file.is_open()) {
        file << "Le joueur " << ((winner == PLAYER_1) ? "1" : "2") << " a gagné.\n";
        file.close();
    }
}

int main() {
    char action;
    int l1, c1, l2, c2, s;
    StatusEnum status = OK;
    Player winner;

    Board* game = new Board();
    Player currentPlayer = PLAYER_1;

    do {
        cout << endl << *game << endl;
        cout << CYAN << "Maison du joueur 1: ";
        winner = game->getWinner();

        if (winner != NO_PLAYER) {
            switch (winner) {
                case PLAYER_1:
                    cout << GREEN << "\n🎉 Le joueur 1 a gagné !\n" << RESET;
                    break;
                case PLAYER_2:
                    cout << RED << "\n🎉 Le joueur 2 a gagné !\n" << RESET;
                    break;
                default:
                    break;
            }
            saveWinner(winner);
            break;
        }

        cout << CYAN << "Tour du joueur " << ((currentPlayer == PLAYER_1) ? "1" : "2") << RESET << endl;
        cout << YELLOW << "Choix d'action. 1: Placer, 2: Déplacer, q: Quitter" << RESET << endl;
        cin >> action;

        if (action == '1') {
            cout << "Taille de pièce (1=SMALL, 2=MEDIUM, 3=LARGE): ";
            cin >> s;
            cout << "Position (ligne colonne): ";
            cin >> l1 >> c1;
            status = game->placePiece(currentPlayer, static_cast<Size>(s), l1, c1);
            if (status != OK) {
                cout << RED << "⛔ Erreur: ";
                switch (status) {
                    case INVALID_SOURCE: cout << "Pièce non disponible."; break;
                    case INVALID_TARGET: cout << "La pièce ne peut pas être posée ici."; break;
                    case INVALID_ENTRY: cout << "Entrée invalide."; break;
                    default: break;
                }
                cout << RESET << endl;
                continue;
            }
        } else if (action == '2') {
            try {
                game->printMovablePieces(currentPlayer);
                cout << "De (ligne colonne): ";
                cin >> l1 >> c1;

                if (!game->getCellAt(l1, c1).canPop())
                    throw MoveException("Aucune pièce ici.");

                if (game->getCellAt(l1, c1).peek().getOwner() != currentPlayer)
                    throw MoveException("Ce n'est pas votre pièce.");

                cout << "Vers (ligne colonne): ";
                cin >> l2 >> c2;

                status = game->movePiece(l1, c1, l2, c2);
                if (status != OK)
                    throw MoveException("Déplacement invalide.");

            } catch (MoveException& ex) {
                cout << RED << "⛔ Erreur : " << ex.what() << RESET << "\n";
                continue;
            }
        } else if (action == 'q') {
            cout << "Fin de la partie.\n";
            break;
        } else {
            cout << RED << "⛔ Entrée invalide." << RESET << "\n";
            continue;
        }

        currentPlayer = game->nextPlayer(currentPlayer);
    } while (true);

    delete game;
    return 0;
}
