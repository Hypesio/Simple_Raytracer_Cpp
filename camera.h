#include "point3.h"
#include "vector3.h"

class Camera {
    public : 
     Point3 center; 
     Point3 lookAt; 
     Vector3 up; 
     float fovAlpha;
     float fovBeta; 
     float nearClipPlane; 

     Camera(Point3 center, Point3 lookAt, Vector3 up, float fovAlpha, float fovBeta, float nearClipPlane) {
         this->center = center; 
         this->lookAt = lookAt; 
         this->up = up; 
         this->fovAlpha = fovAlpha; 
         this->fovBeta = fovBeta; 
         this->nearClipPlane = nearClipPlane; 
     }

};