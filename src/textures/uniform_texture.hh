#pragma once
#include "texture_material.hh"

class UniformTexture : public TextureMaterial
{
public:
    float GetTextureInfos(Point3 point);
};