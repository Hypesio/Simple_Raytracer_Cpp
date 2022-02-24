#include <iostream>

class Point3 {
    public :
     float x = 0; 
     float y = 0; 
     float z = 0;

     Point3(float x, float y, float z = 0) {
        this->x = x; 
        this->y = y;
        this->z = z;
     }

};

std::ostream &operator<<(std::ostream &os, const Point3 &point);