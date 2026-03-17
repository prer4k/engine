#pragma once

#include "game/IGame.h"

class DemoGame : public IGame
{
public:
    void init(Engine& engine) override;
    void update(Engine& engine, float time, float dt) override;
};

