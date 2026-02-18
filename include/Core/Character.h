
#pragma once
#include <string>
#include "Entity.h"

namespace Core {
class Character : public Entity {
public:
    Character(const std::string& name);
    virtual ~Character();

    int getHealth() const;
    void levelUp();

private:
    std::string name;
    int health = 100;
    int level = 1;
};
}
