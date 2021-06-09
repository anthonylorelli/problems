// 0231. Power of Two
// Problem definition: https://leetcode.com/problems/power-of-two/
// Accepted 2021-06-08
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) { return false; }
        return !(n & n - 1);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {1,true},{16,true},{3,false},{4,true},{5,false}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.isPowerOfTwo(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
