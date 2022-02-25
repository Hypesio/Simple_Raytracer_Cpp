#pragma once
#include "camera.hh"
#include "light_source.hh"
#include "model.hh"
#include "vector3.hh"
#include "point3.hh"
#include <vector>

class Scene {
    public : 
     Camera camera; 
     std::vector<LightSource> lights; 
     std::vector<Model> objects;

     Scene(Camera camera, std::vector<LightSource> lights, std::vector<Model> objects) {
         this->camera = camera; 
         this->lights = lights; 
         this->objects = objects; 
     }
};