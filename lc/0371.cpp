// 0371. Sum of Two Integers
// Problem definition: https://leetcode.com/problems/sum-of-two-integers/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    int getSum(int a, int b) {
        uint32_t carry {0};
        while (b != 0) {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int,int>> input {
        {1,2,3},{2,3,5}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, input2, expected] = p;
                REQUIRE(s.getSum(testInput, input2) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
