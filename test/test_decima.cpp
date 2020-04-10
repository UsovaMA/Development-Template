#include <gtest/gtest.h>
#include "Octal.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  Octal a = "26574";
  Octal b = "37252";
  Octal c = a + b;
  ASSERT_EQ(c, "66046");
}
TEST(raznost, CanDiffTwoPositiveNumbers) {
  Octal a = "23745";
  Octal b = "3653";
  Octal c = a - b;
  ASSERT_EQ(c, "20072");
}
TEST(sravnenie, CanSravnTwoPositiveNumbers) {
  Octal a = "25";
  Octal b = "25";
  Octal p1 = "1";
  if (a == b) {
   ASSERT_EQ(p1, "1");
  } else { 
 
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