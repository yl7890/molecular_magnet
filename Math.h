#pragma once

#include <cmath>
#include <tuple>

namespace mm {

static constexpr double EPSILON = 0.0000000001; //  1e-10

/// typedef for a simple 3-vector
using Vec3 = std::tuple<double, double, double>;

/// overloaded Vec3 add Vec3
Vec3 operator+(const Vec3& v1, const Vec3& v2) noexcept;
/// overloaded Vec3 subtract Vec3
Vec3 operator-(const Vec3& v1, const Vec3& v2) noexcept;
/// overloaded scalar times Vec3
Vec3 operator*(double a, const Vec3& v) noexcept;
/// overloaded Vec3 equality
bool operator==(const Vec3& v1, const Vec3& v2) noexcept;


} //  end namespace 'mm'

#include "Math.ipp"
