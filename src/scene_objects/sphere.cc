#include "sphere.hh"
#include <cmath>

Point3 *Sphere::RayIntersect(Point3 origin, Vector3 ray){
    // [ray . (origin - center)]^2 - (||origin - center|| ^ 2 - radius ^ 2)
    // If < 0 -> False else thrue
    float start = pow(ray.dotProduct(origin - this->center), 2); 
    float end = pow((origin - center).norm(), 2) - pow(this->radius, 2);
    float delta = start - end; 
    if (delta < 0) {
        return nullptr;
    }

    float b = ray.dotProduct(origin - this->center) * 2; 
    float a = pow(ray.norm(), 2);
    float dist = 0.0f;

    // One intersection
    if (abs(delta) < 0.001f) {
        dist = -b / (2 * a);
    }
    else {
        float dist1 = (-b - sqrt(delta)) / (2*a); 
        float dist2 = (-b + sqrt(delta)) / (2*a); 
        dist = dist1 > dist2 ? dist2 : dist1; 
    }

    Point3 res = (origin + ray.normalized() * dist); 
    return new Point3(res.x, res.y, res.z);
} 

Vector3 Sphere::GetNormal(Point3 point) {
    // Point is not on the sphere surface
    if (abs(this->center.Distance(point) - radius) > 0.1f ) {
        return Vector3(0, 0, 0);
    }

    return (point - center).normalized(); 
} 

float Sphere::GetInfos(Point3 point) {
    return texture->GetTextureInfos(point);
}