// 0152. Maximum Product Subarray
// Problem definition: https://leetcode.com/problems/maximum-product-subarray/
// Accepted 2021-07-27 - very slow!
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        int max {nums[0]};
        for (auto b = nums.begin(); b != nums.end(); ++b) {
            max = std::max(max, *b);
            std::partial_sum(b, nums.end(), result.begin(), [&](const auto a, const auto b) {
                auto c {a * b};
                max = std::max(max, c);
                return c;
            });
        }
        return max;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{2,3,-2,4},6},{{-2,0,-1},0},{{-2},-2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxProduct(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
