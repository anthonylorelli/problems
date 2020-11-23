// 0026. Remove Duplicates from Sorted Array
// Problem definition: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Accepted 2020-11-21
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"

#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto end = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), end);
    }

    int removeDuplicatesRawLoop(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int left {0};
        for (int right {1}; right < nums.size(); ++right) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
        }
        return left + 1;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::pair<std::vector<int>,int>>> input {
        {{1,2,3},{{1,2,3},3}},
        {{1,1,2,2,3,3},{{1,2,3},3}},
        {{},{{},0}},
        {{1},{{1},1}},
        {{1,1,2,3},{{1,2,3},3}},
        {{1,2,3,3,3},{{1,2,3},3}},
        {{1,1,1,1},{{1},1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                auto& [output, count] = expected;
                REQUIRE(s.removeDuplicates(testInput) == count);
                for (int i {0}; i < count; ++i) {
                    REQUIRE(testInput[i] == output[i]);
                }
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
