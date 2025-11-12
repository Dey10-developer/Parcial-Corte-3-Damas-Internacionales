#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    grid.resize(10, vector<Piece>(10));

    // Colocar las piezas iniciales
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 == 1) grid[i][j] = Piece(PlayerType::PLAYER2);
        }
    }
    for (int i = 6; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 == 1) grid[i][j] = Piece(PlayerType::PLAYER1);
        }
    }
}

void Board::display() const {
    cout << "  ";
    for (int j = 0; j < 10; j++) cout << j << " ";
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << " ";
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j].getSymbol() << " ";
        }
        cout << endl;
    }
}

// Movimiento simplificado (las capturas y coronaciones se manejan manualmente)
bool Board::movePiece(int x1, int y1, int x2, int y2, PlayerType player) {
    if (x1 < 0 || x1 >= 10 || y1 < 0 || y1 >= 10) return false;
    if (x2 < 0 || x2 >= 10 || y2 < 0 || y2 >= 10) return false;

    Piece &p = grid[x1][y1];
    if (p.owner != player) return false;

    if (grid[x2][y2].owner != PlayerType::NONE) return false;

    // Movimiento diagonal simple
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (abs(dx) == 1 && abs(dy) == 1) {
        grid[x2][y2] = p;
        grid[x1][y1] = Piece();
    }
    // Movimiento de captura
    else if (abs(dx) == 2 && abs(dy) == 2) {
        int mx = x1 + dx / 2;
        int my = y1 + dy / 2;
        if (grid[mx][my].owner != player && grid[mx][my].owner != PlayerType::NONE) {
            grid[x2][y2] = p;
            grid[x1][y1] = Piece();
            grid[mx][my] = Piece();
        } else return false;
    } else return false;

    // Se corona la dama
    if (player == PlayerType::PLAYER1 && x2 == 0) grid[x2][y2].type = PieceType::KING;
    if (player == PlayerType::PLAYER2 && x2 == 9) grid[x2][y2].type = PieceType::KING;

    return true;
}

bool Board::hasMoves(PlayerType player) const {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (grid[i][j].owner == player) return true;
    return false;
}

int Board::countPieces(PlayerType player) const {
    int count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (grid[i][j].owner == player) count++;
    return count;
}
