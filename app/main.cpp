// Copyright 2020 Serebrennikov
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <locale.h>
#include "ClassContacts.h"
#include "ClassContact.h"

using namespace std;

int main() {
  Contacts test_s;
  Contact test;
  int kolvo=0; 
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  test_s.add_to_array();//заполнение массива контактами из файла 
  
  cout << "|___________________ТЕЛЕФОННАЯ КНИГА_____________________|" << endl << endl;
  
  int work = 1;
  while (work) {
    cout << "_________________________________________________________" << endl;
    cout << "|1 - СОЗДАТЬ НОВЫЙ КОНТАКТ                               |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|2 - НАЙТИ КОНТАКТ ПО ФИО                                |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|3 - НАЙТИ ИНФОРМАЦИЮ О КОНTАКТЕ ПО ПЕРВОЙ БУКВЕ ФАМИЛИИ |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|4 - НАЙТИ ИНФОРМАЦИЮ О КОНТАКТЕ ПО НОМЕРУ ТЕЛЕФОНА      |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|5 - УЗНАТЬ КОЛИЧЕСТВО КОНТАКТОВ                         |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|6 - ВЫВЕСТИ ВСЕ КОНТАКТЫ НА ЭКРАН                       |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|7 - ВЫВЕСТИ СПИСОК ИЗБРАННЫХ КОНТАКТОВ НА ЭКРАН         |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|8 - ДОБАВТЬ КОНТАКТ В СПИСОК ИЗБРАННЫХ                  |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|9 - ИЗМЕНТИТЬ ИНФОРМАЦИЮ О КОНТАКТЕ                     |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|10 - УДАЛИТЬ КОНТАКТ (НАЙДЕННЫЙ ПО ФИО)                 |" << endl;
    cout << "|________________________________________________________|" << endl;
    cout << "|11 - УДАЛИТЬ КОНТАКТ (НАЙДЕННЫЙ ПО НОРМЕРУ ТЕЛЕФОНА)    |" << endl;
    cout << "|________________________________________________________|" << endl << endl;
    int act;
    cout << "ВЫПОЛНИТЬ: ";
    cin >> act;
    cout << endl;

    if (act == 1) {
      test.create_input(test);
      test_s.create_add(test);
      kolvo++;
    }
    else {
      if (act == 2) {
        string _surname, _name, _patronymic;
        test_s.surname_input(_surname, _name, _patronymic);
        test_s.search_by_surname(_surname, _name, _patronymic);
      }
      else {
        if (act == 3) {
          char b;
          test_s.search_letter_input(b);
          test_s.search_letter_add(b);
        }
        else {
          if (act == 4) {
            cout << "Введите номер телефона в формате 8(ХХХ)ХХХ-ХХ-ХХ:";
            string tel_number;
            test_s.search_tel_number_input(tel_number);
            test_s.search_tel_number_add(tel_number);
          }
          else {
            if (act == 5)
              test_s.kolvo_contacts();
            else {
              if (act == 6)
                test_s.output_array();
              else {
                if (act == 7)
                  test_s.all_favorites();
                else {
                  if (act == 8) {
                    string _surname, _name, _patronymic;
                    test_s.surname_input(_surname, _name, _patronymic);
                    test_s.add_to_favorites();
                  }
                  else {
                    if (act == 9) {
                      string _surname, _name, _patronymic;
                      test_s.change_contact_input(_surname, _name, _patronymic, test);
                      test_s.change_contact_add(_surname, _name, _patronymic, test);
                    }
                    else {
                      if (act == 10) {
                        string _surname, _name, _patronymic;
                        test_s.surname_input(_surname, _name, _patronymic);
                        test_s.delete_surname_add(test);
                      }
                      else {
                        if (act == 11) {
                          test_s.delete_tel_number_input(test);
                          test_s.delete_tel_number_add(test);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << endl;
    cout << "ПРОДОЛЖИТЬ РАБОТУ? " << endl;
    cout << "|1 - ДА |0 - НЕТ | " << endl;
    cout << "ПРОДОЛЖИТЬ: ";
    cin >> work;
  } 
  
  test.end();

  system("pause");
}