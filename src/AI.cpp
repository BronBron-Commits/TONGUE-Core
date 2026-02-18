#include "Core/AI.h"

namespace Core {

void AIController::registerAI(int entityId, DecisionFunc func) {
    aiMap[entityId] = func;
}

void AIController::update(float deltaTime) {
    for (auto& [entityId, func] : aiMap) {
        func(entityId);
    }
}

} // namespace Core
