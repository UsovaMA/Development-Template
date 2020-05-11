#include <gtest/gtest.h>
#include "Room.h"
#include "Format_room.h"
#include "place.h"
#include "Cinema.h"
#include "Calendar.h"

TEST(All, Cinema_plus_Room) {
  Room a;
  Cinema c;
  c.plus_Room(a);
  EXPECT_EQ(a, c.get_Room(0));
}

TEST(All, Cinema_plus_Room_get_s_r) {
  Room a;
  Cinema c;
  c.plus_Room(a);
  EXPECT_EQ(1, c.get_s_r());
}
TEST(All, Cinema_get_s_r) {
  Cinema c;
  EXPECT_EQ(0, c.get_s_r());
}

TEST(All, Cinema_Plus_FSC) {
  Film_show a;
  Cinema c;
  c.Plus_FSC(a);
  EXPECT_EQ(1, c.get_k_fs());
}