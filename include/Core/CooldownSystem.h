#pragma once
#include <unordered_map>
#include <string>

namespace Core {

class CooldownSystem {
public:
    void setCooldown(int entityId, const std::string& ability, float time);
    bool isOnCooldown(int entityId, const std::string& ability) const;
    void update(float deltaTime);
private:
    std::unordered_map<int, std::unordered_map<std::string, float>> cooldowns;
};

} // namespace Core
