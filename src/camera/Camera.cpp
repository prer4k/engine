#include "camera/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float aspect)
{
    this->aspect = aspect;
}

glm::mat4 Camera::getViewMatrix() const
{
    glm::vec3 front;

    front.x =
        cos(glm::radians(yaw)) *
        cos(glm::radians(pitch));

    front.y =
        sin(glm::radians(pitch));

    front.z =
        sin(glm::radians(yaw)) *
        cos(glm::radians(pitch));

    glm::vec3 dir = glm::normalize(front);

    return glm::lookAt(
        position,
        position + dir,
        glm::vec3(0,1,0)
    );
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(
        glm::radians(fov),
        aspect,
        nearPlane,
        farPlane
    );
}

glm::vec3 Camera::getFront() const
{
    glm::vec3 front;

    front.x =
        cos(glm::radians(yaw)) *
        cos(glm::radians(pitch));

    front.y =
        sin(glm::radians(pitch));

    front.z =
        sin(glm::radians(yaw)) *
        cos(glm::radians(pitch));

    return glm::normalize(front);
}

void Camera::setAspect(float aspect)
{
    this->aspect = aspect;
}
