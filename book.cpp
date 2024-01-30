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

void Book::UpdateCounter(int action, int amount)
{    
  std::ifstream booksIn("counter.txt");
  std::string firstLine;
  std::getline(booksIn, firstLine);

  int firstLineI  = stoi(firstLine);
    
  switch(action){
    case  0:
      firstLineI  = firstLineI  - amount;
      break;
    case  1:
      firstLineI  = firstLineI  + amount;
      break;
  }

  std::ofstream  booksOut("counter.txt");
  booksOut  <<  firstLineI;

  booksIn.close();
  booksOut.close();
}

void Book::Add(){
  UpdateCounter(1,  amount);
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
  if(std::stoi(manage::readAmount(bookToBuy))  > 0)
  {
    std::cout <<  "there are "  <<  manage::readAmount(bookToBuy) <<  " copies left" <<  std::endl <<  "do you want to buy this book?[y/n] ";
  }else{
    std::cout <<  "no copies left!";
  }
}
