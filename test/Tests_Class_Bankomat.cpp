#include <gtest/gtest.h>
#include "Class_Bankomat.hpp"

TEST(Class_Client, get_Balance) {
	Client a(1000, 1, "0000", "Test");
	EXPECT_EQ(1000, a.get_Balance());
}

TEST(Class_Client, get_Card_number) {
	Client a(1000, 1, "0000", "Test");
	EXPECT_EQ("0001", a.get_Card_number());
}

TEST(Class_Client, get_Pin_code) {
	Client a(1000, 1, "0000", "Test");
	EXPECT_EQ("0000", a.get_Pin_code());
}

TEST(Class_Client, get_Full_name) {
	Client a(1000, 1, "0000", "Test");
	EXPECT_EQ("Test", a.get_Full_name());
}

TEST(Class_Client, get_Status) {
	Client a(1000, 1, "0000", "Test");
	EXPECT_EQ(1, a.get_Status());
}

TEST(Class_Client, set_Balance) {
	Client a(1000, 1, "0000", "Test");
	a.set_Balance(500);
	EXPECT_EQ(1500, a.get_Balance());
}

TEST(Class_Client, set_Card_number) {
	Client a(1000, 1, "0000", "Test");
	a.set_Card_number("0002");
	EXPECT_EQ("0002", a.get_Card_number());
}

TEST(Class_Client, set_Pin_code) {
	Client a(1000, 1, "0000", "Test");
	a.set_Pin_code("1111");
	EXPECT_EQ("1111", a.get_Pin_code());
}

TEST(Class_Client, set_Full_name) {
	Client a(1000, 1, "0000", "Test");
	a.set_Full_name("Test2");
	EXPECT_EQ("Test2", a.get_Full_name());
}

TEST(Class_Client, set_Status) {
	Client a(1000, 1, "0000", "Test");
	a.set_Status(0);
	EXPECT_EQ(0, a.get_Status());
}

TEST(Class_Client, Quality_true) {
	Client a(1000, 1, "0000", "Test");
	Client b(1000, 1, "0000", "Test");
	EXPECT_EQ(1, a == b);
}

TEST(Class_Client, Quality_false) {
	Client a(1000, 1, "0000", "Test");
	Client b(1000, 2, "0000", "Test");
	EXPECT_EQ(0, a == b);
}

TEST(Class_ProcCenter, add_new_client) {
	Client a(0, 1, "0000", "Test");
	ProcCenter b;
	b.add_new_client("0000", "Test");
	EXPECT_EQ(1, a == b.get_Clients()[0]);
}

TEST(Class_Bankomat, accept_card) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	EXPECT_EQ(1, a.get_in_out());
}

TEST(Class_Bankomat, Find_customer_true) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	EXPECT_EQ(0, a.Find_customer("0001"));
}

TEST(Class_Bankomat, Find_customer_false) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	EXPECT_EQ(-1, a.Find_customer("0002"));
}

TEST(Class_Bankomat, Accept_money_true) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	a.Accept_money("0001", 5000);
	EXPECT_EQ(1601, a.get_rub_5000());
}

TEST(Class_Bankomat, Accept_money_false1) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_money("0001", 5000);
	EXPECT_EQ(0, a.get_in_out());
}

TEST(Class_Bankomat, Accept_money_false_2) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_money("0001", 300000);
	EXPECT_EQ(1600, a.get_rub_5000());
}

TEST(Class_Bankomat, Accept_money_balance_customer) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	a.Accept_money("0001", 5000);
	EXPECT_EQ(5000, a.get_Clients()[0].get_Balance());
}

TEST(Class_Bankomat, Accept_money_false_1) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_money("0001", 5000);
	EXPECT_EQ(0, a.get_in_out());
}

TEST(Class_Bankomat, Give_out_money_balance_customer) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	a.Accept_money("0001", 5000);
	a.Give_out_money("0001", 2000);
	EXPECT_EQ(3000, a.get_Clients()[0].get_Balance());
}

TEST(Class_Bankomat, Give_out_money_bankomat) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	a.Accept_money("0001", 10000);
	a.Give_out_money("0001", 5000);
	EXPECT_EQ(1601, a.get_rub_5000());
}

TEST(Class_Bankomat, Return_card) {
	Bankomat a;
	a.add_new_client("0000", "Test");
	a.Accept_customer_card("0001");
	a.Return_customer_card();
	EXPECT_EQ(0, a.get_in_out());
}

TEST(Throws, throw_1) {
	EXPECT_ANY_THROW(Client(0, 10000, "0000", "Test"));
}

TEST(Throws, throw_2) {
	EXPECT_ANY_THROW(Bankomat(3000,3000,3000,3000,3000,3000));
}
