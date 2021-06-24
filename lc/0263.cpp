// 0263. Ugly Number
// Problem definition: https://leetcode.com/problems/ugly-number/
// Accepted 2021-06-23
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>

class Solution {
public:
    bool isUgly(int num) {
        return 1 == factor_out(factor_out(factor_out(num, 2), 3), 5);
    }

    constexpr int32_t factor_out(int32_t n, const int32_t factor) {
        while (n % factor == 0 && n > 0) { n /= factor; }
        return n;
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
