#include <gtest/gtest.h>
#include"Bancai.h"
#include"ProcCenter.h"
TEST(Bancai, checkingForCorrectness) {
  ASSERT_NO_THROW(Dop s1("Misha", "Alim", "Serg", "0001", 500,0001, 0,0););
}
TEST(Bancai_1, whenTheMoneyIsSetIncorrectly) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "0001", -500, 0001, 0, 0);
  );
}
TEST(Bancai_2, whenNomerCardIsSetIncorrectly) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "001", 500, 0001, 0, 0);
  );
}
TEST(Bancai_2, whenNomerCardIsSetIncorrectly_2) {
  ASSERT_ANY_THROW(Dop s1("Misha", "Alim", "Serg", "00100", 500, 0001, 0, 0);
  );
}
TEST(Bancai_2_1, Proverka_nahogdtnia_carti) {
  Dop c("misha", "alim", "ser", "0001", 3000000, 0000, 0, 0);
  Dop g("123", "123", "1234", "0002", 3000000, 0002, 0, 0);
  
  ProcCenter cl(c);
  cl.AddPers(g);
  Bancai de;
  int b;
  int d = 0;
  de.VVod_NOMERA_FOR_TEST("0001");
  b = de.Finde_card_prog(cl);
  EXPECT_EQ(d, b);
}
TEST(Bancai_2_1, Proverka_nahogdtnia_carti_2) {
  Dop c("misha", "alim", "ser", "0001", 3000000, 0000, 0, 0);
  Dop g("123", "123", "1234", "0002", 3000000, 0002, 0, 0);

  ProcCenter cl(c);
  cl.AddPers(g);
  Bancai de;
  int b;
  int d = 1;
  de.VVod_NOMERA_FOR_TEST("0002");
  b = de.Finde_card_prog(cl);
  EXPECT_EQ(d, b);
}
TEST(Bancai_2_2, Proverka_snatia_deneg_kogda_vse_ok) {
  Dop c("misha", "alim", "ser", "0001", 6000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(5000);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(0,b);
}
TEST(Bancai_2_2, Proverka_snatia_deneg_kogda_vvedennoe_chislo_ne_crato_10) {
  Dop c("misha", "alim", "ser", "0001", 6000, 0000, 0, 0);
  ProcCenter cl(c);
  Bancai de;
  cl.AddPers(c);
  int b;
  de.qwertyuiop(cl);
  de.VVOD_SUUMMi_SNAT_FOR_TEST(5002);
  b = de.Vidat_dengi_prog(cl);
  EXPECT_EQ(10, b);
}
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
}




