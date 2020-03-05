#include <gtest/gtest.h>
#include "Class_Time.hpp"

TEST(Class_time, IntToStr) {
  Time T1(0,5,7);
  string T = "00:05:07";
  EXPECT_EQ(T1.IntToStr(),T);
}

TEST(Class_time, OperatorMinus) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  Time T3(12, 10, 13);
  EXPECT_EQ(T1 - T2, T3);
}

TEST(Class_time, OperatorPlus) {
  Time T1(15, 59, 23);
  Time T2(3, 23, 10);
  Time T3(19, 22, 33);
  EXPECT_EQ(T1 + T2, T3);
}

TEST(Class_time, OperatorGreater) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  EXPECT_EQ(T1 > T2, 1);
}

TEST(Class_time, OperatorLess) {
  Time T1(15, 33, 23);
  Time T2(3, 23, 10);
  EXPECT_EQ(T1 < T2, 0);
}

TEST(Class_time, OperatorEquality) {
  Time T1(3, 23, 10);
  Time T2(3, 23, 10);
  EXPECT_EQ(T1 == T2, 1);
}