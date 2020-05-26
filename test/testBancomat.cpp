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


