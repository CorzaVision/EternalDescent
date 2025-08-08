# Testing Directory

This directory contains all testing and validation scripts organized by type and purpose.

## 📂 Directory Structure

### `/powershell/` - Grid Testing Scripts
PowerShell scripts for comprehensive grid testing and validation:
- **TestVoxelGrid.ps1** - Basic voxel grid testing
- **TestAllGridSizes.ps1** - Multi-size grid validation  
- **TestRoomConnectivity.ps1** - Room connection validation
- **TestLinearPath.ps1** - Linear path generation testing
- **TestFullRange25to100.ps1** - Full range room count testing
- **TestVoxelAlignment.ps1** - Voxel alignment verification
- **Test3RoomGrid.ps1** - Small grid testing
- **Test10x10CubeGrid.ps1** - Large grid testing
- **TestSimpleGrid.ps1** - Basic grid functionality
- **TestCubeGridAlignment.ps1** - Cube alignment testing

### `/proof-of-concept/` - Proof Scripts
PowerShell scripts that validate core concept implementations:
- **ProofOfConcept.ps1** - Initial concept validation
- **ProofComplete.ps1** - Complete system proof
- **ProofOfVoxelGrid.ps1** - Voxel system proof
- **FinalVoxelVerification.ps1** - Final voxel validation

### `/validation/` - System Validation
High-level validation and verification scripts:
- **VerifyUE55.ps1** - UE 5.5 compatibility verification
- **RunFullTests.ps1** - Complete test suite runner
- **Run15Tests.ps1** - Stress test runner (15 iterations)

### `/cpp/` - C++ Test Files
Native C++ test implementations:
- **TestBackend.cpp** - Backend system testing
- **TestSpawning.cpp** - Spawning system testing  
- **TestProof.cpp** - Core proof testing

### `/python/` - Python Test Scripts
Python-based testing utilities:
- **test_proof.py** - Python proof validation
- **test_spawning.py** - Python spawning tests

### `/legacy/` - Legacy Tests
*Reserved for deprecated or archived test files*

## 🚀 Usage

### Quick Testing
```bash
# Run basic validation
./testing/validation/RunFullTests.ps1

# Run proof of concept
./testing/proof-of-concept/ProofComplete.ps1

# Test specific grid size
./testing/powershell/Test10x10CubeGrid.ps1
```

### Comprehensive Testing
```bash
# Full system validation (15 iterations)
./testing/validation/Run15Tests.ps1

# All grid sizes
./testing/powershell/TestAllGridSizes.ps1

# Full range testing (25-100 rooms)
./testing/powershell/TestFullRange25to100.ps1
```

## 📊 Test Categories

- **🔧 Unit Tests** - Individual component testing
- **🏗️ Integration Tests** - System interaction testing  
- **⚡ Performance Tests** - Speed and efficiency validation
- **✅ Proof Tests** - Concept validation and compliance
- **🎯 Stress Tests** - High-load and edge case testing

## 🎯 Testing Philosophy

All tests follow the **TDD (Test-Driven Development)** approach:
1. **Write tests first** - Define expected behavior
2. **Run tests** - Verify they fail initially  
3. **Implement code** - Make tests pass
4. **Refactor** - Improve while maintaining tests
5. **Repeat** - Iterate for each feature

## 📈 Test Coverage Goals

- **100%** Core dungeon generation functionality
- **100%** Grid system operations
- **90%+** Edge cases and error conditions
- **85%+** Performance benchmarks
- **100%** TDD/GDD compliance requirements

---
*All tests are designed to validate the 16ms generation time requirement and 25-room dungeon specifications.*