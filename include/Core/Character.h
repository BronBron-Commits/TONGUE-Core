

#pragma once
#include <string>
#include "Entity.h"
#include "Stats.h"
#include "Leveling.h"

namespace Core {
// Character entity with stats and leveling
class Character : public Entity {
public:
    Character(const std::string& name);
    virtual ~Character();

    // Get current health (delegates to Stats)
    int getHealth() const;
    // Level up (delegates to Leveling and updates Stats)
    void levelUp();

    // Accessors for Stats and Leveling
    Stats& stats();
    const Stats& stats() const;
    Leveling& leveling();
    const Leveling& leveling() const;

private:
    std::string name;
    Stats m_stats;      // Health, mana, etc.
    Leveling m_leveling; // XP, level, etc.
};
}
