#ifndef GIS_OBJECTS_OPERATIONS_DISTANCE
#define GIS_OBJECTS_OPERATIONS_DISTANCE

#include <cmath>
#include <numbers>

#include "point.hpp"
#include "line.hpp"


namespace Objects
{

template <typename T>
T distance_euclidean_sq(const Point<T> &lhs, const Point<T> &rhs)
{
  return std::pow(lhs.x-rhs.x, 2) + std::pow(lhs.y-rhs.y, 2);
}

template <typename T>
T distance_euclidean(const Point<T> &lhs, const Point<T> &rhs)
{
  return std::sqrt(distance_euclidean_sq(lhs, rhs));
}

template <typename T>
T distance_manheton(const Point<T> &lhs, const Point<T> &rhs)
{
  return std::abs(lhs.x-rhs.x) + std::abs(lhs.y-rhs.y);
}

template <typename T>
T distance_great_circle(const GeoPoint<T> &lhs, const GeoPoint<T> &rhs)
{
  constexpr double EARTH_RADIUS_KM{ 6371.0 };

  GeoPoint p1 { 
    lhs.lat * std::numbers::pi_v<T> / 180., 
    lhs.lon * std::numbers::pi_v<T> / 180. 
  };

  GeoPoint p2 { 
    rhs.lat * std::numbers::pi_v<T> / 180., 
    rhs.lon * std::numbers::pi_v<T> / 180. 
  };

  GeoPoint delta { 
    std::abs(p2.lat - p1.lat), 
    std::abs(p2.lon - p1.lon) 
  };

  // угол между двумя точками, через гаверсинус (half the versed sine)
  T haversinus_lat = std::pow(std::sin(delta.lat / 2.), 2);
  T haversinus_lon = std::pow(std::sin(delta.lon / 2.), 2);
  T alpha = haversinus_lat + 
            std::cos(p1.lat) * std::cos(p2.lat) * haversinus_lon;

  return EARTH_RADIUS_KM * 2. *
         std::asin(std::min(1., std::sqrt(alpha)));
}

template <typename T>
T distance_point2line(const Point<T> &p, const Line<T> &l)
{
  T dx{ l.p1.x - l.p2.x };
  T dy{ l.p1.y - l.p2.y };
  T a{  dy };
  T b{ -dx };
  T c{ l.p1.y * dx - l.p1.x * dy };
 
  T d{};
  if (!a && !b) {
    // концы отрезка совпадают
    d = distance_euclidean(p, l.p1);
  }
  else {
    d = std::abs(a * p.x + b * p.y + c) / 
        std::sqrt(a * a + b * b);
  }

  return d;
}

}

#endif // GIS_OBJECTS_OPERATIONS_DISTANCE
