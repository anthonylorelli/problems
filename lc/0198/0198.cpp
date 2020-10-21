// 0198. House Robber
// Problem definition: https://leetcode.com/problems/house-robber/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return nums[0]; }

        int even_max {nums[0]};
        int odd_max {nums[1]};

        for (int i {2}; i < nums.size(); ++i) {
            bool even {i % 2 == 0};
            int next = nums[i] + (even ? even_max : odd_max);
            if (even) {
                odd_max = std::max(odd_max, even_max);
                even_max = next;
            } else {
                even_max = std::max(odd_max, even_max);
                odd_max = next;
            }
        }

        return std::max(even_max, odd_max);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{1,2,3,1},4},
        {{2,7,9,3,1},12},
        {{10,1,2,11},21}
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
