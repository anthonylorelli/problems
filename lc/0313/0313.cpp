// 0313. Super Ugly Number
// Problem definition: https://leetcode.com/problems/super-ugly-number/
// Accepted 2021-02-10
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        if (n == 0) { return 0; }
        std::vector<int32_t> vi(primes.size(), 0);
        std::vector<int32_t> mp(primes.size(), 0);
        std::vector<int32_t> dp(n, 0);
        dp[0] = 1;
        for (int32_t i {1}; i < n; ++i) {
            std::transform(vi.begin(), vi.end(), primes.begin(), mp.begin(), 
                [&dp](const auto a, const auto b) {
                    return dp[a] * b;
                });
            dp[i] = *std::min_element(mp.begin(), mp.end());
            for (int32_t j {0}; j < primes.size(); ++j) {
                if (mp[j] == dp[i]) { ++vi[j]; }
            }
        }
        return dp.back();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<int>,int>> input {
        {12,{2,7,13,19},32},
        {10,{2,3,5},12}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [n, testInput, expected] = p;
                REQUIRE(s.nthSuperUglyNumber(n, testInput) == expected);
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
