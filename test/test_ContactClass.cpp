#include <gtest/gtest.h>
#include "ContactClass.h"
#include <Windows.h>

TEST(Contact,DestructorTest) {
	Contact user;
	user.~Contact();
	int i = 0;
	if (user.getSurname() == "" &&
		user.getName() == "" &&
		user.getOtch() == "" &&
		user.getNumber() == "" &&
		user.getBirthday() == ""&&
		user.getPol() == "" &&
		user.getStatus() == "") {
		i++;
	}
	EXPECT_EQ(i,1); 
}
TEST(Contact, DefaultContstructorsTest) {
	ASSERT_NO_THROW(Contact user);
}

TEST(Contact, DefaultContstructorsCorrectTest) {
	Contact user;
	Contact trueUser("�� ������", "�� ������", "�� ������", "+7.***.***.**.**", "��.��.��", "�/�", "�� ������");
	EXPECT_EQ(user, trueUser);
}
TEST(Contact, InitContstructorsCorrectTest) {
	int res = 0;
	Contact User("�� ������", "�� ������", "�� ������", "+7.***.***.**.**", "��.��.��", "�/�", "�� ������");
	if ((User.getSurname() == "�� ������") && (User.getName() == "�� ������") && (User.getOtch() == "�� ������") && (User.getNumber() == "+7.***.***.**.**") && (User.getBirthday() == "��.��.��") && (User.getPol() == "�/�") && (User.getStatus() == "�� ������")) {
		res = 1;
	}
	EXPECT_EQ(res, 1);
}
TEST(Contact, CopyContstructorsCorrectTest) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contact user1(user);
	EXPECT_EQ(user,user1);
}
TEST(Contact, getFunctionsSurname) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getSurname(), "������");
}
TEST(Contact, getFunctionsName) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getName(), "�������");
}
TEST(Contact, getFunctionsOtch) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getOtch(), "����������");
}
TEST(Contact, getFunctionsNumber) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getNumber(), "+79537511791");
}
TEST(Contact, getFunctionsBirthday) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getBirthday(), "06.06.2001");
}
TEST(Contact, getFunctionsPol) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getPol(), "�");
}
TEST(Contact, getFunctionsStatus) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	EXPECT_EQ(user.getStatus(), "������");
}
TEST(Contact, OperatorTestFirst) {
	int res = 0;
	Contact user;
	Contact trueuser;
	if (user == trueuser) {
		res = 1;
	}
	EXPECT_EQ(res, 1);
}
TEST(Contact, OperatorTestSecond) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contact trueUser = user;
	EXPECT_EQ(trueUser, user);
}
TEST(Contacts, ConstrucorTestsDefault) {
	Contacts book;
	EXPECT_EQ(book.getNumber(),0);
}
TEST(Contacts, ConstrucorTestsInit) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contacts book(1, &user);
	EXPECT_EQ(book.getNumber(), 1);
}
TEST(Contacts, ConstrucorTestsCopy) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contacts book(1, &user);
	Contacts book1(book);
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Contacts, OperatorSameTest) {
	Contact user("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contacts book(1, &user);
	Contacts book1 = book;
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Contacts, FindMethodsByNumber) {
	Contact* users = new Contact[3];
	Contact third("�������", "�������", "����������", "+79210400326", "06.06.2001", "�", "������");
	Contact second("�������", "�����", "����������", "+79113117958", "06.06.2001", "�", "������");
	Contact first("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	Contacts kniga(3, users);
	string number = "+79210400326";
	EXPECT_EQ(kniga.find_by_number(number),2);
}
TEST(Contacts, FindMethodsByFio) {
	Contact* users = new Contact[3];
	Contact third("�������", "�������", "����������", "+79210400326", "06.06.2001", "�", "������");
	Contact second("�������", "�����", "����������", "+79113117958", "06.06.2001", "�", "������");
	Contact first("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	Contacts kniga(3, users);
	string surname = "������";
	string name = "�������";
	string otch = "����������";
	EXPECT_EQ(kniga.find_by_fio(surname,name,otch), 0);
}
/*TEST(Contacts, CreateTEST) {
	Contacts kniga;
	Contact first("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contact second("�������", "�����", "����������", "+79113117958", "06.06.2001", "�", "������");
	kniga.input_and_create_testver1();
	kniga.input_and_create_testver2();
	string surname = "�������";
	string name = "�����";
	string otch = "����������";
	EXPECT_EQ(kniga.find_by_fio(surname, name, otch), 1);
}
*/
TEST(Contacts, FindMethodsByLetter) {
	Contact* users = new Contact[4];
	Contact third("�������", "�������", "����������", "+79210400326", "06.06.2001", "�", "������");
	Contact second("�������", "�����", "����������", "+79113117958", "06.06.2001", "�", "������");
	Contact first("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contact fourth("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	users[3] = fourth;
	Contacts kniga(4, users);
	string firstletter = "�";
	EXPECT_EQ(kniga.search_by_first_letter(firstletter),3);
}

/*TEST(Contacts, DeleteStatusTest) {
	Contact* users = new Contact[4];
	Contact third("�������", "�������", "����������", "+79210400326", "06.06.2001", "�", "������");
	Contact second("�������", "�����", "����������", "+79113117958", "06.06.2001", "�", "������");
	Contact first("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	Contact fourth("������", "�������", "����������", "+79537511791", "06.06.2001", "�", "������");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	users[3] = fourth;
	Contacts kniga(4, users);
	kniga.delete_from_favourites(third);
	int i = 0;
	if (third.getStatus() == "�� ����� �������") {
		i = 1;
	}
	EXPECT_EQ(i, 1);
}*/