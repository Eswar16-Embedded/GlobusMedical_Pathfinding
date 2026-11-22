# AI Interaction Summary

**Project:** RTS Battlefield Pathfinding  
**Language:** C++17  
**AI Tool:** ChatGPT

## My Approach

For this assignment, I worked with a battlefield represented as a grid and needed to find a path between the unit's starting position and its target while avoiding blocked terrain.

I used ChatGPT throughout the exercise to help develop the C++ solution. My previous experience with C++ helped me follow the code structure, compilation process, and debugging steps, although AI supplied much of the implementation.

I compiled and tested the program locally using g++ and VS Code.

## 1. Understanding the Requirements

**What I asked:** I shared the coding challenge and asked for help understanding how to implement the pathfinding problem.

**What AI suggested:** ChatGPT recommended Breadth-First Search (BFS) and explained how to represent the battlefield as a two-dimensional grid.

**What I understood:** Since the unit moves horizontally and vertically and each move has equal cost, BFS is suitable for finding a shortest path.

**Why I continued:** I needed to connect the algorithm to the actual battlefield JSON file.

## 2. Building the C++ Implementation

**What I asked:** I requested the C++ implementation and instructions for setting up the project.

**What AI provided:** ChatGPT generated the main pathfinding logic, including the queue, visited-cell tracking, parent tracking, and path reconstruction.

**What I did:** I added the code to my project, compiled it, and checked the results in the terminal.

**Why I continued:** The next step was to load the supplied battlefield rather than use only a sample grid.

## 3. Reading the JSON Data

**What I asked:** I shared the JSON file and asked how to integrate it into the program.

**What AI provided:** ChatGPT helped implement JSON parsing using nlohmann/json and convert the flattened tile data into a 32×32 grid.

**What I understood:** Each tile has a position determined by its index. The program also needs to identify the start and target and distinguish traversable terrain from obstacles.

**Why I continued:** After integrating the JSON, I needed to investigate the program's output.

## 4. Debugging the Battlefield

**What I asked:** I shared the terminal output showing `No path available` and asked why the program was returning that result.

**What AI suggested:** ChatGPT recommended checking the surrounding cells and running an independent reachability test.

**What I tested:** I compiled and executed the updated program. The results were:

- Start: (25, 0)
- Target: (8, 30)
- Reachable ground cells: 554
- Target reachable: No

**What I understood:** Under the documented terrain assumptions, the target could not be reached through four-direction movement.

**Why I continued:** I wanted to confirm that the algorithm could successfully find a path on a map where a route existed.

## 5. Testing the Pathfinding Logic

**What I asked:** I requested a smaller test case to verify the algorithm.

**What AI provided:** ChatGPT generated a test program with a small grid and a reachable target.

**What I did:** I compiled and executed the test program.

The result was a valid path with four moves:

`(0,0) → (1,0) → (2,0) → (2,1) → (2,2)`

**What I understood:** This test demonstrated that the BFS implementation could reconstruct a path when the target was reachable. It did not independently verify every possible input or terrain interpretation.

## 6. Documentation and Submission

**What I asked:** I requested help preparing the README and uploading the project to GitHub.

**What AI provided:** ChatGPT drafted documentation, explained the build commands, and guided me through the GitHub upload process.

**What I did:** I uploaded the source files, test outputs, and README to a public repository and updated the README to match the uploaded file structure.

## AI Usage Disclosure

ChatGPT provided substantial assistance with the implementation, debugging, testing code, and documentation. I followed its guidance, compiled and executed the program, shared errors and outputs, and checked the resulting behavior.

The parts of the exercise I worked through directly included setting up the local development environment, running compiler commands, checking terminal results, and uploading the project to GitHub.

The full AI conversation is included separately as required by the assessment.
