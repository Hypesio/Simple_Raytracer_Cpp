#pragma once
#include "texture_material.h"

class UniformTexture: public TextureMaterial {
    public: 
     float GetTextureInfos(Point3 point) override; 
};