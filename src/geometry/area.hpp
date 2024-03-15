#ifndef GIS_OBJECTS_OPERATIONS_AREA
#define GIS_OBJECTS_OPERATIONS_AREA

#include <stdexcept>
#include "polygon.hpp"


namespace gis
{

template <typename T>
T area_polygon_trapezoids(Polygon<T> &&polygon)
{
  size_t len = polygon.size();
  if (len < 3) 
    throw std::invalid_argument("Полигон должен иметь минмум 3 точки.");

  T dbl_area{};
  for (size_t i=0; i != len-1; ++i) {
    T dlb_trapezoid_area = polygon[i].x * polygon[i+1].y -
                           polygon[i+1].x * polygon[i].y;
    dbl_area += dlb_trapezoid_area;
  }
  return std::abs(dbl_area) / 2.0;
}

}

#endif // GIS_OBJECTS_OPERATIONS_AREA
