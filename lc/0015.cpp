// 0015. 3Sum
// Problem definition: https://leetcode.com/problems/3sum/
// Accepted 2021-09-12
// Cf. https://leetcode.com/problems/3sum/discuss/369728/Short-C%2B%2B-solution-beats-98-using-sorting-and-2-pointer-method
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.empty()) {
            return result;
        }

        const int32_t size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int32_t i {0}; i < size; ++i) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int32_t left {i + 1}, right {size - 1};
            while (left < right) {
                auto sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    const auto last_l {nums[left]}, last_r {nums[right]};
                    while (left < right && nums[left] == last_l) { ++left; };
                    while (left < right && nums[right] == last_r) { --right; }
                }
            }
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<std::vector<int>>>> input {
        {{-1,0,1,2,-1,-4},{{-1,-1,2},{-1,0,1}}},
        {{},{}},{{0},{}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.threeSum(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
