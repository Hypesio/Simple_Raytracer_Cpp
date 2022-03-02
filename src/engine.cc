#include "engine.hh"
#include <iostream>

Image GenerateImage(Scene scene, int heightImg, int widthImg)
{
    // Step 1 - Iterate on all pixels
    scene.camera.SetPixelSize(heightImg, widthImg);
    std::vector<Color> pixelColors = std::vector<Color>(); 
    pixelColors.reserve(sizeof(Color) * heightImg * widthImg);

    for (int h = 0; h < heightImg; h++)
    {
        for (int w = 0; w < widthImg; w++)
        {
            // 1 - Get the vector
            Point3 pixelPos = scene.camera.GetPixelPos(h, w);
            Vector3 ray = pixelPos - scene.camera.center; 
            
            // 2 - Iterate on all objects
            Color pixColor = Color(0, 0, 0);
            for (const std::shared_ptr<Model>& obj : scene.objects)
            {
                std::shared_ptr<Point3> intersectPoint =
                    obj->RayIntersect(pixelPos, ray);
                if (intersectPoint != nullptr)
                {
                    pixColor = obj->GetInfos(*intersectPoint);
                }
            }

            pixelColors.emplace_back(pixColor);
        }
    }

    return {heightImg, widthImg, pixelColors};
}