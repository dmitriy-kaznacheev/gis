#define BOOST_TEST_MODULE testGeomArea
#include <boost/test/unit_test.hpp>

#include "objects/polygon.hpp"
#include "geometry/area.hpp"

using gis::Point;
using gis::Polygon;


BOOST_AUTO_TEST_SUITE(testGeomArea)

BOOST_AUTO_TEST_CASE(testAreaPolygonTrapezoids)
{
  Polygon polygon {
      Point{10., 20.}, Point{20., 20.},  
      Point{20., 10.}, Point{10., 10.},
      Point{10., 20.},
  };

  BOOST_CHECK_CLOSE(area_polygon_trapezoids(std::move(polygon)), 100, 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
