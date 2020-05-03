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
	Contact trueUser("Не задано", "Не задано", "Не задано", "+7.***.***.**.**", "ДД.ММ.ГГ", "М/Ж", "Не избран");
	EXPECT_EQ(user, trueUser);
}
TEST(Contact, InitContstructorsCorrectTest) {
	int res = 0;
	Contact User("Не задано", "Не задано", "Не задано", "+7.***.***.**.**", "ДД.ММ.ГГ", "М/Ж", "Не избран");
	if ((User.getSurname() == "Не задано") && (User.getName() == "Не задано") && (User.getOtch() == "Не задано") && (User.getNumber() == "+7.***.***.**.**") && (User.getBirthday() == "ДД.ММ.ГГ") && (User.getPol() == "М/Ж") && (User.getStatus() == "Не избран")) {
		res = 1;
	}
	EXPECT_EQ(res, 1);
}
TEST(Contact, CopyContstructorsCorrectTest) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contact user1(user);
	EXPECT_EQ(user,user1);
}
TEST(Contact, getFunctionsSurname) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getSurname(), "Грошев");
}
TEST(Contact, getFunctionsName) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getName(), "Николай");
}
TEST(Contact, getFunctionsOtch) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getOtch(), "Дмитриевич");
}
TEST(Contact, getFunctionsNumber) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getNumber(), "+79537511791");
}
TEST(Contact, getFunctionsBirthday) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getBirthday(), "06.06.2001");
}
TEST(Contact, getFunctionsPol) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getPol(), "М");
}
TEST(Contact, getFunctionsStatus) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	EXPECT_EQ(user.getStatus(), "Избран");
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
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contact trueUser = user;
	EXPECT_EQ(trueUser, user);
}
TEST(Contacts, ConstrucorTestsDefault) {
	Contacts book;
	EXPECT_EQ(book.getNumber(),0);
}
TEST(Contacts, ConstrucorTestsInit) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contacts book(1, &user);
	EXPECT_EQ(book.getNumber(), 1);
}
TEST(Contacts, ConstrucorTestsCopy) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contacts book(1, &user);
	Contacts book1(book);
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Contacts, OperatorSameTest) {
	Contact user("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contacts book(1, &user);
	Contacts book1 = book;
	EXPECT_EQ(book1.getNumber(), 1);
}
TEST(Contacts, FindMethodsByNumber) {
	Contact* users = new Contact[3];
	Contact third("Грошева", "Татьяна", "Васильевна", "+79210400326", "06.06.2001", "М", "Избран");
	Contact second("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");
	Contact first("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	Contacts kniga(3, users);
	string number = "+79210400326";
	EXPECT_EQ(kniga.find_by_number(number),2);
}
TEST(Contacts, FindMethodsByFio) {
	Contact* users = new Contact[3];
	Contact third("Грошева", "Татьяна", "Васильевна", "+79210400326", "06.06.2001", "М", "Избран");
	Contact second("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");
	Contact first("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	Contacts kniga(3, users);
	string surname = "Грошев";
	string name = "Николай";
	string otch = "Дмитриевич";
	EXPECT_EQ(kniga.find_by_fio(surname,name,otch), 0);
}
/*TEST(Contacts, CreateTEST) {
	Contacts kniga;
	Contact first("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contact second("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");
	kniga.input_and_create_testver1();
	kniga.input_and_create_testver2();
	string surname = "Грошева";
	string name = "Дарья";
	string otch = "Дмитриевна";
	EXPECT_EQ(kniga.find_by_fio(surname, name, otch), 1);
}
*/
TEST(Contacts, FindMethodsByLetter) {
	Contact* users = new Contact[4];
	Contact third("Грошева", "Татьяна", "Васильевна", "+79210400326", "06.06.2001", "М", "Избран");
	Contact second("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");
	Contact first("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contact fourth("Прошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	users[3] = fourth;
	Contacts kniga(4, users);
	string firstletter = "П";
	EXPECT_EQ(kniga.search_by_first_letter(firstletter),3);
}

/*TEST(Contacts, DeleteStatusTest) {
	Contact* users = new Contact[4];
	Contact third("Грошева", "Татьяна", "Васильевна", "+79210400326", "06.06.2001", "М", "Избран");
	Contact second("Грошева", "Дарья", "Дмитриевна", "+79113117958", "06.06.2001", "М", "Избран");
	Contact first("Грошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	Contact fourth("Прошев", "Николай", "Дмитриевич", "+79537511791", "06.06.2001", "М", "Избран");
	users[0] = first;
	users[1] = second;
	users[2] = third;
	users[3] = fourth;
	Contacts kniga(4, users);
	kniga.delete_from_favourites(third);
	int i = 0;
	if (third.getStatus() == "Не имеет статуса") {
		i = 1;
	}
	EXPECT_EQ(i, 1);
}*/