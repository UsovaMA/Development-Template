#ifndef __COORD_H__
#define __COORD_H__

class Coord {
private:
    int x, y;
public:
    Coord() {
      x = y = 0;
    }
    Coord(int _x, int _y) {
      x = _x;
      y = _y;
    }
    void up();
    void doun();
    void right();
    void left();
    int get_x();
    int get_y();
    void im_x(int a);
    void im_y(int a);
    Coord & operator =(const Coord & c);
    friend bool operator== (const Coord &c1, const Coord &c2) {
      if ((c1.x == c2.x) && (c1.y == c2.y)) return 1;
      else return 0;
    }
    friend class  Head;
    friend class  Snake;
    friend class  Screen;
};

void sw_coord(Coord & a, Coord & b);

class Head {
private:
  Coord c;
  int route; //1-up, 2-doun, 3-right, 4-left
  char simv;
public:
  Coord get_c() {
    return c;
  }
  void change_simv() {
    if (route == 1) simv = 'V';
    if (route == 2) simv = '^';
    if (route == 3) simv = '>';
    if (route == 4) simv = '<';
  }
  Head() {
    c.im_x(0);
    c.im_y(0);
    route = 4;
    simv = '<';
  }
  friend class  Snake;
  friend class  Screen;
};

#endif // __COORD_H__
