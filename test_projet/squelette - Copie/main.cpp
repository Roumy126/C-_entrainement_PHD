#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "json.hpp"
#include "board.h"

using json = nlohmann::json;
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

void save_action_to_dataset(Board* game, Player player, const std::string& type, int size, int fromLine, int fromCol, int toLine, int toCol) {
    json j;
    std::vector<int> board_flat;
    for (int i = 0; i < DIMENSIONS; ++i) {
        for (int jx = 0; jx < DIMENSIONS; ++jx) {
            const Piece& p = game->getCellAt(i, jx).peek();
            board_flat.push_back(p.getOwner());
            board_flat.push_back(p.getSize());
        }
    }
    j["player"] = player;
    j["board"] = board_flat;
    j["action"] = {
        {"type", type},
        {"size", size},
        {"from", {fromLine, fromCol}},
        {"to", {toLine, toCol}}
    };

    std::ofstream f("dataset.json", std::ios::app);
    f << j.dump() << std::endl;
}

void jouerBot(Board* game, Player botPlayer) {
    system("python bot.py");
    std::ifstream in("bot_output.json");
    if (!in.is_open()) return;
    json j;
    in >> j;
    in.close();

    std::string type = j["type"];
    if (type == "place") {
        int size = j["size"];
        int l = j["to"][0];
        int c = j["to"][1];
        game->placePiece(botPlayer, static_cast<Size>(size), l, c);
        save_action_to_dataset(game, botPlayer, "place", size, -1, -1, l, c);
    } else if (type == "move") {
        int l1 = j["from"][0];
        int c1 = j["from"][1];
        int l2 = j["to"][0];
        int c2 = j["to"][1];
        game->movePiece(l1, c1, l2, c2);
        save_action_to_dataset(game, botPlayer, "move", -1, l1, c1, l2, c2);
    }
}

int main() {
    char action;
    int l1, c1, l2, c2, s;
    StatusEnum status = OK;
    Player winner;
    bool botEnabled = false;

    cout << CYAN << "Bienvenue dans Gobblets !\n" << RESET;
    cout << YELLOW << "Choisissez un mode de jeu :\n";
    cout << "1. Joueur contre Joueur\n";
    cout << "2. Joueur contre Bot\n";
    cout << "Votre choix : " << RESET;
    char choix;
    cin >> choix;
    if (choix == '2') botEnabled = true;

    Board* game = new Board();
    Player currentPlayer = PLAYER_1;

    do {
        cout << endl << *game << endl;
        cout << "     0   1   2\n";
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

        if (botEnabled && currentPlayer == PLAYER_2) {
            jouerBot(game, PLAYER_2);
            currentPlayer = game->nextPlayer(currentPlayer);
            continue;
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
            save_action_to_dataset(game, currentPlayer, "place", s, -1, -1, l1, c1);
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

                save_action_to_dataset(game, currentPlayer, "move", -1, l1, c1, l2, c2);

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
