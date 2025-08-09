# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**Eternal Descent** is a roguelite extraction RPG built in Unreal Engine 5.5 where players descend into a living, adaptive dungeon. The dungeon entity (ADA - Adaptive Dungeon Algorithm) learns and adapts to player behavior in real-time.

## Development Commands

### Building and Running
```bash
# Open the project in Unreal Editor
UnrealEditor.exe "EternalDescent.uproject"

# Generate Visual Studio project files
UnrealBuildTool.exe -projectfiles -project="EternalDescent.uproject" -game -rocket -progress

# Build from command line (Development Editor)
UnrealBuildTool.exe EternalDescentEditor Win64 Development -project="EternalDescent.uproject"

# Package for Windows
UnrealEditor-Cmd.exe "EternalDescent.uproject" -run=Cook -targetplatform=Windows
```

### Testing
```bash
# Run automated tests (when implemented)
UnrealEditor.exe "EternalDescent.uproject" -ExecCmds="Automation RunTests"

# Performance profiling
UnrealEditor.exe "EternalDescent.uproject" -game -log -fps
```

## Architecture Overview

### Core Systems Structure

#### Procedural Generation System
The dungeon uses a **5x5x5 cubic grid system** (1 cubic = 1 cell) with 25 rooms per floor. Located in:
- `Content/Blueprints/CoreSystems/ProceduralSystem/` - Blueprint implementations
- `Source/EternalDescent/Public/DungeonGenerator.h` - C++ base classes
- `Source/EternalDescent/Private/DungeonGenerator.cpp` - C++ implementation

**Performance Target:** 16ms per floor generation

#### Entity System (ADA)
The Adaptive Dungeon Algorithm monitors player behavior and adapts the dungeon accordingly:
- **Stage 1 (Floors 1-10):** Observer phase - learns without interference
- **Stage 2 (Floors 11-25):** Challenger phase - introduces mild adaptations
- **Stage 3 (Floors 26+):** Counter phase - actively counters player strategies

Entity integration points are found throughout:
- `Content/Blueprints/CoreSystems/EntitySystem/` - Entity behavior blueprints
- All systems must be "ADA-ready" for entity influence

#### Character System
Four base classes with hybrid evolution post-level 25:
- **Warrior** → Guardian/Berserker branches
- **Mage** → Elementalist/Scholar branches  
- **Rogue** → Assassin/Scout branches
- **Ranger** → Hunter/Beast Master branches

Located in:
- `Content/Blueprints/CoreSystems/PlayerSystem/` - Player character blueprints
- `Source/EternalDescent/EternalDescentCharacter.h/cpp` - Base character implementation

#### Combat System
Real-time action combat with dodge/defense mechanics:
- `Content/Blueprints/CoreSystems/CombatSystem/` - Combat blueprints
- Uses Gameplay Ability System (GAS) for abilities and effects
- Power fantasy target: 2-3 hits for normal enemies, 5-8 for elites

### Plugin Dependencies

The project uses these Unreal Engine plugins:
- **Gameplay Ability System (GAS)** - Character abilities and entity effects
- **Procedural Content Generation (PCG)** - Room and dungeon generation
- **Enhanced Input System** - Player input handling
- **Modeling Tools Editor Mode** - Level design tools

### Content Organization

```
Content/
├── Blueprints/
│   ├── CoreSystems/       # Main gameplay systems
│   │   ├── ProceduralSystem/
│   │   ├── EntitySystem/
│   │   ├── PlayerSystem/
│   │   └── CombatSystem/
│   ├── Content/           # Game content
│   │   ├── Enemies/
│   │   ├── Items/
│   │   ├── Rooms/
│   │   └── Zones/
│   └── Development/       # Test and debug blueprints
├── Characters/            # Character models and animations
├── Widgets/UI/           # HUD and interface elements
└── ThirdPerson/          # Template content and test maps
```

### Code Patterns

#### Parent-Child Architecture
All systems use modular parent-child class architecture:
```cpp
// Base class example
class ABaseDungeonRoom : public AActor
{
    // Core functionality
};

// Child implementation
class ACombatRoom : public ABaseDungeonRoom
{
    // Specific combat room features
};
```

#### Entity Integration Pattern
All systems must support entity influence:
```cpp
// Entity-aware component
UCLASS()
class UEntityAwareComponent : public UActorComponent
{
    UPROPERTY()
    float EntityInfluence; // 0.0 to 1.0
    
    virtual void ApplyEntityModification();
};
```

### Performance Requirements

- **Generation:** 16ms maximum per floor
- **Gameplay:** 60 FPS minimum at all times
- **Entity Processing:** Zero impact on gameplay performance
- **Memory:** Optimized for large procedural content

### Development Guidelines

1. **Performance First:** Never sacrifice performance for features
2. **Modular Design:** All systems use parent-child component architecture
3. **Entity Integration:** All systems must be designed for ADA influence
4. **Blueprint-C++ Hybrid:** Use Blueprints for rapid iteration, C++ for performance-critical code
5. **Testing:** Profile generation time and FPS regularly

### Current Development Phase

**Version 0.0.1** - Foundation Setup
- Basic project structure established
- Core plugins integrated
- Initial procedural generation tests

**Next Milestone (0.0.2):** Basic Procedural Generation
- Grid-based room system implementation
- 20+ room templates per type
- Zone-based generation (Sunken Crypt, Blighted Forest, Frozen Fortress)

See `docs/ROADMAP.md` for complete development timeline.
- Use only 1 .bat file named @Test\RunTest.bat and remember @Test\TestingRules.md when testing
- When making test proofs or what not clean up old copies of old tests then make new ones in designated folders
- refer to @Design\Eternal Descent TDD.md and @Design\Eternal Descent GDD.md for project features and design choices, these are readonly no editing
- Unreal Engines 5.5 is located in D:\Epic Games
- when user tells you to test always use @agent-test-writer-fixer or when the users tell you to compile use @agent-ue5-build-engineer
- when working on Dungeon Generator use @agent-dungeon-system-architect