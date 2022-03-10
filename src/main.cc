#include "camera.hh"
#include "engine.hh"
#include "image.hh"
#include "point_light.hh"
#include "scene.hh"
#include "sphere.hh"
#include "triangle.hh"

using namespace std;

int main()
{
    auto tr1 = make_shared<Triangle>(Point3(-2.0f, 1, 3), Point3(-1.0f, 2, 3), Point3(-0.5f, 1, 3), std::make_shared<UniformTexture>(Color(255, 0, 0), 1, 0));
    Vector3 ray = Vector3(0, 0, 1); 
    Point3 origin = Point3(0, 1, 0);

    std::cout << "Ray test _ Should not intersect " << tr1->RayIntersect(origin, ray) << '\n';

    auto tr2 = make_shared<Triangle>(Point3(-0.5f, 1, 3), Point3(-1.0f, 2, 3), Point3(1, 1.2f, 3.5f), std::make_shared<UniformTexture>(Color(255, 0, 0), 1, 0));
    std::cout << "Ray test _ Should intersect " << tr2->RayIntersect(origin, ray) << '\n';

    auto tr3 = make_shared<Triangle>(Point3(-1.0f, 0.5f, 2), Point3(0, 1.5f, 2), Point3(1, 0.5f, 2), std::make_shared<UniformTexture>(Color(255, 0, 0), 1, 0));
    std::cout << "Ray test _ Should intersect " << tr3->RayIntersect(origin, ray) << '\n';

    //return 0;
    // --- Prepare Scene
    Camera mainCam = Camera(Point3(0, 3, -1), Point3(0, 2.75f, 0.15f), Vector3(0, 3.75f, 2.8f).normalized(),
                            90, 60, 0.1f);

    auto mainLight = std::make_shared<PointLight>(Point3(-3.0f, 1.0f, 1.0f), 1.3f, 8);
    std::vector<std::shared_ptr<LightSource>> lights = std::vector<std::shared_ptr<LightSource>>();
    lights.push_back(mainLight);
    lights.push_back(std::make_shared<PointLight>(Point3(1.0f, 3.0f, 4.0f), 0.7f, 8));


    std::vector<std::shared_ptr<Model>> objects = std::vector<std::shared_ptr<Model>>();
    objects.push_back(std::make_shared<Sphere>(Point3(0, 1.0f, 5.0f), 1.4f));
    objects.push_back(std::make_shared<Sphere>(Point3(0.75f, -2000.5f, 5.0f), 2000.0f, std::make_shared<UniformTexture>(Color(0, 0, 125), 1, 0)));
    //objects.push_back(std::make_shared<Sphere>(Point3(0.0f, 0.0f, 70.0f), 50.0f, std::make_shared<UniformTexture>(Color(0, 125, 0), 1, 0)));
    objects.push_back(std::make_shared<Sphere>(Point3(1.3f, 0.0f, 3.5f), 0.4f, std::make_shared<UniformTexture>(Color(255, 0, 0), 0.6f, 0.8f)));
    objects.push_back(std::make_shared<Sphere>(Point3(-2.3f, 0.0f, 4.0f), 0.5f, std::make_shared<UniformTexture>(Color(255, 255, 0), 0.5f, 0.2f)));
    objects.push_back(std::make_shared<Sphere>(Point3(-3, 0, 4.8f), 0.5f, std::make_shared<UniformTexture>(Color(255, 180, 0), 0.5f, 0.2f)));
    objects.push_back(tr1);
    objects.push_back(tr2);
    objects.push_back(tr3);
    //objects.push_back(std::make_shared<Sphere>(Point3(0.5f, 1.5f, 3.0f), 0.2f, std::make_shared<UniformTexture>(Color(255, 255, 255), 0.5f, 0.5f)));

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