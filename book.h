#ifndef BOOK_H
#define BOOK_H

#include<fstream>
#include<string>
#include<sstream>
#include<filesystem>

class Book  {

private:
  std::string bookDirPath;
  std::string titel;
  std::string autor;
  std::string verlag;
  std::string isbnString;
  std::string bookFile;

  long isbn;
  int amount;
  
  double  preis;
   
public:
  Book( std::string titel,  std::string autor,  std::string verlag, long isbn, double  preis, int amount);

  void  Add();
  static void  Buy(std::string bookToBuy);
};

#endif
