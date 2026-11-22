

Software Candidate Assessment v1.02(3).pdf
PDF
review the pdf and explain what i need to build and what i/o are expected and let me know about the imp constrains and dont go with code first explain the problem?
I reviewed all three pages of your Software Candidate Assessment v1.02. This is a take-home coding challenge to build a pathfinding system for a Real-Time Strategy (RTS) game.

The main objective is to find a valid route for a battle unit to move from its starting position to a target while avoiding obstacles.

I'll explain the problem, inputs, outputs, constraints, and expected deliverables without writing code.

1. What exactly do you need to build?
Imagine a battlefield divided into a grid of square tiles. Some tiles are open ground, and others are elevated terrain that the unit cannot cross.

Your program must:

Read a battlefield map.

Identify the battle unit's starting position.

Identify its target destination.

Find a valid route that avoids elevated terrain.

Return the sequence of positions the unit should follow.

Example battlefield (illustrative)


Example only, not the map supplied with the assessment. The unit must navigate around blocked tiles.
2. What inputs are expected?
The assessment specifies three main inputs.

Input

Description

Battlefield map

A grid containing at least 32 × 32 positions

Starting position

Where the battle unit begins

Target position

Where the unit needs to go

The program must support JSON files compatible with the RiskyLab Tilemap Editor.

JSON tile values
Value

Meaning

Traversable?

-1

Empty ground

Yes

3

Elevated terrain / obstacle

No

8.3

Battle unit starting position

Starting tile

0.5

Target destination

Target tile

For example, conceptually a small map might look like this:

 8.3   -1   -1    3
  -1    3   -1    3
  -1   -1   -1   -1
   3    3   -1   0.5
This is just a simplified representation of the tile values, not the complete RiskyLab JSON structure.

Important: Your program should read the actual JSON map format rather than assume the map is simply a two-dimensional array.

3. What output is expected?
The required output is a list of positions from the starting tile to the target tile.

For example:

Path found!

(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(3, 2)
(3, 3)
Each coordinate represents one grid position.

The assessment doesn't prescribe the exact output format, so a JSON list of coordinates or a readable console output can be suitable. Including both would make the results easier to inspect.

A useful implementation should also report when no valid route exists, although the PDF doesn't specify the exact wording or structure for that case.

4. Important constraints
These are the most important rules from the assessment.

Minimum map size: 32 × 32

Your program must handle a battlefield with at least 1,024 tiles. It can support larger maps as well.

Only four movement directions

Left, right, up, and down are allowed. Diagonal movement is not permitted.

One tile per step

Movement is discrete. A unit must move from one complete tile to an adjacent tile and cannot occupy a fraction of a tile.

Elevated terrain is blocked

The unit cannot travel through any tile represented by 3.

RiskyLab JSON compatibility

The program must support maps exported from the RiskyLab Tilemap Editor.

5. Which algorithm should you use?
The PDF does not require a specific pathfinding algorithm. It asks for an efficient, accurate solution.

Two reasonable options are:

Algorithm

Why consider it?

Breadth-First Search (BFS)

Simple and guarantees a shortest path when every move has equal cost

A* Search

Uses a heuristic to guide the search toward the target, often exploring fewer tiles

My recommendation: BFS is a strong starting choice for this assessment because the movement rules are simple and each step has equal cost. A* is also appropriate, particularly if you want to demonstrate heuristic pathfinding.

The PDF asks for a valid path, not explicitly the shortest path. However, returning a shortest path is a useful quality goal.

6. Important edge cases
Although not all of these are explicitly listed in the PDF, they are important for a reliable implementation.

The target is completely surrounded by elevated terrain.

The start and target are the same position.

The starting or target coordinates are outside the map.

The JSON is malformed or contains missing information.

The map contains no valid path.

The path runs along the map boundary.

The map is larger than 32 × 32.

A professional solution should handle these situations predictably rather than crash.

7. Optional extra task
The PDF includes an optional extension: multiple units moving simultaneously.

In that version, several units may move toward one common target or different targets, but no two units can occupy the same ground tile at the same time.

This introduces collision avoidance and movement coordination. It is more complex than single-unit pathfinding.

I would complete and test the single-unit implementation first. The multi-unit feature is optional and should not compromise the required functionality.

8. What do you need to submit?
The PDF requests a public Git repository, such as GitHub or GitLab.

Your repository should contain:

Deliverable

Expected content

Source code

Complete working implementation

README.md

Design decisions, project structure, build and execution instructions

Sample inputs

Example battlefield maps, preferably RiskyLab-compatible JSON

Sample outputs

Resulting paths for several test scenarios

Screenshots

Evidence showing the project working

Build instructions

Enough detail for another engineer to compile and run the project

Tests

Appropriate checks for functionality and edge cases

The PDF estimates 3–6 hours for the task and says you should use the programming language and technologies agreed upon when the project was assigned.

9. How will they evaluate your submission?
The assessment explicitly evaluates code organization, readability, maintainability, algorithm efficiency and accuracy, edge-case handling, documentation, completeness, third-party library usage, and project setup. UI quality is considered only if a user interface is applicable.

This means the interviewer is evaluating more than whether the algorithm finds a path. They also want to see how you structure a small software project and explain your engineering decisions.

10. Suggested implementation plan — without code
Understand the JSON map format. Inspect the sample file linked by the assessment and identify how tile values and grid dimensions are stored.

Define the input and output behavior. Decide how the user supplies a map and how the resulting path will be displayed or saved.

Design the pathfinding logic. Determine how to identify valid neighbors, track visited tiles, and reconstruct a path.

Plan error handling. Decide what happens with invalid coordinates, blocked destinations, malformed JSON, or unreachable targets.

Define test cases. Include a clear path, a route around obstacles, and an unreachable destination.

Plan the repository. Separate the algorithm, JSON handling, tests, sample data, and documentation.

One important distinction
Your assignment is to build a pathfinding algorithm, not a complete RTS game. You do not need game graphics, combat systems, animation, or a full game engine. A command-line program is a reasonable design, provided it meets the required inputs, outputs, and submission requirements.

Before we begin coding, the first technical decision is whether to use BFS or A* and how to structure the JSON input handling. We can work through those decisions and the overall architecture first, then implement each component separately.





