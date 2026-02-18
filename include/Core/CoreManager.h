#pragma once
#include "EventSystem.h"
#include "CombatSystem.h"
#include "ResourceSystem.h"
#include "CooldownSystem.h"
#include "BuffSystem.h"
#include "AI.h"

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
    AIController& aiController();
private:
    EventSystem m_events;
    CombatSystem m_combat;
    ResourceSystem m_resource;
    CooldownSystem m_cooldown;
    BuffSystem m_buff;
    AIController m_ai;
};
}
