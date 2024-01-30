#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<string>
#include<fstream>
#include<cctype>
#include<algorithm>
#include"book.h"

namespace manage
{
  std::string readCounter();
  std::string toLower(std::string searchTerm);
  bool  Search( std::string searchTerm  );
}

#endif
