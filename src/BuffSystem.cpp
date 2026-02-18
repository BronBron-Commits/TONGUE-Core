#include "Core/BuffSystem.h"

namespace Core {

void BuffSystem::addBuff(int entityId, const Buff& buff) {
    // If not stackable, replace existing buff of same name
    if (!buff.isStackable) {
        auto& buffs = activeBuffs[entityId];
        for (auto it = buffs.begin(); it != buffs.end(); ) {
            if (it->name == buff.name) {
                if (it->onEnd) it->onEnd();
                it = buffs.erase(it);
            } else {
                ++it;
            }
        }
    }
    activeBuffs[entityId].push_back(buff);
    if (buff.onStart) buff.onStart();
}

void BuffSystem::update(float deltaTime) {
    for (auto& pair : activeBuffs) {
        auto& buffs = pair.second;
        for (auto it = buffs.begin(); it != buffs.end(); ) {
            it->duration -= deltaTime;
            // Status effect logic (e.g., poison tick)
            if (it->type == BuffType::Poison && it->modifier != 0) {
                // TODO: Apply poison damage to entity (requires Stats reference)
            }
            if (it->duration <= 0) {
                if (it->onEnd) it->onEnd();
                it = buffs.erase(it);
            } else {
                ++it;
            }
        }
    }
}

} // namespace Core
