#pragma once
#include "Stats.h"

namespace Core {

class ResourceSystem {
public:
    // Register an entity's stats for resource management
    void registerEntity(int entityId, Stats* stats);

    // Regenerate resources for all registered entities
    void update(float deltaTime);

    // Consume resource for a specific entity
    bool consume(int entityId, float manaCost);

private:
    std::unordered_map<int, Stats*> entityStats;
};

} // namespace Core
