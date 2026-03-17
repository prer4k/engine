#include "renderer/Renderer.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer()
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,800,600);
}

void Renderer::beginFrame()
{
    glClearColor(0.1f,0.1f,0.15f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::endFrame()
{
}

void Renderer::setModel(Shader& shader,
                        const glm::mat4& model)
{
    int loc = glGetUniformLocation(
        shader.ID,
        "model"
    );

    glUniformMatrix4fv(
        loc,
        1,
        GL_FALSE,
        glm::value_ptr(model)
    );
}

void Renderer::draw(
    const Scene& scene,
    const Camera& camera,
    const RenderParams& params)
{
    const glm::mat4 view = camera.getViewMatrix();
    const glm::mat4 proj = camera.getProjectionMatrix();

    for (const auto& obj : scene.getObjects())
    {
        const Material& mat = obj.getMaterial();
        if (!mat.shader)
            continue;

        mat.shader->use();

        // common matrices
        const int vLoc = glGetUniformLocation(mat.shader->ID, "view");
        const int pLoc = glGetUniformLocation(mat.shader->ID, "projection");
        const int mLoc = glGetUniformLocation(mat.shader->ID, "model");

        glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(proj));

        const glm::mat4 model = obj.getModel();
        glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(model));

        // lighting (if shader uses it)
        const int lightPosLoc = glGetUniformLocation(mat.shader->ID, "lightPos");
        if (lightPosLoc != -1)
            glUniform3f(lightPosLoc, params.lightPos.x, params.lightPos.y, params.lightPos.z);

        const int lightColorLoc = glGetUniformLocation(mat.shader->ID, "lightColor");
        if (lightColorLoc != -1)
            glUniform3f(lightColorLoc, params.lightColor.x, params.lightColor.y, params.lightColor.z);

        // material params (optional uniforms)
        const int baseColorLoc = glGetUniformLocation(mat.shader->ID, "baseColor");
        if (baseColorLoc != -1)
            glUniform3f(baseColorLoc, mat.baseColor.x, mat.baseColor.y, mat.baseColor.z);

        const int useTextureLoc = glGetUniformLocation(mat.shader->ID, "useTexture");
        if (useTextureLoc != -1)
            glUniform1i(useTextureLoc, mat.albedo ? 1 : 0);

        const int toonStepsLoc = glGetUniformLocation(mat.shader->ID, "toonSteps");
        if (toonStepsLoc != -1)
            glUniform1f(toonStepsLoc, mat.toonSteps);

        // albedo texture (optional)
        const int texLoc = glGetUniformLocation(mat.shader->ID, "tex");
        if (texLoc != -1 && mat.albedo)
        {
            glActiveTexture(GL_TEXTURE0);
            mat.albedo->bind();
            glUniform1i(texLoc, 0);
        }

        obj.getMesh().draw();
    }
}
