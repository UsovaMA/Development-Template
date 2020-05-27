#include <gtest/gtest.h>
#include "octal.h"

TEST(TestClassHex, Assignment) {
  Octal res("F7A", 3);
  Octal a("F7A", 3);
  Octal b;
  b = a;
  EXPECT_EQ(b, res);
}

TEST(TestClassHex, AddTwoNumbers) {
  Octal res("0", 4);
  Octal resExpct("14E9", 4);
  Octal a("F7A", 3);
  Octal b("56F", 3);
  res = a + b;
  EXPECT_EQ(res, resExpct);
}

TEST(TestClassHex, SubTwoNumbers) {
  Octal res("0", 3);
  Octal resExpct("D21", 3);
  Octal a("E2A", 3);
  Octal b("109", 3);
  res = a - b;
  EXPECT_EQ(res, resExpct);
}

TEST(TestClassHex, AreTwoNumbersNotEqualSameSize) {
  Octal a("108", 3);
  Octal b("109", 3);
  EXPECT_FALSE(a == b);
}

TEST(TestClassHex, AreTwoNumbersNotEqualDiferentSize_frstNumBigger) {
  Octal a("100109", 7);
  Octal b("109", 4);
  EXPECT_FALSE(a == b);
}
TEST(TestClassHex, AreTwoNumbersNotEqualDiferentSize_scndNumBigger) {
  Octal a("102", 3);
  Octal b("200102", 7);
  EXPECT_FALSE(a == b);
}

TEST(TestClassHex, AreTwoNumbersEqual) {
  Octal a("109", 3);
  Octal b("109", 3);
  EXPECT_TRUE(a == b);
}

TEST(TestClassHex, CompareWhatIsBiggerSameSize) {
  Octal a("1A9", 3);
  Octal b("109", 3);
  EXPECT_TRUE(a > b);
  EXPECT_FALSE(b > a);
}

TEST(TestClassHex, CompareWhatIsBigger_frstNumBigger) {
  Octal a("100A9", 6);
  Octal b("109", 3);
  EXPECT_TRUE(a > b);
  EXPECT_FALSE(b > a);
}

TEST(TestClassHex, CompareWhatIsBigger_scndNumBigger) {
  Octal a("1A9", 3);
  Octal b("200109", 7);
  EXPECT_TRUE(a > b);
  EXPECT_FALSE(b > a);
}

TEST(TestClassHex, CompareWhatIsLowwerSameSize) {
  Octal a("1A9", 3);
  Octal b("109", 3);
  EXPECT_TRUE(b < a);
 EXPECT_FALSE(a < b);
}

TEST(TestClassHex, CompareWhatIsLowwer_frstNumBigger) {
  Octal a("100A9", 6);
  Octal b("109", 3);
  EXPECT_TRUE(b < a);
  EXPECT_FALSE(a < b);
}

TEST(TestClassHex, CompareWhatIsLowwer_scndNumBigger) {
  Octal a("200109", 7);
  Octal b("1A9", 3);
  EXPECT_TRUE(b < a);
  EXPECT_FALSE(a < b);
}

TEST(TestClassHex, GetOneNumber) {
  char res;
  char resExpct = '0';
  Octal a("109", 3);
  res = a[1];
  ASSERT_NO_THROW(a[1]);
  EXPECT_EQ(res, resExpct);
}

TEST(TestClassHex, TryGoOutOfRange) {
  char res = '9';
  char resExpct = '9';
  Octal a("109", 3);
  EXPECT_ANY_THROW(a[5]);
}

TEST(TestClassHex, TryGetNegetiveIndex) {
  char res = '9';
  char resExpct = '9';
  Octal a("109", 3);
  EXPECT_ANY_THROW(a[-3]);
}

TEST(TestClassHex, ReadAndWriteTxt) {
  Octal res ("0", 5);
  Octal resExpct("82AF1", 5);
  ofstream fout("output.txt");
  fout << resExpct;
  fout.close();
  ifstream fin("output.txt");
  fin >> res;
  fin.close();
  EXPECT_EQ(res, resExpct);
}
