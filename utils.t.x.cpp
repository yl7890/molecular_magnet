#include "Utils.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

bool splitStringTest1() {
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

bool splitStringTest2() {
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

bool stringAsDoubleTest1() {
  const auto resultA = mm::stringAsDouble("1");
  if (std::abs(resultA - (1.0)) > 1e-12) return false;

  const auto resultB = mm::stringAsDouble("-1");
  if (std::abs(resultB - (-1.0)) > 1e-12) return false;

  const auto resultC = mm::stringAsDouble("-1.12");
  if (std::abs(resultC - (-1.12)) > 1e-12) return false;

  return true;
}

bool stringAsDoubleTest2() {
  try {
    const auto resultA = mm::stringAsDouble("foo");
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("");
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("-1.12 foo");
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("-1.12 1.13");
  } catch (const std::runtime_error &err) {
    return true;
  }

  return false;
}

bool stringAsIntTest1() {
  const auto resultA = mm::stringAsInt("1");
  if (resultA != 1) return false;

  const auto resultB = mm::stringAsInt("-1");
  if (resultB != -1) return false;

  const auto resultC = mm::stringAsInt("-65536");
  if (resultC != -65536) return false;

  return true;
}

bool stringAsIntTest2() {
  try {
    const auto resultA = mm::stringAsInt("foo");
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsInt("1.12");
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsInt("1 foo");
  } catch (const std::runtime_error &err) {
    return true;
  }

  return false;
}

int main() {
  std::cout << "*** Utils Test ***" << std::endl;

  std::cout << std::left << std::setw(32) << "splitStringTest1...";
  std::cout << (splitStringTest1() ? "passed" : "FAILED *") << std::endl;

  std::cout << std::left << std::setw(32) << "splitStringTest2...";
  std::cout << (splitStringTest2() ? "passed" : "FAILED *") << std::endl;

  std::cout << std::left << std::setw(32) << "stringAsIntTest1...";
  std::cout << (stringAsIntTest1() ? "passed" : "FAILED *") << std::endl;

  std::cout << std::left << std::setw(32) << "stringAsIntTest2...";
  std::cout << (stringAsIntTest2() ? "passed" : "FAILED *") << std::endl;

  std::cout << std::left << std::setw(32) << "stringAsDoubleTest1...";
  std::cout << (stringAsDoubleTest1() ? "passed" : "FAILED *") << std::endl;

  std::cout << std::left << std::setw(32) << "stringAsDoubleTest2...";
  std::cout << (stringAsDoubleTest2() ? "passed" : "FAILED *") << std::endl;

  return 0;
}
