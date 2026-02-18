#pragma once

#include <unordered_map>
#include <string>

namespace Core {

// Enum for stat types
enum class StatType {
    Health,
    Mana,
    AttackDamage,
    Armor,
    MagicResist,
    // Add more as needed
};

class Stats {
public:
    Stats();
    void SetStat(StatType type, float value);
    float GetStat(StatType type) const;
    void ModifyStat(StatType type, float delta);
private:
    std::unordered_map<StatType, float> stats;
};

}
