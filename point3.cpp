#include "point3.h"
#include <cmath>

std::ostream &operator<<(std::ostream &os, const Point3 &point) {
    return os << '{' << point.x << ',' << point.y << ',' << point.z << '}';
}

Vector3 Point3::operator-(const Point3 &right) const {
    float x = this->x - right.x; 
    float y = this->y - right.y; 
    float z = this->z - right.z; 

    return Vector3(x, y, z); 
}

float Point3::Distance(const Point3 right) const {
    float distx = pow(this->x - right.x, 2); 
    float disty = pow(this->y - right.y, 2); 
    float distz = pow(this->z - right.z, 2); 
    return sqrt(distx + disty + distz);
}

Point3 Point3::operator+(const Vector3 &right) const {
    float x = this->x + right.x; 
    float y = this->y + right.y; 
    float z = this->z + right.z; 
    return Point3(x, y, z);
}
