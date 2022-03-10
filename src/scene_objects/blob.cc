#include "blob.hh"
#include "sphere.hh"


bool EnoughPotential(Sphere sphere, Point3 pos) {
    float distance = (sphere.center - pos).magnitude() - sphere.radius; 
    if (distance <= 0) {
        return true;
    }

    float potential = 1 / distance; 
    return potential >= POTENTIAL_WANTED;
}


void ApplyMarchingCubes(Point3 extremityA, Point3 extremityB, std::vector<std::shared_ptr<Model>> objs) {
    //
}