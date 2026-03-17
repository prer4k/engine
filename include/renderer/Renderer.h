#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "core/Shader.h"
#include "camera/Camera.h"
#include "scene/Scene.h"
#include "renderer/Material.h"

struct RenderParams
{
    glm::vec3 lightPos {2.0f, 2.0f, 2.0f};
    glm::vec3 lightColor {1.0f, 1.0f, 1.0f};
};

class Renderer
{
public:

    Renderer();

    void beginFrame();

    void endFrame();

    void setModel(Shader& shader, const glm::mat4& model);

    void draw(const Scene& scene,
              const Camera& camera,
              const RenderParams& params);
};
