
#include "Core/Character.h"
#include <string>

namespace Core {
Character::Character(const std::string& name) : name(name), health(100), level(1) {}
Character::~Character() {}

int Character::getHealth() const {
	return health;
}

void Character::levelUp() {
	level++;
	health += 20; // Example: increase health on level up
}
}
