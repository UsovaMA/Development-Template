// Copyright 2020 Serebrennikov
#include <gtest/gtest.h>
#include "ClassContacts.h"

TEST(TestClassContacts, Create_New_Contact) {
  Contacts test;
  ASSERT_NO_THROW(test.create());
}

TEST(TestClassContacts, delete_surname) {
  Contacts test;
  ASSERT_NO_THROW(test.delete_surname());
}

TEST(TestClassContacts, add_to_array) {
  Contacts test;
  ASSERT_NO_THROW(test.add_to_array());
}

TEST(TestClassContacts, delete_tel_number) {
  Contacts test;
  ASSERT_NO_THROW(test.delete_tel_number());
}

TEST(TestClassContacts, search_surname) {
  Contacts test;
  ASSERT_NO_THROW(test.search_surname());
}

TEST(TestClassContacts, all_favorites) {
  Contacts test;
  ASSERT_NO_THROW(test.all_favorites());
}

TEST(TestClassContacts, output_array) {
  Contacts test;
  ASSERT_NO_THROW(test.output_array());
}

/*TEST(TestClassContacts, search_tel_number) {
  Contacts test;
  ASSERT_NO_THROW(test.search_tel_number);
}

TEST(TestClassContacts, add_to_favorites) {
  Contacts test;
  ASSERT_NO_THROW(test.add_to_favorites);
}*/

TEST(TestClassContacts, change_contact) {
  Contacts test;
  ASSERT_NO_THROW(test.change_contact());
}

TEST(TestClassContacts, search_letter) {
  Contacts test;
  ASSERT_NO_THROW(test.search_letter());
}

TEST(TestClassContacts, end) {
  Contacts test;
  ASSERT_NO_THROW(test.end());
}



