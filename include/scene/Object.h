#pragma once

#include "math/Transform.h"
#include "animation/Animation.h"
#include "graphics/Mesh.h"

class Object
{
public:

    Transform transform;
    Animation animation;
    Mesh mesh;

    Object();

    void update(float time);

    glm::mat4 getModel();
};
