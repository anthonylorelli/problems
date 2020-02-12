// 0064. Minimum Path Sum
// Problem definition: https://leetcode.com/problems/minimum-path-sum/
// 2020-02-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) { return 0; }
        for (size_t i {0}; i < grid.size(); ++i) {
            for (size_t j {0}; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    grid[i][j] = grid[i][j];
                } else if (i == 0) {
                    grid[0][j] = grid[0][j] + grid[0][j-1];
                } else if (j == 0) {
                    grid[i][0] = grid[i][0] + grid[i-1][0];
                } else { 
                    grid[i][j] = std::min(grid[i][j-1], grid[i-1][j]) + grid[i][j];
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

TEST_CASE("LC test cases", "[Count Binary Substrings]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{1,3,1},{1,5,1},{4,2,1}}, 7}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.minPathSum(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
