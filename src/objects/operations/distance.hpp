#ifndef GIS_OBJECTS_OPERATIONS_DISTANCE
#define GIS_OBJECTS_OPERATIONS_DISTANCE

#include <cmath>
#include <numbers>

#include "point.hpp"


namespace Objects
{

template <typename T>
T distance_euclidean_sq(const Objects::Point<T> &lhs, const Objects::Point<T> &rhs)
{
  return std::pow(lhs.x-rhs.x, 2) + std::pow(lhs.y-rhs.y, 2);
}

template <typename T>
T distance_euclidean(const Objects::Point<T> &lhs, const Objects::Point<T> &rhs)
{
  return std::sqrt(distance_euclidean_sq(lhs, rhs));
}

template <typename T>
T distance_manheton(const Objects::Point<T> &lhs, const Objects::Point<T> &rhs)
{
  return std::abs(lhs.x-rhs.x) + std::abs(lhs.y-rhs.y);
}

template <typename T>
T distance_great_circle(const Objects::GeoPoint<T> &lhs, const Objects::GeoPoint<T> &rhs)
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
  double haversinus_lat = std::pow(std::sin(delta.lat / 2.), 2);
  double haversinus_lon = std::pow(std::sin(delta.lon / 2.), 2);
  double alpha = haversinus_lat + 
                 std::cos(p1.lat) * std::cos(p2.lat) * haversinus_lon;

  return EARTH_RADIUS_KM * 2. *
         std::asin(std::min(1., std::sqrt(alpha)));
}

}

#endif // GIS_OBJECTS_OPERATIONS_DISTANCE
