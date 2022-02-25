#pragma once
#include "point3.hh"

class TextureMaterial
{
public:
    // Should return diffuse and specular on specific point
    virtual float GetTextureInfos(Point3 point) = 0;
};