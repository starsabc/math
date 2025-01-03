#include"Obstacle.h"
#include"Game.h"
#include <iostream>
using namespace std;
void Obstacle::update(int K){
    game->paintatobstacle(row,col,'#');
}