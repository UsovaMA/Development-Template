#ifndef INCLUDE_TICKETOFFICE_H_
#define INCLUDE_TICKETOFFICE_H_

#pragma once

#include "CinemaClass.h"
#include <locale.h>
#include <time.h>

//Создаем класс самой билетной кассы ,с public спецификатором доступа  для cinema
class TicketOffice :
  public Cinema
{
public:
  int day;
  int numberOfFilm;
  Cinema* films;
  int hall[20][20];
  // добавляем константы стоимости билетов
  const int VipValue = 500;
  const int CommonValue = 300;
  // основные методы
  void addOrder();
  void checkPlaces();
  void reservePlaces();
  void checkPrice();
  void cancelOrder();
  void createTicket();
  void outputall();
  TicketOffice();
 TicketOffice& TicketOffice::operator =(const TicketOffice& c) {
    if (day != 0 && day != c.day) {
      delete[] films;
      day = 0;
      films = new Cinema[c.day];
    }
    day = c.day;
    for (int i = 0; i < day; i++) {
      films[i] = c.films[i];
    }

    return *this;
  }

  void createfilm(const Cinema & new_film);

};















#endif  // INCLUDE_TICKETOFFICE_H_