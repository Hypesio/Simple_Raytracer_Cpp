#include "sphere.hh"
#include "color.hh"

#include <cmath>

std::shared_ptr<Point3> Sphere::RayIntersect(Point3 origin, Vector3 ray)
{
    float b = ray.dotProduct(origin - this->center) * 2;
    float a = pow(ray.norm(), 2);
    float c = pow((origin - this->center).norm(), 2) - pow(this->radius, 2);

    float delta = pow(b / 2, 2) - a * c;
    
    if (delta < -0.000001f)
    {
        return nullptr;
    }

    float dist = 0.0f;

    // One intersection
    if (std::abs(delta) < 0.000001f)
    {
        dist = -b / (2 * a);
    }
    // Two intersections
    else
    {
        float dist1 = (-b - std::sqrt(delta)) / (2 * a);
        float dist2 = (-b + std::sqrt(delta)) / (2 * a);
        dist = dist1 > dist2 ? dist2 : dist1;
    }

    

    Point3 res = (origin + ray * dist);
    //std::cout << res << '\n';
    return std::make_shared<Point3>(res.x, res.y, res.z);
}

Vector3 Sphere::GetNormal(Point3 point)
{
    // Point is not on the sphere surface
    /*if (std::abs(this->center.Distance(point) - radius) > 0.1f)
    {
        std::cout << " Miss the sphere " << '\n';
        return {0, 0, 0};
    }*/
    //std::cout << "point " << point << " direction " << (point - center).normalized() << '\n';
    return (point - center).normalized();
}

TextureInfos Sphere::GetInfos(Point3 point)
{
    return texture->GetTextureInfos(point);
}