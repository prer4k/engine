#include "core/Input.h"

Input::Input(GLFWwindow* w)
{
    window = w;
}

bool Input::isKeyPressed(int key) const
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool Input::isMousePressed(int button) const
{
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

double Input::getMouseX() const
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return x;
}

double Input::getMouseY() const
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return y;
}
