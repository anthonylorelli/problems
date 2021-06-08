// 0191. Number of 1 Bits
// Problem definition: https://leetcode.com/problems/number-of-1-bits/
// Accepted 2021-06-07
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <stack>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits {0};
        while (n > 0) {
            bits += count(n & 0xF);
            n >>= 4;
        }
        return bits;
    }

    constexpr int count(const uint32_t n) {
        switch (n) {
        case 15: // 1111
            return 4;
        case 14: // 1110
        case 13: // 1101
        case 11: // 1011
        case 7:  // 0111
            return 3;
        case 12: // 1100
        case 10: // 1010
        case 9:  // 1001
        case 6:  // 0110
        case 5:  // 0101
        case 3:  // 0011
            return 2;
        case 8:
        case 4:
        case 2:
        case 1:
            return 1;
        }

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
