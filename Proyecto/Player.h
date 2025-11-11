#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include <string>

class Player {
public:
    std::string name;
    PlayerType type;

    Player(std::string playerName, PlayerType t);
};

#endif
