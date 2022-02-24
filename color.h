#pragma once
#include <iostream>

class Color {
    public :
     int r = 0;
     int g = 0; 
     int b = 0;  
     float a = 0;
     
     Color(int r, int g, int b, float a = 1.0F) {
         this->r = r; 
         this->g = g; 
         this->b = b; 
         this->a = a;
     }
}; 

std::ostream &operator<<(std::ostream &out, const Color &color);