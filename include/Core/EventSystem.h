#pragma once
#include <functional>
#include <unordered_map>
#include <vector>
#include <string>

namespace Core {

// Base event type
struct Event {
    std::string type;
};

using EventCallback = std::function<void(const Event&)>;

class EventSystem {
public:
    void subscribe(const std::string& eventType, EventCallback callback);
    void dispatch(const Event& event);
private:
    std::unordered_map<std::string, std::vector<EventCallback>> listeners;
};

} // namespace Core
