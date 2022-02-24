#include "camera.h"
#include "light_source.h"
#include "model.h"
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