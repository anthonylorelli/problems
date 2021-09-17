// 0018. 4Sum
// Problem definition: https://leetcode.com/problems/4sum/
// Accepted 2021-09-16
// Cf. https://leetcode.com/problems/4sum/solution/
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    std::vector<std::vector<int>> kSum(std::vector<int>& nums, int64_t target, int start, int64_t k) {
        std::vector<std::vector<int>> result;
        if (start == nums.size() || (nums[start] * k > target) || (target > nums.back() * k)) {
            return result;
        }
        if (k == 2) {
            return twoSum(nums, target, start);
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (auto& subset : kSum(nums, target - nums[i], i + 1, k - 1)) {
                    result.push_back({nums[i]});
                    std::transform(subset.begin(), subset.end(), std::back_inserter(result.back()), 
                        [](const auto n) { return n; });
                }
            }
        }
        return result;
    }

    std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target, int start) {
        std::vector<std::vector<int>> result;
        std::unordered_set<int> set;
        for (int i {start}; i < nums.size(); ++i) {
            if (result.empty() || result.back()[0] != nums[i]) {
                if (set.count(target - nums[i]) > 0) {
                    result.push_back({nums[i], target - nums[i]});
                }
            }
            set.insert(nums[i]);
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
        {{1,0,-1,0,-2,2},0,{{-2,-1,2,1},{-2,0,2,0},{-1,0,1,0}}},
        {{2,2,2,2,2},8,{{2,2,2,2}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.fourSum(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
