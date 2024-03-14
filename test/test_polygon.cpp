#define BOOST_TEST_MODULE testObjectPolygon
#include <boost/test/unit_test.hpp>

#include "point.hpp"
#include "operations/area.hpp"
#include "operations/distance.hpp"
#include "operations/point_position.hpp"
#include "operations/dump.hpp"

using Objects::Point;


BOOST_AUTO_TEST_SUITE(testObjectPolygon)

BOOST_AUTO_TEST_CASE(testAreaPolygonTrapezoids)
{
  std::vector polygon {
      Point{10., 20.}, Point{20., 20.},  
      Point{20., 10.}, Point{10., 10.},
      Point{10., 20.},
  };

  BOOST_CHECK_CLOSE(area_polygon_trapezoids(std::move(polygon)), 100, 1e-3);
}

BOOST_AUTO_TEST_CASE(testCentoidPolygon)
{
  std::vector polygon {
    Point{10., 20.}, Point{20., 20.},
    Point{20., 10.}, Point{10., 10.},
    Point{10., 20.},
  };

  BOOST_CHECK((centroid_polygon(std::move(polygon)) == Point{ 15., 15. }));
}


BOOST_AUTO_TEST_SUITE_END()
