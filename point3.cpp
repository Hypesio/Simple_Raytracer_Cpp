#include "point3.h"

std::ostream &operator<<(std::ostream &os, const Point3 &point) {
    return os << '{' << point.x << ',' << point.y << ',' << point.z << '}';
}