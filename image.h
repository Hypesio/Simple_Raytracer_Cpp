#include "color.h"
#include <vector> 

class Image {
    public : 
     int h; 
     int w; 
     std::vector<Color> pixels; 
     
     Image(int h, int w) {
         this->h = h; 
         this->w = w; 
     }
};