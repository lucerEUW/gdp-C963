#include<iostream>
#include"include/book.h"
#include"include/fileManagement.h"

int main()
{
  std::string titel,  autor,  verlag, searchTerm;
  long    isbn;
  int     amount;
  double  preis;


  std::cout <<  "give dates of book to add [titel autor verlag isbn preis anzahl]: ";
  std::cin  >>  titel >>  autor >>  verlag  >>  isbn  >>  preis >>  amount;

  Book newBook(titel, autor,  verlag, isbn, preis,  amount);
  newBook.Add();
  std::cout <<  "added "<< amount << " copies of "  <<  titel <<  " to our list"  <<  std::endl;

  std::cout <<  "with it there are " <<  manage::readCounter() <<  " books in the archive" <<  std::endl;
/*   
  std::cout <<  "search for: ";
  std::cin  >>  searchTerm;
  manage::Search(searchTerm);
*/
  return 0;
}
