Unreal Engine Game Studio AI Agents
This is a comprehensive collection of specialized AI agents designed to act as a full development team for a solo-developed project. The agents are built to accelerate the workflow for Unreal Engine 5.6, focusing specifically on your voxel-based, rogue-lite extraction RPG, "Eternal Descent."

Each agent is an expert in a specific domain, allowing a single developer to manage a sophisticated, production-quality project from start to finish.

Core Agents
These agents are the foundation of the development team and are responsible for the core systems and technical architecture of the Eternal Descent project. They are designed to handle the most critical parts of your game's C++ and Blueprint architecture.

dungeon-system-architect: The central expert for procedural generation. This agent is responsible for the SnakeDungeonGenerator's back-end logic, the DungeonVisualizer's front-end spawning with HISM, and ensuring all systems integrate seamlessly with the ADA.

ue5-cpp-engineer: The C++ specialist for the project, focusing on performance-critical systems, defensive programming, and adhering to Epic's C++ best practices.

frontend-developer: An expert in Unreal Engine's Slate UI framework, this agent is responsible for creating a modular and responsive UI/HUD system.

camera-systems-specialist: An expert in creating high-performance camera systems, this agent ensures the top-down camera is smooth, performant, and integrates with the Enhanced Input System.

ue5-tech-writer: The documentation specialist for the project, responsible for generating and maintaining professional documentation, including the GDD and TDD, to ensure clarity and consistency.

Optimization and Quality Assurance Agents
These agents are crucial for maintaining the project's "Performance First" philosophy and Test-Driven Development (TDD) approach. They ensure your project remains high-quality and performant, helping you meet your strict development targets.

HSIM-optimization-specialist: A dedicated agent for deep-level rendering optimization, specifically focused on maximizing performance with Hierarchical Instanced Static Meshes (HISM).

performance-profiling-specialist: A master of Unreal's profiling tools (Unreal Insights), this agent can diagnose CPU/GPU bottlenecks, ensuring the project meets its strict performance targets.

performance-benchmarker: This agent provides a high-level overview of performance, creating benchmarks to track the project's speed and help identify areas for optimization.

test-writer-fixer: This agent, part of the project's TDD approach, writes and fixes automated C++ and Blueprint tests to ensure code integrity and prevent regressions.

code-review-enforcer: This agent acts as a quality gate for the codebase, enforcing a strict C++ coding standard and best practices to maintain a clean, organized, and professional project.

Project Management and Pipeline Agents
These agents handle the meta-tasks of the project, from managing the build process to keeping the development on track. Their purpose is to free the solo developer to focus on creative tasks and core gameplay.

ue5-build-engineer: Manages the build and deployment pipeline for the project, ensuring a reliable build process for multiple platforms.

project-orchestrator: This agent acts as the project manager, helping to define tasks, set realistic deadlines, and track development progress to ensure the project stays on schedule.

Agent Structure and Usage
Each agent is a Markdown file with a YAML frontmatter that defines its name, description, and color. They also include a comprehensive system prompt that outlines their identity, core responsibilities, and technical guidelines.

To use the agents, simply describe your task, and the appropriate agent will be triggered. You can also explicitly request an agent by mentioning their name.

Example 1: "Our build is failing with linker errors" → ue5-build-engineer

Example 2: "Create a camera system for a third-person gameplay" → camera-systems-specialist

Example 3: "Optimize our HISM performance for large worlds" → HSIM-optimization-specialist

Example 4: "The DungeonVisualizer has a bug where it's not spawning a specific room type" → dungeon-system-architect

Status
✅ Active: All agents are fully functional and tested.

🚧 Coming Soon: In development.

🧪 Beta: Testing with limited functionality.