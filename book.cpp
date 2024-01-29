#include<iostream>
#include"book.h"

Book::Book(std::string titel, std::string  autor, std::string  verlag,  int isbn, double preis,  int  amount)
: titel(titel),  autor(autor), verlag(verlag), isbn(isbn), preis(preis), amount(amount)
{

  #include<iostream>
#include"book.h"

Book::Book( std::string titel,  std::string autor,  std::string verlag, int isbn, double  preis, int amount)
: titel(titel),  autor(autor), verlag(verlag), isbn(isbn), preis(preis), amount(amount)
{

std::string bookDirPath = "books/";
std::string isbnString  = std::to_string(isbn); 
std::string bookFile    = bookDirPath + titel + autor +  isbnString  + ".txt";

}

void Book::UpdateCounter(int action){
    
  std::ifstream booksIn("counter.txt");
  std::string firstLine;
  std::getline(booksIn, firstLine);

  int firstLineI  = stoi(firstLine);
    
  switch(action){
    case  0:
      firstLineI--;
      break;
    case  1:
      firstLineI++;
      break;
  }

  std::ofstream  booksOut("counter.txt");
  booksOut  <<  firstLineI;

  booksIn.close();
  booksOut.close();
}

void Book::Add(){
  UpdateCounter(1);
  std::ofstream  book(bookFile);
  book  <<  amount  <<  std::endl 
        <<  titel   <<  std::endl
        <<  autor   <<  std::endl
        <<  verlag  <<  std::endl
        <<  isbn    <<  std::endl
        <<  preis   <<  std::endl;
  book.close();
}
}


void Book::UpdateCounter(int action){
    
  std::ifstream booksIn("counter.txt");
  std::string firstLine;
  std::getline(booksIn, firstLine);

  int firstLineI  = stoi(firstLine);
    
  switch(action){
    case  0:
      firstLineI--;
      break;
    case  1:
      firstLineI++;
      break;
  }

  std::ofstream  booksOut("counter.txt");
  booksOut  <<  firstLineI;

  booksIn.close();
  booksOut.close();
}

void Book::Add(){
  UpdateCounter(1);
  std::ofstream  book(bookFile);
  book  <<  amount  <<  std::endl 
        <<  titel   <<  std::endl
        <<  autor   <<  std::endl
        <<  verlag  <<  std::endl
        <<  isbn    <<  std::endl
        <<  preis   <<  std::endl;
  book.close();
}
