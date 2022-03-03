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
                    TextureInfos texInfos = obj->GetInfos(*intersectPoint);

                    Vector3 lightVector = scene.lights[0]->GetLightVector(*intersectPoint);
                    float intensity = scene.lights[0]->intensity;
                    Vector3 normalVector = obj->GetNormal(*intersectPoint);

                    // -- Diffuse
                    float vectorProduct = normalVector.dotProduct(lightVector);
                    Color diffuse = texInfos.color * texInfos.diffuse * vectorProduct * intensity; 

                    // -- Specular
                    Vector3 reflection = ray.reflection(normalVector); 
                    float ns = 15;
                    Color specular = texInfos.color * texInfos.specular * intensity * pow(reflection.dotProduct(lightVector), ns);
                    
                    //if (diffuse.r != 0 && diffuse.g != 0)
                        //std::cout << "Diffuse " << diffuse << " | Specular " << specular << " Ref " << reflection << " prod " << reflection.dotProduct(lightVector) << '\n';

                    pixColor = specular + diffuse; 
                }
            }

            pixelColors.emplace_back(pixColor);
        }
    }

    return {heightImg, widthImg, pixelColors};
}