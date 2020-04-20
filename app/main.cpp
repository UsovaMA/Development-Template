// Copyright 2020 Podovinnikov
#include "Song.h"



int main(int argc, const char* argv[])
{
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  fstream f;
 f.open("Playlist.txt", fstream::in | fstream::out | fstream::app);
 ifstream strm("Playlist.txt");
 
  if (!f)
  {
    cout << "Close\n\n";
  }
  else
  {
    cout << "Open\n\n";
  }
  Playlist lib;

  lib.append(Song("20.12.1500", "THE CRANBERRIES", "ZOMBIE","Поэт ZOMBIE","Композитор ZOMBIE","Альбом THE CRANBERRIES"));
  lib.append(Song("20.12.1835", "THE BEATLES", "LET IT BE", "Поэт THE BEATLES", "Композитор THE BEATLES", "Альбом THE BEATLES"));
  lib.append(Song("20.12.1000", "LINKIN PARK", "NUMB", "Поэт LINKIN PARK", "Композитор LINKIN PARK", "Альбом LINKIN PARK"));
  lib.append(Song("20.12.2000", "MICHAEL JACKSON", "BILLIE JEAN", "Поэт", "Композитор", "Альбом"));
  lib.append(Song("20.12.1752", "EMINEM", " LOSE YOURSELF", "Поэт", "Композитор", "Альбом"));

  int choice;
  string what;
  string date;
  Song song;
  Song song1;
  string line;
  char ss[20] = { 0 };

  Playlist::Songcase::iterator it;

  do {
    cout << "\n"
"1. Поиск песни по названию\n"
"2. Поиск песни по дате\n"
"3. Поиск песни по исполнителю\n"
"4. Добавление песни в плейлист\n"
"5. Удаление песни из плейлист\n"
"6. Список всех песен\n"
"7. Редактировать данные песни\n"
"8. Выдать все песни данного поэта\n"
"9. Выдать все песни данного композитора\n"
"10.Выдать все песни данного исполнителя\n"
"11. Кол-во песен в плейлисте\n"
"12. Запись и чтение в файл\n"
"0. Выход\n\n"
"Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    cout << endl;

    switch (choice)
    {
    case 1:
      cout << "Укажите название песни: ";
      getline(cin, what);
      it = lib.begin();
      do {
        it = lib.findByTitle(what, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;
    case 2:
      cout << "Укажите дату издания песни: ";
      cin >> date;
      cin.ignore();
      it = lib.begin();
      do {
        it = lib.findByDate(date, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;

    case 3:
      cout << "Укажите исполнителя: ";
      getline(cin, what);
      it = lib.begin();
      do {
        it = lib.findByAuthor(what, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;
    case 4:
      inputSong(song);
      lib.append(song);
      break;
    case 5:
      inputSong(song);
      if (lib.remove(song))
        cout << "песня удалена\n";
      else
        cout << "песня не найдена\n";
      break;
    case 6:
      std::sort(std::begin(lib), std::end(lib), []( Song& p1,  Song& p2)
        {
          return p1.getTitle() < p2.getTitle();
        });
      std::cout << std::endl;
      std::copy(std::begin(lib), std::end(lib), std::ostream_iterator<Song>(std::cout, "\n"));
      break;
    case 7:
      cout << "Введите данные песни которую хотите заменить";
      inputSong(song);
      if (lib.remove(song))
        cout << "песня найдена\n";
      else
        cout << "песня не найдена\n";
      cout << "Введите новые данные\n";
      inputSong(song1);
      lib.append(song1);
      break;
    case 8:
      cout << "Укажите поэта: ";
      getline(cin, what);
      it = lib.begin();
      do {
        it = lib.findByPoet(what, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;
    case 9:
      cout << "Укажите композитора: ";
      getline(cin, what);
      it = lib.begin();
      do {
        it = lib.findByComposer(what, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;
    case 10:
      cout << "Укажите исполнителя: ";
      getline(cin, what);
      it = lib.begin();
      do {
        it = lib.findByAuthor(what, it);
        if (it != lib.end()) {
          cout << *it;
          cout << endl;
          ++it;
        }
      } while (it != lib.end());
      break;
    case 11:
      cout << "Колличество песен в плейлесте:";
      
      cout << lib.numoOfsongs();
      break;
    case 12:
      std::sort(std::begin(lib), std::end(lib), []( Song& p1,  Song& p2)
        {
          return p1.getTitle() < p2.getTitle();
        });
      std::cout << std::endl;
      std::copy(std::begin(lib), std::end(lib), std::ostream_iterator<Song>(f, "\n"));
 
     /* while (std::getline(f, line)) {
        std::cout << line << std::endl;
      }*/
      while (true)
      {
        strm.getline(ss, 50);             // читаем числа как строки
        if (strm.eof()) break;            // проверяем конец файла
        cout << ss << '\n';            // выводим на экран
      }
      break;
    case 0:
      break;
    default:
      cout << "\nНе попал ((\n\n";
    }
  } while (choice != 0);
  f.close();
  system("pause");

  return 0;
}
