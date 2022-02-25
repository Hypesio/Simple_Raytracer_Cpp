#pragma once
#include <string>
#include <vector>

#include "color.hh"

class Image
{
public:
    int h;
    int w;
    std::vector<Color> pixels;

    Image(int h, int w, std::vector<Color> pixels = std::vector<Color>())
    {
        this->h = h;
        this->w = w;
        this->pixels = pixels;
    }

    void SaveImage(std::string fileName);
};