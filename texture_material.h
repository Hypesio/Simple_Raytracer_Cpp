#pragma once
#include "point3.h"

class TextureMaterial {
    public : 
    // Should return diffuse and specular on specific point
     virtual float GetTextureInfos(Point3 point); 
}; 