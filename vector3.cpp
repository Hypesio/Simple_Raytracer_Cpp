#include "vector3.h"
#include <cmath>

Vector3 Vector3::operator*(const float &multiplicator) const {
    float y = this->y * multiplicator; 
    float x = this->x * multiplicator; 
    float z = this->z * multiplicator;

    Vector3 newVect = Vector3(x, y, z); 
    return newVect;
}

Vector3 Vector3::operator-(const float &minus) const {
    float y = this->y - minus; 
    float x = this->x - minus; 
    float z = this->z - minus;
    
    Vector3 newVect = Vector3(x, y, z); 

    return newVect;
}

float Vector3::norm() const {
    float sum = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2); 
    float res = sqrt(sum); 
    return res;
}

float Vector3::dotProduct(const Vector3 &right) const {
    float sum = this->x * right.x + this->y * right.y + this->z * right.z;
    return sum; 
}

std::ostream &operator<<(std::ostream &os, const Vector3 &vect)
{
    return os << '{' << vect.x << ',' << vect.y << ',' << vect.z << '}';
}