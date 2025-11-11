#ifndef PIECE_H
#define PIECE_H

enum class PieceType { MAN, KING };
enum class PlayerType { PLAYER1, PLAYER2, NONE };

class Piece {
public:
    PieceType type;
    PlayerType owner;

    Piece();
    Piece(PlayerType ownerType, PieceType pieceType = PieceType::MAN);

    char getSymbol() const; // Returns the symbol for display
};

#endif
