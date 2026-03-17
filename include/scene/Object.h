#pragma once

#include "math/Transform.h"
#include "animation/Animation.h"
#include "graphics/Mesh.h"
#include "graphics/Texture.h"
#include "renderer/Material.h"

#include <functional>
#include <memory>

class Object
{
public:
    Object(glm::vec3 pos,
           std::shared_ptr<Mesh> mesh,
           std::shared_ptr<Material> material);

    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;

    Object(Object&&) noexcept = default;
    Object& operator=(Object&&) noexcept = default;

    void update(float time, float dt);

    glm::mat4 getModel() const;

    const Mesh& getMesh() const;
    const Material& getMaterial() const;

    Transform transform;

    std::function<void(Object&, float time, float dt)> behavior;

private:
    Animation animation;
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;
};
