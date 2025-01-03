#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Game.h"

class Player :public Item{
public:
    Game* game;
    int xdirection;
    int ydirection;
    Player(Game* g) { 
        row = 18;
        col = 25;
        game = g;
        xdirection=0;
        ydirection=0;
    } 
    void update(int key);
    bool out() { return false; };
};
#endif
