#include<iostream>
#include<string>
#include<fstream>
#include"book.h"

std::string readCounter(){
  std::ifstream counterIn("counter.txt");
  std::string   firstLine;
  std::getline(counterIn,  firstLine);
  counterIn.close();
  return firstLine;
}

bool Search(std::string searchedBook){
  for(const auto  & entry : std::filesystem::directory_iterator("books/")){
    std::string filename = entry.path().filename().string();
    if(filename.find(searchedBook)  !=  std::string::npos){
      return true;
    }
  }
  return false;
}

int main(){
  std::string titel, autor, verlag;
  int isbn, amount;
  double preis;

  std::string searchTerm;

      std::cout <<  "give dates of book to add [titel autor verlag isbn preis anzahl]: ";
      std::cin  >>  titel >>  autor >>  verlag  >>  isbn  >>  preis >>  amount;

      Book newBook(titel, autor,  verlag, isbn, preis,  amount);
      newBook.Add();
      std::cout <<  "added "<< amount << " copies of "  <<  titel <<  " to our list"  <<  std::endl;

      std::cout <<  "with it there are " <<  readCounter() <<  " books in the archive" <<  std::endl;
    
      std::cout <<  "search for: ";
      std::cin  >>  searchTerm;
      if(Search(searchTerm) ==  true){std::cout  <<  "found";}else{std::cout  <<  "not found";}
    
  return 0;
}
