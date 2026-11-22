#include "pathfinder.h"

#include <queue>
#include <algorithm>

PathResult findPath(
    const Grid& grid,
    Position start,
    Position target
) {
    // Step 1: Validate the battlefield
    // Check for an empty grid
if (grid.empty() || grid[0].empty()) {
    return {PathStatus::InvalidInput, {}};
}

const int rows = static_cast<int>(grid.size());
const int cols = static_cast<int>(grid[0].size());

// Check that all rows have the same number of columns
for (const auto& row : grid) {
    if (static_cast<int>(row.size()) != cols) {
        return {PathStatus::InvalidInput, {}};
    }
}

// Check whether a position is inside the battlefield
auto isInside = [&](Position p) {
    return p.row >= 0 && p.row < rows &&
           p.col >= 0 && p.col < cols;
};

// Validate start and target coordinates
if (!isInside(start) || !isInside(target)) {
    return {PathStatus::InvalidInput, {}};
}

// Both positions must be on ground terrain
if (grid[start.row][start.col] != -1 ||
    grid[target.row][target.col] != -1) {
    return {PathStatus::InvalidInput, {}};
}

// Handle the case where start and target are identical
if (start == target) {
    return {PathStatus::Found, {start}};
}

    // Step 2: Initialize BFS data structures
    // Queue for positions waiting to be explored
std::queue<Position> pending;

// Track visited positions
std::vector<std::vector<bool>> visited(
    rows, std::vector<bool>(cols, false)
);

// Sentinel representing no parent
const Position NO_PARENT{-1, -1};

// Store the predecessor of each position
std::vector<std::vector<Position>> parent(
    rows, std::vector<Position>(cols, NO_PARENT)
);

// Begin searching from the starting position
pending.push(start);
visited[start.row][start.col] = true;

    // Step 3: Explore neighboring positions
    // Four allowed directions: Up, Down, Left, Right
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
while (!pending.empty()) {
    Position current = pending.front();
    pending.pop();

    // Stop when the target is removed from the queue
    if (current == target) {
        break;
    }

    // Explore all four neighboring positions
    for (int i = 0; i < 4; ++i) {
        Position next{
            current.row + dr[i],
            current.col + dc[i]
        };

        // Ignore positions outside the battlefield
        if (!isInside(next)) {
            continue;
        }

        // Ignore blocked terrain
        if (grid[next.row][next.col] != -1) {
            continue;
        }

        // Ignore previously visited positions
        if (visited[next.row][next.col]) {
            continue;
        }

        // Record the newly discovered position
        visited[next.row][next.col] = true;
        parent[next.row][next.col] = current;
        pending.push(next);
    }
}

    // Step 4: Reconstruct the shortest path
    // Check whether BFS reached the target
if (visited[target.row][target.col]) {

    std::vector<Position> path;
    Position current = target;

    // Follow parent positions back to the start
    while (!(current == start)) {
        path.push_back(current);
        current = parent[current.row][current.col];
    }

    // Include the starting position
    path.push_back(start);

    // Reverse to obtain start-to-target order
    std::reverse(path.begin(), path.end());

    return {PathStatus::Found, path};
}

    // Step 5: Return the result

    return {PathStatus::Unreachable, {}};
}