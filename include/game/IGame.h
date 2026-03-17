#pragma once

class Engine;

class IGame
{
public:
    virtual ~IGame() = default;

    virtual void init(Engine& engine) = 0;
    virtual void update(Engine& engine, float time, float dt) = 0;
};

