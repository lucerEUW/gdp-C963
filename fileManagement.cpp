#include<iostream>
#include"../include/fileManagement.h"

namespace manage{

std::string getExactLine(const  std::string& filename,  int lineNumber)
{
  std::ifstream file("books/"  + filename);
  std::string outputLine;
  
  for(int i = 0;i < lineNumber  -1; i++)
  {
    if(!std::getline(file,  outputLine))
    {
      return  "";
    }
  }

  std::getline(file,  outputLine);
  file.close();
  return  outputLine;
}

void displayDetails(std::string filename)
{
  std::cout << std::setw(19)  <<  std::left <<  "further details   :"   <<  std::endl
            << std::setw(19)  <<  std::left <<  "title             :"   << std::setw(38)  <<  std::right <<  getExactLine(filename,  2) <<  std::endl
            << std::setw(19)  <<  std::left <<  "author            :"   << std::setw(38)  <<  std::right <<  getExactLine(filename,  3) <<  std::endl
            << std::setw(19)  <<  std::left <<  "published by      :"   << std::setw(38)  <<  std::right <<  getExactLine(filename,  4) <<  std::endl
            << std::setw(19)  <<  std::left <<  "isbn              :"   << std::setw(38)  <<  std::right <<  getExactLine(filename,  5) <<  std::endl
            << std::setw(19)  <<  std::left <<  "price             :"   << std::setw(38)  <<  std::right <<  getExactLine(filename,  6) <<  std::endl
            <<  "========================================================="  <<  std::endl;
}

std::string readAmount(std::string targetFile)
{
  std::ifstream amountIn("books/" + targetFile);

  std::string amount;
  std::getline(amountIn,  amount);

  amountIn.close();
  return  amount;
}

void UpdateAmount(std::string targetFile,  int action, int amount)
{ 
  int bAmountI  = stoi(readAmount(targetFile));
    
  switch(action){
    case  0:
      bAmountI  = bAmountI  - amount;
      break;
    case  1:
      bAmountI  = bAmountI  + amount;
      break;
  }

  std::ofstream  amountOut("books/" + targetFile, std::ios::in  | std::ios::out);
  amountOut  <<  bAmountI;
  amountOut.close();
}

std::string readCounter()
{
  std::string count = readAmount("../counter.txt");
  return count;
}

void UpdateCounter(int action, int amount)
{    
  int firstLineI  = stoi(readCounter());
    
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
  booksOut.close();
}



std::string toLower(std::string searchTerm)
{
  std::transform(searchTerm.begin(), searchTerm.end(),  searchTerm.begin(),  [](unsigned char c)
  {
    return std::tolower(c);
  });
  return searchTerm;
}

std::string getSearchTerm(){
  std::string searchTerm;
  std::cout <<  "search for book: ";
  std::cin  >>  searchTerm;
  std::cout <<  "=========================================================" <<  std::endl;
  return searchTerm;
}

void Search()
{
  std::string searchTerm, filename, foundFileName;
  searchTerm  = toLower(getSearchTerm());
  int booksFound  = 0;

  for(const auto  & entry : std::filesystem::directory_iterator("books/")){
      
    filename = entry.path().filename().string();
      
    if(filename.find(searchTerm)  !=  std::string::npos)
    {
      foundFileName = filename;
      std::cout << std::setw(19)  <<  std::left <<  getExactLine(filename,  2)  << std::setw(19)  <<  std::left  <<  getExactLine(filename,  3)  << std::setw(19)  <<  std::right  <<  getExactLine(filename,  5)  <<  std::endl;
      booksFound++;
    }
  }
  std::cout <<  "=========================================================" <<  std::endl;
  if(booksFound ==  1)
  {
    displayDetails(foundFileName);
    Book::Buy(foundFileName);
  }else{
    std::cout <<  booksFound  <<  " different results found. please specify further!" <<  std::endl;
    Search();
  }
}
}
