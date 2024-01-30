#include<iostream>
#include"../include/fileManagement.h"

namespace manage{

std::string getExactLine(std::string filename,  int index)
{
  std::ifstream file(filename);

  std::string outputLine;
  int readIndex  = 0;

  while(std::getline(file,outputLine))
  {
    if(readIndex ==  index)
    {
      file.close();
      return  outputLine;
    }
    readIndex++;
  }
  return  "";
}

void displayDetails(std::string filename)
{
  std::cout <<  "further details  :"   <<  std::endl
            <<  "title            :"   <<  getExactLine(filename,  1) <<  std::endl
            <<  "author           :"   <<  getExactLine(filename,  2) <<  std::endl
            <<  "published by     :"   <<  getExactLine(filename,  3) <<  std::endl
            <<  "isbn             :"   <<  getExactLine(filename,  4) <<  std::endl
            <<  "price            :"   <<  getExactLine(filename,  5) <<  std::endl
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

std::string readCounter()
{
  std::ifstream counterIn("counter.txt");
  
  std::string   firstLine;
  std::getline  (counterIn,  firstLine);
 
  counterIn.close();
  return firstLine;
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
      std::cout <<  foundFileName  <<  std::endl;
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
