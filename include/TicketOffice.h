#ifndef INCLUDE_TICKETOFFICE_H_
#define INCLUDE_TICKETOFFICE_H_

#pragma once

#include "CinemaClass.h"
#include <locale.h>
#include <time.h>

//������� ����� ����� �������� ����� ,� public �������������� ������� public ��� cinema
class TicketOffice :
  public Cinema
{
public:
  // ��������� ��������� ��������� �������
  const int VipValue = 500;
  const int CommonValue = 300;
  // �������� ������
  void addOrder();
  void checkPlaces();
  void reservePlaces();
  void checkPrice();
  void cancelOrder();
  void createTicket();

};















#endif  // INCLUDE_TICKETOFFICE_H_