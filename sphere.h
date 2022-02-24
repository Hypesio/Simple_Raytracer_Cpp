#pragma once
#include "model.h"

class Sphere : public Model {
    public : 
     float radius; 
     Point3 center; 

     Sphere(Point3 center, float radius) {
         this->center = center;
         this->radius = radius; 
     }

     Point3 *RayIntersect(Point3 origin, Vector3 ray) override; 
     Vector3 GetNormal(Point3 point) override; 
     float GetInfos(Point3 point) override;  
};