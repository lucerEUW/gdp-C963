#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <vector>
#include "book.h"

namespace manage
{
  std::string getExactLine(const std::string& filename,  int line);

  std::string readAmount(std::string targetFile);
  void UpdateAmount(std::string targetFile,  int action, int amount);

  std::string readCounter();
  void UpdateCounter(int action, int amount);

  std::string toLower(std::string searchTerm);

  std::string getSearchTerm();
  void Search();
}

#endif
