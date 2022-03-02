#include "vector3.hh"

#include <cmath>

Vector3 Vector3::operator*(const float &multiplicator) const
{
    float y = this->y * multiplicator;
    float x = this->x * multiplicator;
    float z = this->z * multiplicator;

    Vector3 newVect = Vector3(x, y, z);
    return newVect;
}

Vector3 Vector3::operator-(const float &minus) const
{
    float y = this->y - minus;
    float x = this->x - minus;
    float z = this->z - minus;

    Vector3 newVect = Vector3(x, y, z);

    return newVect;
}

Vector3 Vector3::operator-() const
{
    float y = -this->y;
    float x = -this->x;
    float z = -this->z;

    Vector3 newVect = Vector3(x, y, z);

    return newVect;
}

Vector3 Vector3::operator-(Vector3 right) const
{    
    float y = this->y - right.x;
    float x = this->x - right.y;
    float z = this->z - right.z;

    Vector3 newVect = Vector3(x, y, z);

    return newVect;
}

float Vector3::norm() const
{
    float sum = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
    float res = sqrt(sum);
    return res;
}

float Vector3::dotProduct(const Vector3 &right) const
{
    float sum = this->x * right.x + this->y * right.y + this->z * right.z;
    //float sum = 1/2 * (pow(this->norm(), 2) + pow(right.norm(), 2) - pow((right - *this).norm(), 2));
    return sum;
}


std::ostream &operator<<(std::ostream &os, const Vector3 &vect)
{
    return os << '{' << vect.x << ',' << vect.y << ',' << vect.z << '}';
}

float Vector3::magnitude() const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::normalized() const
{
    float mag = magnitude();
    if (mag > 0)
    {
        return *this / mag;
    }
    return *this;
}

Vector3 Vector3::operator/(const float &divisor) const
{
    float y = this->y / divisor;
    float x = this->x / divisor;
    float z = this->z / divisor;

    Vector3 newVect = Vector3(x, y, z);

    return newVect;
}

Vector3 Vector3::cross(Vector3 &rhs) const
{
    return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                   x * rhs.y - y * rhs.x);
}