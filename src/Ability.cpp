#include "Core/Ability.h"
#include <memory>
#include <utility>

namespace Core {

Ability::Ability(const std::string& name, float damage, float manaCost, float cooldown)
	: m_name(name), m_damage(damage), m_manaCost(manaCost), m_cooldown(cooldown) {}

Ability::~Ability() {}

float Ability::getDamage() const { return m_damage; }
float Ability::getManaCost() const { return m_manaCost; }
float Ability::getCooldown() const { return m_cooldown; }
const std::string& Ability::getName() const { return m_name; }

void Ability::setOnHitEffect(std::shared_ptr<Ability> effect) { m_onHitEffect = std::move(effect); }
std::shared_ptr<Ability> Ability::getOnHitEffect() const { return m_onHitEffect; }

}