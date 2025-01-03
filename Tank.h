#ifndef _TANK_H_
#define _TANK_H_
#include "Game.h"
#include "Gui.h"
class Item;
class Bomb;
class Tank :public Item {
public:
    Game* game;
    int xdirection;
    int ydirection;
    int updates;
    Tank(Game* g,size_t r,size_t c) {
        row = r;
        col = c;
        game = g;
        hp=1;
        xdirection=0;
        ydirection=0;
        updates=0;
    }
    void update(int key);
    bool out();
    void addbomb(size_t,size_t,int,int);

};
#endif