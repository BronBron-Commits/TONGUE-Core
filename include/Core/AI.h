#pragma once
#include <vector>
#include <functional>
#include <unordered_map>

namespace Core {

class AIController {
public:
    using DecisionFunc = std::function<void(int entityId)>;
    void registerAI(int entityId, DecisionFunc func);
    void update(float deltaTime);
private:
    std::unordered_map<int, DecisionFunc> aiMap;
};

} // namespace Core
