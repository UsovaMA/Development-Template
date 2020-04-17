#include <gtest/gtest.h>
#include "Contacts.h"


TEST(Cotacts, Construktors) {
  Contact a("Маша", "Ивановна", "Шарова"), a1("Маша", "Ивановна", "Шарова", "0", 0);
  Contact s1, s2;
  Contact b("Маша Ивановна Шарова");
  EXPECT_EQ(a==a1, 1);
  EXPECT_EQ(s1 != s2, 0);
  EXPECT_EQ(a == b, 1);
}

TEST(Cotacts, All_GET) {
  Contact a("Маша", "Ивановна", "Шарова");
  string a1 = a.getNAME(), a2 = a.getFn(), a3 = a.getPA();
  EXPECT_EQ(a1, "Маша");
  EXPECT_EQ(a2, "Ивановна");
  EXPECT_EQ(a3, "Шарова");
}

TEST(Cotacts, All_IM) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4="88005553535";
  Contact a;
  a.imFn(a2);
  a.imNAME(a1);
  a.imPA(a3);
  a.imPH(a4);
  a.imFav(1);
  EXPECT_EQ(a.getNAME(), "Маша");
  EXPECT_EQ(a.getFn(), "Ивановна");
  EXPECT_EQ(a.getPA(), "Шарова");
  EXPECT_EQ(a.getPH(), "88005553535");
  EXPECT_EQ(a.getFA(), 1);
}