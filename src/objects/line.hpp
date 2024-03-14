#ifndef GIS_OBJECTS_LINE
#define GIS_OBJECTS_LINE

#include <ostream>
#include "point.hpp"

namespace Objects
{

template <typename T>
struct Line final
{
  Point<T> p1{}, p2{};

  auto operator<=>(const Line<T> &rhs) const = default;

  void dump(std::ostream &os) const
  {
    os << "Line[" << p1 << "; " << p2 << "]";
  }
};

}

#endif // GIS_OBJECTS_LINE
