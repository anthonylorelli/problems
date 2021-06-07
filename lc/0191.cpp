// 0191. Number of 1 Bits
// Problem definition: https://leetcode.com/problems/number-of-1-bits/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <stack>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<uint32_t,int>> input {
        {0b00000000000000000000000000001011,3},{0b00000000000000000000000010000000,1},
        {0b11111111111111111111111111111101,31}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.hammingWeight(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
