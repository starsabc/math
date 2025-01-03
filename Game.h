#ifndef _GAME_H_
#define _GAME_H_
#include <list>
#include<set>
#include "Gui.h"
using namespace std;
class Player;
class Bullet;
class Tank;
class Item;
class Supertank;
class Lasertank;
class Laser;
class Obstacle;
class Medicalpack;
class Game {
    Gui gui;
public:
    Game() ;
    ~Game() { gui.end(); };
    void addBullet(size_t r, size_t c,int x,int y);
    void update();

    void paintatplayer(size_t ro, size_t cl, char c) {gui.paintatplayer(ro, cl, c);}
    void paintattank(size_t ro, size_t cl, char c) {gui.paintattank(ro, cl, c);}
    void paintatobstacle(size_t ro, size_t cl, char c) {gui.paintatobstacle(ro, cl, c);}
    void paintatmine(size_t ro, size_t cl, char c) {gui.paintatmine(ro, cl, c);}
    void paintatmedical(size_t ro, size_t cl, char c) {gui.paintatmedical(ro, cl, c);}
    void paintatlaser(size_t ro, size_t cl, char c) {gui.paintat(ro, cl, c);}
    void paintat(size_t ro, size_t cl, char c) {gui.paintat(ro, cl, c);}
    Player* pl;
    int updates;
    int bulletnum;
    int score;

    Tank* tank;
    Supertank* supertank;
    Lasertank* lasertank;
    int tanknumprint;
    void addtank();
    bool hittank(size_t row,size_t col);
    bool bombhittank(size_t row,size_t col);

    int bombnum;
    list <Item*> its;
    int hp;
    void win();
    void complete();

    void addmedicalpack();
    bool eatpack();
    int medicalpacknum;
    Medicalpack* medicalpack;

    int minenum;
    int trace();

    int lasernum;
    int lasertanknum;
    int supertanknum;

    bool hitobstacle(size_t row,size_t col);
    void laserhit(size_t row,size_t col);
    Obstacle* obstacle;
    void init(set<int> s);

    int size;
};
#endif
