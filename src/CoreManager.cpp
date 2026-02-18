#include "Core/CoreManager.h"
#include "Core/AI.h"

namespace Core {


CoreManager::CoreManager()
	: m_combat(m_events) {}

void CoreManager::registerEntity(int entityId, Stats* stats) {
	m_combat.registerEntity(entityId, stats);
	m_resource.registerEntity(entityId, stats);
	// BuffSystem and CooldownSystem can be extended similarly
}

void CoreManager::update(float deltaTime) {
	// Example update order:
	m_resource.update(deltaTime);   // 1. Resource regeneration
	m_cooldown.update(deltaTime);   // 2. Cooldowns
	m_buff.update(deltaTime);       // 3. Buffs
	m_ai.update(deltaTime);         // 4. AI/Decision
	m_combat.update(deltaTime);     // 5. Combat
	// 6. Event dispatching is handled by systems as needed
}

EventSystem& CoreManager::eventSystem() { return m_events; }
CombatSystem& CoreManager::combatSystem() { return m_combat; }
ResourceSystem& CoreManager::resourceSystem() { return m_resource; }
CooldownSystem& CoreManager::cooldownSystem() { return m_cooldown; }
BuffSystem& CoreManager::buffSystem() { return m_buff; }
AIController& CoreManager::aiController() { return m_ai; }

} // namespace Core
