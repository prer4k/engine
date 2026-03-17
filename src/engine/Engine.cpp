#include "engine/Engine.h"

#include <GLFW/glfw3.h>

Engine::Engine(int width, int height, const char* title, std::unique_ptr<IGame> game)
    : window(width, height, title)
    , input(window.get())
    , renderer()
    , scene()
    , assetStore()
    , camera(static_cast<float>(width) / static_cast<float>(height))
    , cameraController(camera)
    , game(std::move(game))
{
    window.setCursorDisabled(false);
    cameraController.setEnabled(false);

    if (this->game)
        this->game->init(*this);
}

int Engine::run()
{
    float lastTime = static_cast<float>(glfwGetTime());

    while (!window.shouldClose())
    {
        renderer.beginFrame();

        const float time = static_cast<float>(glfwGetTime());
        const float dt = time - lastTime;
        lastTime = time;

        update(time, dt);
        render();

        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}

Assets& Engine::assets()
{
    return assetStore;
}

Object& Engine::spawn(std::shared_ptr<Mesh> mesh,
                      std::shared_ptr<Material> material,
                      const glm::vec3& position)
{
    return scene.addObjectRef(Object(position, std::move(mesh), std::move(material)));
}

void Engine::update(float time, float dt)
{
    scene.update(time, dt);
    handleCursorLock();
    cameraController.update(input, dt);

    if (game)
        game->update(*this, time, dt);
}

void Engine::render()
{
    renderer.draw(scene, camera, renderParams);
}

void Engine::handleCursorLock()
{
    if (input.isKeyPressed(GLFW_KEY_ESCAPE))
    {
        window.setCursorDisabled(false);
        mouseLocked = false;
        cameraController.setEnabled(false);
        return;
    }

    if (!mouseLocked && input.isMousePressed(GLFW_MOUSE_BUTTON_LEFT))
    {
        window.setCursorDisabled(true);
        cameraController.resetMouse();
        mouseLocked = true;
        cameraController.setEnabled(true);
    }
}

