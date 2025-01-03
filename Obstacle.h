#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_
#include "Game.h"
#include "Gui.h"
class Item;
class Obstacle:public Item{
public:
    Game* game;
    Obstacle(Game* g,size_t r,size_t c){
        row=r;
        game=g;
        col=c;
    }
    void update(int key) ;
    bool out(){return false;};
};
#endif