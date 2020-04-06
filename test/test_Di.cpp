#include <gtest/gtest.h>
#include "dict.h"
#include "ALLDict.h"

TEST(ALLDict, Comparison) {
  Dict a("Lola", "Ëמכא"), b("Lola", "Ëמכא");
  ALLDict A, B;
  A.DopSTR(a);
  B.DopSTR(b);
  EXPECT_EQ(A == B, 1);
}

TEST(ALLDict, Can_it_stack_multiple_dictionaries) {
  Dict a("Lol", "Ëמכ"), b("Lola", "Ëמכא");
  ALLDict A(a), C(a, b);
  A.DopSTR(b);
  EXPECT_EQ(A, C);
}

TEST(ALLDict, change_translation) {
  Dict a("world", "לטנ"), b("Rome", "Ðטל");
  ALLDict C(a, b);
  C.ChTran("לטנ", "universe");
  EXPECT_EQ(C.Poisk("universe"), 1);
}

TEST(ALLDict, Poisk) {
  Dict a("world", "לטנ"), b("Rome", "Ðטל");
  ALLDict C(a, b);
  EXPECT_EQ(C.Poisk("לטנ"), 1);
  EXPECT_EQ(C.Poisk("Rome"), 1);
}

TEST(ALLDict, translation) {
  Dict a("world", "לטנ"), b("Rome", "Ðטל");
  ALLDict C(a, b);
  EXPECT_EQ(C.Tran("לטנ"), "world");
  EXPECT_EQ(C.Tran("Rome"), "Ðטל");
}

TEST(ALLDict, Translation_Change) {
  Dict a("world", "לטנ"), b("Rome", "Ðטל");
  ALLDict C(a, b);
  C.ChTran("לטנ", "World");
  EXPECT_EQ(C.Poisk("World"), 1);
  EXPECT_EQ(C.Poisk("world"), 0);
}

TEST(ALLDict, getW_getT) {
  Dict a("world", "לטנ");
  string m = a.getW(), c = a.getT();
  EXPECT_EQ(m== "לטנ", 1);
  EXPECT_EQ(c== "world", 1);
}

TEST(ALLDict, ImW_ImT) {
  Dict a("hey", "ץוי");
  string m = "world", c = "לטנ";
  a.ImW(c);
  a.ImT(m);
  EXPECT_EQ(a.getW() == "לטנ", 1);
  EXPECT_EQ(a.getT() == "world", 1);
}

  // a.OB(str);

TEST(ALLDict, Dict_OB) {
  Dict a("hey", "ץוי"), b;
  string m = "hey ץוי";
  b.OB(m);
  EXPECT_EQ(b.getW() == "ץוי", 1);
  EXPECT_EQ(b.getT() == "hey", 1);
}

TEST(ALLDict, Alldict_sum) {
  Dict a("world", "לטנ"), b("Rome", "Ðטל");
  ALLDict C(a, b), A(a), B(b), P;
  P = A + B;
  EXPECT_EQ(P, C);
}

TEST(ALLDict, dict_correct) {
  Dict a("  world  ", "-  לטנ ");
  a.correct();
  Dict b("world", "לטנ");
  ALLDict A(a), B(b);
  EXPECT_EQ(A == B, 1);
}

TEST(ALLDict, get_Size) {
  Dict a("world", "לטנ");
  Dict b("world", "לטנ");
  ALLDict A(a, b), B(b);
  EXPECT_EQ(A.getS(), 2);
  EXPECT_EQ(B.getS(), 1);
}
