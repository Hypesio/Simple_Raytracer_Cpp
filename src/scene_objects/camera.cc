#include "camera.hh"
#include <cmath>

Vector3 Camera::GetVectorPixel(int posH, int posW) {
    Point3 pixelPosition = originPixel + up * pixelHeight * (posH + pixelHeight / 2) + right * pixelWidth * (posW + pixelWidth / 2);

    return (pixelPosition - center); 
}

void Camera::SetPixelSize(int height, int width) {
    pixelHeight = planeHeight / height;
    pixelWidth = planeWidth / width; 
}