#pragma once

#include <string>

namespace Core {

class Ability {
public:
    Ability(const std::string& name);
    virtual ~Ability();
    virtual void Activate();
    float GetCooldown() const;
    void SetCooldown(float cd);
private:
    std::string name;
    float cooldown;
};

}
