// 0364. Ugly Number II
// Problem definition: https://leetcode.com/problems/ugly-number-ii/
// Accepted 2021-02-07
// constexpr approach adapted from https://leetcode.com/problems/ugly-number-ii/discuss/1048918/C%2B%2B-constexpr-approach-(0-ms-faster-than-100.00)
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <array>

class Uglies {
public:
    constexpr Uglies() : m_dp{} {
        m_dp[0] = 1;
        int32_t i2 {0}, i3 {0}, i5 {0};
        for (int32_t i {1}; i < m_dp.size(); ++i) {
            const auto m2 = m_dp[i2] * 2;
            const auto m3 = m_dp[i3] * 3;
            const auto m5 = m_dp[i5] * 5;
            m_dp[i] = std::min(m2, std::min(m3, m5));
            if (m2 == m_dp[i]) { ++i2; }
            if (m3 == m_dp[i]) { ++i3; }
            if (m5 == m_dp[i]) { ++i5; }
        }
    }

    int32_t operator[](const int32_t n) const { return m_dp[n]; }

private:
    std::array<int32_t,1690> m_dp;
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) { return 0; }
        constexpr Uglies uglies;
        return uglies[n-1];
    }

    int nthUglyNumber_bottomup(int n) {
        if (n == 0) { return 0; }

        std::vector<int32_t> dp(n, 0);
        dp[0] = 1;
        int32_t i2 {0}, i3 {0}, i5 {0};
        for (int32_t i {1}; i < n; ++i) {
            const auto m2 = dp[i2] * 2;
            const auto m3 = dp[i3] * 3;
            const auto m5 = dp[i5] * 5;
            dp[i] = std::min({m2, m3, m5});
            if (m2 == dp[i]) { ++i2; }
            if (m3 == dp[i]) { ++i3; }
            if (m5 == dp[i]) { ++i5; }
        }

        return dp[n-1];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {10,12},
        {0,0},
        {1,1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.nthUglyNumber(testInput) == expected);
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
