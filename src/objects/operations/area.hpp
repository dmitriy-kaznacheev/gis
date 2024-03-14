#ifndef GIS_OBJECTS_OPERATIONS_AREA
#define GIS_OBJECTS_OPERATIONS_AREA

#include <vector>
#include "point.hpp"


namespace Objects
{

template <typename T>
T area_polygon_trapezoids(std::vector<Objects::Point<T>> &&polygon)
{
  size_t len = polygon.size();
  if (len < 3) 
    return 0.;

  const Objects::Point<T> &beg = polygon.front();
  const Objects::Point<T> &end = polygon.back();
  if (beg != end) {
    polygon.push_back(beg);
  }

  T dbl_area{};
  for (size_t i=0; i != len-1; ++i) {
    T dlb_trapezoid_area = polygon[i].x * polygon[i+1].y -
                           polygon[i+1].x * polygon[i].y;
    dbl_area += dlb_trapezoid_area;
  }
  return dbl_area / 2.0;
}

}

#endif // GIS_OBJECTS_OPERATIONS_AREA
