

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


// =============================
// Resource & Stat Management
// =============================
TEST(StatsTests, ResourceInitialization) {
    // TODO: Create a Character/Stats and check mana/energy/rage default values
}

TEST(StatsTests, ResourceConsumption) {
    // TODO: Simulate ability use and check resource decrease
}

TEST(StatsTests, ResourceRegeneration) {
    // TODO: Simulate time passing and check resource increases
}

// =============================
// Abilities / Moves
// =============================
TEST(AbilityTests, CooldownPreventsReuse) {
    // TODO: Use ability, check cooldown, try to reuse before ready
}

TEST(AbilityTests, DamageAppliesCorrectly) {
    // TODO: Use damaging ability and check target HP decrease
}

TEST(AbilityTests, HealingAppliesCorrectly) {
    // TODO: Use healing ability and check target HP increase
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
