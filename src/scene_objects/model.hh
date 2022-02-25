#pragma once
#include "texture_material.hh"
#include "vector3.hh"

class Model
{
protected:
    TextureMaterial *texture;

public:
    virtual Point3 *RayIntersect(Point3 origin, Vector3 ray) = 0;
    virtual Vector3 GetNormal(Point3 point) = 0;
    virtual float GetInfos(Point3 point) = 0;
};