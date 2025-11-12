#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

class Board {
public:
    std::vector<std::vector<Piece>> grid;

    Board();
    void display() const;
    bool movePiece(int x1, int y1, int x2, int y2, PlayerType player);
    bool hasMoves(PlayerType player) const;
    int countPieces(PlayerType player) const;
};

#endif
