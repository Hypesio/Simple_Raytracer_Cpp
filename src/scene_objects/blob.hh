#pragma once

#include <vector>
#include <memory>
#include "model.hh"
#include "point3.hh"

#define CUBE_SIZE 0.5f;
#define STEP 0.5f;
#define POTENTIAL_WANTED 0.7f;

class Blob {
    public :
        Point3 position;  

};

void ApplyMarchingCubes(Point3 extremityA, Point3 extremityB, std::vector<std::shared_ptr<Model>> objs);