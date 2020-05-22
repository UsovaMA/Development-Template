#include "Snake.h"
#include <ctime>


Snake::Snake() {
  size_body = 4;
  body = 0;
  hea.route=4;
  hea.change_simv();
  hea.c.x = 4;
  hea.c.y = 1;
  num_of_last = 0;
}

Snake::Snake(const Snake & sn) {
  if(size_body!=0)  delete[]body;
  size_body = sn.size_body;
  num_of_last = sn.num_of_last;
  hea= sn.hea;
  body = new Coord[size_body];
  for (int i = 0; i < size_body; i++) {
    body[i] = sn.body[i];
  }
}

Snake::~Snake() {
  delete[]body;
}

int Snake::get_size_body() {
  return size_body;
}

int Snake::get_num_of_last() {
  return num_of_last;
}

Head Snake::get_hea() {
  return hea;
}

void Snake::new_coord(int m, int n) {
  srand(time(0));
  body = new Coord[4];
  int a = rand();
  hea.c.x = 2 + a % (m-6);
  body[3].x = hea.c.x + 1;
  body[2].x = hea.c.x + 2;
  body[1].x = hea.c.x + 3;
  body[0].x = hea.c.x + 4;
  srand(time(0));
  hea.c.y = 1 + rand() % (n-2);
  body[3].y = hea.c.y;
  body[2].y = hea.c.y;
  body[1].y = hea.c.y;
  body[0].y = hea.c.y;
  num_of_last = 0;
}

void Snake::plus_body(Coord p) {                              //увеличиваем размер тела на 1
    Coord * dop;  // добавляем координату и она становится последней в массиве.
    dop = new Coord[size_body + 1];
    for (int i = 0; i < size_body; i++) {
      dop[i] = body[i];
    }
    dop[size_body] = p;
    if(size_body !=0) delete[]body;
    body = new Coord[size_body + 1];
    for (int i = 0; i < size_body +1; i++) {
      body[i]= dop[i];
    }
    delete[] dop;
    size_body++;
}

bool Snake::check_free(int _x, int _y) {
  if((hea.c.x == _x) && (hea.c.y == _y)) return 0;
  for (int i = 0; i < size_body; i++) {
    if((body[i].x== _x)&&(body[i].y == _y))   return 0;
  }
  return 1;
}

bool Snake::check_free_no_heat(int _x, int _y) {
  for (int i = 0; i < size_body; i++) {
    if ((body[i].x == _x) && (body[i].y == _y))  
      return 1;
  }
  return 0;
}

bool Snake::losing(int m, int n) {
  if((hea.c.x>=m)||(hea.c.x < 0)) return true;
  if ((hea.c.y >= n) || (hea.c.y < 0)) return true;
  return (check_free_no_heat(hea.c.x, hea.c.y));
}

void Snake::new_step(int napravlen, bool food) {
  if (food) { //если еда
    Coord dop;
    if (num_of_last == 0) { //ничего не двигается
      dop = hea.c;
    }
    else { //двигается
      dop = body[0];
      for (int i = 0; i+1 <= num_of_last; i++) {
        body[i] = body[i + 1]; //101
      } 
      body[num_of_last - 1] = hea.c;
    }//передвинули начало
    plus_body(dop);
  } else { //если еды нет
    for (int i = 0; i < size_body; i++) {
      if (num_of_last == i) { //если попали
        body[i] = hea.c; //последний элемент встает на место головы
        //местоположение изменили
        if (num_of_last == size_body - 1)  //если номер является max 
          num_of_last = 0;
        else num_of_last++;
        //номер последнего элемента поменяли
        break; 
      }
    }
    //переместили
  }
  //Меняем местоположение головы
  if (napravlen == 0) napravlen = hea.route;
  if (napravlen == 1) hea.c.up();
  if (napravlen == 2) hea.c.doun();
  if (napravlen == 3) hea.c.right();
  if (napravlen == 4) hea.c.left();
  //Меняем направление головы
  hea.route= napravlen;
  hea.change_simv();
}
