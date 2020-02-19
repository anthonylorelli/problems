// 0283. Move Zeroes
// Problem definition: https://leetcode.com/problems/move-zeroes/description/
// 2020-02-18

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](const auto n) { return n; });
    }
};

TEST_CASE("LC test cases", "[Move Zeroes]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{0,1,0,3,12},{1,3,12,0,0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE_NOTHROW(s.moveZeroes(testInput));
                REQUIRE(testInput == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
