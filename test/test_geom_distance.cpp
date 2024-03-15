#define BOOST_TEST_MODULE testGeomDistance
#include <boost/test/unit_test.hpp>

#include "objects/line.hpp"
#include "geometry/distance.hpp"


using gis::GeoPoint;
using gis::Point;
using gis::Line;


BOOST_AUTO_TEST_SUITE(testGeomDistance)

BOOST_AUTO_TEST_CASE(testPointComparation)
{
  Point p1{ 10., 10. };
  Point p2{ 10., 11. };

  BOOST_CHECK(p1 < p2);
}

BOOST_AUTO_TEST_CASE(testPointDistanceEuclideanSquare)
{
  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_euclidean_sq(p1, p2), 18, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceEuclidean)
{
  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_euclidean(p1, p2), 4.2426407, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceManheton)
{
  Point p1{ 13., 10. };
  Point p2{ 10., 13. };

  BOOST_CHECK_CLOSE(distance_manheton(p1, p2), 6, 1e-6);
}

BOOST_AUTO_TEST_CASE(testPointDistanceGreatCircle)
{
  GeoPoint p1{ 55.74, 37.72 }; // Москва
  GeoPoint p2{ 57.16, 65.15 }; // Тюмень

  BOOST_CHECK_CLOSE(distance_great_circle(p1, p2), 1681.5251528, 1e-6);
}

BOOST_AUTO_TEST_CASE(testDistancePointToLine1)
{
  Point p0{ 10.,   0. };
  Point p1{  0., 100. };
  Point p2{  0.,   1. };

  BOOST_CHECK_CLOSE(distance_point2line(p0, {p1, p2}), 10, 1e-3);
}

BOOST_AUTO_TEST_CASE(testDistancePointToLine2)
{
  Point p0{    0., 10.00  };
  Point p1{ 1000.,  0.001 };
  Point p2{ -100.,  0.00  };

  BOOST_CHECK_CLOSE(distance_point2line(p0, {p1, p2}), 9.9999, 1e-3);
}

BOOST_AUTO_TEST_CASE(testDistancePointToLine3)
{
  Point p0{  0.,  0. };
  Point p1{  0., 10. };
  Point p2{ 10.,  0. };

  BOOST_CHECK_CLOSE(distance_point2line(p0, {p1, p2}), 7.0711, 1e-3);
}

BOOST_AUTO_TEST_CASE(testDistancePointToLine4)
{
  Point p0{  0.,  0. };
  Point p1{ 10., 10. };
  Point p2{ 10., 10. };

  BOOST_CHECK_CLOSE(distance_point2line(p0, {p1, p2}), 14.1421, 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
