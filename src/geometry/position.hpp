#ifndef GIS_OBJECTS_OPERATIONS_POINT_POSITION
#define GIS_OBJECTS_OPERATIONS_POINT_POSITION

#include <stdexcept>
#include "line.hpp"
#include "point.hpp"
#include "polygon.hpp"
#include "area.hpp"


namespace gis
{

enum class Position { LEFT, RIGHT, ON };

template <typename T>
Point<T> centroid_polygon(Polygon<T> &&polygon)
{
  size_t len = polygon.size();
  if (len < 3) 
    throw std::invalid_argument("Полигон должен иметь минмум 3 точки.");

  T dbl_area{};
  Point<T> centroid{};
  for (size_t i=0; i != len-1; ++i) {
    T dlb_trapezoid_area = polygon[i].x * polygon[i+1].y -
                           polygon[i+1].x * polygon[i].y;
    dbl_area += dlb_trapezoid_area;
    centroid.x += (polygon[i+1].x + polygon[i].x) * dlb_trapezoid_area;
    centroid.y += (polygon[i+1].y + polygon[i].y) * dlb_trapezoid_area;
  }

  centroid.x /= 3.0 * dbl_area;
  centroid.y /= 3.0 * dbl_area;
  return centroid;
}

template <typename T>
Position point_relative_line(const Point<T> &p, const Line<T> &l)
{
  Polygon triangle{ p, l.p2, l.p1, p };
  T area = area_polygon_trapezoids_signed(std::move(triangle));
  
  return (area < 0.) ? Position::LEFT
                     : (area > 0.) ? Position::RIGHT
                                   : Position::ON;
}

}

#endif // GIS_OBJECTS_OPERATIONS_POINT_POSITION
