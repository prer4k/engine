#include "scene/Object.h"

Object::Object()
: mesh({
    -0.5f,-0.5f,0, 1,0,0,
     0.5f,-0.5f,0, 0,1,0,
     0.0f, 0.5f,0, 0,0,1
}, 6)
{
}

void Object::update(float time)
{
    animation.update(transform, time);
}

glm::mat4 Object::getModel()
{
    return transform.getModelMatrix();
}
