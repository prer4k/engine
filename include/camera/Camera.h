#pragma once

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>

class Camera
{
public:
    Camera(float aspect);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;
    glm::vec3 getFront() const;

    void setAspect(float aspect);

    glm::vec3 position {0.0f, 0.0f, 5.0f};
    float fov = 45.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;

    float yaw = -90.0f;
    float pitch = 0.0f;

private:
    float aspect;
};
