#ifndef _MEDICALPACK_H_
#define _MEDICALPACK_H_
#include "Game.h"

class Medicalpack :public Item {
public:
    Game* game;
    Medicalpack(Game* g, size_t r, size_t c) {
        row = r;
        col = c;
        game = g;
    }
    void update(int key);
    bool out();
};
#endif