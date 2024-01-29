#include  "fileManagement.h"

std::string readCounter(){

  std::ifstream counterIn("counter.txt");
  
  std::string   firstLine;
  std::getline  (counterIn,  firstLine);
  
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


