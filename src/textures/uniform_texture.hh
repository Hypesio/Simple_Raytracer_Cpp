#pragma once
#include "texture_material.hh"
#include "color.hh"

class UniformTexture : public TextureMaterial
{
public:
    Color color;

    UniformTexture(Color color = Color(0, 0, 0)) {
        this->color = color;
    }

    Color GetTextureInfos(Point3 point);
};