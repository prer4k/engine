#include "game/DemoGame.h"

#include "engine/Engine.h"
#include "graphics/Geometry.h"

#include <cstdlib>
#include <cmath>

namespace
{
    glm::vec3 randomPos()
    {
        const float x = (std::rand() % 10) - 5;
        const float y = (std::rand() % 10) - 5;
        const float z = (std::rand() % 10) - 5;
        return glm::vec3(x, y, z);
    }
}

void DemoGame::init(Engine& engine)
{
    // Meshes (shared)
    auto cubeGeo = Geometry::cube();
    auto sphereGeo = Geometry::uvSphere(16, 32);

    auto cubeMesh = engine.assets().mesh("geo:cube", cubeGeo.vertices, cubeGeo.stride);
    auto sphereMesh = engine.assets().mesh("geo:sphere", sphereGeo.vertices, sphereGeo.stride);

    // Shaders (shared)
    auto basic = engine.assets().shader("shader:basic", "./shaders/basic.vert", "./shaders/basic.frag");
    auto toon = engine.assets().shader("shader:toon", "./shaders/toon.vert", "./shaders/toon.frag");

    // Textures (shared)
    auto cat = engine.assets().texture2D("tex:cat", "assets/image.JPG");

    // Materials (shared)
    auto cubeMat = engine.assets().material("mat:cube");
    cubeMat->shader = basic;
    cubeMat->albedo = cat;
    cubeMat->baseColor = glm::vec3(1.0f);

    auto sphereMat = engine.assets().material("mat:sphereToon");
    sphereMat->shader = toon;
    sphereMat->albedo.reset();
    sphereMat->baseColor = glm::vec3(0.35f, 0.7f, 1.0f);
    sphereMat->toonSteps = 4.0f;

    // Spawn a demo mix
    for (int i = 0; i < 12; i++)
    {
        auto& o = engine.spawn(cubeMesh, cubeMat, randomPos());
        o.behavior = [](Object& self, float time, float dt) {
            (void)dt;
            self.transform.rotation.y = time;
        };
    }

    for (int i = 0; i < 8; i++)
    {
        auto& o = engine.spawn(sphereMesh, sphereMat, randomPos());
        o.behavior = [](Object& self, float time, float dt) {
            (void)dt;
            self.transform.position.y += std::sin(time) * 0.0025f;
            self.transform.rotation.x = time * 0.5f;
        };
    }
}

void DemoGame::update(Engine& engine, float time, float dt)
{
    (void)engine;
    (void)time;
    (void)dt;
    // Game-level update hook (optional); most per-object behavior lives on objects for now.
}

