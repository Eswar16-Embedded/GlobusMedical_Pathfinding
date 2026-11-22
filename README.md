# RTS Battlefield Pathfinding

## Project Overview

This project implements a pathfinding algorithm for a battle unit in a Real-Time Strategy (RTS) game using C++17.

The application reads battlefield data from a JSON file, identifies the battle unit's starting position and target position, and uses Breadth-First Search (BFS) to determine the shortest available path.

Battle units can move horizontally or vertically and cannot travel through elevated terrain.

## Project Structure


```text
GlobusMedical_Pathfinding/
├── main.cpp
├── pathfinder.cpp
├── pathfinder.h
├── test_pathfinder.cpp
├── json.hpp
├── take_home_project.json
├── sample_output.txt
├── reachable_test_output.txt
└── README.md
```


## Algorithm

Breadth-First Search (BFS) is used to find the shortest path between the starting position and the target.

The algorithm works as follows:

1. Add the starting position to a queue.
2. Check neighboring positions in four directions: up, down, left, and right.
3. Skip positions outside the battlefield or containing blocked terrain.
4. Track visited positions to avoid processing the same position multiple times.
5. Store each visited position's parent to reconstruct the path.
6. When the target is reached, reconstruct the shortest path.
7. If no route exists, return an unreachable result.

BFS was selected because each movement has an equal cost of one step. It guarantees a shortest path in an unweighted grid when a path exists.

### Time and Space Complexity

For a battlefield with R rows and C columns:

- **Time Complexity:** O(R × C)
- **Space Complexity:** O(R × C)

Each battlefield position is visited at most once.

## Battlefield Input

The application supports JSON battlefield data compatible with the RiskyLab Tilemap Editor format.

The current example uses a 32 × 32 battlefield containing 1,024 positions.

### Tile Definitions

| Tile Value | Description |
|---|---|
| -1 | Ground terrain — traversable |
| 3 | Elevated terrain — blocked |
| 8.3 | Battle unit starting position |
| 0.5 | Target position |
| 0 | Treated as blocked (assumption) |

The value `0` appears in the sample JSON but is not defined in the assessment's tile specifications. For safety, the application treats this value as non-traversable.

Starting and target tiles are treated as traversable positions during pathfinding.

## Build Instructions

### Requirements

- C++17-compatible compiler
- Windows PowerShell or another compatible terminal
- nlohmann/json single-header library

### Compile

From the project root directory:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp pathfinder.cpp -o main.exe
```

### Run

```powershell
.\main.exe
```

The application reads `take_home_project.json` from the current working directory.

## Sample Execution

### Input

- Battlefield: 32 × 32
- Start position: (25, 0)
- Target position: (8, 30)
- Movement: Four directions
- Obstacles: Elevated terrain and undefined tile `0`

### Output

```text
Start: (25, 0)
Target: (8, 30)

No path available.
```

### Explanation

The algorithm explores reachable ground positions from the starting location.

For the provided battlefield and documented terrain assumptions, the target cannot be reached through horizontal and vertical movements.

The application therefore reports that no path is available.

## Pathfinding Behavior

The pathfinding component handles the following scenarios:

- A valid route exists between start and target.
- The target is unreachable.
- The starting position equals the target position.
- The starting or target position is outside the grid.
- The starting or target position is blocked.
- The grid is empty or has inconsistent row lengths.

When a path exists, the application outputs the sequence of positions, including the start and target, along with the number of moves.

## Design Decisions

**Modular structure:** Pathfinding logic is separated from JSON parsing and application execution to improve maintainability and testing.

**BFS algorithm:** BFS provides shortest-path results for uniform-cost, four-directional movement.

**Queue-based traversal:** A FIFO queue processes battlefield positions in order of increasing distance from the starting position.

**Visited tracking:** Prevents repeated processing and infinite traversal loops.

**Parent tracking:** Allows the shortest route to be reconstructed after reaching the target.

**Input validation:** Checks JSON data size, recognized tile values, and the presence of exactly one starting position and one target.

## Third-Party Libraries

This project uses **nlohmann/json** for parsing JSON files.

Repository: https://github.com/nlohmann/json

The library is distributed under the MIT License.

## Current Limitations

- The JSON-loading application currently supports 32 × 32 maps.
- Only one battle unit is supported.
- Movement is restricted to four directions.
- Diagonal movement is not supported.
- Multiple-unit collision avoidance is not implemented.
- The application uses a command-line interface.

## Future Improvements

Potential enhancements include:

- Support for different battlefield dimensions.
- Multiple units moving simultaneously.
- Collision avoidance between moving units.
- A graphical battlefield visualization.
- Additional JSON sample maps and automated integration tests.

## AI Assistance

AI assistance was used during development for implementation guidance, code generation and refinement, JSON integration, compilation troubleshooting, and debugging.

The submission should include the full AI interaction transcript and a separate interaction summary describing the development process and decisions accurately.
