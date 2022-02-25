#pragma once
#include <cmath>
#include "point3.hh"
#include "vector3.hh"


class Camera {
    private : 
        Point3 imagePlanPosition; 
        Point3 originPixel; 
        float planeWidth; 
        float planeHeight; 
        float pixelHeight = 0;
        float pixelWidth = 0;  

    public : 
     Point3 center; 
     Point3 lookAt; 
     Vector3 up; 
     Vector3 forward; 
     Vector3 right; 
     float fovAlpha;
     float fovBeta; 
     float nearClipPlane; 

     Camera();

     Camera(Point3 center, Point3 lookAt, Vector3 up, float fovAlpha, float fovBeta, float nearClipPlane) {
         this->center = center; 
         this->lookAt = lookAt; 
         this->up = up.normalized(); 
         this->fovAlpha = fovAlpha; 
         this->fovBeta = fovBeta; 
         this->nearClipPlane = nearClipPlane; 
         
         forward = (lookAt - center).normalized();

         // Position plan image
         Point3 positionPlan = center + forward * nearClipPlane;

         // Compute size of imagePlan
         float planeWidth = nearClipPlane * tan((fovAlpha / 2.0f) * M_PI / 180.0f) * 2;
         float planeHeight = nearClipPlane * tan((fovBeta / 2.0f) * M_PI / 180.0f) * 2;

         Vector3 down = -up;
         // Cross product
         right = Vector3(up.y * forward.z - up.z * forward.y,
                         up.z * forward.x - up.x * forward.z,
                         up.x * forward.y - up.y * forward.x).normalized(); 
         Vector3 left = -right;
         
         originPixel = positionPlan + left * planeWidth / 2 + down * planeHeight / 2;
     }

     void SetPixelSize(int height, int width); 

     Vector3 GetVectorPixel(int posH, int posW); 

};