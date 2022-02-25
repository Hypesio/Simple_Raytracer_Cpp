#include "engine.hh"

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
            Vector3 ray = scene.camera.GetVectorPixel(h, w);

            // 2 - Iterate on all objects
            Color pixColor = Color(0, 0, 0);
            for (Model *obj : scene.objects)
            {
                Point3 *intersectPoint =
                    obj->RayIntersect(scene.camera.center, ray);
                if (intersectPoint != nullptr)
                {
                    // TMP just white color if intersect
                    pixColor = Color(255, 255, 255);
                }
            }

            pixelColors.push_back(pixelColors);
        }
    }

    return Image(heightImg, widthImg);
}