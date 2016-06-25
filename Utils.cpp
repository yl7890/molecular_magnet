#include "Utils.h"

#include <sstream>

namespace mm {

std::vector<std::string> splitString(const std::string& line,
                                     char token /* = ',' */) {
  std::vector<std::string> out;
  std::stringstream lineStream(line);

  std::string tempString;
  while (std::getline(lineStream, tempString, token)) out.push_back(tempString);
  return out;
}

}  //  end namespace 'mm'
