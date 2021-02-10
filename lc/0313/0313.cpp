// 0313. Super Ugly Number
// Problem definition: https://leetcode.com/problems/super-ugly-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <array>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        if (n == 0) { return 0; }
        std::vector<int32_t> vi(primes.size(), 0);
        std::vector<int32_t> dp(n, 0);
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<int>,int>> input {
        {12,{2,7,13,19},32}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.nthSuperUglyNumber(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
