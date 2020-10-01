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

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
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
