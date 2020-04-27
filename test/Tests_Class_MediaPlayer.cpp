#include <gtest/gtest.h>
#include "Class_MediaPlayer.hpp"

TEST(MediaPlayer, test_operator_true) {
	string a, b, c, d, e, f;
	Song Test1("Test1", "a", "a", "a", "a", "1");
	Song Test2("Test1", "a", "a", "a", "a", "1");
	EXPECT_EQ(1, Test1 == Test2);
}

TEST(MediaPlayer, test_operator_false) {
	string a, b, c, d, e, f;
	Song Test1("Test1", "a", "b", "a", "a", "1");
	Song Test2("Test1", "a", "a", "a", "a", "1");
	EXPECT_EQ(0, Test1 == Test2);
}

TEST(MediaPlayer, add_song) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	Song Test2("Test1", "a", "a", "a", "a", "1");
	EXPECT_EQ(1, Test2 == mass.arr[0]);
}

TEST(MediaPlayer, index_of_Song_name_true) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(0, mass.index_of_Song_name("Test1"));
}

TEST(MediaPlayer, index_of_Song_name_false) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(-1, mass.index_of_Song_name("Test2"));
}

TEST(MediaPlayer, index_of_Song_name_and_singer_true) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(0, mass.index_of_Song_name_and_singer("Test1", "a"));
}

TEST(MediaPlayer, index_of_Song_name_and_singer_false) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	EXPECT_EQ(-1, mass.index_of_Song_name_and_singer("Test1", "b"));
}

TEST(MediaPlayer, delete_song_true) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	a = "Test2";
	b = "b";
	c = "b";
	d = "b";
	e = "b";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	mass.delete_song(0);
	EXPECT_EQ(1, mass.size);
}

TEST(MediaPlayer, delete_song_false) {
	MediaPlayer mass;
	string a, b, c, d, e, f;
	int index;
	a = "Test1";
	b = "a";
	c = "a";
	d = "a";
	e = "a";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	a = "Test2";
	b = "b";
	c = "b";
	d = "b";
	e = "b";
	f = "1";
	mass.add_new_song(a, b, c, d, e, f);
	index = mass.index_of_Song_name("Test3");
	if (index != -1) mass.delete_song(index);
	EXPECT_EQ(2, mass.size);
}

TEST(MediaPlayer, Throw1) {
	EXPECT_ANY_THROW(Song a("asd", "asd", "asd", "sdf", "sdf", "sdf"));
}

TEST(MediaPlayer, Thro2) {
	EXPECT_ANY_THROW(Song a("asd", "asd", "asd", "sdf", "sdf", "20:21:f"));
}

TEST(MediaPlayer, Throw3) {
	MediaPlayer mass;
	EXPECT_ANY_THROW(mass.add_new_song("asd", "asd", "asd", "sdf", "sdf", "dsff"));
}
