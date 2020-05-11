#include <gtest/gtest.h>
#include "place.h"

TEST(Place, Constructor) {
  place a, b;
  EXPECT_EQ(a, b);
}

TEST(Place, Constructor1) {
  place a(1, 2, 0, 1);
  int g1 = a.get_pl();
  EXPECT_EQ(g1, 2);
}
TEST(Place, Constructor2) {
  place a(1, 2, 0, 1);
  int g2 = a.get_row();
  EXPECT_EQ(g2, 1);
}
TEST(Place, Constructor3) {
  place a(1, 2, 0, 1);
  bool g3 = a.get_free();
  EXPECT_EQ(g3, 1);
}
TEST(Place, Constructor4) {
  place a(1, 2, 0, 1);
  bool g4 = a.get_vip();
  EXPECT_EQ(g4, 0);
}

TEST(Place, bool_get_im1) {
  place a;
  a.im_vip(1);
  a.im_free(0);
  bool g1 = a.get_vip();
  EXPECT_EQ(g1, 1);
}
TEST(Place, bool_get_im2) {
  place a;
  a.im_vip(1);
  a.im_free(0);
  bool g2 = a.get_free();
  EXPECT_EQ(g2, 0);
}
