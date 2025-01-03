#ifndef _MINE_H_
#define _MINE_H_
#include "Game.h"
class Player;
class Mine :public Item {
public:
    Game* game;
    Mine(Game* g, size_t r, size_t c) {
        row = r;
        col = c;
        game = g;
    }
    void update(int key);
    bool out();
    bool hitplayer();
};
#endif