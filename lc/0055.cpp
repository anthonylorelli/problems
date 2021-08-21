// 0055. Jump Game
// Problem definition: https://leetcode.com/problems/jump-game/
// Accepted 2021-08-21
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        for (int i = 0, max_range = nums[0]; i < nums.size(); ++i) {
            if (max_range < i) {
                return false;
            }

            max_range = std::max(max_range, i + nums[i]);
        }
        return true;
    }
};

class Solution_toomuchwork {
public:
    bool canJump(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        for (int i = 1, current = nums[0], max_range = nums[0]; i < nums.size(); ++i) {
            if (current == 0 && max_range == 0) {
                return false;
            }
            if (current + i >= nums.size()) {
                return true;
            }

            max_range--;
            max_range = std::max(max_range, nums[i]);
            current--;

            if (current == 0) {
                current = max_range;
            }
        }
        return true;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,bool>> input {
        {{2,3,1,1,4},true},{{3,2,1,0,4},false},{{5},true},{{4,0},true},{{0,1},false},
        {{1,1,1,1,0,1,1},false},{{0,1,1,1},false},{{2,1,2,0,1,2,0,1},true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.canJump(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
