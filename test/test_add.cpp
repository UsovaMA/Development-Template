#include <gtest/gtest.h>
#include"Bancai.h"
#include"ProcCenter.h"
TEST(Bancai, checkingForCorrectness) {
  ASSERT_NO_THROW(Dop s1("Misha", "Alim", "Serg", "0001", 500,0001, 0,0););
}
TEST(Bancai_1, whenTheMoneyIsSetIncorrectly) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "0001", -500, 0001, 0, 0);
  );
}
TEST(Bancai_2, whenNomerCardIsSetIncorrectly) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "001", 500, 0001, 0, 0);
  );
}
TEST(Bancai_2, whenNomerCardIsSetIncorrectly_2) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "00100", 500, 0001, 0, 0);
  );
}