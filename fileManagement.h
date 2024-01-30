#include<fstream>
#include<cctype>
#include<algorithm>
#include<limits>
#include"book.h"


namespace manage
{
  std::string getExactLine(std::string filename,  int line);
  std::string readAmount(std::string targetFile);
  std::string readCounter();
  std::string toLower(std::string searchTerm);
  std::string getSearchTerm();
  void Search();
}

#endif
