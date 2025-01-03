#include"Tank.h"
#include"Game.h"
#include"Bomb.h"
#include <iostream>
using namespace std;
void Tank::update(int k) {
    updates++;
    if(updates%10==0){
        switch(rand()%4){
        case 1://right
            xdirection=1;
            ydirection=0;
            col+=xdirection;
            row+=ydirection;
            if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col-=xdirection;
            addbomb(row,col+2,xdirection,ydirection);
            break;
        case 0://left
            xdirection=-1;
            ydirection=0;
            col+=xdirection;
            row+=ydirection;
            if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col-=xdirection;
            addbomb(row,col,xdirection,ydirection);
            break;
        case 2://down
            ydirection=1;
            xdirection=0;
            col+=xdirection;
            row+=ydirection;
            if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row-=ydirection;
            addbomb(row,col+1,xdirection,ydirection);
            break;
        case 3://up
            ydirection=-1;
            xdirection=0;
            col+=xdirection;
            row+=ydirection;
            if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row-=ydirection;
            addbomb(row,col+1,xdirection,ydirection);
            break;
        default:
            break;
        }
    }
    if (col > 76) {  col = 76; }
    if (col < 1) {   col = 1; }
    if (row < 2) { row = 2;}
    if(row > 28) { row = 28;}
    game->paintattank(row, col , 'C'); 
    game->paintattank(row, col + 1, 'M');
    game->paintattank(row, col + 2, 'D');
}
bool Tank::out() {
    if ( hp==1 ) return false;
    game->tanknumprint -- ;
    return true;
}
 
void Tank::addbomb(size_t a,size_t b,int c,int d){
    if(rand()%2==1 && game->bombnum<6 ) {
        game->its.push_back(new Bomb(game,a,b,c,d)); 
        game->bombnum++;
    }
}