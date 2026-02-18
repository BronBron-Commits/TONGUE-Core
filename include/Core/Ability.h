
#pragma once
#include <string>
#include <memory>

namespace Core {

class Ability {
public:
    Ability(const std::string& name, float damage, float manaCost, float cooldown = 0.0f);
    virtual ~Ability();

    float getDamage() const;
    float getManaCost() const;
    float getCooldown() const;
    const std::string& getName() const;

    void setOnHitEffect(std::shared_ptr<Ability> effect);
    std::shared_ptr<Ability> getOnHitEffect() const;

private:
    std::string m_name;
    float m_damage;
    float m_manaCost;
    float m_cooldown;
    std::shared_ptr<Ability> m_onHitEffect;
};

}
