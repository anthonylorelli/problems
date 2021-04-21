// 0464. Can I Win
// Problem definition: https://leetcode.com/problems/can-i-win/
// Accepted ?
// Cf. https://leetcode.com/problems/can-i-win/discuss/95320/Clean-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <array>
#include <iostream>

constexpr int32_t pow2(const int32_t exp) {
    return 1 << exp;
}

int32_t g_mem[pow2(20)] = {};

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int32_t sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal < 2) {
            return true;
        }
        if (sum < desiredTotal) {
            return false;
        }
        if (sum == desiredTotal) {
            return is_odd(maxChoosableInteger);
        }
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

private:
    constexpr bool is_odd(const int32_t n) const noexcept {
        return n & 1;
    }

    bool dfs(const int m, const int t, const int k) {
        if (g_mem[k] != 0) {
            return g_mem[k] > 0;
        }
        if (t <= 0) {
            return false;
        }

        for (int32_t i {0}; i < m; ++i) {
            if (!(k & pow2(i)) && !dfs(m, t - i - 1, k | pow2(i))) {
                g_mem[k] = 1;
                return true;
            }
        }

        g_mem[k] = -1;
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    SECTION("Test cases") {
        std::vector<std::tuple<int,int,bool>> input {
            {10, 11, false}, {10, 0, true}, {10, 1, true}, {4, 6, true}
        };
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto [maxInt, desired, expected] = p;
                REQUIRE(Solution{}.canIWin(maxInt, desired) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
