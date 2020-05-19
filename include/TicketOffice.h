#ifndef INCLUDE_TICKETOFFICE_H_
#define INCLUDE_TICKETOFFICE_H_

#pragma once

#include "CinemaClass.h"
#include <locale.h>
#include <time.h>

//Создаем класс самой билетной кассы ,с public спецификатором доступа public для cinema
class TicketOffice :
  public Cinema
{
public:
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

};















#endif  // INCLUDE_TICKETOFFICE_H_