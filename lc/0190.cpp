// 0190. Reverse Bits
// Problem definition: https://leetcode.com/problems/reverse-bits/
// Accepted 2021-06-10
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = (n >> 16) | (n << 16);
        result = ((result & 0xff00ff00) >> 8) | ((result & 0x00ff00ff) << 8);
        result = ((result & 0xf0f0f0f0) >> 4) | ((result & 0x0f0f0f0f) << 4);
        result = ((result & 0xcccccccc) >> 2) | ((result & 0x33333333) << 2);
        return ((result & 0xaaaaaaaa) >> 1) | ((result & 0x55555555) << 1);
    }

    uint32_t reverseBits_iter(uint32_t n) {
        uint32_t result {0};
        for (uint32_t i {0}; i < 32; ++i, n >>= 1) {
            result <<= 1;
            result |= (n & 1);
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<uint32_t,uint32_t>> input {
        {0b00000010100101000001111010011100,0b00111001011110000010100101000000},
        {0b11111111111111111111111111111101,0b10111111111111111111111111111111}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.reverseBits(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
