#include"Tank.h"
#include"Game.h"
#include"Bomb.h"
#include"Mine.h"
#include"Supertank.h"
#include <iostream>
using namespace std;
void Supertank::update(int k) {
    if(updates%10==1) {
        int a=rand();
        int temp=game->trace();
        int plrow=temp/100;
        int plcol=temp%100;
        if(a%2==1){
            if(row<plrow) {
            row++;
            if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row--;
            }
            if(row>plrow) {
                row--;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) row++;
            }
        }
        else{
            if(col<plcol) {
                col++;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col--;
            }
            if(col>plcol) {
                col--;
                if(game->hitobstacle(row,col)==true || game->hitobstacle(row,col+1)==true || game->hitobstacle(row,col+2)==true) col++;
            }
        }
        
    }
    if (col > 76) {  col = 76; }
    if (col < 1) {   col = 1; }
    if (row < 1) { row = 1;}
    if(row > 28) { row = 28;}
    game->paintattank(row, col , 'S');
    game->paintattank(row, col + 1, 'U');
    game->paintattank(row, col + 2, 'P');
    updates++;
    addmine();
}
bool Supertank::out() {
    if ( hp<=0 ) {
        game->tanknumprint -- ;
        game->supertanknum--;
        return true;
    }
    else return false;
}
void Supertank::addmine(){
    if(updates%100==0 && game->minenum<10 ){
        game->its.push_back(new Mine(game,row,col));
        game->minenum++;
    }
}