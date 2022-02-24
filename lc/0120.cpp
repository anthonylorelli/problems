// 0120. Triangle
// Problem definition: https://leetcode.com/problems/triangle/
// Accepted 2020-12-31
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        if (triangle.size() == 1) { return triangle[0][0]; }
        std::vector<int> memo = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j {0}; j < triangle[i].size(); ++j) {
                memo[j] = triangle[i][j] + std::min(memo[j], memo[j+1]);
            }
        }
        return memo[0];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{2},{3,4},{6,5,7},{4,1,8,3}},11},
        {{{-10}},-10},
        {{{-1},{3,2},{-3,1,-1}},-1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.minimumTotal(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
