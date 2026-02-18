#include "Core/Effect.h"

namespace Core {

Effect::Effect(const std::string& name) : name(name) {}
Effect::~Effect() {}
void Effect::Apply() {}

}