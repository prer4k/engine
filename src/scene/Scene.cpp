#include "scene/Scene.h"
#include <utility>

Scene::Scene()
{
}

void Scene::update(float time, float dt)
{
    for (auto& obj : objects)
    {
        obj.update(time, dt);
    }
}

void Scene::addObject(Object obj)
{
    objects.push_back(std::move(obj));
}

Object& Scene::addObjectRef(Object obj)
{
    objects.push_back(std::move(obj));
    return objects.back();
}

std::vector<Object>& Scene::getObjects()
{
    return objects;
}

const std::vector<Object>& Scene::getObjects() const
{
    return objects;
}
