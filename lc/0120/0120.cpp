// 0120. Triangle
// Problem definition: https://leetcode.com/problems/triangle/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        if (triangle.size() == 1) { return triangle[0][0]; }
        std::vector<std::vector<int>> memo(triangle.size());
        memo[0].push_back(triangle[0][0]);
        for (int i {1}; i < triangle.size(); ++i) {
            int limit = triangle[i-1].size();
            for (int j {0}; j < triangle[i].size(); ++j) {
                int min {std::numeric_limits<int>::max()};
                if (j > 0) {
                    min = std::min(min, memo[i-1][j-1]);
                }
                if (j < limit) {
                    min = std::min(min, memo[i-1][j]);
                }
                if (j + 1 < limit) {
                    min = std::min(min, memo[i-1][j+1]);
                }
                memo[i].push_back(triangle[i][j] + min);
            }
        }
        return *std::min_element(memo.back().begin(), memo.back().end());
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{2},{3,4},{6,5,7},{4,1,8,3}},11},
        {{{-10}},-10},
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
