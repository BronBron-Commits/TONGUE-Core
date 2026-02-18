#pragma once

namespace Core {

class Leveling {
public:
    Leveling();
    void AddXP(int amount);
    void levelUp();
    int GetLevel() const;
    int GetXP() const;
    int GetXPToNextLevel() const;
private:
    int level;
    int xp;
};

}
