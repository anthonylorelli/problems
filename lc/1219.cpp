// 1296. Path with Maximum Gold
// Problem definition: https://leetcode.com/problems/path-with-maximum-gold/
// Accepted 2020-10-05

#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        for (int i {0}; i < grid.size(); ++i) {
            for (int j {0}; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    walk(grid, i, j, 0);
                }
            }
        }

        return m_max;
    }

private:
    void walk(std::vector<std::vector<int>>& grid, const int row, const int col, const int sum) {
        if (grid[row][col] <= 0) {
            return;
        }

        const int latest {grid[row][col] + sum};
        m_max = std::max(latest, m_max);

        grid[row][col] *= -1;

        if (col > 0) { walk(grid, row, col - 1, latest); }
        if (row > 0) { walk(grid, row - 1, col, latest); }
        if (row < (grid.size() - 1)) { walk(grid, row + 1, col, latest); }
        if (col < (grid[0].size() - 1)) { walk(grid, row, col + 1, latest); }

        grid[row][col] *= -1;
    }

    int m_max {0};
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{0,6,0},{5,8,7},{0,9,0}},24},
        {{{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}},28},
        {{{1,0},{0,1}},1},
        {{{10}},10},
        {{{0}},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.getMaximumGold(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
