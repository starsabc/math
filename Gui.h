#ifndef _GUI_H_
#define _GUI_H_
#include <ncurses.h>
class Item {
public:
    size_t row;
    size_t col;
    int hp ;
    virtual void update(int key=0) {
        return;
    }
    virtual bool out() {
        return false;
    }
};
class Gui:public Item {
    WINDOW* win;
public:
    Gui() {
        row = 20;
        col = 50; 
        init(); 
    }
    ~Gui() {endwin();}
    void init();
    int get();
    void paintat(size_t, size_t, char);
    void paintatplayer(size_t, size_t, char);
    void paintatmedical(size_t, size_t, char);
    void paintatlaser(size_t, size_t, char);
    void paintatmine(size_t, size_t, char);
    void paintatobstacle(size_t, size_t, char);
    void paintattank(size_t, size_t, char);
    void printMsg(int row, int col, char* prompt, int v);
    void clear();
    void end() {endwin();}
    void redraw();
};
#endif