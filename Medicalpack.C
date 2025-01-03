#include"Medicalpack.h"
#include"Game.h"
#include <iostream>
using namespace std;
void Medicalpack::update(int k) {
    game->paintatmedical(row, col, '+');   
}
bool Medicalpack::out() {
    if( game->eatpack()==true ){
        game->medicalpacknum = 0 ;
        return true;
    }
    return false;
} 