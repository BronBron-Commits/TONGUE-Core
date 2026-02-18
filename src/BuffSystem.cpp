#include "Core/BuffSystem.h"

namespace Core {

void BuffSystem::addBuff(int entityId, const Buff& buff) {
    activeBuffs[entityId].push_back(buff);
    if (buff.onStart) buff.onStart();
}

void BuffSystem::update(float deltaTime) {
    for (auto& pair : activeBuffs) {
        auto& buffs = pair.second;
        for (auto it = buffs.begin(); it != buffs.end(); ) {
            it->duration -= deltaTime;
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
