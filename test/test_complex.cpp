#include <gtest/gtest.h>
#include "complex.h"

TEST(TestClassComplex, ConstructorDefaultRight) {
  Complex c1;
  Complex c2(0, 0);
  EXPECT_EQ(c1, c2);
}

TEST(TestClassComplex, ConstructorCopyRight) {
	Complex c2(3, 2);
	Complex c1(c2);
	EXPECT_EQ(c1, c2);
}

TEST(TestClassComplex, ConstructorPrivedenTypeRight) {
	Complex c2(3, 0);
	Complex c1(3);
	EXPECT_EQ(c1, c2);
}

TEST(TestClassComplex, CanPrisvoit) {
	Complex c2(3, 3);
	Complex c1;
	ASSERT_NO_THROW(c1 = c2);
}

TEST(TestClassComplex, CanRightPrisvoit) {
	Complex c2(3, 3);
	Complex c1 = c2;
	EXPECT_EQ(c1, c2);
}

TEST(TestClassComplex, CanSravn) {
	Complex c2(3, 3);
	Complex c1(3, 7);
	ASSERT_NO_THROW(c1 == c2);
}

TEST(TestClassComplex, CanRightSravn1) {
	Complex c2(3, 3);
	Complex c1 = c2;
	EXPECT_EQ(true, c1 == c2);
}

TEST(TestClassComplex, CanRightSravn2) {
	Complex c2(3, 3);
	Complex c1(3, 4);
	EXPECT_EQ(false, c1 == c2);
}

TEST(TestClassComplex, CanDiv) {
	Complex c2(3, 3);
	Complex c1(3, 7);
	ASSERT_NO_THROW(c1 / c2);
}

TEST(TestClassComplex, CantDivByZero) {
	Complex c2(0, 0);
	Complex c1(3, 7);
	ASSERT_ANY_THROW(c1 / c2);
}

TEST(TestClassComplex, CanPrint) {
	Complex c1(3, 7);
	ASSERT_NO_THROW();
}

TEST(TestClassComplex, CanSubTwoPositiveNumbers) {
  Complex c1(5, 5), c2(5, 5);
  Complex res = c1 - c2;
  Complex trueRes(0, 0);
  EXPECT_EQ(res, trueRes);
}
