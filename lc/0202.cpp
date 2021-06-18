// 0202. Happy Number
// Problem definition: https://leetcode.com/problems/happy-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>

class Solution {
public:
    bool isHappy(int n) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {19,true},{2,false}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.isHappy(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
