
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "pathfinder.h"
#include "json.hpp"

int main() {
    // Load battlefield JSON
    std::ifstream file("take_home_project.json");

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open JSON file.\n";
        return 1;
    }

    nlohmann::json mapJson;

    try {
        file >> mapJson;
    } catch (const std::exception& e) {
        std::cerr << "JSON parsing error: "
                  << e.what() << "\n";
        return 1;
    }

    const int width = 32;
    const int height = 32;

    Grid grid(height, std::vector<int>(width, -1));

    Position start{-1, -1};
    Position target{-1, -1};

    int startCount = 0;
    int targetCount = 0;

    // Convert JSON tile data into the battlefield grid
    try {
        const auto& data =
            mapJson.at("layers").at(0).at("data");

        if (!data.is_array() ||
            data.size() != static_cast<std::size_t>(width * height)) {
            std::cerr << "Invalid map dimensions.\n";
            return 1;
        }

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                double tile =
                    data.at(row * width + col).get<double>();

                if (tile == 8.3) {
                    start = {row, col};
                    grid[row][col] = -1;
                    ++startCount;
                } else if (tile == 0.5) {
                    target = {row, col};
                    grid[row][col] = -1;
                    ++targetCount;
                } else if (tile == -1) {
                    grid[row][col] = -1;
                } else if (tile == 3 || tile == 0) {
                    // Assumption: undefined tile 0 is blocked.
                    grid[row][col] = 3;
                } else {
                    std::cerr << "Unknown tile value: "
                              << tile << " at ("
                              << row << ", " << col << ")\n";
                    return 1;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Invalid battlefield JSON: "
                  << e.what() << "\n";
        return 1;
    }

    // Validate start and target positions
    if (startCount != 1 || targetCount != 1) {
        std::cerr << "Expected exactly one start "
                  << "and one target.\n";
        return 1;
    }

    std::cout << "Start: (" << start.row
              << ", " << start.col << ")\n";

    std::cout << "Target: (" << target.row
              << ", " << target.col << ")\n";

    // Find the shortest path using BFS
    PathResult result = findPath(grid, start, target);

    if (result.status == PathStatus::Found) {
        std::cout << "\nPath found!\n";

        std::cout << "Number of moves: "
                  << result.path.size() - 1 << "\n";

        for (const Position& p : result.path) {
            std::cout << "(" << p.row
                      << ", " << p.col << ")\n";
        }
    } else if (result.status == PathStatus::Unreachable) {
        std::cout << "\nNo path available.\n";
    } else {
        std::cerr << "\nInvalid battlefield input.\n";
        return 1;
    }

    return 0;
}
