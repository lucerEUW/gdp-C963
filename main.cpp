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

  std::cout <<  "Buecherverwaltung" <<  std::endl
            <<  "=========================================================" << std::endl
            <<  "s:search/buy for books  a:add books"  <<  std::endl
            <<  "=========================================================" << std::endl;
  std::cin  >>  choice;

  switch (choice) {
    case  's':
      manage::Search();
      break;
    case  'a':
      std::cout <<  "give dates of book to add [titel autor verlag isbn preis anzahl]: ";
      std::cin  >>  titel >>  autor >>  verlag  >>  isbn  >>  preis >>  amount;

      break;
    default:
      std::cout <<  "invalid";
      break;
  }
  return 0;
}
