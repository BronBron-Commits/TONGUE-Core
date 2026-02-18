#pragma once

#include <unordered_map>
#include <string>

namespace Core {

class CooldownManager {
public:
    CooldownManager();
    void SetCooldown(const std::string& ability, float time);
    float GetCooldown(const std::string& ability) const;
    void Tick(float deltaTime);
private:
    std::unordered_map<std::string, float> cooldowns;
};

}
