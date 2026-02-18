#pragma once
#include "EventSystem.h"
#include "CombatSystem.h"
#include "ResourceSystem.h"
#include "CooldownSystem.h"
#include "BuffSystem.h"

namespace Core {
class CoreManager {
public:
    CoreManager();
    void update(float deltaTime);

    // Register an entity with all systems
    void registerEntity(int entityId, Stats* stats);

    EventSystem& eventSystem();
    CombatSystem& combatSystem();
    ResourceSystem& resourceSystem();
    CooldownSystem& cooldownSystem();
    BuffSystem& buffSystem();
private:
    EventSystem m_events;
    CombatSystem m_combat;
    ResourceSystem m_resource;
    CooldownSystem m_cooldown;
    BuffSystem m_buff;
};
}
