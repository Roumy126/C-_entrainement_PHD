#include "board.h"

Board::Board() {
    for (int i = 0; i < NB_SIZE; ++i) {
        p1Pieces[i] = NB_INITIAL_PIECES;
        p2Pieces[i] = NB_INITIAL_PIECES;
    }
} // Initializes the board with the initial number of pieces for each player

Board::Board(const Board& other) {
    for (int i = 0; i < DIMENSIONS; ++i)
        for (int j = 0; j < DIMENSIONS; ++j)
            state[i][j] = other.state[i][j];

    for (int i = 0; i < NB_SIZE; ++i) {
        p1Pieces[i] = other.p1Pieces[i];
        p2Pieces[i] = other.p2Pieces[i];
    }
} // Copy constructor initializes the board from another board

Board::~Board() {}

Cell& Board::getCellAt(int line, int column) {
    return state[line][column];
}

int* Board::getHousesOfPlayer(Player player) {
    return player == PLAYER_1 ? p1Pieces : p2Pieces;
}

Player Board::nextPlayer(Player currentPlayer) const {
    return currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

Player Board::getPlaceHolder(int line, int column) {
    return state[line][column].peek().getOwner();
}

Size Board::getPieceSize(int line, int column) {
    return state[line][column].peek().getSize();
}

int Board::getNbPiecesInHouse(Player checkedPlayer, Size pieceSize) {
    return getHousesOfPlayer(checkedPlayer)[pieceSize - 1];
}

StatusEnum Board::placePiece(Player currentPlayer, Size pieceSize, int line, int column) {
    if (line < 0 || line >= DIMENSIONS || column < 0 || column >= DIMENSIONS) return INVALID_ENTRY;
    int* house = getHousesOfPlayer(currentPlayer);
    if (house[pieceSize - 1] <= 0) return INVALID_SOURCE;
    if (!state[line][column].canPush(Piece(currentPlayer, pieceSize))) return INVALID_TARGET;

    state[line][column].push(Piece(currentPlayer, pieceSize));
    house[pieceSize - 1]--;
    return OK;
}

StatusEnum Board::movePiece(int sourceLine, int sourceColumn, int targetLine, int targetColumn) {
    if (sourceLine < 0 || sourceLine >= DIMENSIONS || sourceColumn < 0 || sourceColumn >= DIMENSIONS
        || targetLine < 0 || targetLine >= DIMENSIONS || targetColumn < 0 || targetColumn >= DIMENSIONS)
        return INVALID_ENTRY;

    if (!state[sourceLine][sourceColumn].canPop()) return INVALID_SOURCE;

    Piece moving = state[sourceLine][sourceColumn].peek();
    if (moving.getOwner() != getPlaceHolder(sourceLine, sourceColumn)) return INVALID_SOURCE;

    if (!state[targetLine][targetColumn].canPush(moving)) return INVALID_TARGET;

    state[sourceLine][sourceColumn].pop();
    state[targetLine][targetColumn].push(moving);
    return OK;
}

Player Board::getWinner() {
    for (int i = 0; i < DIMENSIONS; ++i) {
        Player row = getPlaceHolder(i, 0);
        if (row != NO_PLAYER && row == getPlaceHolder(i, 1) && row == getPlaceHolder(i, 2)) return row;
        Player col = getPlaceHolder(0, i);
        if (col != NO_PLAYER && col == getPlaceHolder(1, i) && col == getPlaceHolder(2, i)) return col;
    }
    Player diag1 = getPlaceHolder(0, 0);
    if (diag1 != NO_PLAYER && diag1 == getPlaceHolder(1, 1) && diag1 == getPlaceHolder(2, 2)) return diag1;
    Player diag2 = getPlaceHolder(0, 2);
    if (diag2 != NO_PLAYER && diag2 == getPlaceHolder(1, 1) && diag2 == getPlaceHolder(2, 0)) return diag2;
    return NO_PLAYER;
}

std::ostream& Board::printHouses(std::ostream& stream, Player player) {
    int* house = getHousesOfPlayer(player);
    stream << "Player " << (player == PLAYER_1 ? "1" : "2") << " house: ";
    stream << "S:" << house[SMALL - 1] << " M:" << house[MEDIUM - 1] << " L:" << house[LARGE - 1] << std::endl;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Board& board) {
    stream << "\n    +---+---+---+\n";
    for (int i = 0; i < DIMENSIONS; ++i) {
        stream << "    |";
        for (int j = 0; j < DIMENSIONS; ++j) {
            Piece p = board.state[i][j].peek();
            Player owner = p.getOwner();
            Size size = p.getSize();
            char c = ' ';
            if (owner == PLAYER_1) c = (size == SMALL) ? SMALLP1 : (size == MEDIUM) ? MEDIUMP1 : LARGEP1;
            else if (owner == PLAYER_2) c = (size == SMALL) ? SMALLP2 : (size == MEDIUM) ? MEDIUMP2 : LARGEP2;
            stream << " " << c << " |";
        }
        stream << "\n    +---+---+---+\n";
    }

    stream << "\nContenu des maisons :\n";
    for (int i = 0; i < board.p1Pieces[SMALL - 1]; ++i) stream << SMALLP1 << " ";
    for (int i = 0; i < board.p1Pieces[MEDIUM - 1]; ++i) stream << MEDIUMP1 << " ";
    for (int i = 0; i < board.p1Pieces[LARGE - 1]; ++i) stream << LARGEP1 << " ";
    stream << "\n";

    for (int i = 0; i < board.p2Pieces[SMALL - 1]; ++i) stream << SMALLP2 << " ";
    for (int i = 0; i < board.p2Pieces[MEDIUM - 1]; ++i) stream << MEDIUMP2 << " ";
    for (int i = 0; i < board.p2Pieces[LARGE - 1]; ++i) stream << LARGEP2 << " ";
    stream << "\n";

    return stream;
}

void Board::printMovablePieces(Player current) {
    std::cout << "Vous pouvez déplacer depuis :\n";
    for (int i = 0; i < DIMENSIONS; ++i) {
        for (int j = 0; j < DIMENSIONS; ++j) {
            if (state[i][j].canPop() && state[i][j].peek().getOwner() == current) {
                std::cout << "(" << i << ", " << j << ") ";
            }
        }
    }
    std::cout << std::endl;
}
