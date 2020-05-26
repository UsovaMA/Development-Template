#include <gtest/gtest.h>
#include"roga_i_copita.h"
TEST(Construct, when_correct) {

  ASSERT_NO_THROW(roga_i_copita a(4567););
}
TEST(Construct, when_un_correct) {
  ASSERT_NO_THROW(roga_i_copita a(-4567););
}
TEST(roga_i_copita_1, when__correct) {
  roga_i_copita a(6872); 
  bool k;
  char ours[] = { '8','2','7' };
  k = a.SameDigits(ours, 3);
  EXPECT_EQ(k, false);
}
TEST(roga_i_copita_2, canFindMinByData) {
  roga_i_copita a(6872);
  bool k;
  char ours[] = { '8','8','6' };
  k = a.SameDigits(ours, 3);
  EXPECT_EQ(k,true);
}

