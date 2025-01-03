#ifndef _SUPERTANK_H_
#define _SUPERTANK_H_
#include "Game.h"
#include "Gui.h"
class Item;
class Bomb;
class Mine;
class Supertank :public Item {
public:
    Game* game;
    Supertank(Game* g,size_t r,size_t c) {
        row = r;
        col = c;
        game = g;
        hp=4;
        updates=0;
    }
    void update(int key);
    bool out();
    void addmine();
    int updates;

};
#endif