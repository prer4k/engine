#pragma once

#include <glm/gtc/matrix_transform.hpp>

#include "core/Shader.h"
#include "camera/Camera.h"
#include "scene/Scene.h"

class Renderer
{
public:

    Renderer();

    void beginFrame();

    void endFrame();

    void setModel(Shader& shader, const glm::mat4& model);

    void draw(Scene& scene, Shader& shader, Camera& camera);
};
