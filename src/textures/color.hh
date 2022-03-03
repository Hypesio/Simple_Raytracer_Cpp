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
    
    Color(int red, int green, int blue, float a = 1.0F)
    {
        r = red > 255 ? 255 : red;
        r =  r < 0 ? 0 : r;

        g = green > 255 ? 255 : green;
        g =  g < 0 ? 0 : g;
        b = blue > 255 ? 255 : blue;
        b =  b < 0 ? 0 : b;
        this->a = a;
    }

    Color operator*(const float &multiplicator) const;
    Color operator+(const Color &rhs) const;
};

std::ostream &operator<<(std::ostream &out, const Color &color);