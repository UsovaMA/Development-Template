#include <gtest/gtest.h>
#include "Class_Hex.hpp"

TEST(Class_Hex, in_out_file) {
	Hex res1("0", 1);
	Hex res2("2", 1);
	ofstream fout("C://Test.txt");
	fout << res2;
	fout.close();
	ifstream fin("C://Test.txt");
	fin >> res1;
	fin.close();
	EXPECT_EQ(res1, res2);
}

TEST(Class_Hex, operator_of_index_true) {
	Hex a("3B5", 3);
	char b = a[1];
	EXPECT_EQ('B', b);
}

TEST(Class_Hex, operator_of_index_false) {
	Hex a("3B5", 3);
	EXPECT_ANY_THROW(a[10]);
}

TEST(Class_Hex, operator_of_equality_true) {
	Hex a("B", 1);
	Hex b("B", 1);
	EXPECT_EQ(1, a == b);
}

TEST(Class_Hex, operator_of_equality_false) {
	Hex a("A", 1);
	Hex b("B", 1);
	EXPECT_EQ(0, a == b);
}


TEST(Class_Hex, operator_of_assignment) {
	Hex a("4", 1);
	Hex b("10", 2);
	a = b;
	EXPECT_EQ(a, b);
}

TEST(Class_Hex, operator_of_compare_less_true) {
	Hex a("4", 1);
	Hex b("10", 2);
	EXPECT_EQ(1, a < b);
}

TEST(Class_Hex, operator_of_compare_less_false) {
	Hex a("4", 1);
	Hex b("10", 2);
	EXPECT_EQ(0, b < a);
}

TEST(Class_Hex, operator_of_compare_larger_true) {
	Hex a("4", 1);
	Hex b("10", 2);
	EXPECT_EQ(1, b > a);
}

TEST(Class_Hex, operator_of_compare_larger_false) {
	Hex a("4", 1);
	Hex b("10", 2);
	EXPECT_EQ(0, a > b);
}

TEST(Class_Hex, operator_of_add) {
	Hex a("B", 1);
	Hex b("10", 2);
	Hex res1("1B", 2);
	Hex res2 = a + b;
	EXPECT_EQ(res1, res2);
}

TEST(Class_Hex, operator_of_sub) {
	Hex a("3B", 2);
	Hex b("10", 2);
	Hex res1("2B", 2);
	Hex res2 = a - b;
	EXPECT_EQ(res1, res2);
}

TEST(Class_Hex, operator_of_sub_less_than_zero) {
	Hex a("3B", 2);
	Hex b("10", 2);
	Hex res = b - a;
	EXPECT_EQ('0', res[0]);
}

TEST(Class_Hex, ConvertCC_16_to_10) {
	string a = ConvertCC("A", 16, 10);
	EXPECT_EQ("10", a);
}

TEST(Class_Hex, ConvertCC_10_to_16) {
	string a = ConvertCC("15", 10, 16);
	EXPECT_EQ("F", a);
}
