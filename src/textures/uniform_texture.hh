#pragma once
#include "texture_material.hh"
#include "color.hh"



class UniformTexture : public TextureMaterial
{
public:
    Color color;
    float diffuse;
    float specular; 

    UniformTexture(Color color = Color(255, 255, 255), float diffuse = 0.5f, float specular = 0.5f) {
        this->color = color;
        this->diffuse = diffuse;
        this->specular = specular;
    }

    TextureInfos GetTextureInfos(Point3 point);
};