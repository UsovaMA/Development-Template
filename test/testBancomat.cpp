#include <gtest/gtest.h>
#include"Bancomat.h"
#include"ProcCenter.h"
TEST(Bancomat, checkingForConstr) {
  ASSERT_NO_THROW(Sup a1("name", "mid", "last", 1234, 1000,1234, 0,0));
}
TEST(Bancomat, FindCard) {
  Sup a("name", "mid", "last", 1234, 1000, 1234, 0, 0);
  Sup b("name2", "mid2", "last2", 4321, 2000000, 1111, 0, 0);
  ProcCenter c1;
  c1.AddPers(b);
  Bancomat t;
  int c;
  int d = 0;
  c = t.FindCardMain(c1);
  EXPECT_EQ(c, -1);
}

TEST(Bancomat, TakeMoneyOK) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  int n;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckTakeForTest(c1,500);
  n = t.TakeMoneyMain(c1);
  EXPECT_EQ(n,0);
}
TEST(Bancomat, TakeMoneySoMuch) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckTakeForTest(c1, 200000);
  EXPECT_EQ(t.TakeMoneyMain(c1), 8);
}
TEST(Bancomat, putmoneyOk ) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckPutMoneyForTest(c1, 20000);
  EXPECT_EQ(t.PutMoneyMain(c1), 0);
}
TEST(Bancomat, putmoneySoMuch) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckPutMoneyForTest(c1, 200000000);
  EXPECT_EQ(t.PutMoneyMain(c1), 6);
}
TEST(Bancomat, NeKratno100Take) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  int n;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckTakeForTest(c1, 5030);
  n = t.TakeMoneyMain(c1);
  EXPECT_EQ(n, 100);
}
TEST(Bancomat, NeKratno100Put) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckPutMoneyForTest(c1, 20020);
  EXPECT_EQ(t.PutMoneyMain(c1), 100);
}
TEST(Bancomat, NotCardBalance) {
  Sup a("name", "mid", "last", 1234, 10000, 1234, 0, 0);
  ProcCenter c1;
  Bancomat t;
  int n;
  c1.AddPers(a);
  t.nexttest(c1);
  t.CheckTakeForTest(c1, 20030);
  n = t.TakeMoneyMain(c1);
  EXPECT_EQ(n, 8);
}

/*
TEST(Bancomat, NeKratno100) {
  Sup a("name", "mid", "last", 12345, 10000, 1234, 0, 0);
  ProcCenter c1(a);
  Bancomat t;
  c1.AddPers(a);
  int b;
  //de.qwertyuiop(cl);
  t.CheckPutMoneyForTest(c1, 520);
  b = t.TakeMoneyMain(c1);
  EXPECT_EQ(100, b);
}*/
/*
TEST(Bancai_2_2, Proverka_snatia_deneg_kogda_karta_blokted) {
  Dop c("misha", "alim", "ser", "0001", 6000, 0000, true, 3);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(5000);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(9, b);
}
TEST(Bancai_2_2, Proverka_snatia_deneg__kogda_na_schete_nedostatochno_sredstv) {
  Dop c("misha", "alim", "ser", "0001", 5000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(10000);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(8, b);
}
TEST(Bancai_2_2, Proverka_snatia_deneg__kogda_na_odin_vid_cupur_zaconcilsa) {
  Dop c("misha", "alim", "ser", "0001", 5000000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(405000);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(1, b);
}
TEST(Bancai_2_2, Proverka_snatia_deneg_kogda_v_bancomate_conchikis_vse_dengi) {
  Dop c("misha", "alim", "ser", "0001", 3000000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(1000000);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(6, b);
}
TEST(Bancai_2_3, Proverka_vvod_deneg_1) {
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.CHECK_FOR_VVODA_DENEG(100);
  b = de.Vzat_dengi_prog(cl);
  EXPECT_EQ(0, b);
}
TEST(Bancai_2_3, Proverka_vvod_deneg_2) {
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.CHECK_FOR_VVODA_DENEG(105000);
  b = de.Vzat_dengi_prog(cl);
  EXPECT_EQ(1, b);
}
TEST(Bancai_2_3, Proverka_vvod_deneg_3) {
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.CHECK_FOR_VVODA_DENEG(100000000);
  b = de.Vzat_dengi_prog(cl);
  EXPECT_EQ(6, b);
}
TEST(Bancai_2_3, Proverka_vvod_deneg_kogda_carta_zablok) {
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, true, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.CHECK_FOR_VVODA_DENEG(100000000);
  b = de.Vzat_dengi_prog(cl);
  EXPECT_EQ(9, b);
}
TEST(Bancai_2_3, Proverka_vvod_deneg_chislo_nelza_snat_tak_kak_ne_kratno) {
  Dop c("misha", "alim", "ser", "0001", 3000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.CHECK_FOR_VVODA_DENEG(1001);
  b = de.Vzat_dengi_prog(cl);
  EXPECT_EQ(10, b);
}*/




