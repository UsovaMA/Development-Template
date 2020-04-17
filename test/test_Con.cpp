#include <gtest/gtest.h>
#include "Contacts.h"
#include "FUN.h"


TEST(Cotacts, Construktors1) {
  Contact a("Маша", "Ивановна", "Шарова"), a1("Маша", "Ивановна", "Шарова", "0", 0);
  Contact s1, s2;
  Contact b("Маша Ивановна Шарова");
  EXPECT_EQ(a==a1, 1);
}
TEST(Cotacts, Construktors2) {
  Contact a("Маша", "Ивановна", "Шарова"), a1("Маша", "Ивановна", "Шарова", "0", 0);
  Contact s1, s2;
  Contact b("Маша Ивановна Шарова");
  EXPECT_EQ(s1 != s2, 0);
}
TEST(Cotacts, Construktors3) {
  Contact a("Маша", "Шарова", "Ивановна"), a1("Маша", "Шарова", "Ивановна", "0", 0);
  Contact s1, s2;
  Contact b("Шарова Маша Ивановна");
  EXPECT_EQ(a == b, 1);
}


TEST(Cotacts, getNAME) {
  Contact a("Маша", "Ивановна", "Шарова");
  string a1 = a.getNAME();
  EXPECT_EQ(a1, "Маша");
}
TEST(Cotacts, getFn) {
  Contact a("Маша", "Ивановна", "Шарова");
  string a2 = a.getFn();
  EXPECT_EQ(a2, "Ивановна");
}
TEST(Cotacts, getPA) {
  Contact a("Маша", "Ивановна", "Шарова");
  string a3 = a.getPA();
  EXPECT_EQ(a3, "Шарова");
}

TEST(Cotacts, imFn) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4="88005553535";
  Contact a;
  a.imFn(a2);
  EXPECT_EQ(a.getFn(), "Ивановна");
}
TEST(Cotacts, imNAME) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4 = "88005553535";
  Contact a;
  a.imNAME(a1);
  EXPECT_EQ(a.getNAME(), "Маша");
}
TEST(Cotacts, imPA) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4 = "88005553535";
  Contact a;
  a.imPA(a3);
  EXPECT_EQ(a.getPA(), "Шарова");
}
TEST(Cotacts, imPH) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4 = "88005553535";
  Contact a;
  a.imPH(a4);
  EXPECT_EQ(a.getPH(), "88005553535");
}
TEST(Cotacts, imFav) {
  string a1 = "Маша", a2 = "Ивановна", a3 = "Шарова", a4 = "88005553535";
  Contact a;
  a.imFav(1);
  EXPECT_EQ(a.getFA(), 1);
}

TEST(Cotacts, Alph) {
  Contact a("Шарова Маша Ивановна"), b("Анютина Клавдия Ивановна");
  EXPECT_EQ(b>a, 1);
}

//TEST(Cotacts, fun_swap) {
//  Contact a("Маша", "Ивановна", "Шарова");
//  Contact b("Яна Вячеславовна Алимова");
//  swap_con(a, b);
//  int i = 0;
//  //EXPECT_EQ(a, 1);
//}