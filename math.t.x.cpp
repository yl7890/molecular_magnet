#include "Math.h"
#include "Test.h"

#include <cmath>


bool vec3SumTest1() {
  using namespace mm;
  const auto vecA = Vec3(0.1, 0.2, -0.3);
  const auto vecB = Vec3(-1, -2, 3);

  const auto vecC = vecA + vecB;
  
  if(std::abs(getX(vecC) - (-0.9)) > EPSILON) return false;
  if(std::abs(getY(vecC) - (-1.8)) > EPSILON) return false;
  if(std::abs(getZ(vecC) - (2.7)) > EPSILON) return false;
  return true;
}

bool vec3DiffTest1() {
  using namespace mm;
  const auto vecA = Vec3(0.1, 0.2, -0.3);
  const auto vecB = Vec3(-1, -2, 3);

  const auto vecC = vecA - vecB;
  
  if(std::abs(getX(vecC) - (1.1)) > EPSILON) return false;
  if(std::abs(getY(vecC) - (2.2)) > EPSILON) return false;
  if(std::abs(getZ(vecC) - (-3.3)) > EPSILON) return false;
  return true;
}

bool vec3ScalarMultTest1() {
  using namespace mm;
  const auto vecA = Vec3(0.1, 0.2, -0.3);

  const auto vecC = 2.0 * vecA;
  
  if(std::abs(getX(vecC) - (0.2)) > EPSILON) return false;
  if(std::abs(getY(vecC) - (0.4)) > EPSILON) return false;
  if(std::abs(getZ(vecC) - (-0.6)) > EPSILON) return false;
  return true;
}

bool vec3ScalarMultTest2() {
  using namespace mm;
  const auto vecA = Vec3(0.1, 0.2, -0.3);

  const auto vecC = 0.0 * vecA;
  
  if(std::abs(getX(vecC) - (0.0)) > EPSILON) return false;
  if(std::abs(getY(vecC) - (0.0)) > EPSILON) return false;
  if(std::abs(getZ(vecC) - (0.0)) > EPSILON) return false;
  return true;
}

bool vec3AssignmentTest1() {
  using namespace mm;
  auto vecA = Vec3(0.1, 0.2, -0.3);
  getX(vecA) = 1.0;
  getY(vecA) = 2.0;
  getZ(vecA) = -3.0;
  
  if(std::abs(getX(vecA) - (1.0)) > EPSILON) return false;
  if(std::abs(getY(vecA) - (2.0)) > EPSILON) return false;
  if(std::abs(getZ(vecA) - (-3.0)) > EPSILON) return false;
  return true;
}


int main() {
  std::cout << "*** Math Test ***" << std::endl;

  MM_RUNTEST(vec3SumTest1);
  MM_RUNTEST(vec3DiffTest1);
  MM_RUNTEST(vec3ScalarMultTest1);
  MM_RUNTEST(vec3ScalarMultTest2);
  MM_RUNTEST(vec3AssignmentTest1);

  return 0;
}
