#include "Core/Ability.h"

namespace Core {

Ability::Ability(const std::string& name) : name(name), cooldown(0.0f) {}
Ability::~Ability() {}
void Ability::Activate() {}
float Ability::GetCooldown() const { return cooldown; }
void Ability::SetCooldown(float cd) { cooldown = cd; }

}