#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;
void Gui::init() {
    initscr();                 
    refresh();                  
    win = stdscr;
    refresh();
    curs_set(0);
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
    for (int i = 0; i < 30; i++) {
        mvaddch(i, 0, '|');
        mvaddch(i, 79, '|');
    }
    for(int i=0;i<80;i++){
        mvaddch(0,i,'-');
        mvaddch(29,i,'-');
    }
}
int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}
void Gui::paintatplayer(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(1));
    //wrefresh(win);
    return;
}
void Gui::paintat(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(3,COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(3));
    //wrefresh(win);
    return;
}
void Gui::paintatmedical(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(2));
    //wrefresh(win);
    return;
}
void Gui::paintattank(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(5,COLOR_BLUE,COLOR_BLACK);
    attron(COLOR_PAIR(5));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(5));
    //wrefresh(win);
    return;
}
void Gui::paintatmine(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(4,COLOR_WHITE,COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(4));
    //wrefresh(win);
    return;
}
void Gui::paintatobstacle(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(6,COLOR_CYAN,COLOR_BLACK);
    attron(COLOR_PAIR(6));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(6));
    //wrefresh(win);
    return;
}
void Gui::paintatlaser(size_t rw, size_t cl, char c) {
    start_color();
    init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
    attron(COLOR_PAIR(5));
    mvwaddch(win, rw, cl, c);
    attroff(COLOR_PAIR(5));
    //wrefresh(win);
    return;
}
void Gui::printMsg(int row, int col, char* prompt, int v) {
    mvwprintw(win, row, col, prompt);
    char s[32];
    sprintf(s, "%d", v);
    mvwprintw(win, row, col+strlen(prompt)+1, s);
    //wrefresh(win);
}
void Gui::clear() {
    werase(win);
    for (int i = 0; i < 30; i++) {
        mvaddch(i, 0, '|');
        mvaddch(i, 79, '|');
    }
    for(int i=0;i<80;i++){
        mvaddch(0,i,'-');
        mvaddch(29,i,'-');
    }
}
void Gui::redraw(){
    wrefresh(win);
}