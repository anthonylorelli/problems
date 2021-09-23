// 0053. Maximum Subarray
// Problem definition: https://leetcode.com/problems/maximum-subarray/
// Accepted 2021-09-22
// Cf. https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int32_t sum {nums[0]}, max {nums[0]};
        for (int32_t i {1}; i < nums.size(); ++i) {
            sum = std::max(nums[i], sum + nums[i]);
            max = std::max(max, sum);
        }
        return max;
    }

    int maxSubArray_foreach(std::vector<int>& nums) {
        int32_t sum {nums[0]}, max {nums[0]};
        std::for_each(nums.begin() + 1, nums.end(), [&](const auto n) {
            sum = std::max(n, sum + n);
            max = std::max(max, sum);
        });
        return max;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{-2,1,-3,4,-1,2,1,-5,4},6},{{1},1},{{5,4,-1,7,8},23}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxSubArray(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
