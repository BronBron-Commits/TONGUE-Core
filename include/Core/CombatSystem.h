#pragma once
#include "EventSystem.h"
#include "Stats.h"
#include <memory>

namespace Core {

struct DamageEvent : public Event {
    int sourceId;
    int targetId;
    float amount;
    std::string damageType; // e.g., "physical", "magical"
};

class CombatSystem {
public:
    CombatSystem(EventSystem& eventSystem);

    // Register an entity's stats for combat
    void registerEntity(int entityId, Stats* stats);

    // Apply direct damage
    void attack(int sourceId, int targetId, float amount, const std::string& type);

    // Apply healing
    void heal(int sourceId, int targetId, float amount);

    // Called per tick to resolve queued combat events (if any)
    void update(float deltaTime);

private:
    EventSystem& events;
    std::unordered_map<int, Stats*> entityStats;
};

} // namespace Core
