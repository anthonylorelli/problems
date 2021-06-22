// 0263. Ugly Number
// Problem definition: https://leetcode.com/problems/ugly-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>

class Solution {
public:
    bool isUgly(int num) {
        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {6,true},{8,true},{14,false},{1,true}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.isUgly(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
