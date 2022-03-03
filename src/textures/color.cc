#include "color.hh"

std::ostream &operator<<(std::ostream &os, const Color &color)
{
    return os << '{' << color.r << ',' << color.g << ',' << color.b << ','
              << color.a << '}';
}

Color Color::operator*(const float &multiplicator) const {
    float red = r * multiplicator;
    float green = g * multiplicator;
    float blue = b * multiplicator;

    return Color(red, green, blue);
}

Color Color::operator+(const Color &rhs) const {
    float red = r + rhs.r; 
    float green = g + rhs.g; 
    float blue = b + rhs.b; 

    return Color(red, green, blue);
}