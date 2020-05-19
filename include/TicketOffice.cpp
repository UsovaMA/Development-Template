#include "TicketOffice.h"
#include <Windows.h>
void TicketOffice::addOrder()
{
  cout << "Введите данные для заказа" << endl;

}
TicketOffice::TicketOffice() {
  films = nullptr;
  day = 0;
}

void TicketOffice::createfilm(const Cinema &new_film) {
  TicketOffice result;
  cout << "Сколько фильмов вы хотите добавить в " << day << "День" << endl;
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {

    result.numberOfFilm = numberOfFilm + 1;
    result.films = new Cinema[numberOfFilm + 1];
    for (int i = 0; i < count; i++) {

      result.films[i] = films[i];
    }
    result.films[result.numberOfFilm - 1].numberOfHall = new_film.numberOfHall;
    result.films[result.numberOfFilm - 1].NameOfFilm = new_film.NameOfFilm;
    result.films[result.numberOfFilm - 1].timeOfStart = new_film.timeOfStart;
    result.films[result.numberOfFilm - 1].duration = new_film.duration;
    result.films[result.numberOfFilm - 1].ageRate = new_film.ageRate;
    result.films[result.numberOfFilm - 1].status = new_film.status;
    day++;
    (*this) = result;
  }
}

  void TicketOffice::outputall() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < day; i++) {
      cout << "День " << day << endl;
      cout << "Номер фильма " << films[i].numberOfFilm << endl;
      cout << "Номер зала " << films[i].numberOfHall << endl;
      cout << "Название фильма " << films[i].NameOfFilm << endl;
      cout << "Время начала " << films[i].timeOfStart << endl;
      cout << "Продолжительность " << films[i].duration << endl;
      cout << "Возрастной рейтинг " << films[i].ageRate << endl;
      cout << "Статус зала" << films[i].status << endl;
    }
  }