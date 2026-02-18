# TONGUE-Core

This module provides the core functionality for the TONGUE project, including the Entity-Component-System (ECS) architecture and core management classes.

## Directory Structure

- `include/Core/` - Public header files for core classes
- `src/` - Source files for core implementation
- `tests/` - Unit tests for core functionality

## Building

This project uses CMake. To build:

```sh
mkdir build
cd build
cmake ..
make
```


## Testing

Unit tests are provided using Google Test. After building, run:

```sh
ctest --verbose
```

Example output for a successful test run:

```
Test project C:/Projects/TONGUE/TONGUE-Core/build
	Start 1: CharacterTests.InitialHealth
1/2 Test #1: CharacterTests.InitialHealth ...........   Passed    0.01 sec
	Start 2: LevelingTests.LevelUpIncreasesHealth
2/2 Test #2: LevelingTests.LevelUpIncreasesHealth ...   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2
```

## Main Classes & Features

- `Entity` - Base class for all entities
- `Component` - Base class for all components
- `Character` - Example entity
- `Move` - Example component or action
- `Event` - Event system base
- `System` - Base for systems
- `CoreManager` - Manages core logic
- `Stats` - Handles health, mana, attack, defense, and other stats
- `Leveling` - XP, level, and stat scaling
- `Ability` - Move/ability logic, cooldowns, targeting
- `Effect` - Buffs, debuffs, status effects
- `CooldownManager` - Manages ability cooldowns

### Example ECS Components & Systems
- StatsComponent, ResourceComponent, PositionComponent, AbilityComponent, BuffComponent
- LevelingSystem, CombatSystem, ResourceSystem, CooldownSystem, BuffSystem

---

For more details, see the source and header files in their respective directories.
