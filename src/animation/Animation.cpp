#include "animation/Animation.h"

#include <cmath>

Animation::Animation()
{
    radius = 0.5f;
    speed  = 2.0f;
}

void Animation::update(Transform& t, float time)
{
    t.position.x = cos(time) * radius;
    t.position.y = sin(time) * radius;

    t.rotation.z = time * speed;
}
