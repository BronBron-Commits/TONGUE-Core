#include "Core/CombatSystem.h"

namespace Core {


CombatSystem::CombatSystem(EventSystem& eventSystem) : events(eventSystem) {}

void CombatSystem::registerEntity(int entityId, Stats* stats) {
    entityStats[entityId] = stats;
}

void CombatSystem::attack(int sourceId, int targetId, float amount, const std::string& type) {
    // Apply damage to target's stats
    auto it = entityStats.find(targetId);
    if (it != entityStats.end()) {
        float newHP = it->second->getHealth() - amount;
        it->second->setHealth(newHP);
    }
    // Dispatch event
    DamageEvent ev;
    ev.type = "OnDamage";
    ev.sourceId = sourceId;
    ev.targetId = targetId;
    ev.amount = amount;
    ev.damageType = type;
    events.dispatch(ev);
}

void CombatSystem::heal(int sourceId, int targetId, float amount) {
    auto it = entityStats.find(targetId);
    if (it != entityStats.end()) {
        float newHP = it->second->getHealth() + amount;
        it->second->setHealth(newHP);
    }
    // Could dispatch OnHeal event here
}

void CombatSystem::update(float /*deltaTime*/) {
    // For future: process queued combat events, DoTs, etc.
}

} // namespace Core
