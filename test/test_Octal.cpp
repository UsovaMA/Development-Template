#include <gtest/gtest.h>
#include "Octal.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  Octal a = "26574";
  Octal b = "37252";
  Octal c = a + b;
  ASSERT_EQ(c, "66046");
}
TEST(Addition, CanAddTwoPositiveNumbers2) {
  Octal a = "37252";
  Octal b = "26574";
  Octal c = a + b;
  ASSERT_EQ(c, "66046");
}
TEST(Addition, CanAddTwoPositiveNumbers3) {
  Octal a = "7";
  Octal b = "1";
  Octal c = a + b;
  ASSERT_EQ(c, "10");
}
TEST(Addition, CanAddTwoPositiveNumbers4) {
  Octal a = "6";
  Octal b = "1";
  Octal c = a + b;
  ASSERT_EQ(c, "7");
}
TEST(raznost, CanDiffTwoPositiveNumbers) {
  Octal a = "23745";
  Octal b = "3653";
  Octal c = a - b;
  ASSERT_EQ(c, "20072");
}

TEST(raznost, CanDiffTwoPositiveNumbers2) {
  Octal a = "32";
  Octal b = "63";
  Octal c = a - b;
  ASSERT_EQ(c, "31");
}
TEST(raznost, CanDiffTwoPositiveNumbers3) {
  Octal a = "10";
  Octal b = "1";
  Octal c = a - b;
  ASSERT_EQ(c, "7");
}
TEST(raznost, CanDiffTwoPositiveNumbers4) {
  Octal a = "7";
  Octal b = "1";
  Octal c = a - b;
  ASSERT_EQ(c, "6");
}
TEST(sravnenie, CanSravnTwoPositiveNumbers) {
  Octal a = "25";
  Octal b = "25";
  Octal p1 = "1";
  if (a == b) {
   ASSERT_EQ(p1, "1");
  } 
}
TEST(sravnenie, CanSravnTwoPositiveNumbers2) {
  Octal a = "24";
  Octal b = "25";
  Octal p1 = "0";
  if (a == b) {
    ASSERT_EQ(p1, "0");
  }
}
TEST(priravniaem, CanpriravnivaemTwoPositiveNumbers) {
  Octal a = "40";
  Octal b = "20";
  a = b;
  ASSERT_EQ(a, "20");
}
TEST(kop, CanCopTwoPositiveNumbers) {
  Octal a = "69";
  Octal b(a);
  ASSERT_EQ(b, "69" );
}