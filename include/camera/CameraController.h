#pragma once

#include "camera/Camera.h"
#include "core/Input.h"

class CameraController
{
public:
    explicit CameraController(Camera& camera);

    void setEnabled(bool enabled);
    bool isEnabled() const;

    void update(const Input& input, float dt);
    void resetMouse();

private:
    Camera& camera;

    float moveSpeed = 2.5f;
    float sensitivity = 0.1f;

    bool enabled = true;
    bool firstMouse = true;
    double lastX = 0.0;
    double lastY = 0.0;
};

