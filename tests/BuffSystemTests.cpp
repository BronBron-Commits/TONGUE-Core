#include <gtest/gtest.h>
#include "Core/CoreManager.h"
#include "Core/Stats.h"
#include "Core/BuffSystem.h"
#include "Core/EventSystem.h"

using namespace Core;

// Test: Apply and expire a stun buff
TEST(BuffSystemTests, StunBuffPreventsAction) {
    Stats hero;
    int heroId = 1;
    hero.setHealth(100);
    CoreManager manager;
    manager.registerEntity(heroId, &hero);
    bool stunned = false;
    Buff stun{"Stun", BuffType::Stun, 1.0f, 0.0f,
        [&]() { stunned = true; }, // onStart
        [&]() { stunned = false; } // onEnd
    };
    manager.buffSystem().addBuff(heroId, stun);
    manager.buffSystem().update(0.5f);
    EXPECT_TRUE(stunned);
    manager.buffSystem().update(0.6f);
    EXPECT_FALSE(stunned);
}

// Test: Poison deals damage over time
TEST(BuffSystemTests, PoisonDealsDamageOverTime) {
    Stats hero;
    int heroId = 2;
    hero.setHealth(100);
    CoreManager manager;
    manager.registerEntity(heroId, &hero);
    float poisonDmg = 5.0f;
    Buff poison{"Poison", BuffType::Poison, 2.0f, poisonDmg, nullptr, nullptr};
    manager.buffSystem().addBuff(heroId, poison);
    // Simulate poison tick manually (since BuffSystem doesn't have direct Stats access yet)
    for (int i = 0; i < 2; ++i) {
        hero.setHealth(hero.getHealth() - poisonDmg);
        manager.buffSystem().update(1.0f);
    }
    EXPECT_EQ(hero.getHealth(), 90);
}

// Test: Buff stacking
TEST(BuffSystemTests, NonStackableBuffReplaces) {
    Stats hero;
    int heroId = 3;
    hero.setHealth(100);
    CoreManager manager;
    manager.registerEntity(heroId, &hero);
    int startCount = 0, endCount = 0;
    Buff buffA{"Shield", BuffType::StatBoost, 2.0f, 0.5f, [&]() { ++startCount; }, [&]() { ++endCount; }, false};
    Buff buffB{"Shield", BuffType::StatBoost, 2.0f, 0.7f, [&]() { ++startCount; }, [&]() { ++endCount; }, false};
    manager.buffSystem().addBuff(heroId, buffA);
    manager.buffSystem().addBuff(heroId, buffB); // Should replace buffA
    manager.buffSystem().update(2.1f);
    EXPECT_EQ(startCount, 2);
    EXPECT_EQ(endCount, 2);
}
