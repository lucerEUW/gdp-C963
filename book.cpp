#include<iostream>
#include"../include/book.h"
#include"../include/fileManagement.h"

Book::Book(std::string titel, std::string  autor, std::string  verlag,  long isbn, double preis,  int  amount)
: titel(titel),  autor(autor), verlag(verlag), isbn(isbn), preis(preis), amount(amount)
{
  std::string bookDirPath = "books/";
  std::string isbnString  = std::to_string(isbn); 
  bookFile    = bookDirPath + manage::toLower(titel) + manage::toLower(autor) +  isbnString  + ".txt";
}

void Book::Add(){
  manage::UpdateCounter(1,  amount);
  std::ofstream  book(bookFile);
  book  <<  amount  <<  std::endl 
        <<  titel   <<  std::endl
        <<  autor   <<  std::endl
        <<  verlag  <<  std::endl
        <<  isbn    <<  std::endl
        <<  preis   <<  std::endl;
  book.close();
}

void Book::Buy(std::string bookToBuy)
{
  char yn;
  int amount;

  if(std::stoi(manage::readAmount(bookToBuy))  > 0)
  {
    std::cout <<  "there are "  <<  manage::readAmount(bookToBuy) <<  " copies left" <<  std::endl
              <<  "do you want to buy this book?[y/n amount] "  <<  std::endl
              <<  "=========================================================" <<  std::endl;
    std::cin  >>  yn  >>  amount;

    switch(yn)
    {
      case  'y':
        std::cout <<  "total price: " <<  amount  * std::stod(manage::getExactLine(bookToBuy,  6));
        manage::UpdateCounter(0,  amount);
        break;
      case  'n':
        std::cout <<  "purchase canceled";
        break;
    }
  }else{
    std::cout <<  "no copies left!";
  }
}
