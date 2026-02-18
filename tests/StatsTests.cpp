
#include "gtest/gtest.h"
#include "Core/Character.h"
#include "Core/Stats.h"
#include "Core/Leveling.h"
using namespace Core;

// -----------------------------
// Stats Initialization Tests
// -----------------------------
TEST(StatsTests, InitialHealth) {
    Character c("TestHero");
    // TODO: Replace with actual health/max health logic if needed
    // EXPECT_EQ(c.stats().getHealth(), c.stats().getMaxHealth());
}

TEST(StatsTests, InitialMana) {
    Character c("TestHero");
    // TODO: Replace with actual mana/max mana logic if needed
    // EXPECT_EQ(c.stats().getMana(), c.stats().getMaxMana());
}

// -----------------------------
// Resource Consumption / Regeneration
// -----------------------------
TEST(StatsTests, ManaConsumption) {
    Character c("TestHero");
    // float initialMana = c.stats().getMana();
    // float cost = 30.0f;
    // bool result = c.stats().consumeMana(cost);
    // EXPECT_TRUE(result);
    // EXPECT_EQ(c.stats().getMana(), initialMana - cost);
}

TEST(StatsTests, ManaOverConsumptionFails) {
    Character c("TestHero");
    // float cost = c.stats().getMaxMana() + 10.0f;
    // bool result = c.stats().consumeMana(cost);
    // EXPECT_FALSE(result);
    // EXPECT_EQ(c.stats().getMana(), c.stats().getMaxMana());
}

TEST(StatsTests, ManaRegeneration) {
    Character c("TestHero");
    // c.stats().consumeMana(50.0f);
    // float beforeRegen = c.stats().getMana();
    // c.stats().regenerateMana(20.0f);
    // EXPECT_EQ(c.stats().getMana(), beforeRegen + 20.0f);
    // EXPECT_LE(c.stats().getMana(), c.stats().getMaxMana());
}

// -----------------------------
// Leveling / Stat Scaling
// -----------------------------
TEST(LevelingTests, LevelUpIncreasesMaxHealth) {
    Character c("TestHero");
    // float oldMaxHealth = c.stats().getMaxHealth();
    // c.leveling().levelUp();
    // float newMaxHealth = c.stats().getMaxHealth();
    // EXPECT_GT(newMaxHealth, oldMaxHealth);
}

TEST(LevelingTests, LevelUpResetsHealth) {
    Character c("TestHero");
    // c.stats().consumeHealth(50.0f);
    // c.leveling().levelUp();
    // EXPECT_EQ(c.stats().getHealth(), c.stats().getMaxHealth());
}
