#include <gtest/gtest.h>
#include "Format_room.h"
#include "place.h"

TEST(Formatroom, Checkget) {
  Format_room a, b;
  EXPECT_EQ(a, b);
}

TEST(Formatroom, Checkget1) {
  Format_room a;
  int b = a.get_k_row_c();
  EXPECT_EQ(b, 0);
}
TEST(Formatroom, Check_place1) {
  Format_room a(1, 2, 3);
  int b = a.get_k_row_c();
  EXPECT_EQ(b, 1);
}
TEST(Formatroom, Check_place2) {
  Format_room a(1, 2, 3);
  int c = a.get_k_row_v();
  EXPECT_EQ(c, 2);
}
TEST(Formatroom, Check_place3) {
  Format_room a(1, 2, 3);
  int d = a.get_k_seats();
  EXPECT_EQ(d, 3);
}

TEST(Formatroom, UpFormat_room1) {
  Format_room a(1, 2, 3);
  a.UpFormat_room(2, 3, 4);
  int b = a.get_k_row_c();
  EXPECT_EQ(b, 2);
}
TEST(Formatroom, UpFormat_room2) {
  Format_room a(1, 2, 3);
  a.UpFormat_room(2, 3, 4);
  int c = a.get_k_row_v();
  EXPECT_EQ(c, 3);
}
TEST(Formatroom, UpFormat_room3) {
  Format_room a(1, 2, 3);
  a.UpFormat_room(2, 3, 4);
  int d = a.get_k_seats();
  EXPECT_EQ(d, 4);
}

TEST(Formatroom, get_all) {
  Format_room a(5, 5, 0);
  int b = a.get_all_seats();
  EXPECT_EQ(b, 0);
}

TEST(Formatroom, get_all1) {
  Format_room a(0, 5, 10);
  int b = a.get_all_seats();
  EXPECT_EQ(b, 50);
}

TEST(Formatroom, get_all2) {
  Format_room a(10, 5, 10);
  int b = a.get_all_seats();
  EXPECT_EQ(b, 150);
}