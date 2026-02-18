#include <gtest/gtest.h>
#include "Core/CoreManager.h"
#include "Core/Stats.h"

using namespace Core;

TEST(ScenarioTests, SimpleDuel) {
    CoreManager core;
    Stats aStats, bStats;
    int aId = 1, bId = 2;
    aStats.setHealth(100); bStats.setHealth(100);
    aStats.setMana(50); bStats.setMana(50);
    core.registerEntity(aId, &aStats);
    core.registerEntity(bId, &bStats);

    // A attacks B for 30 damage
    core.combatSystem().attack(aId, bId, 30, "physical");
    EXPECT_EQ(bStats.getHealth(), 70);

    // B heals self for 20
    core.combatSystem().heal(bId, bId, 20);
    EXPECT_EQ(bStats.getHealth(), 90);

    // Simulate a tick (resource regen, buffs, cooldowns)
    core.update(1.0f);
    EXPECT_GT(aStats.getMana(), 50);
    EXPECT_GT(bStats.getMana(), 50);
}
