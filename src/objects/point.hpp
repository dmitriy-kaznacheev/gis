#ifndef GIS_OBJECTS_POINT
#define GIS_OBJECTS_POINT

#include <ostream>


namespace Objects
{

template <typename T>
struct Point final
{
  T x{}, y{};

  auto operator<=>(const Point<T> &rhs) const = default;

  void dump(std::ostream &os) const
  {
    os << "Point(" << x << ", " << y << ")";
  }
};

template <typename T>
struct GeoPoint final
{
  T lat{}, lon{};

  auto operator<=>(const GeoPoint<T> &rhs) const = default;

  void dump(std::ostream &os) const
  {
    os << "GeoPoint(" << lat << "\u00B0" << ", " << lon << "\u00B0" << ")";
  }
};


}

#endif // GIS_OBJECTS_POINT
