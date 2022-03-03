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
            float minDistance = 234567890.0f;
            std::shared_ptr<Point3> bestIntersectPoint = nullptr;
            std::shared_ptr<Model> bestObj = nullptr;

            for (const std::shared_ptr<Model> &obj : scene.objects)
            {
                std::shared_ptr<Point3> intersectPoint =
                    obj->RayIntersect(pixelPos, ray);
                if (intersectPoint != nullptr)
                {
                    float dist =
                        (scene.camera.center - *intersectPoint).magnitude();
                    if (dist < minDistance)
                    {
                        minDistance = dist;
                        bestIntersectPoint = intersectPoint;
                        bestObj = obj;
                    }
                }
            }

            if (bestIntersectPoint != nullptr)
            {
                TextureInfos texInfos = bestObj->GetInfos(*bestIntersectPoint);

                Vector3 lightVector =
                    scene.lights[0]->GetLightVector(*bestIntersectPoint);
                float intensity = scene.lights[0]->intensity;
                Vector3 normalVector = bestObj->GetNormal(*bestIntersectPoint);

                // -- Diffuse
                float vectorProduct = normalVector.dotProduct(lightVector);
                Color diffuse = texInfos.color * texInfos.diffuse
                    * vectorProduct * intensity;

                // -- Specular
                Vector3 reflection = ray.reflection(normalVector);

                float ns = 15;
                Color specular = texInfos.color * texInfos.specular * intensity
                    * pow(reflection.dotProduct(lightVector), ns);

                float intensityIllumination = GetIllumination(scene, reflection, *bestIntersectPoint, 2);
                pixColor = specular + diffuse + texInfos.color * texInfos.specular * intensityIllumination;
            }

            pixelColors.emplace_back(pixColor);
        }
    }

    return { heightImg, widthImg, pixelColors };
}

float GetIllumination(Scene scene, Vector3 ray, Point3 origin, int bounce)
{
    if (bounce < 0)
    {
        return 0;
    }

    float minDistance = 123456789.0f;
    std::shared_ptr<Point3> bestIntersectPoint = nullptr;
    std::shared_ptr<Model> bestObj = nullptr;

    for (const std::shared_ptr<Model> &obj : scene.objects)
    {
        std::shared_ptr<Point3> intersectPoint = obj->RayIntersect(origin, ray);
        if (intersectPoint != nullptr)
        {
            float dist = (scene.camera.center - *intersectPoint).magnitude();
            if (dist < minDistance)
            {
                minDistance = dist;
                bestIntersectPoint = intersectPoint;
                bestObj = obj;
            }
        }
    }

    if (bestIntersectPoint == nullptr)
    {
        return 0;
    }

    TextureInfos texInfos = bestObj->GetInfos(*bestIntersectPoint);

    Vector3 lightVector = scene.lights[0]->GetLightVector(*bestIntersectPoint);
    float intensity = scene.lights[0]->intensity;
    Vector3 normalVector = bestObj->GetNormal(*bestIntersectPoint);

    // -- Diffuse
    float vectorProduct = normalVector.dotProduct(lightVector);
    float diffuse = texInfos.diffuse * vectorProduct * intensity;

    // -- Specular
    Vector3 reflection = ray.reflection(normalVector);

    float ns = 15;
    float specular = texInfos.specular * intensity
        * pow(reflection.dotProduct(lightVector), ns);


    float intensityOnPoint = specular + diffuse;


    return intensityOnPoint + GetIllumination(scene, reflection, *bestIntersectPoint, bounce - 1);
}
