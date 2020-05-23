#include <gtest/gtest.h>
#include "menu.h"
TEST(MenuConstructors, CanCreateMenuWithInitConstractor) {
  ASSERT_NO_THROW(Menu());
}
TEST(MenuConstructors, CanCreateMenuWithInitConstracto) {

  int x = 2, y = 2;

  int size = 20;

  int num = 3;

  std::string* mn = new std::string[num];

  mn[0] = "mars";
  mn[1] = "vener";
  mn[2] = "chel";
  
  ASSERT_NO_THROW(Menu m(x, y, size, num, mn));
}
TEST(MenuConstructors, CanCreateMenuWithInitConstract) {

  int x = 2, y = 2;

  int size = 5;

  int num = 3;

  std::string* mn = new std::string[num];

  mn[0] = "mars";
  mn[1] = "vener";
  mn[2] = "chel";

  ASSERT_ANY_THROW(Menu m(x, y, size, num, mn));
}
TEST(MenuConstructors, CanCreateMenuWithInitConstrac) {
 ASSERT_ANY_THROW(Menu m("Menu"));
}
TEST(MenuConstructors, CanCreateMenuWithInitConstra) {
  ASSERT_ANY_THROW(Menu m("Menu_2"));
}