#define BOOST_TEST_MODULE testGeomPosition
#include <boost/test/unit_test.hpp>

#include "objects/polygon.hpp"
#include "geometry/position.hpp"

using gis::Point;
using gis::Line;
using gis::Polygon;
using POS = gis::Position;


BOOST_AUTO_TEST_SUITE(testGeomPosition)

BOOST_AUTO_TEST_CASE(testCentoidPolygon)
{
  Polygon polygon {
    Point{10., 20.}, Point{20., 20.},
    Point{20., 10.}, Point{10., 10.},
    Point{10., 20.},
  };

  BOOST_CHECK((centroid_polygon(std::move(polygon)) == Point{ 15., 15. }));
}

BOOST_AUTO_TEST_CASE(testPointRelativeLine1)
{
  Point p{1., 1.};
  Line l {
    Point{0., 0.},
    Point{1., 0.}
  };

  BOOST_CHECK(point_relative_line(p, l) ==  POS::LEFT);
}

BOOST_AUTO_TEST_CASE(testPointRelativeLine2)
{
  Point p{1., 1.};
  Line l {
    Point{1., 0.},
    Point{0., 0.}
  };

  BOOST_CHECK(point_relative_line(p, l) ==  POS::RIGHT);
}

BOOST_AUTO_TEST_CASE(testPointRelativeLine3)
{
  Point p{0.5, 0.};
  Line l {
    Point{0., 0.},
    Point{1., 0.}
  };

  BOOST_CHECK(point_relative_line(p, l) ==  POS::ON);
}

BOOST_AUTO_TEST_CASE(testPointRelativeLine4)
{
  Point p{0.5, 0.};
  Line l {
    Point{1., 0.},
    Point{0., 0.}
  };

  BOOST_CHECK(point_relative_line(p, l) ==  POS::ON);
}


BOOST_AUTO_TEST_SUITE_END()
