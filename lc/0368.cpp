// 0368. Largest Divisible Subset
// Problem definition: https://leetcode.com/problems/largest-divisible-subset/
// Accepted 2021-08-28
// Cf. https://leetcode.com/problems/largest-divisible-subset/discuss/714538/Classical-DP-Similar-to-Longest-Increasing-Subsequence-(LIS)
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> dp(nums.size(), 1);
        int max_len {1};
        for (int i {0}; i < nums.size(); ++i) {
            for (int j {0}; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_len = std::max(max_len, dp[i]);
        }

        std::vector<int> result;
        int prev {-1};
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (max_len == dp[i] && (prev == -1 || prev % nums[i] == 0)) {
                result.push_back(nums[i]);
                max_len--;
                prev = nums[i];
            }
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{1,2,3},{3,1}},{{1,2,4,8},{8,4,2,1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.largestDivisibleSubset(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
