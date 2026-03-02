#include "core/Window.h"
#include "core/Shader.h"
#include "renderer/Renderer.h"
#include "scene/Scene.h"
#include "camera/Camera.h"

int main()
{
    Window window(800,600,"engine");

    Renderer renderer;

    Shader shader(
        "./shaders/triangle.vert",
        "./shaders/triangle.frag"
    );
    Scene scene;

    Camera camera(800.0f/600.0f);

    while (!window.shouldClose())
    {
        renderer.beginFrame();

        float time = glfwGetTime();

        scene.update(time);

        shader.use();

        renderer.draw(
            scene,
            shader,
            camera
        );

        window.swapBuffers();
        window.pollEvents();
    }
}
