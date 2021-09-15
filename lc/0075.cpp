// 0075. Sort Colors
// Problem definition: https://leetcode.com/problems/sort-colors/
// Accepted 2020-03-21

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        if (nums.size() <= 1) { return; }
        int i {0}, start {0}, end = nums.size() - 1;
        while (i <= end) {
            if (nums[i] == 0) {
                std::swap(nums[i++], nums[start++]);
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[end--]);
            } else {
                i++;
            }
        }
    }
};

TEST_CASE("LC test cases", "[Sort Colors]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{2,0,2,1,1,0},{0,0,1,1,2,2}},{{0},{0}},{{1},{1}},{{2},{2}},
        {{1,0,2},{0,1,2}},{{1,2,0},{0,1,2}},{{2,2},{2,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE_NOTHROW(s.sortColors(testInput));
                REQUIRE(testInput == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
