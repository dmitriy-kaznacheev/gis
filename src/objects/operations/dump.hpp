#ifndef GIS_OBJECTS_OPERATIONS_DUMP
#define GIS_OBJECTS_OPERATIONS_DUMP

#include <ostream>

#include "point.hpp"


namespace Objects
{

template <typename Object>
std::ostream &operator<<(std::ostream &os, const Object &obj)
{
  obj.dump(os);
  return os;
}

}

#endif // GIS_OBJECTS_OPERATIONS_DUMP
