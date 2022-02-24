#pragma once
#include "texture_material.h"
#include "vector3.h"


class Model {
    protected : 
     TextureMaterial texture; 

    public : 
     virtual Point3 *RayIntersect(Point3 origin, Vector3 ray); 
     virtual Vector3 GetNormal(Point3 point); 
     virtual float GetInfos(Point3 point);
};