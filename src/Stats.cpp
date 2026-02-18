#include "Core/Stats.h"

namespace Core {

Stats::Stats() {}

void Stats::SetStat(StatType type, float value) {
    stats[type] = value;
}

float Stats::GetStat(StatType type) const {
    auto it = stats.find(type);
    return it != stats.end() ? it->second : 0.0f;
}

void Stats::ModifyStat(StatType type, float delta) {
    stats[type] += delta;
}

}