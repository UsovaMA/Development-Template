#include <gtest/gtest.h>
#include "Funck.h"

TEST(Funck, one_chislo) {
  unsigned char a = 'B';
  int chislo = one_chislo(a);
  EXPECT_EQ(chislo, 11);
}

TEST(Funck, one_chislo2) {
  unsigned char a = '2';
  int chislo = one_chislo(a);
  EXPECT_EQ(chislo, 2);
}
//string_int


TEST(Funck, six_ten) {
  string a = "10A";
  int chislo = six_ten(a);
  EXPECT_EQ(chislo, 266);
}

TEST(Funck, six_ten1) {
  string a = "0";
  int chislo = six_ten(a);
  EXPECT_EQ(chislo, 0);
}

TEST(Funck, six_ten2) {
  string a = "ABC1";
  int chislo = six_ten(a);
  EXPECT_EQ(chislo, 43969);
}

TEST(Funck, six_ten3) {
  string a = "-ABC1";
  int chislo = six_ten(a);
  EXPECT_EQ(chislo, -43969);
}

TEST(Funck, ten_six1) {
  int a = 1200;
  EXPECT_EQ(ten_six(1200), "4B0");
}
TEST(Funck, ten_six2) {
  int a = 0;
  EXPECT_EQ(ten_six(0), "0");
}
TEST(Funck, ten_six3) {
  EXPECT_EQ(ten_six(1201), "4B1");
}
TEST(Funck, ten_six4) {
  EXPECT_EQ(ten_six(191), "BF");
}


