#include <gtest/gtest.h>
#include "DictionaryClassNew.h"

TEST(Words, ConstructorTestDefault) {
	ASSERT_NO_THROW(Words user);
}

TEST(Words, ConstructorTestDefaultCorrect) {
	Words word;
	Words word1("none", "none");
  EXPECT_EQ(word,word1);
}

TEST(Words, DestructorTest) {
	Words s1;
	s1.~Words();
	int n = 0;
	if (s1.getWord() == ""&&s1.getTranslate() == "") {
		n = 1;
	}
  EXPECT_EQ(n, 1);
}
TEST(Words, getFuncTest1) {
	Words s1("kid", "ребенок");
	EXPECT_EQ(s1.getWord(), "kid");
}
TEST(Words, getFuncTest2) {
	Words s1("kid", "ребенок");
	EXPECT_EQ(s1.getTranslate(), "ребенок");
}
TEST(Words, ConstructorTestCopy) {
	Words s1("kid", "ребенок");
	Words s2(s1);
	int n = 0;
	if (s2.getWord() == "kid"&&s2.getTranslate() == "ребенок") {
		n = 1;
	}
	EXPECT_EQ(n, 1);
}
TEST(Words, ConstructorTestInit) {
	Words s1("kid", "ребенок");
	int n = 0;
	if (s1.getWord() == "kid"&&s1.getTranslate() == "ребенок") {
		n = 1;
	}
	EXPECT_EQ(n, 1);
}
TEST(Dictionary, ConstructorTestDefault) {
	Dictionary book;
	EXPECT_EQ(book.getNumber(), 0);
}
TEST(Dictionary, ConstrucorTestsInit) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	EXPECT_EQ(book.getNumber(), 1);
}
TEST(Dictionary, ConstrucorTestsCopy) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	Dictionary book1(book);
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Dictionary, OperatorSameTest) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	Dictionary book1 = book;
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Dictionary, FindFuncTest) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	EXPECT_EQ(book.find_word("kid"), 1);
}
TEST(Dictionary, FindFuncTest2) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	EXPECT_EQ(book.find_translate("kid"), "ребенок");
}
TEST(Dictionary, FindFuncTest2) {
	Words s1("kid", "ребенок");
	Dictionary book(1, &s1);
	EXPECT_EQ(book.find_translate("kid"), "ребенок");
}
