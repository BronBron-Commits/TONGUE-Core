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

    // --- Health management ---
    // Get current health
    float getHealth() const { return health; }
    // Get maximum health
    float getMaxHealth() const { return maxHealth; }
    // Set current health (clamped to max)
    void setHealth(float h) { health = std::min(h, maxHealth); }
    // Increase maximum health
    void increaseMaxHealth(float amount) { maxHealth += amount; }

    // --- Mana management ---
    float getMana() const { return mana; }
    float getMaxMana() const { return maxMana; }
    void setMana(float m) { mana = std::min(m, maxMana); }

    // --- Generic stat interface ---
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
