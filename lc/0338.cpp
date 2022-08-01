// 0338. Counting Bits
// Problem definition: https://leetcode.com/problems/counting-bits/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<int,std::vector<int>>> input {
        {{2, {0,1,1}}, {5, {0,1,1,2,1,2}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBits(testInput, k) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
