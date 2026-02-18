#include "Core/CoreManager.h"

namespace Core {

CoreManager::CoreManager()
	: m_combat(m_events) {}

void CoreManager::update(float deltaTime) {
	// Example update order: Buffs, Cooldowns, Resources
	m_buff.update(deltaTime);
	m_cooldown.update(deltaTime);
	// Resource regen could be called per entity elsewhere
}

EventSystem& CoreManager::eventSystem() { return m_events; }
CombatSystem& CoreManager::combatSystem() { return m_combat; }
ResourceSystem& CoreManager::resourceSystem() { return m_resource; }
CooldownSystem& CoreManager::cooldownSystem() { return m_cooldown; }
BuffSystem& CoreManager::buffSystem() { return m_buff; }

} // namespace Core
