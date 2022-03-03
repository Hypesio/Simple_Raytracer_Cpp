#pragma once
#include "image.hh"
#include "scene.hh"
#include "color.hh"

Image GenerateImage(Scene scene,int heightImg, int widthImg);
float GetIllumination(Scene scene, Vector3 ray, Point3 origin, int bounce);