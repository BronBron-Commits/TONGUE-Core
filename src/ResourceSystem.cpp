#include "Core/ResourceSystem.h"

namespace Core {


void ResourceSystem::registerEntity(int entityId, Stats* stats) {
    entityStats[entityId] = stats;
}

void ResourceSystem::update(float deltaTime) {
    float regenRate = 5.0f; // Example: 5 mana/sec
    for (auto& pair : entityStats) {
        pair.second->setMana(pair.second->getMana() + regenRate * deltaTime);
    }
}

bool ResourceSystem::consume(int entityId, float manaCost) {
    auto it = entityStats.find(entityId);
    if (it != entityStats.end() && it->second->getMana() >= manaCost) {
        it->second->setMana(it->second->getMana() - manaCost);
        return true;
    }
    return false;
}

} // namespace Core
