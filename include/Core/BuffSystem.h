#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

namespace Core {

enum class BuffType { Generic, Stun, Poison, HealOverTime, StatBoost, StatDebuff };

struct Buff {
    std::string name;
    BuffType type = BuffType::Generic;
    float duration;
    float modifier; // e.g., damage multiplier, poison damage, etc.
    std::function<void()> onStart;
    std::function<void()> onEnd;
    bool isStackable = false;
};

class BuffSystem {
public:
    void addBuff(int entityId, const Buff& buff);
    void update(float deltaTime);
private:
    std::unordered_map<int, std::vector<Buff>> activeBuffs;
};

} // namespace Core
