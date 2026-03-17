#include "engine/Engine.h"
#include "game/DemoGame.h"

#include <memory>

int main()
{
    Engine engine(800, 600, "engine", std::make_unique<DemoGame>());
    return engine.run();
}
