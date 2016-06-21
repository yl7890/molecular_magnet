namespace mm {

inline Vec3 operator+(const Vec3& v1, const Vec3& v2) noexcept {
  Vec3 u;
  std::get<0>(u) = std::get<0>(v1) + std::get<0>(v2);
  std::get<1>(u) = std::get<1>(v1) + std::get<1>(v2);
  std::get<2>(u) = std::get<2>(v1) + std::get<2>(v2);
  return u;
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2) noexcept {
  Vec3 u;
  std::get<0>(u) = std::get<0>(v1) - std::get<0>(v2);
  std::get<1>(u) = std::get<1>(v1) - std::get<1>(v2);
  std::get<2>(u) = std::get<2>(v1) - std::get<2>(v2);
  return u;
}

inline Vec3 operator*(double a, const Vec3& v) noexcept {
  Vec3 u;
  std::get<0>(u) = a * std::get<0>(v);
  std::get<1>(u) = a * std::get<1>(v);
  std::get<2>(u) = a * std::get<2>(v);
  return u;
}

inline bool operator==(const Vec3& v1, const Vec3& v2) noexcept {
  return (std::get<0>(v1) == std::get<0>(v2)) &&
         (std::get<1>(v1) == std::get<1>(v2)) &&
         (std::get<2>(v1) == std::get<2>(v2));
}

}  //  end namespace 'mm'
