#ifndef GIS_OBJECTS_POLYGON
#define GIS_OBJECTS_POLYGON

#include <ostream>
#include <vector>
#include "point.hpp"

namespace gis
{

// TODO инкапсулировать инварианты: сортированость узлов и замкнутость
template <typename T>
using Polygon = std::vector<Point<T>>;

}

#endif // GIS_OBJECTS_POLYGON
