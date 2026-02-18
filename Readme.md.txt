T.O.N.G.U.E Core

Foundation of the T.O.N.G.U.E Engine

The TONGUE-Core repository contains the essential building blocks for the T.O.N.G.U.E system. It defines core abstractions, shared data structures, and utility functions used across the client, server, renderer, and tools modules.

Responsibilities

TONGUE-Core is designed to provide:

Shared Data Structures – Basic types for characters, entities, physics, and networking messages.

Core Utilities – Logging, math libraries, configuration handling, and memory management.

Abstractions & Interfaces – Base classes for systems like rendering, input, audio, and network events.

Cross-Module Contracts – Interfaces and constants shared between client and server to ensure consistent behavior.

Project Layout
TONGUE-Core/
├─ include/          # Public headers for core utilities and types
│  ├─ Tongue.h       # Main umbrella header
│  ├─ Types/         # Shared structures (Vector, Color, Entity, Character, etc.)
│  ├─ Math/          # Vector, Matrix, Quaternion, and math utilities
│  ├─ Network/       # Core networking messages, serialization helpers
│  └─ Utils/         # Logging, config parsing, error handling
├─ src/              # Implementation files
├─ tests/            # Unit tests for core functionality
└─ CMakeLists.txt    # Build configuration

Usage

Include TONGUE-Core in any other T.O.N.G.U.E module:

#include <Tongue.h>

Character myCharacter;
Vector3 position;
Log::Info("Created character at position: {}", position);


All modules (Client, Server, Renderer, Tools) should rely on TONGUE-Core for foundational types to maintain consistency and avoid duplication.

Guidelines

Keep it lightweight – Core should not depend on other T.O.N.G.U.E modules.

Minimal external dependencies – Only standard libraries and low-level utilities.

Document everything – Every type and function should have clear explanations and intended usage.

Test-driven – Core utilities must have automated tests in tests/.

Contribution

Add only abstractions or types needed across multiple modules.

Avoid implementing module-specific logic (like rendering or server logic).

Follow naming conventions and consistent formatting.