#include "Utils.h"

#include <iomanip>
#include <iostream>

bool test1() {
  const auto testStr = "this,is,a,test,string";
  const auto result = mm::splitString(testStr);
  if (result.size() != 5) return false;
  if (result[0] != "this") return false;
  if (result[1] != "is") return false;
  if (result[2] != "a") return false;
  if (result[3] != "test") return false;
  if (result[4] != "string") return false;
  return true;
}

bool test2() {
  const auto testStr = "this+is+a+test+string";
  const auto result = mm::splitString(testStr, '+');
  if (result.size() != 5) return false;
  if (result[0] != "this") return false;
  if (result[1] != "is") return false;
  if (result[2] != "a") return false;
  if (result[3] != "test") return false;
  if (result[4] != "string") return false;
  return true;
}

int main() {
  std::cout << "*** Utils Test ***" << std::endl;

  std::cout << std::left << std::setw(16) << "test 1...";
  std::cout << (test1() ? "passed" : "FAILED*") << std::endl;

  std::cout << std::left << std::setw(16) << "test 2...";
  std::cout << (test2() ? "passed" : "FAILED*") << std::endl;

  return 0;
}
