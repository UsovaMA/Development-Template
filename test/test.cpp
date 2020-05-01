// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "ClassContacts.h"
#include <locale.h>

TEST(TestClassContacts, Create_input)
{
  Contacts test_s;
  Contact test;
  ASSERT_NO_THROW(test.create_input(test));
}

TEST(TestClassContacts, create_add) {
  Contacts test_s;
  Contact test;
  ASSERT_NO_THROW(test_s.create_add(test));
}

TEST(TestClassContacts, surname_input) {
  Contacts test_s;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.surname_input(_surname, _name, _patronymic));
}

TEST(TestClassContacts, search_by_surname) {
  Contacts test_s;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.search_by_surname(_surname, _name, _patronymic));
}

TEST(TestClassContacts, search_letter_input) {
  Contacts test_s;
  char b;
  ASSERT_NO_THROW(test_s.search_letter_input(b));
}

TEST(TestClassContacts, tel_num_input) {
  Contacts test_s;
  string tel_number;
  ASSERT_NO_THROW(test_s.search_tel_number_input(tel_number));
}

TEST(TestClassContacts, tel_num_add) {
  Contacts test_s;
  string tel_number;
  ASSERT_NO_THROW(test_s.search_tel_number_add(tel_number));
}

TEST(TestClassContacts, kolvo_contacts) {
  Contacts test_s;
  ASSERT_NO_THROW(test_s.kolvo_contacts());
}

TEST(TestClassContacts, output_array) {
  Contacts test_s;
  ASSERT_NO_THROW(test_s.output_array());
}

TEST(TestClassContacts, all_favorites) {
  Contacts test_s;
  ASSERT_NO_THROW(test_s.all_favorites());
}


TEST(TestClassContacts, add_to_favorites) {
  Contacts test_s;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.add_to_favorites(_surname, _name, _patronymic));
}

TEST(TestClassContacts, change_contact_input) {
  Contacts test_s;
  Contact test;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.change_contact_input(_surname, _name, _patronymic, test));
}

TEST(TestClassContacts, change_contact_add) {
  Contacts test_s;
  Contact test;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.change_contact_add(_surname, _name, _patronymic, test));
}

TEST(TestClassContacts, sur_input) {
  Contacts test_s;
  Contact test;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.surname_input(_surname, _name, _patronymic));
}

TEST(TestClassContacts, del_sur_add) {
  Contacts test_s;
  Contact test;
  string _surname, _name, _patronymic;
  ASSERT_NO_THROW(test_s.delete_surname_add(test));
}


TEST(TestClassContacts, del_tel_input) {
  Contacts test_s;
  Contact test;
  ASSERT_NO_THROW(test_s.delete_tel_number_input(test));
}

TEST(TestClassContacts, del_tel_add) {
  Contacts test_s;
  Contact test;
  ASSERT_NO_THROW(test_s.delete_tel_number_add(test));
  
}




