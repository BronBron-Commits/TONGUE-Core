
# TONGUE-Core

TONGUE-Core provides the core gameplay logic and systems for the TONGUE MOBA-style game, including:

- Entity-Component-System (ECS) architecture
- Character stats, leveling, abilities, effects, and cooldowns
- Resource management (health, mana, etc.)
- Event and combat system foundations

## Directory Structure

- `include/Core/` — Public header files for core classes (Entity, Component, Character, Stats, Leveling, Ability, Effect, CooldownManager, etc.)
- `src/` — Source files for core implementation
- `tests/` — Unit and integration tests (Google Test)

## Building

This project uses CMake and vcpkg for dependencies. To build:

```sh
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=<vcpkg-root>/scripts/buildsystems/vcpkg.cmake -A x64 -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

## Testing

Unit and integration tests are provided using Google Test. After building, run:

```sh
ctest --test-dir build --verbose
```

Example output for a successful test run:

```
Test project C:/Projects/TONGUE/TONGUE-Core/build
      Start  1: CharacterTests.InitialHealth
 1/15 Test  #1: CharacterTests.InitialHealth ..............   Passed    0.01 sec
      ...
      Start 15: AbilityTests.HealingAppliesCorrectly
15/15 Test #15: AbilityTests.HealingAppliesCorrectly ......   Passed    0.01 sec

100% tests passed, 0 tests failed out of 15
Total Test time (real) =   0.59 sec
```

## Main Features & Classes

- `Entity`, `Component`, `System` — ECS base
- `Character` — Main entity for gameplay
- `Stats` — Health, mana, and stat management
- `Leveling` — XP, level, and stat scaling
- `Ability`, `Effect`, `CooldownManager` — Moves, buffs/debuffs, and cooldown logic
- `CoreManager` — Manages core logic

### Example Components & Systems

- Components: StatsComponent, ResourceComponent, PositionComponent, AbilityComponent, BuffComponent
- Systems: LevelingSystem, CombatSystem, ResourceSystem, CooldownSystem, BuffSystem

## Test Coverage

Tests cover:
- Stat/resource initialization, consumption, and regeneration
- Leveling and stat scaling
- Ability cooldowns and effects
- Integration of core gameplay mechanics

---

For more details, see the source and header files in their respective directories.
