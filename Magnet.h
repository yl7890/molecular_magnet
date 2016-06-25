#pragma once

#include "Math.h"

#include <string>
#include <vector>

namespace mm {

class Magnet {
 public:
  /// loads a magnet from a csv file
  /// @param  csvFileName the filename to open
  Magnet(const std::string& csvFileName);

  /// loads a magnet from an array of lattice sites and their spin values
  /// @param  latticeSites  array of lattice site coordinates
  /// @parram spinValues    array of their corresponding spin values
  /// @note   the latticeSites and their spinValues must be in 1-to-1
  ///         correspondance --- in particular, they must be of the same length
  Magnet(const std::vector<Vec3> &latticeSites,
         const std::vector<int> &spinValues);

  /// the lattice sites of the magnet
  const std::vector<Vec3>& latticeSites() const noexcept;

  /// the current spin values of the magnet
  const std::vector<int>& spinValues() const noexcept;

  /// the total number of spins
  size_t numSpins() const noexcept;
  /// the current number of up spins
  size_t numUp() const noexcept;
  /// the currnet number of down spins
  size_t numDn() const noexcept;

  /// flips the spin value at site of the given idx
  /// throws if idx is out of range
  void flipSpin(size_t idx);

  /// saves the current state of the magnet to file
  /// @param  csvFileName the filename to which the state is saved
  void save(const std::string& csvFileName) const;

  Magnet() = default;
  Magnet(const Magnet&) = default;
  Magnet(Magnet&&) = default;
  Magnet& operator=(const Magnet&) = default;
  Magnet& operator=(Magnet&&) = default;

 private:
  void initialize(const std::vector<Vec3> &latticeSites,
                  const std::vector<int> &spinValues);

 private:
  std::vector<Vec3> m_latticeSites;  //  the lattice sites
  std::vector<int> m_spinValues;  //  their spin values (each must be +1 or -1)

  size_t m_numUp = 0;  //  number of up spins;
  size_t m_numDn = 0;  //  number of dn spins;
};

}  //  end namespace 'mm'

#include "Magnet.ipp"
