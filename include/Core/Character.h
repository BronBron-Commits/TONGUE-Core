

#pragma once
#include <string>
#include "Entity.h"
#include "Stats.h"
#include "Leveling.h"

namespace Core {
class Character : public Entity {
public:
    Character(const std::string& name);
    virtual ~Character();

    int getHealth() const;
    void levelUp();

    // Accessors for Stats and Leveling
    Stats& stats();
    const Stats& stats() const;
    Leveling& leveling();
    const Leveling& leveling() const;

private:
    std::string name;
    Stats m_stats;
    Leveling m_leveling;
};
}
