// 0039. Combination Sum
// Problem definition: https://leetcode.com/problems/combination-sum/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
        {{2,3,6,7},7,{{2,2,3},{7}}},
        {{2,3,5},8,{{2,2,2,2},{2,3,3},{3,5}}},
        {{2},1,{}},{{1},1,{{1}}},
        {{1},2,{{1,1}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.combinationSum(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
