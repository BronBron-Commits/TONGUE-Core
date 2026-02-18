#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

namespace Core {

struct Buff {
    std::string name;
    float duration;
    float modifier;
    std::function<void()> onStart;
    std::function<void()> onEnd;
};

class BuffSystem {
public:
    void addBuff(int entityId, const Buff& buff);
    void update(float deltaTime);
private:
    std::unordered_map<int, std::vector<Buff>> activeBuffs;
};

} // namespace Core
