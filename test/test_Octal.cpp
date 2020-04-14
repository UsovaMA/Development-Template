#include <gtest/gtest.h>
#include "Octal.h"

TEST(Addition, CanAddTwoPositiveNumbersOneLenght) {
  Octal a = "26574";
  Octal b = "37252";
  Octal c = a + b;
  ASSERT_EQ(c, "66046");
}
TEST(Addition, CanAddTwoPositiveNumbersWhenTheFirstChangeOfTheOther) {
  Octal a = "37252";
  Octal b = "26574";
  Octal c = a + b;
  ASSERT_EQ(c, "66046");
}
TEST(Addition, CanAddTwoNumbersDifferentLenghtFirstLong) {
  Octal a = "17";
  Octal b = "1";
  Octal c = a + b;
  ASSERT_EQ(c, "20");
}
TEST(Addition, CanAddTwoNumbersDifferentLenghtSecondLong) {
  Octal a = "1";
  Octal b = "17";
  Octal c = a + b;
  ASSERT_EQ(c, "20");
}
TEST(raznost, CanDiffTwoNumbersDifferentLenghtFirstLong) {
  Octal a = "23745";
  Octal b = "3653";
  Octal c = a - b;
  ASSERT_EQ(c, "20072");
}

TEST(raznost, CanDiffTwoNumbersOneLenght) {
  Octal a = "63";
  Octal b = "32";
  Octal c = a - b;
  ASSERT_EQ(c, "31");
}
TEST(raznost, CanDiffTwoNumbersDifferentLenghtSecondLong) {
  Octal a = "23";
  Octal b = "162";
  Octal c = a - b;
  ASSERT_EQ(c, "137");
}
TEST(sravnenie, CanSravnTwoPositiveNumbersRavni) {
  Octal a = "25";
  Octal b = "25";
  bool k=0;
  if (a == b) {
    k = 1;
  } 
  ASSERT_EQ(k, 1);
}
TEST(sravnenie, CanSravnTwoPositiveNumbersRavniPomenyalMestami) {
  Octal a = "25";
  Octal b = "25";
  bool k = 0;
  if (b == a) {
    k = 1;
  }
  ASSERT_EQ(k, 1);
}
TEST(sravnenie, CanSravnTwoPositiveNumbersNeRavni) {
  Octal a = "24";
  Octal b = "25";
  bool k = 0;
  if (a == b) {
     k = 1;
  }
  ASSERT_EQ(k, 0);
}
TEST(sravnenie, CanSravnTwoPositiveNumbersNeRavniPomenyalMestami) {
  Octal a = "24";
  Octal b = "25";
  bool k = 0;
  if (a == b) {
    k = 1;
  }
  ASSERT_EQ(k, 0);
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