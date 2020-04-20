// Copyright 2020 Podovinnikov
#include <gtest/gtest.h>
#include "Song.h"
TEST(TestClassSong, constrinit1) {
   Song c1 ("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  Song c2 ("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");

  EXPECT_EQ(c1, c2);
}

TEST(TestClassSong, numofsongs) {
  Playlist lib;
  Playlist lib2;
  lib.append(Song("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES"));
  lib2.append(Song("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES"));
  lib.remove(Song("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES"));
  lib2.remove(Song("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES"));
  lib.numoOfsongs();
  lib2.numoOfsongs();

  EXPECT_EQ(lib.numoOfsongs(), lib2.numoOfsongs());
}
TEST(TestClassSong, getauthor) {
  Song c1("20.12.1752", "EMINEM", " LOSE YOURSELF", "Поэт", "Композитор", "Альбом");
  Song c2("20.12.1752", "EMINEM", " LOSE YOURSELF", "Поэт", "Композитор", "Альбом");
  EXPECT_EQ(c1.getAuthor(), c2.getAuthor());

}
TEST(TestClassSong, gettitle) {
  Song c1("20.12.2000", "MICHAEL JACKSON", "BILLIE JEAN", "Поэт", "Композитор", "Альбом");
  Song c2("20.12.2000", "MICHAEL JACKSON", "BILLIE JEAN", "Поэт", "Композитор", "Альбом");
  EXPECT_EQ(c1.getTitle(), c2.getTitle());

}
TEST(TestClassSong, getpoet) {
  Song c1("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  Song c2("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  EXPECT_EQ(c1.getPoet(), c2.getPoet());

}
TEST(TestClassSong, getcomposer) {
  Song c1("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  Song c2("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  EXPECT_EQ(c1.getComposer(), c2.getComposer());

}
TEST(TestClassSong, getdate) {
  Song c1("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  Song c2("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  EXPECT_EQ(c1.getDate(), c2.getDate());

}
TEST(TestClassSong, getalbum) {
  Song c1("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  Song c2("20.12.1500", "THE CRANBERRIES", "ZOMBIE", "Поэт ZOMBIE", "Композитор ZOMBIE", "Альбом THE CRANBERRIES");
  EXPECT_EQ(c1.getAlbum(), c2.getAlbum());
  system("pause");
}




