// 0377. Combination Sum IV
// Problem definition: https://leetcode.com/problems/combination-sum-iv/
// Accepted 2021-08-29
// Cf. https://leetcode.com/problems/combination-sum-iv/discuss/1167162/C%2B%2B-DP-Solution-Explained-100-Time-~80-Space
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<int64_t> dp(target + 1, 0);
        dp[0] = 1;
        for (int32_t i {1}; i <= target; ++i) {
            for (const auto n : nums) {
                if (i >= n) {
                    dp[i] += dp[i - n];
                }
                if (dp[i] > std::numeric_limits<int32_t>::max()) {
                    break;
                }
            }
        }
        return dp[target];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,int>> input {
        {{1,2,3},4,7},{{9},3,0},{{1,2,3},32,181997601}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.combinationSum4(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
