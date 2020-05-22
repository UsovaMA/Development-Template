#include <gtest/gtest.h>
#include "Coord.h"

TEST(Coord, Get_Im) {
  Coord a, b;
  a.im_x(0); a.im_y(1);
  b.im_x(2); b.im_y(3);
  EXPECT_EQ(a.get_x(), 0);
  EXPECT_EQ(a.get_y(), 1);
  EXPECT_EQ(b.get_x(), 2);
  EXPECT_EQ(b.get_y(), 3);
}

TEST(Coord, Konstr) {
  Coord a;
  EXPECT_EQ(a.get_x(), 0);
  EXPECT_EQ(a.get_y(), 0);
}

TEST(Coord, up ) {
  Coord a(1, 2);
  a.up();
  EXPECT_EQ(a.get_x(), 1);
  EXPECT_EQ(a.get_y(), 3);
}

TEST(Coord, doun) {
  Coord a(1, 2);
  a.doun();
  EXPECT_EQ(a.get_x(), 1);
  EXPECT_EQ(a.get_y(), 1);
}

TEST(Coord, right) {
  Coord a(1, 2);
  a.right();
  EXPECT_EQ(a.get_x(), 2);
  EXPECT_EQ(a.get_y(), 2);
}

TEST(Coord, left) {
  Coord a(1, 2);
  a.left();
  EXPECT_EQ(a.get_x(), 0);
  EXPECT_EQ(a.get_y(), 2);
}

TEST(Coord, Ravno) {
  Coord a, b;
  b.im_x(2); b.im_y(3);
  a = b;
  EXPECT_EQ(a.get_x(), 2);
  EXPECT_EQ(a.get_y(), 3);
}
TEST(Coord, RavnoRavno1) {
  Coord a, b;
  a.im_x(0); a.im_y(1);
  b.im_x(2); b.im_y(3);
  EXPECT_EQ((a==b), 0);
}

TEST(Coord, RavnoRavno2) {
  Coord a, b;
  a.im_x(0); a.im_y(1);
  b.im_x(0); b.im_y(1);
  EXPECT_EQ((a == b), 1);
}

TEST(Coord, Head_konstr) {
  Head h;
  Coord a = h.get_c();
  EXPECT_EQ(a.get_x(), 0);
  EXPECT_EQ(a.get_y(), 0);
}