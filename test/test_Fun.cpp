#include <gtest/gtest.h>
#include "FUN.h"

TEST(function, Check_three_word1) {
  string a = "Варвара Николаевна Сеничева", a1=" Варвара Николаевна Сеничева";
  string b = "", b1="Варвара", b2="Ann Get Im";
  EXPECT_EQ(ver_three_word(a), 1);
}
TEST(function, Check_three_word2) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = "Ann Get Im";
  EXPECT_EQ(ver_three_word(a1), 1);
}
TEST(function, Check_three_word3) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = "Ann Get Im";
  EXPECT_EQ(ver_three_word(b2), 1);

}
TEST(function, Check_three_word4) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = "Ann Get Im";
  EXPECT_EQ(ver_three_word(b), 0);
}
TEST(function, Check_three_word5) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = "Ann Get Im";
  EXPECT_EQ(ver_three_word(b1), 0);
}

TEST(function, Check_one_word1) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(a), 1);
}
TEST(function, Check_one_word2) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(a1), 1);
}
TEST(function, Check_one_word3) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(b2), 0);
}
TEST(function, Check_one_word4) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(b), 0);
}
TEST(function, Check_one_word5) {
  string a = "Варвара Николаевна Сеничева", a1 = " Варвара Николаевна Сеничева";
  string b = "", b1 = "Варвара", b2 = " ";
  EXPECT_EQ(ver_one_word(b1), 1);
}

TEST(function, breakdown) {
  string a = "Сеничева Варвара Николаевна";
  EXPECT_EQ(breakdown1(a), "Сеничева");
  EXPECT_EQ(breakdown2(a), "Варвара");
  EXPECT_EQ(breakdown3(a), "Николаевна");
}

TEST(function, high_letter0) {
  char a = 'А', b = 'Я';
  int hb = high_letter(a, b);
  EXPECT_EQ(hb, 1);
}
TEST(function, high_letter1) {
  char a = 'а', b = 'я';
  int hb = high_letter(a, b);
  EXPECT_EQ(hb, 1);
}
TEST(function, high_letter2) {
  char a = 'а', b = 'я';
  int hb = high_letter(a, b);
  EXPECT_EQ(hb, 1);
}
TEST(function, high_letter3) {
  char a = 'Я', b = 'Я';
  int hb = high_letter(a, b);
  EXPECT_EQ(hb, 2);
}
TEST(function, high_letter4) {
  char a = 'Я', b = 'А';
  int hb = high_letter(a, b);
  EXPECT_EQ(hb, 0);
}

TEST(function, high_name1) {
  string A = "Александра", B = "Иван";
  int hb = high_name(A, B);
  EXPECT_EQ(hb, 1);
}
TEST(function, high_name2) {
  string A = "Александра", B = "Иван";
  int hb = high_name(B, A);
  EXPECT_EQ(hb, 0);
}
TEST(function, high_name3) {
  string A = "Александра", B = "Александра";
  int hb = high_name(B, A);
  EXPECT_EQ(hb, 2);
}
