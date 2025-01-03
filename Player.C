#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Player::update(int key) {
     int shoot = 0;
     switch (key) {
         case KEY_LEFT:
            xdirection=-1;
            ydirection=0;
            col +=xdirection;
            if(game->hitobstacle(row,col)==true) col-=xdirection;
            break;
         case KEY_RIGHT:
            xdirection=1;
            ydirection=0;
            col +=xdirection;
            if(game->hitobstacle(row,col)==true) col-=xdirection;
            break;
        case KEY_UP:
            ydirection=-1;
            xdirection=0;
            row +=ydirection;
            if(game->hitobstacle(row,col)==true) row-=ydirection;
            break;
        case KEY_DOWN:
            ydirection=1;
            xdirection=0;
            row +=ydirection;
            if(game->hitobstacle(row,col)==true) row-=ydirection;
            break;
         case ' ':
            shoot = 1;
            break;
         default:
            break;
     }
     if (shoot == 1 && game->bulletnum > 0) {
         game->addBullet(row, col,xdirection,ydirection);
         game->bulletnum--; 
     }

     if (row < 1) { row = 1; }
     if (row > 28) {  row = 28; } 
     if (col > 78) { col = 78;}
     if (col < 1) { col = 1;}
     game->paintatplayer(row, col, 'M');
     if( game->score==2000){
        game->win();
     }
     if( game->hp<=0 ){
        game->complete();
    }
}
