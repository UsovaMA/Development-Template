#include <gtest/gtest.h>
#include "Class_Dictionary.hpp"

TEST(Word_test, eng_get) {
	Word a("Test", "义耱");
	EXPECT_EQ("Test", a.get_eng_word());
}

TEST(Word_test, rus_get) {
	Word a("Test", "义耱");
	EXPECT_EQ("义耱", a.get_rus_word());
}

TEST(Word_test, eng_set) {
	Word a("", "义耱");
	a.set_eng_word("Test");
	EXPECT_EQ("Test", a.get_eng_word());
}

TEST(Word_test, rus_set) {
	Word a("Test", "");
	a.set_rus_word("义耱");
	EXPECT_EQ("义耱", a.get_rus_word());
}

TEST(Word_test, equality) {
	Word a("Test", "义耱");
	Word b("Test", "义耱");
	EXPECT_EQ(1, a == b);
}

TEST(Dictionary_test, add_word_and_index_true) {
	Dictionary mass;
	mass.add_word("Test","义耱");
	Word a("Test", "义耱");
	EXPECT_EQ(mass.arr[0], a);
}

TEST(Dictionary_test, index_false) {
	Dictionary mass;
	mass.add_word("Test", "义耱");
	EXPECT_ANY_THROW(mass[1]);
}

TEST(Dictionary_test, change_translation) {
	Dictionary mass;
	mass.add_word("Test", "义耱");
	mass.change_translation(0, "义耱2");
	Word a("Test", "义耱2");
	EXPECT_EQ(mass.arr[0], a);
}

TEST(Dictionary_test, file) {
	Dictionary mass1;
	Dictionary mass2;
	mass2.add_word("Test", "义耱");
	mass2.set_data_to_file("C://Data.txt");
	Word res("Test", "义耱");
	mass1.get_data_from_file("C://Data.txt");
	Word a("Test", "义耱");
	EXPECT_EQ(mass1.arr[0], res);
}

TEST(Dictionary_test, operator_equality) {
	Dictionary mass1;
	Dictionary mass2;
	mass1.add_word("Test", "义耱");
	mass2 = mass1;
	EXPECT_EQ(mass1[0], mass2[0]);
}

TEST(Dictionary_test, operator_add) {
	Dictionary mass1;
	Dictionary mass2;
	mass1.add_word("Test", "义耱");
	mass2.add_word("Test1", "义耱1");
	mass1 + mass2;
	Word res("Test1", "义耱1");
	EXPECT_EQ(res, mass1[1]);
}
