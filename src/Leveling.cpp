#include "Core/Leveling.h"

namespace Core {

Leveling::Leveling() : level(1), xp(0) {}

void Leveling::AddXP(int amount) {
    xp += amount;
    // Example: 100 XP per level
    while (xp >= GetXPToNextLevel()) {
        xp -= GetXPToNextLevel();
        level++;
    }
}

int Leveling::GetLevel() const {
    return level;
}

int Leveling::GetXP() const {
    return xp;
}

int Leveling::GetXPToNextLevel() const {
    return 100 * level;
}

}