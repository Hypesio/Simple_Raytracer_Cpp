#include "vector3.h"; 

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

std::ostream &operator<<(std::ostream &os, const Vector3 &vect)
{
    return os << '{' << vect.x << ',' << vect.y << ',' << vect.z << '}';
}