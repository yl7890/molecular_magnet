#include "Utils.h"
#include "Test.h"

#include <cmath>
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
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("");
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("-1.12 foo");
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsDouble("-1.12 1.13");
    (void) resultA; //  turn off -Wall unused variable warning
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
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsInt("1.12");
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  try {
    const auto resultA = mm::stringAsInt("1 foo");
    (void) resultA; //  turn off -Wall unused variable warning
  } catch (const std::runtime_error &err) {
    return true;
  }

  return false;
}

int main() {
  std::cout << std::endl;
  std::cout << "*** Utils Test ***" << std::endl;

  MM_RUNTEST(splitStringTest1);
  MM_RUNTEST(splitStringTest2);
  MM_RUNTEST(stringAsIntTest1);
  MM_RUNTEST(stringAsIntTest2);
  MM_RUNTEST(stringAsDoubleTest1);
  MM_RUNTEST(stringAsDoubleTest2);

  return 0;
}
