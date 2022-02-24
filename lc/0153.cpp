// 0153. Find Minimum in Rotated Sorted Array
// Problem definition: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Accepted 2021-01-08
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left {0};
        int right = nums.size() - 1;
        if (nums[left] < nums[right]) {
            return nums[left];
        }

        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[left] > nums[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{3,4,5,1,2},1},
        {{4,5,6,7,0,1,2},0},
        {{11,13,15,17},11},
        {{-10},-10},
        {{-10,10},-10},
        {{10,-10},-10}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findMin(testInput) == expected);
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
