// 0935. Knight Dialer
// Problem definition: https://leetcode.com/problems/knight-dialer/
// Accepted 2019-07-24
// Adapted from https://leetcode.com/problems/knight-dialer/discuss/189229/Concise-C%2B%2B-using-DP-with-explanation

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
private:
    const std::vector<std::vector<unsigned long>> m_hops {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
    static constexpr int m_mod = 1000000007;

public:
    int knightDialer(int N) {
        std::vector<unsigned long> current(10, 1);
        for (std::vector<unsigned long> next(10, 0); --N > 0; std::for_each(next.begin(), next.end(), [](auto& n) { n = 0; })) {
            for (int i {0}; i <= 9; ++i) {
                for (auto hop : m_hops[i]) {
                    next[i] += current[hop] % m_mod;
                }
            }
            current.swap(next);
        }
        return std::accumulate(current.cbegin(), current.cend(), 0UL) % m_mod;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Knight Dialer]") {
    SECTION("LC test case 1-3") {
        Solution s;
        REQUIRE(s.knightDialer(1) == 10);
        REQUIRE(s.knightDialer(2) == 20);
        REQUIRE(s.knightDialer(3) == 46);
    }
}
