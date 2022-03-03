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
                            90, 60, 0.1f);

    auto mainLight = std::make_shared<PointLight>(Point3(0.5f, 1.5f, 3.0f), 1, 8);
    std::vector<std::shared_ptr<LightSource>> lights = std::vector<std::shared_ptr<LightSource>>();
    lights.push_back(mainLight);


    std::vector<std::shared_ptr<Model>> objects = std::vector<std::shared_ptr<Model>>();
    objects.push_back(std::make_shared<Sphere>(Point3(0, 1.0f, 8.0f), 2.7f));
    objects.push_back(std::make_shared<Sphere>(Point3(0.75f, -50.0f, 4.0f), 50.0f, std::make_shared<UniformTexture>(Color(0, 0, 125), 1, 0)));
    objects.push_back(std::make_shared<Sphere>(Point3(0.0f, 0.0f, 70.0f), 50.0f, std::make_shared<UniformTexture>(Color(0, 125, 0), 1, 0)));
    objects.push_back(std::make_shared<Sphere>(Point3(0.75f, 0.75f, 4.0f), 0.7f, std::make_shared<UniformTexture>(Color(255, 0, 0), 0.6f, 0.2f)));
    objects.push_back(std::make_shared<Sphere>(Point3(-2.3f, 0.0f, 3.0f), 0.5f, std::make_shared<UniformTexture>(Color(255, 255, 0), 0.5f, 0.4f)));
    objects.push_back(std::make_shared<Sphere>(Point3(-2.0f, 1.5f, 4.0f), 0.4f, std::make_shared<UniformTexture>(Color(255, 180, 0), 0.5f, 0.5f)));
    objects.push_back(std::make_shared<Sphere>(Point3(0.5f, 1.5f, 3.0f), 0.2f, std::make_shared<UniformTexture>(Color(255, 255, 255), 0.5f, 0.5f)));

    Scene mainScene = Scene(mainCam, lights, objects);

    // --- Launch Engine
    printf("Image is ready\n");
    Image img = GenerateImage(mainScene, 450, 800);
    img.SaveImage("/home/antoinea/Desktop/IMAGE/Raytracer/test/SphereTest.ppm");
    //img.SaveImage(R"(C:\Users\Melvin\Documents\Ubuntu\Image\Raytracer\test\SphereTest.ppm)");

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