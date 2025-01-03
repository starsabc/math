#ifndef _BOMB_H_
#define _BOMB_H_
#include "Game.h"
class Player;
class Bomb :public Item {
public:
    int xdirection;
    int ydirection;
    Game* game;
    Bomb(Game* g, size_t r, size_t c,int xd,int yd) {
        row = r;
        col = c;
        game = g;
        hp=1;
        xdirection=xd;
        ydirection=yd;
    }
    void update(int key);
    bool out();
    void hitplayer();
    void hittank();
};
#endif
