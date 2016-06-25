#include "Utils.h"

#include <cmath>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace mm {

std::vector<std::string> splitString(const std::string &line,
                                     char token /* = ',' */) {
  std::vector<std::string> out;
  std::stringstream lineStream(line);

  std::string tempString;
  while (std::getline(lineStream, tempString, token)) out.push_back(tempString);
  return out;
}

int stringAsInt(const std::string &str) {
  auto asInt = std::numeric_limits<int>::max();
  size_t pos = 0;

  try {
    asInt = std::stoi(str, &pos);
  } catch (const std::invalid_argument &err) {
    throw std::runtime_error("unable to parse the string \'" + str +
                             "\' as an integer");
  } catch (const std::out_of_range &err) {
    throw std::runtime_error(
        "the string \'" + str +
        "\' is out of the range of representable integers");
  }
  const auto asDouble = stringAsDouble(str);
  if (std::abs(asInt - asDouble) > 1e-12) {
    throw std::runtime_error("unable to parse the string \'" + str +
                             "\' as an integer");
  }
  if (pos != str.size()) {
    throw std::runtime_error("the string \'" + str +
                             "\' contains extraneous information");
  }
  return asInt;
}

double stringAsDouble(const std::string &str) {
  auto asDouble = std::numeric_limits<double>::quiet_NaN();
  size_t pos = 0;
  try {
    asDouble = std::stod(str, &pos);
  } catch (const std::invalid_argument &err) {
    throw std::runtime_error("unable to parse the string \'" + str +
                             "\' as a double");
  } catch (const std::out_of_range &err) {
    throw std::runtime_error("the string \'" + str +
                             "\' is out of the range of representable doubles");
  }
  if (pos != str.size()) {
    throw std::runtime_error("the string \'" + str +
                             "\' contains extraneous information");
  }
  return asDouble;
}

}  //  end namespace 'mm'
