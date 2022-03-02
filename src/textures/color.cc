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

Color Color::operator*(const Vector3 &multiplicator) const {
    float red = r * multiplicator.x;
    float green = g * multiplicator.y;
    float blue = b * multiplicator.z;

    return Color(red, green, blue);
}
