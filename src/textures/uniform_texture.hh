#pragma once
#include "texture_material.hh"
#include "color.hh"



class UniformTexture : public TextureMaterial
{
public:
    Color color;
    float diffuse;

    UniformTexture(Color color = Color(255, 255, 255), float diffuse = 1) {
        this->color = color;
        this->diffuse = diffuse;
    }

    TextureInfos GetTextureInfos(Point3 point);
};