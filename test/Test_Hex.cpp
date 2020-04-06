// Copyright 2020 <Diana Lukashuk>
#include <gtest/gtest.h>
#include "Hex.h"
#include "Header.h"

TEST(Hex, Addition1plusplus) {
  Hex a("A10", 0), b("B22", 0);
  Hex c("1532", 0);
  Hex myRes;
  myRes = a + b;

  EXPECT_EQ(myRes, c);
}

TEST(Hex, Check) {
  Hex a("00A10", 0), b("A10", 0);
  a.correct();
  EXPECT_EQ(a, b);
}

//TEST(Hex, Addition2plus_plus0) {
//  Hex a("0", 0), b("0", 0);
//  Hex c("0", 0);
//  EXPECT_EQ(a + b, c);
//}
//
//TEST(Hex, Addition3minus_plus) {
//  Hex a("A10", 1), b("B22", 1);
//  Hex c("1532", 1);
//  EXPECT_EQ(a + b, c);
//}
//
//TEST(Hex, Addition4plus_minus) {
//  Hex a("A10", 1), b("B22", 0);
//  Hex d = a + b;
//  Hex c("112", 0);
//  EXPECT_EQ((a + b), c);
//}
//TEST(Hex, Addition5minus_plus) {
//  Hex a("A10", 0), b("B22", 1);
//  Hex d = a + b;
//  Hex c("112", 1);
//  EXPECT_EQ((a + b), c);
//}
//
//TEST(Hex, subtraction5plus_plus) {
//  Hex a("A10", 0), b("B22", 0);
//  Hex c("112", 1);
//  EXPECT_EQ((a - b), c);
//}
//
//TEST(Hex, subtraction6minus_plus) {
//  Hex a("A10", 1), b("B22", 0);
//  Hex c("1532", 1);
//  EXPECT_EQ((a - b), c);
//}
//
//TEST(Hex, comparison) {
//  Hex a("A10", 1), b("B22", 0);
//  EXPECT_EQ((a > b), 0);
//  EXPECT_EQ((a >= b), 0);
//  EXPECT_EQ((a <= b), 1);
//  EXPECT_EQ((a < b), 1);
//  EXPECT_EQ((a != b), 1);
//  EXPECT_EQ((a == b), 0);
//}
