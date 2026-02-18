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

    // Health logic
    float getHealth() const { return health; }
    float getMaxHealth() const { return maxHealth; }
    void setHealth(float h) { health = std::min(h, maxHealth); }
    void increaseMaxHealth(float amount) { maxHealth += amount; }

    // Mana logic (stub for now)
    float getMana() const { return mana; }
    float getMaxMana() const { return maxMana; }
    void setMana(float m) { mana = std::min(m, maxMana); }

    // ...existing stat methods...
    void SetStat(StatType type, float value);
    float GetStat(StatType type) const;
    void ModifyStat(StatType type, float delta);

private:
    float health = 100;
    float maxHealth = 100;
    float mana = 100;
    float maxMana = 100;
    std::unordered_map<StatType, float> stats;
};

}
