namespace mm {

inline const std::vector<Vec3>& Magnet::latticeSites() const noexcept {
  return m_latticeSites;
}
inline const std::vector<int>& Magnet::spinValues() const noexcept {
  return m_spinValues;
}

inline size_t Magnet::numSpins() const noexcept { return m_spinValues.size(); }
inline size_t Magnet::numUp() const noexcept { return m_numUp; }
inline size_t Magnet::numDn() const noexcept { return m_numDn; }

inline void Magnet::flipSpin(size_t idx) {

  //  access the value of the spin at 'idx'.
  //  throws std::out_of_range if 'idx' is >= the number of spins
  auto& spinVal = m_spinValues.at(idx);

  m_numUp -= spinVal; //  if spinVal == 1, m_numUp decreases by 1,
                      //  and if spinVal == -1, m_numUp increases by 1

  m_numDn += spinVal; //  if spinVal == 1, m_numDn increases by 1,
                      //  and if spinVal == -1, m_numDn decreases by 1

  spinVal *= -1;  //  flip the spin's sign
}

}  //  end namespace 'mm'
