#include <gtest/gtest.h>
#include "Snake.h"

TEST(Snake, start) {
  Zmeika s;
  ASSERT_NO_THROW(s.Setup());
}

TEST(Snake, errortrueSmall) {
  Zmeika s;
  int w = 1;
  ASSERT_ANY_THROW(s.Logic(w));
}

TEST(Snake, errortrueBig) {
  Zmeika s;
  int w = 200;
  ASSERT_NO_THROW(s.Logic(w));
}