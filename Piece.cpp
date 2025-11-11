#include "Piece.h"

Piece::Piece() {
    type = PieceType::MAN;
    owner = PlayerType::NONE;
}

Piece::Piece(PlayerType ownerType, PieceType pieceType) {
    owner = ownerType;
    type = pieceType;
}

char Piece::getSymbol() const {
    if (owner == PlayerType::PLAYER1) {
        return (type == PieceType::MAN) ? 'x' : 'X';
    } else if (owner == PlayerType::PLAYER2) {
        return (type == PieceType::MAN) ? 'o' : 'O';
    } else {
        return '.';
    }
}
