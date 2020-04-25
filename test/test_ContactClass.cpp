#include <gtest/gtest.h>
#include "ContactClass.h"
#include <Windows.h>

TEST(Contact, ContstructorsTestIn) {
	Contact user;
	int i = 0;
	if (user.getSurname() == "Не задано" &&
		user.getName() == "Не задано" &&
		user.getOtch() == "Не задано" &&
		user.getNumber() == "+7.***.***.**.**" &&
		user.getBirthday() == "ДД.ММ.ГГ" &&
		user.getPol() == "М/Ж" &&
		user.getStatus() == "Не избран") {
		i++;
	}
  EXPECT_EQ(i, 1);
}

/*TEST(Contact, ContstructorsTestCop) {
	Contact user()

  EXPECT_EQ(add(-5, 5), 0);
}*/

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
/*TEST(Contact, InputTests) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Contact user;
	user.input_all_data();
	int i = 0;
	if (user.getSurname() == "Грошев" &&
		user.getName() == "Николай" &&
		user.getOtch() == "Дмитриевич" &&
		user.getNumber() == "+795375117931" &&
		user.getBirthday() == "06.06.2001"&&
		user.getPol() == "М" &&
		user.getStatus() == "Избран") {
		i++;
	}
	EXPECT_EQ(i, 1);
}*/