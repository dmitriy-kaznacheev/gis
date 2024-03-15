#ifndef GIS_OBJECTS_OPERATIONS_DUMP
#define GIS_OBJECTS_OPERATIONS_DUMP

#include <ostream>

#include "point.hpp"


namespace gis
{

template <typename Object>
std::ostream &operator<<(std::ostream &os, const std::vector<Object> &vobj)
{
  os << "{ ";
  for (auto &&obj : vobj) {
    obj.dump(os);
    os << " ";
  }
  os << "}";
  return os;
}

template <typename Object>
std::ostream &operator<<(std::ostream &os, const Object &obj)
{
  obj.dump(os);
  return os;
}

}

#endif // GIS_OBJECTS_OPERATIONS_DUMP
