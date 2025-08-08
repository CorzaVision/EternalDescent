# EternalDescent - Project Structure

## 📁 Clean Project Organization

```
EternalDescent/
├── 📄 Core Documentation
│   ├── README.md               # Project overview and quick start
│   ├── CLAUDE.md              # Development guidelines for AI assistance
│   ├── LICENSE                # Project license
│   └── PROJECT_STRUCTURE.md   # This file
│
├── 🛠️ Build & Development
│   └── EternalDescent.bat     # Unified build and test utility
│
├── 📋 Design Documents
│   └── Design/
│       ├── Eternal Descent GDD.md    # Game Design Document
│       └── Eternal Descent TDD.md    # Technical Design Document
│
├── 🎮 Unreal Engine Project
│   └── EternalDescent/        # Main UE 5.5 project folder
│       ├── Source/           # C++ source code
│       ├── Content/          # Blueprints, assets, maps
│       ├── Config/           # Engine configuration
│       └── [UE Generated]    # Binaries, Intermediate, Saved
│
├── 📊 Reports & Analytics
│   └── reports/
│       ├── compatibility/    # UE 5.5 compatibility reports
│       ├── build/           # Build validation reports
│       ├── testing/         # Test execution results
│       ├── performance/     # Performance benchmark data
│       └── SystemStatus.md  # Overall project status
│
├── 🧪 Testing Suite
│   └── testing/
│       ├── powershell/      # Grid and voxel testing scripts
│       ├── proof-of-concept/ # Concept validation scripts
│       ├── validation/      # System validation scripts
│       ├── cpp/            # C++ test implementations
│       ├── python/         # Python testing utilities
│       └── legacy/         # Archived test files
│
├── 📖 Documentation
│   └── docs/
│       ├── systems/        # System architecture docs
│       ├── template/       # Documentation templates
│       └── [Feature Docs]  # Blueprint guides, test results
│
└── 🧪 Legacy Testing (Existing)
    └── Test/              # Original test files (preserved)
        └── [Various Tests] # Batch files, C++, Python, PowerShell
```

## 🎯 Key Improvements

### ✅ Project Root Cleanup
- **Removed 22 loose test files** from root directory
- **Organized by purpose** into logical folder structure
- **Single build utility** replaces 7 redundant batch files
- **Professional presentation** for development and collaboration

### 📂 Organized Structure
- **`/testing/`** - All validation and proof scripts by language/purpose
- **`/reports/`** - All generated reports categorized by type
- **`/Design/`** - Core design documents (GDD/TDD)
- **`/docs/`** - Technical documentation and guides
- **`/EternalDescent/`** - Clean UE 5.5 project structure

### 🔧 Development Workflow
```bash
# Quick build and test
./EternalDescent.bat

# Run comprehensive validation
./testing/validation/RunFullTests.ps1

# Check compatibility
./testing/validation/VerifyUE55.ps1

# View project status
./reports/SystemStatus.md
```

## 🎮 Core Project Features

- **Engine:** Unreal Engine 5.5
- **Target:** 60 FPS at all times
- **Generation:** <16ms per floor
- **Architecture:** Modular, TDD-compliant
- **Testing:** Comprehensive automated validation

## 📈 Quality Assurance

- **449 UE Reflection declarations** properly configured
- **UE 5.5 compatibility** verified
- **TDD compliance** validated
- **Performance benchmarks** documented
- **Comprehensive testing** across all systems

---
*Clean, professional project structure optimized for rapid UE 5.5 development*