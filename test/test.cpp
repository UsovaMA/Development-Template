// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "ClassIntegrals.h"

// 1(first) function
TEST(TestClassIntegrals, 1integration_centre) {
  Integrals c1(0, 8, 4);
  double res = c1.metod_centre();
  double trueres = 96;
  EXPECT_EQ(res, trueres);
}

TEST(TestClassIntegrals, 1integration_left) {
  Integrals c1(0, 8, 4);
  double res = c1.metod_left();
  double trueres = 64;
  EXPECT_EQ(res, trueres);
}

TEST(TestClassIntegrals, 1integration_right) {
  Integrals c1(0, 8, 4);
  double res = c1.metod_right();
  double trueres = 128;
  EXPECT_EQ(res, trueres);
}

TEST(TestClassIntegrals, 1integration_sr_res) {
  Integrals c1(0, 8, 4);
  double res = c1.sr_znach();
  double trueres = 96;
  EXPECT_EQ(res, trueres);
}

