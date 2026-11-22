#pragma once

#include <vector>

struct Position {
    int row;
    int col;

    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
};

using Grid = std::vector<std::vector<int>>;

enum class PathStatus {
    Found,
    Unreachable,
    InvalidInput
};

struct PathResult {
    PathStatus status;
    std::vector<Position> path;
};

PathResult findPath(
    const Grid& grid,
    Position start,
    Position target
);