#include "scene/Object.h"

#include <utility>

Object::Object(glm::vec3 pos,
               std::shared_ptr<Mesh> mesh,
               std::shared_ptr<Material> material)
: mesh(std::move(mesh)),
  material(std::move(material))
{
    transform.position = pos;
}

void Object::update(float time, float dt)
{
    if (behavior)
    {
        behavior(*this, time, dt);
        return;
    }

    (void)dt;
    animation.update(transform, time);
}

glm::mat4 Object::getModel() const
{
    return transform.getModelMatrix();
}

const Mesh& Object::getMesh() const
{
    return *mesh;
}

const Material& Object::getMaterial() const
{
    return *material;
}
