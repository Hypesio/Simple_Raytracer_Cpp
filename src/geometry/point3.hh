#pragma once
#include <iostream>

#include "vector3.hh"

class Point3
{
public:
    float x = 0;
    float y = 0;
    float z = 0;

    Point3(float x = 0, float y = 0, float z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 operator-(const Point3 &right) const;

    float Distance(const Point3 right) const;

    Point3 operator+(const Vector3 &right) const;

    Vector3 pointToVector() const;
};

std::ostream &operator<<(std::ostream &os, const Point3 &point);