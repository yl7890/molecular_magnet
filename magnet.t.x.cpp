#include "Magnet.h"
#include "Utils.h"
#include "Test.h"

#include <iostream>

bool magnetCtorTest1() {
  using namespace mm;

  std::vector<Vec3> latticeSites = {
      Vec3(0, 0, 0),  Vec3(1, 0, 0),  Vec3(0, 1, 0), Vec3(0, 0, 1),
      Vec3(-1, 0, 0), Vec3(0, -1, 0), Vec3(0, 0, -1)};
  std::vector<int> spinValues = {1, 1, -1, 1, -1, -1, 1};
  const auto magnet = Magnet(latticeSites, spinValues);
  if (magnet.numSpins() != 7) return false;
  if (magnet.numUp() != 4) return false;
  if (magnet.numDn() != 3) return false;

  return true;
}

bool magnetCtorTest2() {
  using namespace mm;

  const auto magnet = Magnet("test_magnet.csv");
  if (magnet.numSpins() != 7) return false;
  if (magnet.numUp() != 4) return false;
  if (magnet.numDn() != 3) return false;

  const auto& latticeSites = magnet.latticeSites();
  const auto& spinValues = magnet.spinValues();

  if (spinValues[0] != 1) return false;
  if (spinValues[1] != 1) return false;
  if (spinValues[2] != -1) return false;
  if (spinValues[3] != 1) return false;
  if (spinValues[4] != -1) return false;
  if (spinValues[5] != -1) return false;
  if (spinValues[6] != 1) return false;

  if (latticeSites[0] != Vec3(0, 0, 0)) return false;
  if (latticeSites[1] != Vec3(1, 0, 0)) return false;
  if (latticeSites[2] != Vec3(0, 1, 0)) return false;
  if (latticeSites[3] != Vec3(0, 0, 1)) return false;
  if (latticeSites[4] != Vec3(-1, 0, 0)) return false;
  if (latticeSites[5] != Vec3(0, -1, 0)) return false;
  if (latticeSites[6] != Vec3(0, 0, -1)) return false;

  return true;
}

bool magnetFlipTest1() {
  using namespace mm;

  std::vector<Vec3> latticeSites = {
      Vec3(0, 0, 0),  Vec3(1, 0, 0),  Vec3(0, 1, 0), Vec3(0, 0, 1),
      Vec3(-1, 0, 0), Vec3(0, -1, 0), Vec3(0, 0, -1)};
  std::vector<int> spinValues = {1, 1, -1, 1, -1, -1, 1};

  auto magnet = Magnet(latticeSites, spinValues);

  if (magnet.spinValues()[2] != -1) return false;
  magnet.flipSpin(2);
  if (magnet.spinValues()[2] != 1) return false;
  if (magnet.numUp() != 5) return false;
  if (magnet.numDn() != 2) return false;

  return true;
}

bool magnetFlipTest2() {
  using namespace mm;

  std::vector<Vec3> latticeSites = {
      Vec3(0, 0, 0),  Vec3(1, 0, 0),  Vec3(0, 1, 0), Vec3(0, 0, 1),
      Vec3(-1, 0, 0), Vec3(0, -1, 0), Vec3(0, 0, -1)};
  std::vector<int> spinValues = {1, 1, -1, 1, -1, -1, 1};

  auto magnet = Magnet(latticeSites, spinValues);

  if (magnet.spinValues()[6] != 1) return false;
  magnet.flipSpin(6);
  if (magnet.spinValues()[6] != -1) return false;
  if (magnet.numUp() != 3) return false;
  if (magnet.numDn() != 4) return false;

  return true;
}

int main() {
  std::cout << "*** Magnet Tests ***" << std::endl;

  MM_RUNTEST(magnetCtorTest1);
  MM_RUNTEST(magnetCtorTest2);
  MM_RUNTEST(magnetFlipTest1);
  MM_RUNTEST(magnetFlipTest2);

  return 0;
}
