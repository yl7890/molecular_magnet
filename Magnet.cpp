#include "Magnet.h"
#include "Utils.h"

#include <ctime>
#include <fstream>
#include <stdexcept>
#include <string>

namespace mm {

void Magnet::initialize(const std::vector<Vec3> &latticeSites,
                        const std::vector<int> &spinValues) {
  //  check both are of the same length
  if (latticeSites.size() != spinValues.size())
    throw std::runtime_error(
        "latticeSites.size() (=" + std::to_string(latticeSites.size()) +
        ") and spinValues.size() (=" + std::to_string(spinValues.size()) +
        ") are not of the same size");
  if (latticeSites.empty()) throw std::runtime_error("latticeSites is empty");

  //  check that spin values are valid
  for (const auto &s : m_spinValues) {
    if ((s != 1) && (s != -1))
      throw std::runtime_error("not all spin values are either +1 or -1");
  }

  //  assign the lattice and spin values
  m_latticeSites = latticeSites;
  m_spinValues = spinValues;

  //  compute the number of up and down spins
  m_numUp = 0;
  m_numDn = 0;
  for (const auto &s : m_spinValues) {
    if (s == 1)
      ++m_numUp;
    else if (s == -1)
      ++m_numDn;
  }
}

Magnet::Magnet(const std::vector<Vec3> &latticeSites,
               const std::vector<int> &spinValues) {
  initialize(latticeSites, spinValues);
}

Magnet::Magnet(const std::string &csvFileName) {
  //  try opening the csvFile
  std::ifstream csvFile;
  csvFile.open(csvFileName);
  if (!csvFile.is_open())
    throw std::runtime_error("unable to load magnet from csv file " +
                             csvFileName);

  //  at this point we've opened the file successfully.
  //  we assume that the lines of the csv file are in the format of
  //
  //  site_x_value,site_y_value,site_z_value,spin_value
  //
  //  with one line of header, and no spaces

  std::string currentLine;
  size_t currentLineCount = 0;
  //  read in the header and ignore
  ++currentLineCount;
  std::getline(csvFile, currentLine);

  //  read in the rest of the lines and extract the lattice sites and
  //  spin values
  std::vector<Vec3> latticeSites;
  std::vector<int> spinValues;
  while (std::getline(csvFile, currentLine)) {
    ++currentLineCount;
    const auto splitStr = splitString(currentLine, ',');
    if (splitStr.size() != 4)
      throw std::runtime_error("invalid csv line at line number " +
                               std::to_string(currentLineCount) + ":\n" +
                               currentLine);

    const auto x = stringAsDouble(splitStr[0]);
    const auto y = stringAsDouble(splitStr[1]);
    const auto z = stringAsDouble(splitStr[2]);
    const auto s = stringAsInt(splitStr[3]);

    latticeSites.emplace_back(Vec3(x, y, z));
    spinValues.emplace_back(s);
  }  //  end while loop

  csvFile.close();

  initialize(latticeSites, spinValues);
}

void Magnet::save(const std::string &csvFileName) const {
  //  try opening the file
  std::ofstream csvFile;
  csvFile.open(csvFileName);
  if (!csvFile.is_open())
    throw std::runtime_error("unable to open csv file " + csvFileName +
                             " for saving");

  //  write header
  csvFile << "x,y,z,s" << std::endl;

  for (size_t idx = 0; idx < numSpins(); ++idx) {
    const auto &site = m_latticeSites[idx];
    const auto spin = m_spinValues[idx];
    csvFile << std::to_string(getX(site)) << ",";
    csvFile << std::to_string(getY(site)) << ",";
    csvFile << std::to_string(getZ(site)) << ",";
    csvFile << std::to_string(spin) << std::endl;
  }

  csvFile.close();
}

Magnet Magnet::SphericalMagnet(const Vec3 &axis1, const Vec3 &axis2,
                               const Vec3 &axis3, double radius,
                               int initialSpin) {
  //  some input validation
  if (radius < EPSILON)
    throw std::runtime_error("invalid value of radius' (=" +
                             std::to_string(radius) + ")");
  if ((initialSpin != 1) && (initialSpin != -1) && (initialSpin != 0))
    throw std::runtime_error("invalid value of initialSpin (=" +
                             std::to_string(initialSpin) +
                             "), only +1, 0, or -1 allowed");

  RandomSpinGenerator rsg;

  std::vector<Vec3> latticeSites;
  std::vector<int> spinValues;

  /*
      your code here
   */

  return Magnet(latticeSites, spinValues);
}

}  //  end namespace 'mm'
