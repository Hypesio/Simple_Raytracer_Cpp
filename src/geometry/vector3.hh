#pragma once
#include <iostream>

class Vector3
{
public:
    float x = 0;
    float y = 0;
    float z = 0;

    Vector3(float x = 0, float y = 0, float z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 operator*(const float &multiplicator) const;

    Vector3 operator-(const float &minus) const;

    Vector3 operator-() const;

    Vector3 operator+(Vector3 right) const;

    Vector3 operator/(const float &divisor) const;

    Vector3 operator-(Vector3 right) const;

    Vector3 reflection(Vector3 normal) const; 

    float dotProduct(const Vector3 &vector) const;

    float norm() const;

    float magnitude() const;

    Vector3 normalized() const;

    Vector3 cross(Vector3 &rhs) const;
};

std::ostream &operator<<(std::ostream &out, const Vector3 &vect);
Vector3 operator*(const float &multiplicator, const Vector3 &lhs);