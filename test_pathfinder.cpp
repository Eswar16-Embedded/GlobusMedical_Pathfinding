
#include <iostream>
#include "pathfinder.h"

int main() {
    Grid grid = {
        {-1, -1, -1},
        {-1,  3, -1},
        {-1, -1, -1}
    };

    Position start{0, 0};
    Position target{2, 2};

    PathResult result = findPath(grid, start, target);

    if (result.status == PathStatus::Found) {
        std::cout << "Path found!\n";
        std::cout << "Number of moves: "
                  << result.path.size() - 1 << "\n";

        for (const Position& p : result.path) {
            std::cout << "(" << p.row
                      << ", " << p.col << ")\n";
        }
    } else {
        std::cout << "No path available.\n";
    }

    return 0;
}
