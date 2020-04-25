#include <gtest/gtest.h>
#include "Class_MediaPlayer.hpp"

TEST(MediaPlayer, test_operator) {
	string a, b, c, d, e, f;
	Song Test1("Test1", "a", "a", "a", "a", "a");
	Song Test2("Test1", "a", "a", "a", "a", "a");
	EXPECT_EQ(1, Test1 == Test2);
}

TEST(MediaPlayer, add_song) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "a";
	mass.add_new_song(a, b, c, d, e, f);
	Song Test2("Test1", "a", "a", "a", "a", "a");
	EXPECT_EQ(1, Test2 == mass.arr[0]);
}

TEST(MediaPlayer, index_of_Song_name) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "a";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(0, mass.index_of_Song_name("Test1"));
}

TEST(MediaPlayer, index_of_Song_name_and_singer) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "a";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(0, mass.index_of_Song_name_and_singer("Test1", "a"));
}

TEST(MediaPlayer, delete_song) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "a";
	mass.add_new_song(a, b, c, d, e, f);
	a = "Test2";
	b = "b";
	c = "b";
	d = "b";
	e = "b";
	f = "b";
	mass.add_new_song(a, b, c, d, e, f);
	mass.delete_song("Test1", 0);
	EXPECT_EQ(1, mass.size);
}