#include "Core/ResourceSystem.h"

namespace Core {

void ResourceSystem::regenerate(Stats& stats, float deltaTime) {
    float regenRate = 5.0f; // Example: 5 mana/sec
    stats.setMana(stats.getMana() + regenRate * deltaTime);
}

bool ResourceSystem::consume(Stats& stats, float manaCost) {
    if (stats.getMana() >= manaCost) {
        stats.setMana(stats.getMana() - manaCost);
        return true;
    }
    return false;
}

} // namespace Core
