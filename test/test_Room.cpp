#include <gtest/gtest.h>
#include "Room.h"

TEST(Room, Constructor) {
  Room a, b;
  EXPECT_EQ(a, b);
}

TEST(Room, Constructor1) {
  Format_room f;
  Room a, b(1, 1, f);
  bool s = (a == b);
  EXPECT_EQ(s, 0);
}

TEST(Room, Price_Base1) {
  Format_room f;
  Room a(100, 200,  f);
  int a1 = a.price_base_cl();
  EXPECT_EQ(a1, 100);
}

TEST(Room, Price_Base2) {
  Format_room f;
  Room a(100, 200, f);
  int a2 = a.price_base_vip();
  EXPECT_EQ(a2, 200);
}

TEST(Room, Price_Night1) {
  Format_room f;
  Room a(100, 200, f);
  double a2 = a.price_vip_night();
  EXPECT_EQ(a2, 300);
}
TEST(Room, Price_Night2) {
  Format_room f;
  Room a(100, 200, f);
  double a1 = a.price_cl_night();
  EXPECT_EQ(a1, 150);
}

TEST(Room, Price_Morning) {
  Format_room f;
  Room a(100, 200, f);
  double a1 = a.price_cl_morning();
  double a2 = a.price_vip_morning();
  EXPECT_EQ(a1, 75);
  EXPECT_EQ(a2, 150);
}

TEST(Room, Up_Room1) {
  Format_room f;
  Format_room f1(10, 10, 100);
  Room a(100, 200, f);
  a.UpRoom(120, 220, f1);
  EXPECT_EQ(a.get_format(), f1);
}

TEST(Room, Up_Room2) {
  Format_room f;
  Format_room f1(10, 10, 100);
  Room a(100, 200, f);
  a.UpRoom(120, 220, f1);
  double a1 = a.price_base_cl();
  EXPECT_EQ(a1, 120);
}

TEST(Room, Up_Room3) {
  Format_room f;
  Format_room f1(10, 10, 100);
  Room a(100, 200, f);
  a.UpRoom(120, 220, f1);
  double a2 = a.price_base_vip();
  EXPECT_EQ(a2, 220);
}
