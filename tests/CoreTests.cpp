

#include <gtest/gtest.h>

#include "../include/Core/Character.h"
using namespace Core;

// Simple test to verify Character health
TEST(CharacterTests, InitialHealth) {
    Character c("Hero");
    EXPECT_EQ(c.getHealth(), 100); // adjust to your default value
}

// Simple test for Leveling system
TEST(LevelingTests, LevelUpIncreasesHealth) {
    Character c("Hero");
    int oldHealth = c.getHealth();
    c.levelUp();
    EXPECT_GT(c.getHealth(), oldHealth);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
