// 0053. Maximum Subarray
// Problem definition: https://leetcode.com/problems/maximum-subarray/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{-2,1,-3,4,-1,2,1,-5,4},6},{{1},1},{{5,4,-1,7,8},23}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxSubArray(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
