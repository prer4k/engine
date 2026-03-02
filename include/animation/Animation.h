#pragma once

#include "math/Transform.h"

class Animation
{
public:

    float radius;
    float speed;

    Animation();

    void update(Transform& t, float time);
};
