// Copyright 2020 <Diana Lukashuk>
#include <gtest/gtest.h>
#include "Hex.h"

TEST(Hex, Constr) {
  Hex h("152");
  EXPECT_EQ(h.get_zn(), 1);
  EXPECT_EQ(h.get_i_h(), 338);
  EXPECT_EQ(h.get_s_h(), 3);
  EXPECT_EQ(h.get_c_h(0), '1');
  EXPECT_EQ(h.get_c_h(1), '5');
  EXPECT_EQ(h.get_c_h(2), '2');
}
TEST(Hex, comparison1) {
    Hex a("A10"), b("B22");
    EXPECT_EQ((a > b), 0);
  }

TEST(Hex, comparison11) {
  Hex a("A10"), b("B22");
  EXPECT_EQ((a >= b), 0);
}
TEST(Hex, comparison2) {
  Hex a("A10"), b("B22");
  EXPECT_EQ((a <= b), 1);
}

TEST(Hex, comparison3) {
  Hex a("A10"), b("B22");
  EXPECT_EQ((a != b), 1);
}

TEST(Hex, comparison4) {
  Hex a("A10"), b("B22");
  EXPECT_EQ((a == b), 0);
}

TEST(Hex, Pplus_plus) {
  Hex a("A10"), b("B22"); //1532 и 5426
  Hex res;
  res = a + b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 5426);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '5');
  EXPECT_EQ(res.get_c_h(2), '3');
  EXPECT_EQ(res.get_c_h(3), '2');
}
TEST(Hex, Pplus_plus_ziro) {
  Hex a("0"), b("0"); 
  Hex res;
  res = a + b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 0);
  EXPECT_EQ(res.get_c_h(0), '0');
}

TEST(Hex, Pminusminus) {
  Hex a("-A10"), b("-B22"); //меняется только знак, значения те-же
  Hex res;
  res = a + b;
  EXPECT_EQ(res.get_zn(), 0);
  EXPECT_EQ(res.get_i_h(), 5426);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '5');
  EXPECT_EQ(res.get_c_h(2), '3');
  EXPECT_EQ(res.get_c_h(3), '2');
}

TEST(Hex, Pplus_minus) {
  Hex a("A10"), b("-B22"); 
  Hex res;
  res = a + b;
  EXPECT_EQ(res.get_zn(), 0);
  EXPECT_EQ(res.get_i_h(), 274);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '1');
  EXPECT_EQ(res.get_c_h(2), '2');
}

TEST(Hex, Pplus_minus1) {
  Hex a("-A10"), b("B22");
  Hex res;
  res = a + b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 274);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '1');
  EXPECT_EQ(res.get_c_h(2), '2');
}

TEST(Hex, Mplus_plus1) {
  Hex a("A10"), b("B22");
  Hex res;
  res = a - b;
  EXPECT_EQ(res.get_zn(), 0);
  EXPECT_EQ(res.get_i_h(), 274);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '1');
  EXPECT_EQ(res.get_c_h(2), '2');
}

TEST(Hex, M_ziro) {
  Hex a("0"), b("0");
  Hex res;
  res = a - b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 0);
  EXPECT_EQ(res.get_c_h(0), '0');
}

TEST(Hex, M_plus_ziro) {
  Hex a("A10"), b("0");
  Hex res;
  res = a - b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 2576);
  EXPECT_EQ(res.get_c_h(0), 'A');
  EXPECT_EQ(res.get_c_h(1), '1');
  EXPECT_EQ(res.get_c_h(2), '0');
}

TEST(Hex, Mplus_minus) {
  Hex a("-A10"), b("-B22");
  Hex res;
  res = a - b;
  EXPECT_EQ(res.get_zn(), 1);
  EXPECT_EQ(res.get_i_h(), 274);
  EXPECT_EQ(res.get_c_h(0), '1');
  EXPECT_EQ(res.get_c_h(1), '1');
  EXPECT_EQ(res.get_c_h(2), '2');
}