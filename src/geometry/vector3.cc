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

Vector3 operator*(const float &multiplicator, const Vector3 &lhs)
{
    float y = lhs.y * multiplicator;
    float x = lhs.x * multiplicator;
    float z = lhs.z * multiplicator;

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
    float y = this->y - right.y;
    float x = this->x - right.x;
    float z = this->z - right.z;

    Vector3 newVect = Vector3(x, y, z);

    return newVect;
}

Vector3 Vector3::operator+(Vector3 right) const
{    
    float y = this->y + right.y;
    float x = this->x + right.x;
    float z = this->z + right.z;

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
    Vector3 rightNorm = right; 
    Vector3 thisNorm = *this; 

    float sum = this->x * right.x + this->y * right.y + this->z * right.z;
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
    return Vector3(y * rhs.z - z * rhs.y, x * rhs.z - z * rhs.x,
                   x * rhs.y - y * rhs.x);
}

Vector3 Vector3::reflection(Vector3 normal) const {
    normal = normal.normalized();
    Vector3 ray = this->normalized();

    return (ray - 2 * normal.dotProduct(ray) * normal).normalized(); //(ray * ray.dotProduct(normal) + normal * (pow(ray.magnitude(), 2) - 2 * pow(ray.dotProduct(normal), 2))) * -1; 
}