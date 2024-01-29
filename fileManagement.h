#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include<string>
#include<fstream>
#include"book.h"

class Manage{

public:
  static  std::string   readCounter();
  static  bool          Search( std::string searchedBook  );
};

#endif
