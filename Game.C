#include "Game.h"
#include "Obstacle.h"
#include "Player.h"
#include "Bullet.h"
#include"Tank.h"
#include"Supertank.h"
#include"Lasertank.h"
#include"Medicalpack.h"
#include <cstdlib>
#include <set>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstddef>
Game::Game() {
    gui.init();
    pl = new Player(this);
    updates = 0;
    srand(time(0));
    bulletnum = 20;
    bombnum=0;
    score = 0;
    tanknumprint = 0;



    hp=10;
    its.push_front(pl);
    medicalpacknum=0;
    minenum=0;
    lasernum=0;
    lasertanknum=0;
    supertanknum=0;
    size=0;
    
} 
void Game::init(set<int> s){
    gui.clear();
    gui.printMsg(12,25,"random mode,tap ",1);
    gui.printMsg(13,25,"conventional mode,tap",2);
    gui.printMsg(5,25,"Welcome to Tank Battle",2);
    gui.printMsg(20,3,"Bomb(*) hp-",1);
    gui.printMsg(21,3,"Mine(@),hp-",5);
    gui.printMsg(22,3,"Bullet(^),enery hp-",1);
    gui.printMsg(23,3,"laser($),hp-",3);
    gui.printMsg(24,3,"medicalpack(+),hp  recover to",10);
    gui.printMsg(25,3,"win when your score=",2000);
    gui.printMsg(26,3,"when hit tank,score+",100);
    gui.printMsg(27,3,"defeat when hp=",0);
    gui.redraw();
    usleep(6000000);
    int c=gui.get();
    if(c=='1'){   
        set<int> s1;
        while(s1.size()<20){
            int a=(2+rand()%25)*100+(3+rand()%75) ;
            s1.insert(a);
        }
        size=int(s1.size());
        set<int>::iterator it =s1.begin();
        while(it!=s1.end()){
            obstacle=new Obstacle(this,(*it)/100,(*it)%100);
            its.push_back(obstacle);
            it++;
        }
    }
    else if(c=='2'){
        set<int> s1(s);
        set<int>::iterator it =s1.begin();
        while(it!=s1.end()){
            obstacle=new Obstacle(this,(*it)/100,(*it)%100);
            its.push_back(obstacle);
            it++;
        }
    }
    else{
        gui.end();
        exit(0);
    }
}
void Game::addBullet(size_t r, size_t c,int x,int y) {
    its.push_back(new Bullet(this, r, c,x,y));
}

void Game::update() {
    gui.clear();
    gui.printMsg(2, 85, "Bulletnum", bulletnum);
    gui.printMsg(3, 85, "Score", score);
    gui.printMsg(4, 85, "HP",hp);
    addtank();
    list<Item*>::iterator it = its.begin();
    int c = gui.get();
    while (it != its.end() ) {
        (*it)->update(c);
        if ((*it)->out() == true) {
           delete *it;
           it = its.erase(it);
        }
        it++;
    }
    addmedicalpack();
    updates++;
    if (updates % 40==0 && bulletnum < 10) {
        bulletnum++;
    }
    gui.redraw();
}
void Game::addtank() {
    while (tanknumprint < 4 ) {
        int a=rand()%100;
        int r=2+rand()%20;
        int c=3+rand()%75;
        if(hitobstacle(r,c)==false && hitobstacle(r,c+1)==false && hitobstacle(r,c+2)==false){
            if(supertanknum==0 && a>49 && a<=79 ) {
                supertank=new Supertank(this, r, c);
                its.push_back(supertank);
                supertanknum++;
                tanknumprint ++;
            }
            if(lasertanknum==0 && a>79){
                lasertank=new Lasertank(this, r, c);
                its.push_back(lasertank);
                lasertanknum++;
                tanknumprint ++;
            }
            if(a<=49){
                tank = new Tank(this, r, c);
                its.push_back(tank);
                tanknumprint ++;
            }
        }
    }
}
bool Game::hittank(size_t row, size_t col) {
    if (tanknumprint == 0) return false;
    list<Item*>::iterator it = its.begin();
    while (it != its.end()) {
        if (typeid(*(*it)) == typeid(Tank) || typeid(*(*it)) == typeid(Supertank) || typeid(*(*it)) == typeid(Lasertank)) 
            if ((*it)->row == row  && (*it)->col <= col && col<=(*it)->col+2 )   {
                (*it)->hp--;
                return true;
            }
        it++;
    }
    return false;
}
void Game::complete() {
    gui.clear();
    gui.printMsg(10, 25, "Defeat,Final Score:", score);
    gui.redraw();
    usleep(3000000);
    gui.end();
    exit(0);
}
void Game::win(){
    gui.clear();
    gui.printMsg(10, 25, "You win the game,Final Score:", score);
    gui.redraw();
    usleep(3000000);
    gui.end();
    exit(0);
}
void Game::addmedicalpack(){
    int r=2+rand()%26;
    int c=3+rand()%75;
     if( medicalpacknum==0 && rand()%50 == 1 && hitobstacle(r,c)==false){
        medicalpack=new Medicalpack(this,r,c);
        its.push_back(medicalpack);
        medicalpacknum=1;
     }
}
bool Game::eatpack(){
    if(pl->row==medicalpack->row && pl->col==medicalpack->col){
        hp=10;
        return true;
    }
    return false;
}
int Game::trace(){
    return pl->row*100+pl->col;
}
bool Game::bombhittank(size_t row, size_t col) {
    if (tanknumprint == 0) return false;
    list<Item*>::iterator it = its.begin();
    while (it != its.end()) {
        if (typeid(*(*it)) == typeid(Tank) || typeid(*(*it)) == typeid(Supertank) || typeid(*(*it)) == typeid(Lasertank)) 
            if ((*it)->row == row  && (*it)->col <= col && col<=(*it)->col+2)   {
                (*it)->hp--;
                return true;
            }
        it++;
    }
    return false;
}
void Game::laserhit(size_t row,size_t col){
    list<Item*>::iterator it = its.begin();
    while (it != its.end()) {
        if (typeid(*(*it)) == typeid(Tank) && (*it)->row==row && (*it)->col <= col && col<=(*it)->col+2) (*it)->hp--;
        if(typeid(*(*it)) == typeid(Supertank) && (*it)->row==row && (*it)->col <= col && col<=(*it)->col+2) (*it)->hp-=2;
        it++;
    }
    if(row==pl->row && col==pl->col) hp-=3;
}
bool Game::hitobstacle(size_t row,size_t col){
    list<Item*>::iterator it = its.begin();
    while (it != its.end()) {
        if(typeid(*(*it)) == typeid(Obstacle) && (*it)->col==col && (*it)->row==row) return true;
        it++;
    }
    return false;        
}