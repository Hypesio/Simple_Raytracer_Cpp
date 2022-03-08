#pragma once
#include "image.hh"
#include "scene.hh"
#include "color.hh"

Image GenerateImage(Scene scene,int heightImg, int widthImg);
Color GetIllumination(Scene scene, std::shared_ptr<Model> obj, Vector3 ray, Point3 origin, int bounce);
bool LightVectorIntersectObj(Scene scene, Vector3 lightVector, Point3 originn, std::shared_ptr<Model> obj);