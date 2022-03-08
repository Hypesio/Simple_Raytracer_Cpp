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
            const Vector3 ray = (pixelPos - scene.camera.center).normalized();

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

                for (int i = 0; i < scene.lights.size(); i++)
                {
                    Vector3 lightVector =
                        scene.lights[i]->GetLightVector(*bestIntersectPoint);

                    if (LightVectorIntersectObj(scene, lightVector, *bestIntersectPoint, bestObj)) {
                        continue;
                    }

                    float lightDistance = lightVector.magnitude();
                    lightVector = lightVector.normalized();

                    float intensity = scene.lights[i]->intensity;
                    Vector3 normalVector =
                        bestObj->GetNormal(*bestIntersectPoint);

                    // -- Diffuse
                    float vectorProduct = normalVector.dotProduct(lightVector);
                    Color diffuse = texInfos.color * texInfos.diffuse
                        * vectorProduct * intensity;

                    // -- Specular
                    Vector3 reflection = ray.reflection(normalVector);

                    float ns = 15.0f;
                    Color specular = texInfos.color * texInfos.specular
                        * pow(reflection.dotProduct(lightVector), ns)
                        * intensity;

                    Color reflectionIllumination = GetIllumination(
                        scene, bestObj, reflection, *bestIntersectPoint, 12);
                    pixColor = pixColor + specular + diffuse; //+ (reflectionIllumination * texInfos.specular);
                }
            }

            pixelColors.emplace_back(pixColor);
        }
    }

    return { heightImg, widthImg, pixelColors };
}

bool LightVectorIntersectObj(Scene scene, Vector3 lightVector, Point3 origin, std::shared_ptr<Model> objStart)
{
    for (const std::shared_ptr<Model> &obj : scene.objects)
    {
        if (obj == objStart)
            continue;
        std::shared_ptr<Point3> intersectPoint =
            obj->RayIntersect(origin, lightVector);
        if (intersectPoint != nullptr)
        {
            if ((intersectPoint->pointToVector() - origin.pointToVector()).magnitude() > lightVector.magnitude())
                continue;
            //std::cout << "Colide point " << *intersectPoint << " dist " << (intersectPoint->pointToVector() - origin.pointToVector()).magnitude() << '\n';
            return true;
        }
    }
    return false;
}

Color GetIllumination(Scene scene, std::shared_ptr<Model> lastObjTouched,
                      Vector3 ray, Point3 origin, int bounce)
{
    if (bounce <= 0)
    {
        return Color(0, 0, 0);
    }

    origin = origin + ray.normalized() * 0.001f;

    float minDistance = 123456789.0f;
    std::shared_ptr<Point3> bestIntersectPoint = nullptr;
    std::shared_ptr<Model> bestObj = nullptr;

    for (const std::shared_ptr<Model> &obj : scene.objects)
    {
        std::shared_ptr<Point3> intersectPoint = obj->RayIntersect(origin, ray);
        if (intersectPoint != nullptr)
        {
            // if (origin.x > 0)
            // std::cout << origin << '\n';
            float dist = (scene.camera.center - *intersectPoint).magnitude();
            if (dist < minDistance)
            {
                minDistance = dist;
                bestIntersectPoint = intersectPoint;
                bestObj = obj;
            }
        }
    }

    if (bestIntersectPoint == nullptr || bestObj == lastObjTouched)
    {
        return Color(0, 0, 0);
    }

    TextureInfos texInfos = bestObj->GetInfos(*bestIntersectPoint);

    Vector3 lightVector = scene.lights[0]->GetLightVector(*bestIntersectPoint);
    float lightDistance = lightVector.magnitude();
    lightVector = lightVector.normalized();

    float intensity = scene.lights[0]->intensity;
    Vector3 normalVector = bestObj->GetNormal(*bestIntersectPoint);

    // -- Diffuse
    float vectorProduct = normalVector.dotProduct(lightVector);
    Color diffuse =
        texInfos.color * texInfos.diffuse * vectorProduct * intensity;

    // -- Specular
    Vector3 reflection = ray.reflection(normalVector);

    float ns = 15;
    Color specular = texInfos.color * texInfos.specular * intensity
        * pow(reflection.dotProduct(lightVector), ns);

    Color intensityOnPoint = specular + diffuse;

    return (intensityOnPoint
            + GetIllumination(scene, bestObj, reflection, *bestIntersectPoint,
                              bounce - 1));
}

Color GetReflection(Scene scene, std::shared_ptr<Model> lastObjTouched,
                    Vector3 ray, Point3 origin, int bounce)
{
    if (bounce <= 0)
    {
        return Color(0, 0, 0);
    }

    origin = origin + ray.normalized() * 0.001f;

    float minDistance = 123456789.0f;
    std::shared_ptr<Point3> bestIntersectPoint = nullptr;
    std::shared_ptr<Model> bestObj = nullptr;

    for (const std::shared_ptr<Model> &obj : scene.objects)
    {
        std::shared_ptr<Point3> intersectPoint = obj->RayIntersect(origin, ray);
        if (intersectPoint != nullptr)
        {
            // if (origin.x > 0)
            // std::cout << origin << '\n';
            float dist = (scene.camera.center - *intersectPoint).magnitude();
            if (dist < minDistance)
            {
                minDistance = dist;
                bestIntersectPoint = intersectPoint;
                bestObj = obj;
            }
        }
    }

    if (bestIntersectPoint == nullptr || bestObj == lastObjTouched)
    {
        return Color(0, 0, 0);
    }

    TextureInfos texInfos = bestObj->GetInfos(*bestIntersectPoint);

    Vector3 lightVector = scene.lights[0]->GetLightVector(*bestIntersectPoint);
    float lightDistance = lightVector.magnitude();
    lightVector = lightVector.normalized();

    float intensity = scene.lights[0]->intensity;
    Vector3 normalVector = bestObj->GetNormal(*bestIntersectPoint);

    // -- Diffuse
    float vectorProduct = normalVector.dotProduct(lightVector);
    Color diffuse =
        texInfos.color * texInfos.diffuse * vectorProduct * intensity;

    // -- Specular
    Vector3 reflection = ray.reflection(normalVector);

    float ns = 15;
    Color specular = texInfos.color * texInfos.specular * intensity
        * pow(reflection.dotProduct(lightVector), ns);

    Color intensityOnPoint = specular + diffuse;

    return (intensityOnPoint
            + GetIllumination(scene, bestObj, reflection, *bestIntersectPoint,
                              bounce - 1));
}
