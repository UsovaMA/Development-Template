#include <gtest/gtest.h>
#include "FUN.h"

TEST(function, Check_three_word) {
  string a = "Варвара Николаевна Сеничева", a1=" Варвара Николаевна Сеничева";
  string b = "", b1="Варвара", b2="Ann Get Im";
  EXPECT_EQ(ver_three_word(a), 1);
  EXPECT_EQ(ver_three_word(a1), 1);
  EXPECT_EQ(ver_three_word(b2), 1);
  EXPECT_EQ(ver_three_word(b), 0);
  EXPECT_EQ(ver_three_word(b1), 0);
}

TEST(function, Check_one_word) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(a), 1);
  EXPECT_EQ(ver_one_word(a1), 1);
  EXPECT_EQ(ver_one_word(b2), 0);
  EXPECT_EQ(ver_one_word(b), 0);
  EXPECT_EQ(ver_one_word(b1), 1);
}

TEST(function, breakdown) {
  string a = "Варвара Николаевна Сеничева";
  EXPECT_EQ(breakdown1(a), "Варвара");
  EXPECT_EQ(breakdown2(a), "Николаевна");
  EXPECT_EQ(breakdown3(a), "Сеничева");
}