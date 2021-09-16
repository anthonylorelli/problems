// 0016. 3Sum Closest
// Problem definition: https://leetcode.com/problems/3sum-closest/
// Accepted 2021-09-15
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int32_t answer {nums[0] + nums[1] + nums[2]};
        const int32_t size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int32_t i {0}; i < size - 2; ++i) {
            int32_t left {i + 1}, right {size - 1};
            while (left < right) {
                int32_t sum = nums[i] + nums[left] + nums[right];
                if (std::abs(sum - target) < std::abs(answer - target)) {
                    answer = sum;
                }
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    return target;
                }
            }
        }
        return answer;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,int>> input {
        {{-1,2,1,-4},1,2},{{0,0,0},1,0},
        {{1,1,1,0},-100,2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.threeSumClosest(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
