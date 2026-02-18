#include <gtest/gtest.h>
#include "Core/CoreManager.h"
#include "Core/Stats.h"
#include "Core/Ability.h"
#include <memory>

using namespace Core;

// Simultaneous Abilities Test
TEST(ScenarioTests, SimultaneousAbilitiesDoNotConflict) {
    Stats aStats, bStats;
    int aId = 1, bId = 2;
    aStats.setHealth(100); bStats.setHealth(100);
    aStats.setMana(50); bStats.setMana(50);
    CoreManager manager;
    manager.registerEntity(aId, &aStats);
    manager.registerEntity(bId, &bStats);
    auto fireball = std::make_shared<Ability>("Fireball", 20, 5, 1);
    // Both attack each other
    manager.combatSystem().attack(aId, bId, fireball->getDamage(), "magical");
    manager.combatSystem().attack(bId, aId, fireball->getDamage(), "magical");
    manager.resourceSystem().consume(aId, fireball->getManaCost());
    manager.resourceSystem().consume(bId, fireball->getManaCost());
    manager.update(1.0f);
    EXPECT_EQ(aStats.getHealth(), 80);
    EXPECT_EQ(bStats.getHealth(), 80);
}

// Resource Overconsumption Test
TEST(ScenarioTests, AbilityFailsWhenResourceInsufficient) {
    Stats mageStats;
    int mageId = 3;
    mageStats.setHealth(50); mageStats.setMana(10);
    CoreManager manager;
    manager.registerEntity(mageId, &mageStats);
    auto expensiveSpell = std::make_shared<Ability>("Expensive", 20, 20, 1);
    bool castResult = manager.resourceSystem().consume(mageId, expensiveSpell->getManaCost());
    EXPECT_FALSE(castResult);
    EXPECT_EQ(mageStats.getMana(), 10);
}

// Cooldown Enforcement Test (simplified)
TEST(ScenarioTests, AbilityCooldownPreventsImmediateReuse) {
    Stats rogueStats;
    int rogueId = 4;
    rogueStats.setHealth(80); rogueStats.setMana(30);
    CoreManager manager;
    manager.registerEntity(rogueId, &rogueStats);
    auto quickStrike = std::make_shared<Ability>("QuickStrike", 10, 5, 2);
    // First cast: should NOT be on cooldown
    bool firstCast = !manager.cooldownSystem().isOnCooldown(rogueId, quickStrike->getName());
    manager.cooldownSystem().setCooldown(rogueId, quickStrike->getName(), quickStrike->getCooldown());
    // Second cast: should be on cooldown
    bool secondCast = !manager.cooldownSystem().isOnCooldown(rogueId, quickStrike->getName());
    EXPECT_TRUE(firstCast);
    EXPECT_FALSE(secondCast);
}
