# Endless Dungeon Mode Test

## Maximum Stage Generation Test

This system tests generating the **maximum possible number of dungeon stages** without worrying about room limits.

## Quick Setup

### 1. Create Endless Tester Blueprint
1. Content Browser → Blueprint Class
2. Parent: `AEndlessDungeonTester`
3. Name: `BP_EndlessTester`

### 2. Configure for Maximum Generation
In `BP_EndlessTester` Details:

**Configuration:**
- Max Stages To Generate: **1000** (or higher!)
- Auto Generate On Start: **True**
- Delay Between Stages: **0.01** (minimal)
- Visualize Each Stage: **False** (for max performance)
- Log Detailed Stats: **True**

**Room Scaling:**
- Min Rooms Per Stage: **10**
- Max Rooms Per Stage: **30**
- Increase Complexity Over Time: **True**
- Complexity Growth Rate: **0.05** (5% per 10 stages)

**Performance Limits:**
- Min Acceptable FPS: **30**
- Max Memory Usage MB: **4096** (4GB)
- Stop On Performance Issue: **True**

### 3. Run the Test
1. Place `BP_EndlessTester` in level
2. Hit Play
3. Watch the console for progress

## Test Modes

### 🚀 **Maximum Stages Test**
```cpp
// Generates as many stages as possible
GenerateMaximumStages()
```
- Targets 1000+ stages
- Generates in batches of 10
- Monitors performance
- Stops if FPS < 30 or memory > 4GB

### 📊 **Stress Test**
```cpp
// Run with custom limit
RunStressTest(2000)
```
- Tests up to 2000 stages
- No visualization
- Minimal delays
- Pure generation speed

### 🔬 **Scaling Test**
```cpp
TestRoomScaling()
```
- Tests 10-50 rooms per stage
- Measures generation time
- Reports success rates

### ⚡ **Speed Test**
```cpp
TestGenerationSpeed()
```
- Generates 100 stages rapidly
- Calculates stages/second
- Estimates theoretical maximums

## Expected Results

### Stage Progression
```
Stages 1-10:    10-15 rooms each
Stages 11-50:   15-20 rooms each  
Stages 51-100:  20-25 rooms each
Stages 101-500: 25-35 rooms each
Stages 500+:    35-50 rooms each
```

### Performance Targets
- **Generation Speed**: 10-15ms per stage
- **Stages per Second**: 60-100
- **Stages per Minute**: 3600-6000
- **Theoretical Maximum**: 10,000+ stages possible

### Memory Usage
- Base: ~500MB
- Per Stage: ~0.5-2MB
- At 1000 stages: ~2GB
- Maximum sustainable: ~2000-3000 stages

## Real-Time Statistics

The tester tracks:
- Total stages generated
- Total rooms created
- Average generation time
- Current/Lowest FPS
- Current/Peak memory usage
- Enemies & chests spawned

## ADA Integration

ADA responds to milestones:
- Stage 10: "Ten floors down..."
- Stage 25: "Quarter of a hundred..."
- Stage 50: "Fifty stages..."
- Stage 100: "One hundred floors!"
- Stage 500: "Five hundred... impossible..."
- Stage 1000: "You have broken the dungeon itself."

## Console Output Example

```
========================================
ENDLESS DUNGEON TEST STARTED
Target: 1000 stages
========================================
Stage 10: 15 rooms, 12.34ms generation, Total: 10 stages
Stage 20: 18 rooms, 13.45ms generation, Total: 20 stages
Stage 30: 21 rooms, 14.56ms generation, Total: 30 stages
...
Stage 100: 35 rooms, 18.90ms generation, Total: 100 stages
Stage 200: 42 rooms, 22.34ms generation, Total: 200 stages
...
Stage 1000: 50 rooms, 28.45ms generation, Total: 1000 stages
========================================
```

## Final Report

After completion, get detailed stats:

```
=== GENERATION STATS ===
Total Stages Generated: 1000
Total Rooms Generated: 25,000
Average Rooms per Stage: 25.0
Largest Stage: 50 rooms
Smallest Stage: 10 rooms

=== CONTENT STATS ===
Total Enemies Spawned: 75,000
Total Chests Spawned: 15,000

=== PERFORMANCE STATS ===
Average Generation Time: 15.5ms
Stages per Second: 64.5
Lowest FPS: 45.2
Peak Memory Usage: 1823MB

=== THEORETICAL LIMITS ===
Stages per Minute: 3870
Stages per Hour: 232,200
Max Sustainable Stages: ~2240
```

## Test Commands

Console commands during test:

```
// Start endless test
ke * StartEndlessTest

// Stop current test
ke * StopEndlessTest

// Generate specific number
ke * GenerateMultipleStages 100

// Jump to stage
ke * TransitionToStage 50

// Print current stats
ke * PrintTestReport

// Save results
ke * SaveTestResults
```

## Optimization Tips

For maximum stages:
1. Disable visualization (`bVisualizeEachStage = false`)
2. Minimize delay (`DelayBetweenStages = 0.01`)
3. Use smaller room counts initially
4. Clear old stages from memory periodically
5. Run in Shipping build for best performance

## Known Limits

- **Soft limit**: ~1000 stages (performance degrades)
- **Hard limit**: ~2000-3000 stages (memory constraints)
- **Theoretical limit**: 10,000+ (with memory management)

## Results Storage

Test results auto-save to:
```
Project/Saved/DungeonTests/EndlessTest_[timestamp].txt
```

Contains:
- All stage details
- Performance metrics
- Failure reasons (if any)
- Complete statistics

## What to Look For

✅ **Success Metrics:**
- All stages generate successfully
- Consistent generation times
- FPS stays above 30
- Memory grows linearly

⚠️ **Warning Signs:**
- Generation time > 50ms
- FPS drops below 30
- Memory spikes
- Failed stage generations

## Next Steps

After testing maximum stages:
1. Optimize based on bottlenecks
2. Implement stage streaming/unloading
3. Add save/load for persistence
4. Create infinite scrolling system
5. Add procedural difficulty scaling