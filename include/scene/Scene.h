#pragma once

#include <vector>
#include "scene/Object.h"

class Scene
{
private:

    std::vector<Object> objects;

public:

    Scene();

    void update(float time);

    std::vector<Object>& getObjects();
};
