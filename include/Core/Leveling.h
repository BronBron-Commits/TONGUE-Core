#pragma once

namespace Core {

// Handles XP, level, and progression
class Leveling {
public:
    Leveling();
    // Add experience points
    void AddXP(int amount);
    // Level up (increments level)
    void levelUp();
    // Get current level
    int GetLevel() const;
    // Get current XP
    int GetXP() const;
    // Get XP required for next level
    int GetXPToNextLevel() const;
private:
    int level; // Current level
    int xp;    // Current experience points
};

}
