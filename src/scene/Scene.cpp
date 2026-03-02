#include "scene/Scene.h"

Scene::Scene()
{
    objects.emplace_back(); // one object for now
}

void Scene::update(float time)
{
    for (auto& obj : objects)
    {
        obj.update(time);
    }
}

std::vector<Object>& Scene::getObjects()
{
    return objects;
}
