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
ctest
```

## Main Classes

- `Entity` - Base class for all entities
- `Component` - Base class for all components
- `Character` - Example entity
- `Move` - Example component or action
- `Event` - Event system base
- `System` - Base for systems
- `CoreManager` - Manages core logic

---

For more details, see the source and header files in their respective directories.
