#include <gtest/gtest.h>
#include "Class_Time.hpp"

TEST(Addition, IntToStr) {
  Time T1(0,5,7);
  string T = "00:05:07";
  EXPECT_EQ(T1.IntToStr(),T);
}

TEST(Addition, OperatorMinus) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  Time T3(12, 10, 13);
  Time T4 = T1 - T2;
  EXPECT_EQ(T4.IntToStr(), T3.IntToStr());
}

TEST(Addition, OperatorPlus) {
  Time T1(15, 59, 23);
  Time T2(3, 23, 10);
  Time T3(19, 22, 33);
  Time T4 = T1 + T2;
  EXPECT_EQ(T4.IntToStr(), T3.IntToStr());
}

TEST(Addition, OperatorGreater) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  int a = T1 > T2;
  EXPECT_EQ(a, 1);
}

TEST(Addition, OperatorLess) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  int a = T1 < T2;
  EXPECT_EQ(a, 0);
}

TEST(Addition, OperatorEquality) {
  Time T1(3, 23, 10);
  Time T2(3, 23, 10);
  int a = T1 == T2;
  EXPECT_EQ(a, 1);
}