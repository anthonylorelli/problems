// 0190. Reverse Bits
// Problem definition: https://leetcode.com/problems/reverse-bits/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>

constexpr uint32_t c_most {0x80000000};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result {0};
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
                REQUIRE(Solution{}.hammingWeight(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
