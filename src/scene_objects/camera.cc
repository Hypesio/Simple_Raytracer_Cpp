#include "camera.hh"

#include <cmath>

Camera::Camera(Point3 center, Point3 lookAt, Vector3 up, float fovAlpha,
               float fovBeta, float nearClipPlane)
{
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
    float planeWidth =
        nearClipPlane * tan((fovAlpha / 2.0f) * M_PI / 180.0f) * 2;
    float planeHeight =
        nearClipPlane * tan((fovBeta / 2.0f) * M_PI / 180.0f) * 2;

    Vector3 down = -up;
    // Cross product
    right = forward.cross(up).normalized();
    Vector3 left = -right;

    originPixel = positionPlan + left * planeWidth / 2 + down * planeHeight / 2;
}

Vector3 Camera::GetVectorPixel(int posH, int posW)
{
    Point3 pixelPosition = originPixel
        + up * pixelHeight * (posH + pixelHeight / 2)
        + right * pixelWidth * (posW + pixelWidth / 2);

    return (pixelPosition - center);
}

void Camera::SetPixelSize(int height, int width)
{
    pixelHeight = planeHeight / height;
    pixelWidth = planeWidth / width;
}