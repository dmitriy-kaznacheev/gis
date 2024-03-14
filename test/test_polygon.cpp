#define BOOST_TEST_MODULE testObjectPolygon
#include <boost/test/unit_test.hpp>

#include "point.hpp"
#include "operations/area.hpp"


using Objects::Point;


BOOST_AUTO_TEST_SUITE(testObjectPolygon)

BOOST_AUTO_TEST_CASE(testAreaPolygonTrapezoids)
{
  std::vector polygon {
      Point{ 0., 10.}, Point{ 5.,  0.}, Point{10., 10.}, Point{15.,  0.}, Point{20., 10.}, 
      Point{25.,  0.}, Point{30., 20.}, Point{40., 20.}, Point{45.,  0.}, Point{50., 50.},
      Point{40., 40.}, Point{30., 50.}, Point{25., 20.}, Point{20., 50.}, Point{15., 10.},
      Point{10., 50.}, Point{ 8.,  8.}, Point{ 4., 50.}, Point{ 0., 10.}
  };

  BOOST_CHECK_CLOSE(area_polygon_trapezoids(std::move(polygon)), 1294, 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
