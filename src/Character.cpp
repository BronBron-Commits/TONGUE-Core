
#include "Core/Character.h"
#include <string>

namespace Core {

Character::Character(const std::string& name) : name(name) {}
Character::~Character() {}


int Character::getHealth() const {
	return static_cast<int>(m_stats.getHealth());
}

void Character::levelUp() {
	m_leveling.levelUp();
	m_stats.increaseMaxHealth(20); // Example: increase max health by 20
	m_stats.setHealth(m_stats.getMaxHealth()); // Restore health to max
}

Stats& Character::stats() { return m_stats; }
const Stats& Character::stats() const { return m_stats; }
Leveling& Character::leveling() { return m_leveling; }
const Leveling& Character::leveling() const { return m_leveling; }
}
