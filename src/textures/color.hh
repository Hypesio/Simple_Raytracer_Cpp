#pragma once
#include <iostream>
#include "vector3.hh"

class Color
{
public:
    int r = 0;
    int g = 0;
    int b = 0;
    float a = 0;
    
    Color() {

    }
    
    Color(int r, int g, int b, float a = 1.0F)
    {
        this->r = r > 255 ? 255 : r;
        this->r =  r < 0 ? 0 : r;
        this->g = g > 255 ? 255 : g;
        this->g =  g < 0 ? 0 : g;
        this->b = b > 255 ? 255 : b;
        this->b =  b < 0 ? 0 : b;
        this->a = a;
    }

    Color operator*(const float &multiplicator) const;
    Color operator*(const Vector3 &multiplicator) const;
};

std::ostream &operator<<(std::ostream &out, const Color &color);