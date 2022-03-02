#pragma once
#include "point3.hh"
#include "color.hh"

class TextureMaterial
{
public:
    // Should return diffuse and specular on specific point
    virtual Color GetTextureInfos(Point3 point) = 0;
};