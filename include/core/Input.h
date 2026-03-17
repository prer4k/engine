#pragma once

#include <GLFW/glfw3.h>

class Input
{
public:
    explicit Input(GLFWwindow* window);

    bool isKeyPressed(int key) const;
    bool isMousePressed(int button) const;

    double getMouseX() const;
    double getMouseY() const;

private:
    GLFWwindow* window;
};
