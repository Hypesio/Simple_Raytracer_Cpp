#include <iostream>

class Vector3 {
    public :
     float x = 0; 
     float y = 0; 
     float z = 0;

     Vector3(float x = 0, float y = 0, float z = 0) {
        this->x = x; 
        this->y = y;
        this->z = z;
     }

     Vector3 operator*(const float &multiplicator) const;

     Vector3 operator-(const float &minus) const;

     float dotProduct(const Vector3 &vector) const;

     float norm() const; 
};

std::ostream &operator<<(std::ostream &out, const Vector3 &vect);