#include "Core/CooldownManager.h"

namespace Core {

CooldownManager::CooldownManager() {}

void CooldownManager::SetCooldown(const std::string& ability, float time) {
    cooldowns[ability] = time;
}

float CooldownManager::GetCooldown(const std::string& ability) const {
    auto it = cooldowns.find(ability);
    return it != cooldowns.end() ? it->second : 0.0f;
}

void CooldownManager::Tick(float deltaTime) {
    for (auto& pair : cooldowns) {
        if (pair.second > 0.0f) {
            pair.second -= deltaTime;
            if (pair.second < 0.0f) pair.second = 0.0f;
        }
    }
}

}