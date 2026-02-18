#include <gtest/gtest.h>
#include "Core/Entity.h"
#include "Core/Component.h"
#include "Core/Character.h"
#include "Core/Move.h"
#include "Core/Event.h"
#include "Core/System.h"
#include "Core/CoreManager.h"

using namespace Core;

TEST(EntityTest, ConstructorDestructor) {
    Entity e;
}

TEST(ComponentTest, ConstructorDestructor) {
    Component c;
}

TEST(CharacterTest, ConstructorDestructor) {
    Character ch;
}

TEST(MoveTest, ConstructorDestructor) {
    Move m;
}

TEST(EventTest, ConstructorDestructor) {
    Event ev;
}

TEST(SystemTest, ConstructorDestructor) {
    System s;
}

TEST(CoreManagerTest, ConstructorDestructor) {
    CoreManager cm;
}
