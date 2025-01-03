#ifndef _LASERTANK_H_
#define _LASERTANK_H_
#include "Game.h"
#include "Gui.h"
class Item;
class Laser:public Item{
public:
    int xdirection;
    int ydirection;
    int updates;
    Laser(Game* g,size_t r,size_t c,int xd,int yd) {
        row = r;
        col = c+1;
        game = g;
        hp=4;
        xdirection=xd;
        ydirection=yd;
        updates=0;
    }
    Game* game;
    void update(int key){
        hp--;
        while(row<=28 && col<=78){
            if(game->hitobstacle(row,col)==true) return;
            game->paintatlaser(row,col,'$');
            game->laserhit(row,col);
            col+=xdirection;
            row+=ydirection;
        }
    };
    bool out(){
        if(hp<=0)  {
            game->lasernum--;
            return true;
        }
        return false;
    };
};
class Lasertank :public Item {
public:
    Game* game;
    int xdirection;
    int ydirection;
    int updates;
    Lasertank(Game* g,size_t r,size_t c) {
        row = r;
        col = c;
        game = g;
        hp=5;
        updates=0;
        xdirection=0;
        ydirection=0;
    }
    void update(int key);
    bool out();
    void addlaser();

};
#endif