// 1296. Path with Maximum Gold
// Problem definition: https://leetcode.com/problems/path-with-maximum-gold/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <iostream>
#include <queue>
#include <tuple>

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        auto predicate = [](const auto& a, const auto& b) {
            return std::get<2>(a) < std::get<2>(b);
        };
        std::priority_queue<std::tuple<int,int,int>, 
            std::vector<std::tuple<int,int,int>>, decltype(predicate)> queue(predicate);
        for (int i {0}; i < grid.size(); ++i) {
            for (int j {0}; j < grid[i].size(); ++j) {
                if (grid[i][j] != 0) {
                    queue.push({i,j,grid[i][j]});
                }
            }
        }

        std::vector status(grid.size(), std::vector<std::pair<int,bool>>(grid[0].size(),{0,false}));
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{0,6,0},{5,8,7},{0,9,0}},24},
        {{{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}},28}
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
