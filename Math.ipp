namespace mm {

inline double& getX(Vec3& v) noexcept { return std::get<0>(v); }
inline double getX(const Vec3& v) noexcept { return std::get<0>(v); }
inline double& getY(Vec3& v) noexcept { return std::get<1>(v); }
inline double getY(const Vec3& v) noexcept { return std::get<1>(v); }
inline double& getZ(Vec3& v) noexcept { return std::get<2>(v); }
inline double getZ(const Vec3& v) noexcept { return std::get<2>(v); }

inline Vec3 operator+(const Vec3& v1, const Vec3& v2) noexcept {
  Vec3 u;
  getX(u) = getX(v1) + getX(v2);
  getY(u) = getY(v1) + getY(v2);
  getZ(u) = getZ(v1) + getZ(v2);
  return u;
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2) noexcept {
  Vec3 u;
  getX(u) = getX(v1) - getX(v2);
  getY(u) = getY(v1) - getY(v2);
  getZ(u) = getZ(v1) - getZ(v2);
  return u;
}

inline Vec3 operator*(double a, const Vec3& v) noexcept {
  Vec3 u;
  getX(u) = a * getX(v);
  getY(u) = a * getY(v);
  getZ(u) = a * getZ(v);
  return u;
}

inline bool operator==(const Vec3& v1, const Vec3& v2) noexcept {
  return (std::abs(getX(v1) - getX(v2)) < EPSILON) &&
         (std::abs(getY(v1) - getY(v2)) < EPSILON) &&
         (std::abs(getZ(v1) - getZ(v2)) < EPSILON);
}

}  //  end namespace 'mm'
