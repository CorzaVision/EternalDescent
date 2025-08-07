# Documentation Guidelines for Unreal Engine Classes

## Overview

This document establishes the standard format for documenting Unreal Engine classes in markdown. Following these guidelines ensures consistency, clarity, and comprehensive coverage across the codebase.

## Document Structure Template

Every class documentation file should follow this structure:

```markdown
# UMyClassName / FMyStructName / IMyInterfaceName

## Overview

**In Simple Terms:** [Layman's explanation using analogies]

**Technical Description:** [Precise technical description]

### What Does This Do?
- **Feature 1**: Brief description
- **Feature 2**: Brief description
- **Feature 3**: Brief description

### Visual Overview
```
[ASCII diagram showing the component's main function]
Input → [Component] → Output
```

## Class Declaration
```cpp
UCLASS() / USTRUCT() / UINTERFACE()
class PROJECTNAME_API UMyClassName : public UBaseClass
```

## Dependencies
- `Dependency1` - What it's used for
- `Dependency2` - What it's used for

## Architecture

### Component Relationships
```mathematica
[ASCII diagram showing how this component fits in the larger system]
Example:
    SystemA
        ↓
    ThisComponent ←→ SystemB
        ↓
    SystemC
```

### Processing Pipeline
```mathematica
[ASCII diagram showing internal data flow]
Step 1 → Step 2 → Step 3
   ↓        ↓        ↓
 Process  Transform Output
```

1. **Step 1**: Description
2. **Step 2**: Description
3. **Step 3**: Description

## API Reference

### Core Operations

| Operation | Description | Arguments | Returns | Notes |
|-----------|-------------|-----------|---------|-------|
| **MethodName** | What it does | `Type Arg` | `ReturnType` | Important details |

## Data Structures

### FMyDataStructure
```cpp
USTRUCT(BlueprintType)
struct FMyDataStructure
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    Type MemberName; // Comment explaining purpose
};
```

## Implementation Details

### Algorithm/Concept Name

**What It Does:** [Simple explanation]

**Real-World Analogy:** [Relatable comparison]

**Visual Representation:**
```mathematica
[ASCII diagram showing the algorithm/concept]
Example:
    Before:        After:
    [####]   →    [#-#-]
    [####]        [#-#-]
```

[Implementation details, code snippets, additional visualizations]

## Usage Examples

### Basic Usage
```cpp
// Example code with comments
```

### Advanced Usage
```cpp
// More complex example
```

## Performance Scorecard

### 🎯 Key Performance Indicators (KPIs)

| Metric | Target | Critical Threshold | Status |
|--------|--------|-------------------|--------|
| **Metric 1** | < X.Xms | < X.Xms | ✅ PASS |

### Detailed Performance Benchmarks
[Tables with specific performance targets]

### Statistical Validation Requirements
[Acceptable variance criteria]

### Success Criteria Checklist
- [ ] Performance criterion 1
- [ ] Performance criterion 2

## Testing

### Test Categories

#### Category 1 Tests
```cpp
TEST: "Test Name"
- GIVEN: Initial conditions
- WHEN: Action taken
- THEN: Expected result
```

### Performance Test Implementation
[Performance test code examples]

### Test Execution Commands
```bash
# Command to run tests
cmd.exe /c "cd /d C:\path && RunTest.bat TestName --options"
```

## Additional Sections (as needed)
- Thread Safety
- Migration Guide
- Known Issues
- Future Improvements
```yaml

## Section Guidelines

### 1. Overview Section
- **Purpose**: Provide both technical and non-technical readers with understanding
- **Requirements**:
  - "In Simple Terms" must use analogies or real-world comparisons
  - Technical description should be precise but concise
  - "What Does This Do?" should list 3-5 key features as bullet points

### 2. Class Declaration
- **Purpose**: Show the exact C++ declaration
- **Requirements**:
  - Include relevant macros (UCLASS, USTRUCT, etc.)
  - Show inheritance hierarchy
  - Include API export macro

### 3. Dependencies
- **Purpose**: List what this class needs to function
- **Requirements**:
  - List each dependency with its purpose
  - Include both hard dependencies and optional integrations

### 4. Architecture
- **Purpose**: Show how the component fits in the larger system
- **Requirements**:
  - Visual diagram (ASCII art or flowchart)
  - Processing pipeline if applicable
  - Data flow representation

### 5. API Reference
- **Purpose**: Quick reference for all public methods
- **Requirements**:
  - Table format for easy scanning
  - Group related operations together
  - Include brief descriptions in the Notes column
  - For complex APIs, break into subsections (Core Operations, Utility Functions, etc.)

### 6. Data Structures
- **Purpose**: Document all related structs and enums
- **Requirements**:
  - Full struct definitions with UPROPERTY macros
  - Comments explaining each member's purpose
  - Default values clearly shown
  - Group related structures together

### 7. Implementation Details
- **Purpose**: Explain complex algorithms or concepts
- **Requirements**:
  - Start with simple explanation
  - Provide real-world analogies
  - Include code snippets for key algorithms
  - Use visualizations (ASCII diagrams) where helpful

### 8. Usage Examples
- **Purpose**: Show practical usage patterns
- **Requirements**:
  - Start with simplest usage
  - Progress to more complex scenarios
  - Include complete, runnable code
  - Add comments explaining each step

### 9. Performance Scorecard
- **Purpose**: Define and track performance requirements
- **Requirements**:
  - Clear KPIs with pass/fail status
  - Detailed benchmarks for different scenarios
  - Statistical validation criteria
  - Test commands for verification
  - Historical performance tracking

### 10. Testing
- **Purpose**: Document test specifications and execution
- **Requirements**:
  - Group tests by category
  - Use Given-When-Then format
  - Include performance test implementations
  - Provide exact commands to run tests

## ASCII Diagram Guidelines

### When to Use Diagrams
ASCII diagrams should be used liberally throughout documentation to:
- **Overview Section**: Show what the component does at a glance
- **Architecture Section**: Illustrate system relationships and data flow
- **Data Structures**: Visualize complex data layouts
- **Algorithms**: Show before/after states or step-by-step processes
- **Examples**: Illustrate runtime behavior or state changes

### Diagram Best Practices

#### 1. Keep It Simple
```
```mathematica
Good:                           Bad:
┌─────┐    ┌─────┐             ╔═══════╗~~>╔═══════╗
│  A  │───▶│  B  │             ║   A   ║   ║   B   ║
└─────┘    └─────┘             ╚═══║═══╝   ╚═══════╝
                                   ▼
```



```mathematica

#### 2. Use Consistent Symbols
- `→` or `▶` for directional flow
- `↔` or `◀▶` for bidirectional
- `│ ─ ┌ ┐ └ ┘` for boxes
- `↓ ↑` for vertical flow
- `...` for continuation

#### 3. Label Everything
```
```mathematica
Input Data     Processing     Output
    │              │             │
    ▼              ▼             ▼
┌────────┐    ┌────────┐    ┌────────┐
│ Height │───▶│Discrete│───▶│ Levels │
│ 0.0-1.0│    │  izer  │    │  0-10  │
└────────┘    └────────┘    └────────┘
```

#### 4. Show State Changes



```mathematica
Before Smoothing:        After Smoothing:
┌───┬───┬───┐           ┌───┬───┬───┐
│ 0 │ 9 │ 0 │           │ 2 │ 5 │ 2 │
├───┼───┼───┤    ───▶   ├───┼───┼───┤
│ 9 │ 0 │ 9 │           │ 5 │ 4 │ 5 │
├───┼───┼───┤           ├───┼───┼───┤
│ 0 │ 9 │ 0 │           │ 2 │ 5 │ 2 │
└───┴───┴───┘           └───┴───┴───┘
```


#### 5. Use for Complex Relationships

Voxel System Architecture:

```mathematica
World
  │
  ├─── Static Voxels
  │         │
  │         ├─── Terrain Chunks
  │         └─── Base Structures
  │
  └─── Moving Voxels
            │
            ├─── Ships
            └─── Vehicles
```
```yaml

## Best Practices

### 1. Language and Tone
- Use clear, concise language
- Avoid jargon in "Simple Terms" sections
- Be precise in technical sections
- Use active voice

### 2. Code Examples
- Ensure all code examples compile
- Include necessary includes/usings
- Show both declaration and usage
- Comment non-obvious parts

### 3. Tables and Formatting
- Use tables for structured data
- Keep table cells concise
- Use consistent formatting
- Align columns for readability

### 4. Visual Elements
- **Use ASCII diagrams extensively** - Every major concept should have a visual
- **Place diagrams near related text** - Don't separate explanation from visualization
- **Show data flow with arrows** - Make relationships explicit
- **Keep diagrams readable in text editors** - Test in plain text view
- **Label all parts clearly** - No unlabeled boxes or arrows
- **Update diagrams with code changes** - Keep visuals in sync with implementation

### 5. Performance Documentation
- Always include measurable targets
- Show how to verify performance
- Document regression thresholds
- Include optimization opportunities

### 6. Maintenance
- Update documentation with code changes
- Keep performance baselines current
- Add new examples as patterns emerge
- Remove outdated information

## File Naming Convention

Documentation files should follow this pattern:
- Class documentation: `MyClassName.md`
- System overviews: `SystemName_Overview.md`
- Performance specs: `ComponentName_Performance.md`
- Architecture docs: `SystemName_Architecture.md`

## Example Structure Reference

See `/docs/MyRTMS/Generation/MyRTMSHeightField.md` for a complete example following these guidelines.

## Validation Checklist

Before considering documentation complete, verify:

- [ ] Overview provides both simple and technical descriptions
- [ ] **Visual overview diagram shows component's main function**
- [ ] All public APIs are documented in tables
- [ ] Data structures include purpose comments
- [ ] **Architecture diagrams show system relationships**
- [ ] **Processing pipeline has visual flow diagram**
- [ ] At least one usage example is provided
- [ ] **Complex algorithms include before/after visualizations**
- [ ] Performance targets are defined (if applicable)
- [ ] Test specifications are included
- [ ] **Each major section has supporting diagrams**
- [ ] Dependencies are clearly listed
- [ ] **All diagrams are labeled and easy to understand**

## Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2024-01-15 | Initial guidelines established |

---

*These guidelines are living documentation. Propose improvements through pull requests.*