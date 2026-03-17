#include "camera/CameraController.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

CameraController::CameraController(Camera& camera)
    : camera(camera)
{
}

void CameraController::setEnabled(bool enabled)
{
    this->enabled = enabled;
}

bool CameraController::isEnabled() const
{
    return enabled;
}

void CameraController::resetMouse()
{
    firstMouse = true;
}

void CameraController::update(const Input& input, float dt)
{
    if (!enabled)
        return;

    const bool fast =
        input.isKeyPressed(GLFW_KEY_LEFT_SHIFT) ||
        input.isKeyPressed(GLFW_KEY_RIGHT_SHIFT);

    const float speed = moveSpeed * (fast ? 3.0f : 1.0f);

    const glm::vec3 front = camera.getFront();
    const glm::vec3 up(0, 1, 0);
    const glm::vec3 right =
        glm::normalize(glm::cross(front, up));

    if (input.isKeyPressed(GLFW_KEY_W))
        camera.position += front * speed * dt;
    if (input.isKeyPressed(GLFW_KEY_S))
        camera.position -= front * speed * dt;
    if (input.isKeyPressed(GLFW_KEY_A))
        camera.position -= right * speed * dt;
    if (input.isKeyPressed(GLFW_KEY_D))
        camera.position += right * speed * dt;
    if (input.isKeyPressed(GLFW_KEY_E))
        camera.position += up * speed * dt;
    if (input.isKeyPressed(GLFW_KEY_Q))
        camera.position -= up * speed * dt;

    const double x = input.getMouseX();
    const double y = input.getMouseY();

    if (firstMouse)
    {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    const double dx = x - lastX;
    const double dy = lastY - y;

    lastX = x;
    lastY = y;

    camera.yaw += static_cast<float>(dx) * sensitivity;
    camera.pitch += static_cast<float>(dy) * sensitivity;

    if (camera.pitch > 89.0f) camera.pitch = 89.0f;
    if (camera.pitch < -89.0f) camera.pitch = -89.0f;
}

