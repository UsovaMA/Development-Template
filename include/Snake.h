#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <vector>
#include "Coord.h"
class Snake {
public:
    Snake();
    Snake(const Snake &sn);
    ~Snake();
    int get_size_body();
    int get_num_of_last();
    Head get_hea();
    void new_coord(int m, int  n);
    void new_step(int napravlen, bool food);
    void plus_body(Coord p);
    bool check_free(int _x, int _y);
    bool check_free_no_heat(int _x, int _y);
    bool losing(int m, int n);
private:
  int size_body, num_of_last;
  Head hea;
  Coord * body;
  friend class Screen;
};

#endif // __SNAKE_H__
