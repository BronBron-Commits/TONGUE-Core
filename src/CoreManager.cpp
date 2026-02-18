#include "Core/CoreManager.h"

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
	m_buff.update(deltaTime);       // 2. Buffs
	m_combat.update(deltaTime);     // 3. Combat
	m_cooldown.update(deltaTime);   // 4. Cooldowns
	// 5. Event dispatching is handled by systems as needed
}

EventSystem& CoreManager::eventSystem() { return m_events; }
CombatSystem& CoreManager::combatSystem() { return m_combat; }
ResourceSystem& CoreManager::resourceSystem() { return m_resource; }
CooldownSystem& CoreManager::cooldownSystem() { return m_cooldown; }
BuffSystem& CoreManager::buffSystem() { return m_buff; }

} // namespace Core
