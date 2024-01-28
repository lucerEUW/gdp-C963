#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<filesystem>

class Book{

private:
  std::string bookDirPath = "books/";

  std::string titel, autor, verlag;
  int     isbn  , amount  ; 
  double  preis ;
  
  std::string isbnString  = std::to_string(isbn); 
  std::string bookFile    = bookDirPath + titel + autor +  isbnString  + ".txt";
  
  void updateCounter(int action){
    
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

public:
  Book( std::string titel,  std::string autor,  std::string verlag, int isbn, double  preis, int amount)
  : titel(titel),  autor(autor), verlag(verlag), isbn(isbn), preis(preis), amount(amount)
  {}

  void Add(){
    updateCounter(1);
    std::ofstream  book(bookFile);
    book  <<  amount  <<  std::endl 
          <<  titel   <<  std::endl
          <<  autor   <<  std::endl
          <<  verlag  <<  std::endl
          <<  isbn    <<  std::endl
          <<  preis   <<  std::endl;
    book.close();
  }

  void Buy(){
    updateCounter(0);
      std::ifstream counterIn(bookFile);
      std::string   firstLine;
      std::getline(counterIn,  firstLine);
      counterIn.close();
  }
};
