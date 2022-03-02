#include "camera.hh"
#include "engine.hh"
#include "image.hh"
#include "point_light.hh"
#include "scene.hh"
#include "sphere.hh"

int main()
{
    // --- Prepare Scene
    Camera mainCam = Camera(Point3(0, 1, 0), Point3(0, 1, 1), Vector3(0, 1, 0),
                            80, 80, 0.1f);

    LightSource mainLight = PointLight(Point3(0, 2, 2.5f), 1, 3);
    std::vector<LightSource> lights = std::vector<LightSource>();
    lights.push_back(mainLight);


    std::vector<std::shared_ptr<Model>> objects = std::vector<std::shared_ptr<Model>>();
    objects.push_back(std::make_shared<Sphere>(Point3(0, 1.0f, 5.0f), 2.7f));
    objects.push_back(std::make_shared<Sphere>(Point3(0.5f, 0.5f, 2.0f), 0.7f, std::make_shared<UniformTexture>(Color(255, 0, 0))));
    objects.push_back(std::make_shared<Sphere>(Point3(-0.5f, 0.5f, 2.0f), 0.7f, std::make_shared<UniformTexture>(Color(255, 255, 0))));

    Scene mainScene = Scene(mainCam, lights, objects);

    // --- Launch Engine
    printf("Image is ready\n");
    Image img = GenerateImage(mainScene, 1000, 1000);
    //img.SaveImage("/home/antoinea/Desktop/IMAGE/Raytracer/test/SphereTest.ppm");
    img.SaveImage(R"(C:\Users\Melvin\Documents\Ubuntu\Image\Raytracer\test\SphereTest.ppm)");

    return 0;
}

int TestImage()
{
    int height = 1000;
    int width = 800;
    Color red = Color(255, 0, 0);
    std::vector<Color> pixels;
    printf("Reserve vector\n");
    pixels.reserve(sizeof(Color) * height * width);

    printf("Try to create an image\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixels.emplace_back(red);
        }
    }

    printf("Image is ready\n");

    Image img = Image(height, width, pixels);
    img.SaveImage("/home/antoinea/Desktop/IMAGE/Raytracer/test/ColorTest.ppm");
    return 0;
}