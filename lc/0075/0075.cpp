// 0075. Sort Colors
// Problem definition: https://leetcode.com/problems/sort-colors/
// Accepted 2020-03-21

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int zeros {0}, ones {0}, twos {0};
        for (const auto n : nums) {
            if (n == 0) {
                zeros++;
            } else if (n == 1) {
                ones++;
            } else {
                twos++;
            }
        }
        std::fill(nums.begin(), nums.begin() + zeros, 0);
        std::fill(nums.begin() + zeros, nums.begin() + zeros + ones, 1);
        std::fill(nums.begin() + zeros + ones, nums.end(), 2);
    }
};

TEST_CASE("LC test cases", "[Sort Colors]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{2,0,2,1,1,0},{0,0,1,1,2,2}},{{0},{0}},{{1},{1}},{{2},{2}}
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
