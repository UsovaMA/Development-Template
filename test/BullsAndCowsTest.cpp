#include <gtest/gtest.h>
#include "BullsAndCows.h"
TEST(BullsCows, construct) {
  BullsCows a(1234);
  ASSERT_NO_THROW();
}
TEST(BullsCows, simmilar) {
  BullsCows a(1234);
  bool k;
  char playerinput[] = {'1','2','4'};
  k = a.SimillarNums(playerinput, 2);
  EXPECT_EQ(k, false);
}
TEST(BullsCows, simmilar1) {
  BullsCows a(43217);
  bool k;
  char playerinput[] = { '1','3','4' };
  k = a.SimillarNums(playerinput, 3);
  EXPECT_EQ(k,true);
}
TEST(BullsCows, newgame) {
  BullsCows a(567);
  bool k;
  char playerinput[] = { '7','5','6' };
  int num = 345;
  ASSERT_NO_THROW(a.Inttostr(num, playerinput, 3););
}
