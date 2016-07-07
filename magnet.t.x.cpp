#include "Magnet.h"
#include "Utils.h"
#include "Test.h"

#include <iostream>
#include <set>

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

  const auto &latticeSites = magnet.latticeSites();
  const auto &spinValues = magnet.spinValues();

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

bool magnetSaveTest1() {
  using namespace mm;

  std::vector<Vec3> latticeSites = {
      Vec3(0, 0, 0),  Vec3(1, 0, 0),  Vec3(0, 1, 0), Vec3(0, 0, 1),
      Vec3(-1, 0, 0), Vec3(0, -1, 0), Vec3(0, 0, -1)};
  std::vector<int> spinValues = {1, 1, -1, 1, -1, -1, 1};
  const auto magnet = Magnet(latticeSites, spinValues);

  magnet.save("test_saved_magnet.csv");

  const auto magnet2 = Magnet("test_saved_magnet.csv");

  const auto &latticeSites2 = magnet2.latticeSites();
  const auto &spinValues2 = magnet2.spinValues();

  if (spinValues2[0] != 1) return false;
  if (spinValues2[1] != 1) return false;
  if (spinValues2[2] != -1) return false;
  if (spinValues2[3] != 1) return false;
  if (spinValues2[4] != -1) return false;
  if (spinValues2[5] != -1) return false;
  if (spinValues2[6] != 1) return false;

  if (latticeSites2[0] != Vec3(0, 0, 0)) return false;
  if (latticeSites2[1] != Vec3(1, 0, 0)) return false;
  if (latticeSites2[2] != Vec3(0, 1, 0)) return false;
  if (latticeSites2[3] != Vec3(0, 0, 1)) return false;
  if (latticeSites2[4] != Vec3(-1, 0, 0)) return false;
  if (latticeSites2[5] != Vec3(0, -1, 0)) return false;
  if (latticeSites2[6] != Vec3(0, 0, -1)) return false;

  return true;
}

bool magnetSphericalMagnetTest1() {
  using namespace mm;

  //  create a spherical cubic magnet with all spin up and a radius of 1.0
  //  inclusive
  const auto magnet = Magnet::SphericalMagnet(Vec3(1, 0, 0), Vec3(0, 1, 0),
                                              Vec3(0, 0, 1), 1.0, 1);
  std::set<Vec3> expectedLatticePoints(
      {Vec3(0, 0, 0), Vec3(1, 0, 0), Vec3(-1, 0, 0), Vec3(0, 1, 0),
       Vec3(0, -1, 0), Vec3(0, 0, 1), Vec3(0, 0, -1)});
  std::set<Vec3> actualLatticePoints(magnet.latticeSites().cbegin(),
                                     magnet.latticeSites().cend());

  //  if lattice points don't match up
  if (expectedLatticePoints != actualLatticePoints) return false;

  //  test if all spins are up
  for (const auto s : magnet.spinValues())
    if (s != +1) return false;

  return true;
}

bool magnetSphericalMagnetTest2() {
  using namespace mm;

  //  create a spherical cubic magnet with all spin dn and a radius of 2.0
  //  inclusive
  const auto magnet = Magnet::SphericalMagnet(Vec3(1, 0, 0), Vec3(0, 1, 0),
                                              Vec3(0, 0, 1), 1.0, 1);
  std::set<Vec3> expectedLatticePoints(
      {Vec3(-2, 0, 0), Vec3(-1, -1, -1), Vec3(-1, -1, 0), Vec3(-1, -1, 1),
       Vec3(-1, 0, -1), Vec3(-1, 0, 0), Vec3(-1, 0, 1), Vec3(-1, 1, -1),
       Vec3(-1, 1, 0), Vec3(-1, 1, 1), Vec3(0, -2, 0), Vec3(0, -1, -1),
       Vec3(0, -1, 0), Vec3(0, -1, 1), Vec3(0, 0, -2), Vec3(0, 0, -1),
       Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 0, 2), Vec3(0, 1, -1),
       Vec3(0, 1, 0), Vec3(0, 1, 1), Vec3(0, 2, 0), Vec3(1, -1, -1),
       Vec3(1, -1, 0), Vec3(1, -1, 1), Vec3(1, 0, -1), Vec3(1, 0, 0),
       Vec3(1, 0, 1), Vec3(1, 1, -1), Vec3(1, 1, 0), Vec3(1, 1, 1),
       Vec3(2, 0, 0)
      });
  std::set<Vec3> actualLatticePoints(magnet.latticeSites().cbegin(),
                                     magnet.latticeSites().cend());

  //  if lattice points don't match up
  if (expectedLatticePoints != actualLatticePoints) return false;

  //  test if all spins are up
  for (const auto s : magnet.spinValues())
    if (s != +1) return false;

  return true;
}

int main() {
  std::cout << std::endl;
  std::cout << "*** Magnet Tests ***" << std::endl;

  MM_RUNTEST(magnetCtorTest1);
  MM_RUNTEST(magnetCtorTest2);
  MM_RUNTEST(magnetFlipTest1);
  MM_RUNTEST(magnetFlipTest2);
  MM_RUNTEST(magnetSaveTest1);
  MM_RUNTEST(magnetSphericalMagnetTest1);
  MM_RUNTEST(magnetSphericalMagnetTest2);

  return 0;
}
