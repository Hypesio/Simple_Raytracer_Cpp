#pragma once
#include "point3.hh"
#include "color.hh"

struct TextureInfos {
    Color color; 
    float diffuse; 
    float specular; 
};

class TextureMaterial
{
public:
    // Should return diffuse and specular on specific point
    virtual TextureInfos GetTextureInfos(Point3 point) = 0;
};