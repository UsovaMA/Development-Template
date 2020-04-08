// Copyright 2020 Podovinnikov
#include <gtest/gtest.h>
#include "ClassOctal.h"
TEST(TestClassOctal, constructorCopy) {
  Octal c1("7042", 4);
  Octal c2(c1);
  EXPECT_EQ(c1, c2);
}
TEST(TestClassOctal, subtraction) {
  Octal c1("37251", 5);
  Octal c2("3122", 4);
  Octal p = c1 - c2;
  Octal restrue("34127", 5);
  EXPECT_EQ(p, restrue);
}
TEST(TestClassOctal, subtraction1) {
  Octal c1("37251", 5);
  Octal c2("3122", 4);
  Octal p = c2 - c1;
  Octal restrue("-34127", 6);
  EXPECT_EQ(p, restrue);
}

TEST(TestClassOctal, sum) {
  Octal c1("420", 3);
  Octal c2("1232", 4);
  Octal p = c1 + c2;
  Octal restrue("1652", 4);
  EXPECT_EQ(p, restrue);
}
TEST(TestClassOctal, prisvoit) {
  Octal c1("7042", 4);
  Octal c2("666", 3);
  c1 = c2;
  EXPECT_EQ(c1, c2);
}
TEST(TestClassOctal, prisvoit1) {
  Octal c1("7042", 4);
  Octal c2("666", 3);
  c2 = c1;
  EXPECT_EQ(c2, c1);
}
TEST(TestClassOctal, CanSravn) {
  Octal c2("3567", 4);
  Octal c1("3567", 4);
  ASSERT_NO_THROW(c1 == c2);
}
TEST(TestClassOctal, CanRightSravn1) {
  Octal c2("543", 3);
  Octal c1 = c2;
  EXPECT_EQ(true, c1 == c2);
}

TEST(TestClassOctal, CanRightSravn2) {
  Octal c2("4325", 4);
  Octal c1("43677", 5);
  EXPECT_EQ(false, c1 == c2);
}
TEST(TestClassOctal, CanPrisvoit) {
  Octal c2("543", 3);
  Octal c1;
  ASSERT_NO_THROW(c1 = c2);
}

TEST(TestClassOctal, CanRightPrisvoit) {
  Octal c2("223", 3);
  Octal c1 = c2;
  EXPECT_EQ(c1, c2);
  system("pause");
}




