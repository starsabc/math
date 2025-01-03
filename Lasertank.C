#include"Lasertank.h"
#include"Game.h"
#include <iostream>
using namespace std;
void Lasertank::update(int k){
    if(updates%10==1){
        switch(rand()%4){
            case 1:
                xdirection=1;
                ydirection=0;
                col+=xdirection;
                row+=ydirection;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col-=xdirection;
                addlaser();
                break;
            case 0:
                xdirection=-1;
                ydirection=0;
                col+=xdirection;
                row+=ydirection;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col-=xdirection;
                addlaser();
                break;
            case 2:
                ydirection=1;
                xdirection=0;
                col+=xdirection;
                row+=ydirection;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row-=ydirection;
                addlaser();
                break;
            case 3:
                ydirection=-1;
                xdirection=0;
                col+=xdirection;
                row+=ydirection;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row-=ydirection;
                addlaser();
                break;
            default:
                break;
        }
    }
    updates++;
    if (col > 76) {  col = 76; }
    if (col < 2) {   col = 2; }
    if (row < 2) { row = 2;}
    if(row > 28) { row = 28;}
    game->paintattank(row, col , 'R'); 
    game->paintattank(row, col + 1, 'A');
    game->paintattank(row, col + 2, 'Y');
}
bool Lasertank::out() {
    if ( hp<=0 ) {
        game->tanknumprint -- ;
        game->lasertanknum--;
        return true;
    }
    else return false;
}
void Lasertank::addlaser(){
    if(updates%50==1 && game->lasernum==0 && game->hitobstacle(row,col)==false){
        game->its.push_back(new Laser(game,row,col,xdirection,ydirection));
        game->lasernum++;
    }
}