#pragma once

#include <memory>

#include "camera/Camera.h"
#include "camera/CameraController.h"
#include "core/Input.h"
#include "core/Window.h"
#include "engine/Assets.h"
#include "game/IGame.h"
#include "renderer/Renderer.h"
#include "scene/Scene.h"

class Engine
{
public:
    Engine(int width, int height, const char* title, std::unique_ptr<IGame> game);

    int run();

    // "Game-facing" API
    Assets& assets();
    Object& spawn(std::shared_ptr<Mesh> mesh,
                  std::shared_ptr<Material> material,
                  const glm::vec3& position);

private:
    void update(float time, float dt);
    void render();
    void handleCursorLock();

    Window window;
    Input input;

    Renderer renderer;
    Scene scene;
    Assets assetStore;

    Camera camera;
    CameraController cameraController;

    RenderParams renderParams;
    bool mouseLocked = false;

    std::unique_ptr<IGame> game;
};

