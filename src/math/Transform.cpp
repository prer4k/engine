#include "math/Transform.h"

#include <glm/gtc/matrix_transform.hpp>

Transform::Transform()
{
    position = {0.0f, 0.0f, 0.0f};
    rotation = {0.0f, 0.0f, 0.0f};
    scale    = {1.0f, 1.0f, 1.0f};
}

glm::mat4 Transform::getModelMatrix() const
{
    glm::mat4 model(1.0f);

    model = glm::translate(model, position);

    model = glm::rotate(model, rotation.x, {1,0,0});
    model = glm::rotate(model, rotation.y, {0,1,0});
    model = glm::rotate(model, rotation.z, {0,0,1});

    model = glm::scale(model, scale);

    return model;
}
