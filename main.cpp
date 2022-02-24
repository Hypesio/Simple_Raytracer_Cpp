#include "image.h"
#include "point_light.h"
#include "scene.h"
#include "sphere.h"

int main() {
    
    // --- Prepare Scene
    Camera mainCam = Camera(Point3(0, 1, 0), Point3(0, 1, 1), Vector3(0, 1, 0), 80, 80, 0.1f);
    
    LightSource mainLight = PointLight(Point3(0, 2, 2.5f), 1, 3); 
    std::vector<LightSource> lights = std::vector<LightSource>();
    lights.push_back(mainLight); 

    Model sphere1 = Sphere(Point3(0.5f, 0.5f, 2.5f), 0.7f);
    std::vector<Model> objects = std::vector<Model>();
    objects.push_back(sphere1); 
     
    Scene mainScene = Scene(mainCam, lights, objects); 

    // --- Launch Engine
    

}

int TestImage()  {
    int height = 1000; 
    int width = 800; 
    Color red = Color (255, 0, 0); 
    std::vector<Color> pixels;
    printf("Reserve vector\n");
    pixels.reserve(sizeof(Color) * height * width); 

    printf("Try to create an image\n");
    
    for (int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j ++) {
            pixels.emplace_back(red);
        }
    }

    printf("Image is ready\n");

    Image img = Image(height, width, pixels); 
    img.SaveImage("/home/antoinea/Desktop/IMAGE/Raytracer/test/ColorTest.ppm");
}