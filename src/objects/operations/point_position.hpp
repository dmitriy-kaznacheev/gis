#ifndef GIS_OBJECTS_OPERATIONS_POINT_POSITION
#define GIS_OBJECTS_OPERATIONS_POINT_POSITION

#include <vector>
#include <stdexcept>
#include "point.hpp"


namespace Objects
{

template <typename T>
Point<T> centroid_polygon(std::vector<Point<T>> &&polygon)
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

}

#endif // GIS_OBJECTS_OPERATIONS_POINT_POSITION
