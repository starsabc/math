#ifndef _BULLET_H_
#define _BULLET_H_
#include "Game.h"

class Bullet:public Item {
public:
    int xdirection;
    int ydirection;
    Game* game;
    Bullet (Game* g, size_t r, size_t c,int x,int y){
        row = r;
        col = c;
        game = g;
        xdirection=x;
        ydirection=y;
    }
    void update(int);
    bool out();
};
#endif
