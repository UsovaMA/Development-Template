#include <gtest/gtest.h>
#include "Coord.h"
#include "Snake.h"

TEST(Snake, Konstr_h) {
  Snake sn;
  Head h = sn.get_hea();
  Coord a = h.get_c();
  EXPECT_EQ(a.get_x(), 4);
  EXPECT_EQ(a.get_y(), 1);
}

TEST(Snake, Konstr_sn) {
  Snake sn;
  EXPECT_EQ(sn.get_num_of_last(), 0);
  EXPECT_EQ(sn.get_size_body(), 4);
}


TEST(Snake, new_coord_down) {
  Snake sn; 
  sn.new_coord(10, 20);
  Head h = sn.get_hea();
  Coord a = h.get_c();
  EXPECT_EQ((a.get_x() > 0), 1);
  EXPECT_EQ((a.get_y() > 0), 1);
}

TEST(Snake, new_coord_up) {
  Snake sn;
  sn.new_coord(10, 20);
  Head h = sn.get_hea();
  Coord a = h.get_c();
  EXPECT_EQ((a.get_x() < 10), 1);
  EXPECT_EQ((a.get_y() < 20), 1);
}


TEST(Snake, new_step) {
  Snake sn;
  sn.new_coord(10, 20);
  sn.new_step(0, 1);
  EXPECT_EQ(sn.get_size_body(), 5);
}

TEST(Snake, new_step1) {
  Snake sn;
  sn.new_coord(10, 20);
  sn.new_step(0, 0);
  EXPECT_EQ(sn.get_size_body(), 4);
}

TEST(Snake, plus_body) {
  Snake sn;
  sn.new_coord(10, 20);
  Coord a;
  sn.plus_body(a);
  EXPECT_EQ(sn.get_size_body(), 5);
}

TEST(Snake, check_free) {
  Snake sn;
  sn.new_coord(10, 20);
  Head h = sn.get_hea();
  Coord a = h.get_c();
  EXPECT_EQ(sn.check_free(a.get_x(), a.get_y()), 0);
}

TEST(Snake, check_free_no_heat) {
  Snake sn;
  sn.new_coord(10, 20);
  Head h = sn.get_hea();
  Coord a = h.get_c();
  EXPECT_EQ(sn.check_free_no_heat(a.get_x(), a.get_y()), 0);
}

TEST(Snake, losing) {
  Snake sn;
  sn.new_coord(10, 20);
  EXPECT_EQ(sn.losing(10, 20), 0);
}