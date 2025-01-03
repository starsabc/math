#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include<fstream>
#include <ctime>
#include <set>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
using namespace std;
int main(int argc,char** argv)
{
    struct timeval time_now {};
    gettimeofday(&time_now, NULL);
    time_t oldTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    time_t currentTime =  oldTime;
    Game game;
    set<int> s1;
    ifstream mymap(argv[1]);
    if(mymap.is_open()){
        string line;
        int row=0;
        while(getline (mymap,line) && row<30){
            for(size_t col=0;col<line.size() && col<80;++col){
                if(line[col]=='#') s1.insert(row*100+col);
                if(line[col]=='$'){ break;}
            }
            row++;
        }
        mymap.close();
    }
    game.init(s1);
    while (true) {
        gettimeofday(&time_now, NULL);
        currentTime = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        if (currentTime - oldTime < 50) {usleep(25);continue;}
        game.update();
        oldTime = currentTime;
    }
    return 0;
}
