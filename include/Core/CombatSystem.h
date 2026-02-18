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
    void attack(int sourceId, int targetId, float amount, const std::string& type);
private:
    EventSystem& events;
};

} // namespace Core
