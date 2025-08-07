# Testing Rules and Guidelines for EternalDescent

## Tiered Profiling System

### Overview
Tests support three profiling levels with different overhead characteristics:

1. **Minimal (Default)** - Always on, <0.01ms overhead
   - Uses `FPlatformTime::Seconds()` for timing
   - Stores results with `AddAnalyticsItem()` after test completion
   - No file I/O during measurement

2. **CSV** - Moderate overhead, 0.5-2ms per frame
   - Enables Unreal's CSV profiler
   - Detailed per-frame metrics
   - Use: `--profile-csv`

3. **Insights** - Significant overhead, 10-30% performance impact
   - Full Unreal Insights trace capture
   - Comprehensive CPU/GPU profiling
   - Use: `--profile-insights`

### Running Tests with Profiling

```bash
# Standard test (minimal profiling)
RunTest.bat EternalDescent.Dungeon.Performance

# With CSV profiling
RunTest.bat EternalDescent.Dungeon.Performance --profile-csv

# With Insights profiling
RunTest.bat EternalDescent.Dungeon.Performance --profile-insights

# Custom output directory
RunTest.bat EternalDescent.Dungeon.Performance --profile-csv --profile-output=D:\TestResults
```

### Profile Output Locations
- **Minimal**: Results in test log only
- **CSV**: `Saved/Profiling/[TestName]/[Timestamp]/*.csv`
- **Insights**: `Saved/Profiling/[TestName]/[Timestamp]/*.utrace`

## Core Testing Principles

### 1. Test File Organization
- **One test file per system**: Each major system has one test file
  - System: `DungeonGenerator` → Test: `TestDungeonGenerator.cpp`
  - System: `CubeDungeonGenerator` → Test: `TestCubeDungeonGenerator.cpp`
- All test files must be in `Source/EternalDescent/Private/Tests/`

### 2. Performance Testing Requirements

All performance tests **MUST** follow these rules to ensure hard failures:

#### Use `check()` or `checkf()` for Critical Thresholds
```cpp
// GOOD - Hard crashes on failure
double TimeMs = ElapsedTime * 1000.0;
checkf(TimeMs < 16.0, TEXT("CRITICAL: Dungeon generation took %.3fms, exceeds 16ms limit"), TimeMs);
```

#### Always Log Actual Measurements
```cpp
// GOOD - Provides visibility into actual performance
UE_LOG(LogTemp, Display, TEXT("Generation completed in %.3fms"), TimeMs);
AddInfo(FString::Printf(TEXT("Operation completed in %.3fms"), TimeMs));
```

### 3. Dungeon-Specific Performance Thresholds

#### Generation Performance
- **Floor generation**: < 16ms per floor (CRITICAL)
- **Room connectivity**: < 2ms per floor
- **Entity influence calculation**: < 1ms per floor
- **Cube grid initialization**: < 5ms for 50x50x10 grid
- **Plane assignment**: < 3ms per 1000 cubes

#### Memory Thresholds
- **Per floor memory**: < 10MB
- **Per cube memory**: < 256 bytes
- **Total dungeon (100 floors)**: < 1GB

#### Thread Performance
- **No blocking on game thread**: > 16ms
- **Async generation**: Must not block main thread
- **Worker thread utilization**: > 80% during generation

### 4. GPU Performance Metrics
- **Draw calls per room**: < 10
- **Vertices per cube**: < 24
- **Texture memory per floor**: < 50MB

## Test Pattern Template

### Standard Pattern (Minimal Profiling)
```cpp
// Intent: Validate dungeon generation meets 16ms target
// Purpose: Ensure smooth gameplay during procedural generation
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonPerformance, "EternalDescent.Dungeon.Performance",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestDungeonPerformance::RunTest(const FString& Parameters)
{
    // Setup
    ADungeonGenerator* Generator = GetWorld()->SpawnActor<ADungeonGenerator>();
    
    // Measure performance
    double StartTime = FPlatformTime::Seconds();
    
    // Execute operation
    FDungeonLayout Layout = Generator->GenerateFloor(1);
    
    // Calculate metrics
    double ElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
    
    // Log actual measurement
    AddInfo(FString::Printf(TEXT("Floor generation took %.3fms"), ElapsedMs));
    
    // Validate with hard check for critical performance
    checkf(ElapsedMs < 16.0, TEXT("CRITICAL: Generation %.3fms exceeds 16ms limit"), ElapsedMs);
    
    // Validate functionality
    TestEqual(TEXT("Room count"), Layout.Rooms.Num(), 25);
    
    // Cleanup
    Generator->Destroy();
    
    return true;
}
```

## Exit Codes
- **0**: All tests passed
- **255**: One or more tests failed
- **Crash**: `check()` or `checkf()` assertion failed (critical threshold exceeded)

## Test Categories

### Required Test Categories per System
1. **Performance** - Generation speed, frame rate impact
2. **Memory** - Memory usage, leak detection
3. **Threading** - Async operations, thread safety
4. **GPU** - Rendering performance, draw calls
5. **Stress** - Large-scale generation, edge cases

## DO NOT Do These Things

1. **DO NOT** rely on log parsing for test validation
2. **DO NOT** skip performance measurements
3. **DO NOT** test without proper cleanup
4. **DO NOT** ignore memory leaks
5. **DO NOT** block the game thread for > 16ms
6. **DO NOT** use `TestTrue()` without measurements
7. **DO NOT** mix profiling overhead with measurements