#include"Mine.h"
#include"Game.h"
#include"Player.h"
#include <iostream>
using namespace std;
void Mine::update(int k) {
    game->paintatmine(row, col, '@');   
}
bool Mine::out() {
    if( hitplayer()==true ){
        game->hp-=5;
        return true;
    }
    return false;
}
bool Mine::hitplayer(){
    if(row-1<=game->pl->row && game->pl->row<=row+1 && col-1<=game->pl->col && game->pl->col<=col+1 ) {
        return true;
    }
    return false;
}