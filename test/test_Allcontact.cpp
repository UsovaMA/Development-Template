#include <gtest/gtest.h>
#include "Allcontact.h"
using namespace std;

TEST(AllCotact, Construktors) {
  Contact *a = new Contact[1];
  Contact a1("Маша", "Ивановна", "Шарова");
  a[0] = a1;
  AllContact A, A1(a, 1);
  A.DopСon(a1);
  int s = A.getSize();
  EXPECT_EQ(s, 1);
  EXPECT_EQ(A, A1);
}

TEST(AllCotact, Im_Get_favorite) {
  Contact *a = new Contact[1];
  Contact a1("Маша", "Ивановна", "Шарова");
  AllContact A;
  A.DopСon(a1);
  A.imFav(0, 1);
  bool d = A.getFav( 0 );
  EXPECT_EQ(d, 1 );
}

TEST(AllCotact, Del_element) {
  Contact *a = new Contact[1];
  Contact a1("Маша", "Ивановна", "Шарова");
  AllContact A, A1;
  A.DopСon(a1);
  A.DelСon(0);
  int s = A.getSize();
  EXPECT_EQ(s, 0);
  EXPECT_EQ(A, A1);
}