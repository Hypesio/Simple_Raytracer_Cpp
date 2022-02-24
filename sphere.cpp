#include "sphere.h"
#include <cmath>

bool Sphere::RayIntersect(Point3 origin, Vector3 ray){
    // [ray . (origin - center)]^2 - (||origin - center|| ^ 2 - radius ^ 2)
    // If < 0 -> False else thrue
    float start = pow(ray.dotProduct(origin - this->center), 2); 
    float end = pow((origin - center).norm(), 2) - pow(this->radius, 2);
    float delta = start - end; 
    return delta >= 0; 
} 

Vector3 Sphere::GetNormal(Point3 point) {
    // Point is not on the sphere surface
    if (abs(this->center.Distance(point) - radius) > 0.1f ) {
        return Vector3(0, 0, 0);
    }

    return point - center; 
} 

float Sphere::GetInfos(Point3 point) {
    return this->texture.GetTextureInfos(point);
}