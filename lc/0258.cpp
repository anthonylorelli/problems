// 0258. Add Digits
// Problem definition: https://leetcode.com/problems/add-digits/
// Accepted 2021-06-16
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) { return 0; }
        if (num % 9 == 0) { return 9; }
        return num % 9;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {38,2},{0,0}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.addDigits(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
