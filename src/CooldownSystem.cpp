#include "Core/CooldownSystem.h"

namespace Core {

void CooldownSystem::setCooldown(int entityId, const std::string& ability, float time) {
    cooldowns[entityId][ability] = time;
}

bool CooldownSystem::isOnCooldown(int entityId, const std::string& ability) const {
    auto it = cooldowns.find(entityId);
    if (it != cooldowns.end()) {
        auto ab = it->second.find(ability);
        if (ab != it->second.end())
            return ab->second > 0.0f;
    }
    return false;
}

void CooldownSystem::update(float deltaTime) {
    for (auto& entity : cooldowns) {
        for (auto& ab : entity.second) {
            if (ab.second > 0.0f) {
                ab.second -= deltaTime;
                if (ab.second < 0.0f) ab.second = 0.0f;
            }
        }
    }
}

} // namespace Core
