// 0045. Jump Game II
// Problem definition: https://leetcode.com/problems/jump-game-ii/
// Accepted 2021-08-21
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        for (int i = 1, max_range = nums[0], current = nums[0], steps = 0; i < nums.size(); ++i) {
            if (current + i >= nums.size()) {
                return steps + 1;
            }
            current--;
            max_range--;
            max_range = std::max(max_range, nums[i]);
            if (current == 0) {
                current = max_range;
                steps++;
            }
        }
        return 0;
    }
};

class Solution_n2 {
public:
    int jump(std::vector<int>& nums) {
        std::vector<int> jumps(nums.size(), 0);
        for (size_t i {0}; i < nums.size(); ++i) {
            const auto steps {jumps[i] + 1};
            for (size_t j {i + 1}; j <= (i + nums[i]) && j < nums.size(); ++j) {
                jumps[j] = jumps[j] == 0 ? steps : std::min(steps, jumps[j]);
            }
        }
        return jumps.back();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{2,3,1,1,4},2},{{2,3,0,1,4},2},{{5},0},{{4,0},1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.jump(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
