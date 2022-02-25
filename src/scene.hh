#pragma once
#include <vector>

#include "camera.hh"
#include "light_source.hh"
#include "model.hh"
#include "point3.hh"
#include "vector3.hh"

class Scene
{
public:
    Camera camera;
    std::vector<LightSource> lights;
    std::vector<Model *> objects;

    Scene(Camera camera, std::vector<LightSource> lights,
          std::vector<Model *> objects)
    {
        this->camera = camera;
        this->lights = lights;
        this->objects = objects;
    }
};