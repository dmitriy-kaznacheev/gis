#define BOOST_TEST_MODULE testObjectPoint
#include <boost/test/unit_test.hpp>

#include "point.hpp"
#include "operations/distance.hpp"


BOOST_AUTO_TEST_SUITE(testObjectPoint)

BOOST_AUTO_TEST_CASE(testPointComparation)
{
  using Objects::Point;

  Point p1{ 10., 10. };
  Point p2{ 10., 11. };

  BOOST_CHECK(p1 < p2);
}

BOOST_AUTO_TEST_CASE(testPointDistanceEuclideanSquare)
{
  using Objects::Point;

  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_euclidean_sq(p1, p2), 18, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceEuclidean)
{
  using Objects::Point;

  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_euclidean(p1, p2), 4.2426407, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceManheton)
{
  using Objects::Point;

  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_manheton(p1, p2), 6, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceGreatCircle)
{
  using Objects::GeoPoint;

  GeoPoint p1{ 55.74, 37.72 }; // Москва
  GeoPoint p2{ 57.16, 65.15 }; // Тюмень

  BOOST_CHECK_CLOSE(distance_great_circle(p1, p2), 1681.5251528, 1e-6);
}


BOOST_AUTO_TEST_SUITE_END()
