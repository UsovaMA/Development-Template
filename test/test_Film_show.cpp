#include <gtest/gtest.h>
#include "..\include\Film_show.h"
#include "Room.h"

TEST(Film_show, testtime) {
  Format_room f(10, 10, 10);
  Room r(100, 200, f);
  Film_show film("YEE", 2, 2, "21:00", r);
  int t = film.type_time();
  EXPECT_EQ(t, 3);
}

TEST(Film_show, Upgr) {
  Format_room f(10, 10, 10);
  Room r(100, 200, f);
  Film_show film("YEE", 2, 2, "21:00", r);
  film.Upgr("No", 1, 1, "00:00", r);
  int t = film.type_time();
  EXPECT_EQ(t, 3);
}
