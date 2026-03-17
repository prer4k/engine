#pragma once

#include <memory>
#include <glm/glm.hpp>

#include "core/Shader.h"
#include "graphics/Texture.h"

struct Material
{
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Texture> albedo; // optional

    glm::vec3 baseColor {1.0f, 1.0f, 1.0f};
    float toonSteps = 4.0f; // used by toon shader
};

