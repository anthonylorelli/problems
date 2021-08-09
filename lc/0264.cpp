// 0264. Ugly Number II
// Problem definition: https://leetcode.com/problems/ugly-number-ii/
// Accepted 2021-08-08
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <array>

constexpr int32_t c_max_size {1690};

class Uglies {
public:
    constexpr Uglies() : m_arr{} {
        m_arr[0] = 1;
        int32_t i2 {0}, i3 {0}, i5 {0};
        for (int32_t i {1}; i < m_arr.size(); ++i) {
            const auto n2 {m_arr[i2] * 2};
            const auto n3 {m_arr[i3] * 3};
            const auto n5 {m_arr[i5] * 5};
            m_arr[i] = std::min({n2, n3, n5});
            if (m_arr[i] == n2) { i2++; }
            if (m_arr[i] == n3) { i3++; }
            if (m_arr[i] == n5) { i5++; }
        }
    }

    constexpr int32_t operator[](const int32_t index) const { return m_arr[index]; }

private:
    std::array<int32_t,c_max_size> m_arr;
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) { return 0; }
        constexpr Uglies uglies;
        return uglies[n-1];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {10,12},{1,1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [in, expected] = p;
                REQUIRE(s.nthUglyNumber(in) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
