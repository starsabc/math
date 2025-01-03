#include "Bullet.h"
#include "Game.h"

void Bullet::update(int) {
    col += xdirection;
    row += ydirection;
    if(game->hitobstacle(row,col)==true) return;
    game->paintat(row, col, '^');   

    if (row >= 29 ) return;
    if( row <= 1 ) return;
    if(col<=79) return;
    if(col<=1) return;
}

bool Bullet::out() {
    if (row>=29 || row<=1 || col >= 79 || col <= 1 || game->hitobstacle(row,col)==true )  {
        return true;
    }
    if(game->hittank(row,col) == true ){
        game->score+=100;
        return true;
    }
    return false;
}
