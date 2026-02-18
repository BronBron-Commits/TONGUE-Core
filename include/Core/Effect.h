#pragma once

#include <string>

namespace Core {

class Effect {
public:
    Effect(const std::string& name);
    virtual ~Effect();
    virtual void Apply();
private:
    std::string name;
};

}
