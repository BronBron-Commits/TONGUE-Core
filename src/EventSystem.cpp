#include "Core/EventSystem.h"

namespace Core {

void EventSystem::subscribe(const std::string& eventType, EventCallback callback) {
    listeners[eventType].push_back(callback);
}

void EventSystem::dispatch(const Event& event) {
    auto it = listeners.find(event.type);
    if (it != listeners.end()) {
        for (auto& cb : it->second) {
            cb(event);
        }
    }
}

} // namespace Core
