#include <iostream>

class Vector3 {
    public :
     float x = 0; 
     float y = 0; 
     float z = 0;

     Vector3(float x, float y, float z = 0) {
        this->x = x; 
        this->y = y;
        this->z = z;
     }

     Vector3 Vector3::operator*(const float &multiplicator) const;

     Vector3 Vector3::operator-(const float &minus) const;

};

std::ostream &operator<<(std::ostream &out, const Vector3 &vect);