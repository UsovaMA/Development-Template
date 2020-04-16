#include <gtest/gtest.h>
#include "Allcontact.h"
using namespace std;

TEST(AllCotact, Construktors) {
  Contact a("Маша", "Ивановна", "Шарова");
  AllContact A; /*A1(a, 1);*/
  A.DopСon(a);
  /*int s = A.getSize();
  EXPECT_EQ(s, 1);
  EXPECT_EQ(A, A1);*/
}