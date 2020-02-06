// 0189. Rotate Array
// Problem definition: https://leetcode.com/problems/rotate-array/
// 2020-02-06

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::rotate(nums.rbegin(), nums.rbegin() + (k % nums.size()), nums.rend());
    }
};

TEST_CASE("LC test cases", "[Rotate Array]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,std::vector<int>>> input {
        {{{1,2,3,4,5,6,7},3},{5,6,7,1,2,3,4}},{{{-1,-100,3,99},2},{3,99,-1,-100}},
        {{{1,2,3,4,5,6,7},0},{1,2,3,4,5,6,7}},{{{1,2,3,4,5,6,7},1},{7,1,2,3,4,5,6}},
        {{{1,2,3,4,5,6,7},8},{7,1,2,3,4,5,6}},{{{1,2,3,4,5,6,7},9},{6,7,1,2,3,4,5}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE_NOTHROW(s.rotate(testInput.first, testInput.second));
                REQUIRE(testInput.first == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
