#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "Snake.h"
#include "Coord.h"
#include <windows.h>

class Screen {
public:
    Screen();
    Screen(const Screen &s);
    int get_m();
    int get_n();
    int get_res();
    bool new_cadr(int napr);
    void draw();
    void new_fruct();
    ~Screen();
private:
  int m, n;
  int res;
  Coord fruct;
  Snake pitosha;
};

#endif // __CSCREEN_H__
