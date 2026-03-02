#include "camera/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float aspect)
{
    position = {0.0f, 0.0f, 3.0f};

    this->aspect = aspect;

    fov = 45.0f;
    nearPlane = 0.1f;
    farPlane = 100.0f;
}

glm::mat4 Camera::getViewMatrix()
{
    glm::mat4 view(1.0f);

    view = glm::translate(
        view,
        -position
    );

    return view;
}

glm::mat4 Camera::getProjectionMatrix()
{
    return glm::perspective(
        glm::radians(fov),
        aspect,
        nearPlane,
        farPlane
    );
}
