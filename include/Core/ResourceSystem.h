#pragma once
#include "Stats.h"

namespace Core {

class ResourceSystem {
public:
    void regenerate(Stats& stats, float deltaTime);
    bool consume(Stats& stats, float manaCost);
};

} // namespace Core
