#include<iostream>
#include"include/book.h"
#include"include/fileManagement.h"

int main()
{
  std::string titel,  autor,  verlag, searchTerm;
  long    isbn;
  int     amount;
  double  preis;
  char    choice;
  bool contRunning  = true;

  while(contRunning){
    std::cout <<  "=========================================================" << std::endl
              <<  "Buecherverwaltung" <<  std::endl
              <<  "=========================================================" << std::endl
              <<  std::setw(25) <<  std::left <<  "s:search/restock/buy"  <<  std::setw(13) << std::right <<"a:add new  q:quit"  <<  std::setw(5) << std::right <<  "[" <<  manage::readCounter()  <<  " copies]"  <<  std::endl
              <<  "=========================================================" << std::endl;
    std::cin  >>  choice;

    switch (choice) {
      case  's':
        manage::Search();
        break;
      case  'a':
        {
          std::cout <<  "give dates of book to add [titel autor verlag isbn preis anzahl]: ";
          std::cin  >>  titel >>  autor >>  verlag  >>  isbn  >>  preis >>  amount;
          Book newBook(titel, autor, verlag, isbn, preis,  amount);
          newBook.Add();
          break;
        }
      case  'q':
        std::cout <<  "quitting..." <<  std::endl;
        contRunning = false;
        break;
      default:
        std::cout <<  "invalid" <<  std::endl;
        break;
    }
  }
  return 0;
}
