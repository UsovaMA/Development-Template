#include <gtest/gtest.h>
#include "dict.h"
#include "ALLDict.h"

TEST(ALLDict, Comparison) {
  Dict a("Lola", "Ћола"), b("Lola", "Ћола");
  ALLDict A, B;
  A.DopSTR(a);
  B.DopSTR(b);
  EXPECT_EQ(A == B, 1);
}

TEST(ALLDict, Can_it_stack_multiple_dictionaries) {
  Dict a("Lol", "Ћол"), b("Lola", "Ћола");
  ALLDict A, B, C(a, b);
  A.DopSTR(a);
  B.DopSTR(b);
  EXPECT_EQ(A + B, C);
}

TEST(ALLDict, change_translation) {
  Dict a("world", "мир"), b("Rome", "–им");
  ALLDict C(a, b);
  C.ChTran("мир", "universe");
  EXPECT_EQ(C.Poisk("universe"), 1);
}

TEST(ALLDict, Poisk) {
  Dict a("world", "мир"), b("Rome", "–им");
  ALLDict C(a, b);
  EXPECT_EQ(C.Poisk("мир"), 1);
  EXPECT_EQ(C.Poisk("Rome"), 1);
}

TEST(ALLDict, translation) {
  Dict a("world", "мир"), b("Rome", "–им");
  ALLDict C(a, b);
  EXPECT_EQ(C.Tran("мир"), "world");
  EXPECT_EQ(C.Tran("Rome"), "–им");
}

TEST(ALLDict, Translation_Change) {
  Dict a("world", "мир"), b("Rome", "–им");
  ALLDict C(a, b);
  C.ChTran("мир", "World");
  EXPECT_EQ(C.Poisk("World"), 1);
  EXPECT_EQ(C.Poisk("world"), 0);
}