#include<iostream>
#include"../include/fileManagement.h"

namespace manage{

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

bool Search(std::string searchTerm)
{
  bool found  = false;
  std::string filename;
  searchTerm  = toLower(searchTerm);

  for(const auto  & entry : std::filesystem::directory_iterator("books/")){
      
    filename = entry.path().filename().string();
      
    if(filename.find(searchTerm)  !=  std::string::npos){
      std::cout <<  filename  <<  std::endl;
      found = true;
    }
  }
  return found;
}
}

