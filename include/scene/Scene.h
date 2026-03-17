#pragma once

#include <vector>
#include "scene/Object.h"

class Scene
{
private:

    std::vector<Object> objects;

public:

    Scene();

    void update(float time, float dt);

    void addObject(Object obj);
    Object& addObjectRef(Object obj);

    std::vector<Object>& getObjects();
    const std::vector<Object>& getObjects() const;
};
