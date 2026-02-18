#include "Core/CombatSystem.h"

namespace Core {

CombatSystem::CombatSystem(EventSystem& eventSystem) : events(eventSystem) {}

void CombatSystem::attack(int sourceId, int targetId, float amount, const std::string& type) {
    DamageEvent ev;
    ev.type = "OnDamage";
    ev.sourceId = sourceId;
    ev.targetId = targetId;
    ev.amount = amount;
    ev.damageType = type;
    events.dispatch(ev);
}

} // namespace Core
