#pragma once

#include "light_source.hh"
#include "point3.hh"

class PointLight : public LightSource
{
public:
    Point3 center;
    float intensity;
    float radius;

    PointLight(Point3 center, float intensity, float radius)
    {
        this->center = center;
        this->intensity = intensity;
        this->radius = radius;
    }
};