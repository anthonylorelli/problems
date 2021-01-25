// 0204. Count Primes
// Problem definition: https://leetcode.com/problems/count-primes/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int countPrimes(int n) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {10,4},
        {0,0},
        {1,0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countPrimes(testInput) == expected);
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
