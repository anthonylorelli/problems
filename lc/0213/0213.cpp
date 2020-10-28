// 0213. House Robber II
// Problem definition: https://leetcode.com/problems/house-robber-ii/
// Accepted 2020-10-27
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <array>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        auto size {nums.size()};
        if (size == 0) { return 0; }
        if (size == 1) { return nums[0]; }
        if (size == 2) { return std::max(nums[0], nums[1]); }

        int lower = rob(nums, 0, size - 1);
        int upper = rob(nums, 1, size);

        return std::max(lower, upper);
    }

private:
    int rob(std::vector<int>& nums, const int start, const int end) {
        int maxes[] = {nums[start], nums[start+1]};

        for (int i = start + 2; i < end; ++i) {
            int j {(i + start) % 2};
            int next = nums[i] + maxes[j];
            maxes[(j + 1) % 2] = std::max(maxes[0], maxes[1]);
            maxes[j] = next;
        }

        return std::max(maxes[0], maxes[1]);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{1,2,3,1},4},
        {{2,7,9,3,1},11},
        {{10,1,2,11},12},
        {{1},1},
        {{4,3},4},
        {{4,3,4},4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.rob(testInput) == expected);
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
