#include"Bomb.h"
#include"Game.h"
#include"Player.h"
#include <iostream>
using namespace std;
void Bomb::update(int k) {
    col += xdirection;
    row += ydirection;
    if(game->hitobstacle(row,col)==true) return;
    game->paintat(row, col, '*');   
    hitplayer();
    hittank();

    if (row >= 29 ) return;
    if( row <= 1 ) return;
    if(col<=79) return;
    if(col<=1) return;
}
bool Bomb::out() {
    if (row>=29 || row<=1 || col >= 79 || col <= 1 || hp==0 || game->hitobstacle(row,col)==true) {
        game->bombnum -- ;
        return true;
    }
    return false;
}
void Bomb::hitplayer(){
    if(row==game->pl->row && col==game->pl->col) {
        game->hp--;
        hp--;
    }
}
void Bomb::hittank(){
    if(game->bombhittank(row,col)==true){
        hp--;
    }
}