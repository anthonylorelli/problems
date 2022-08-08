// 0338. Counting Bits
// Problem definition: https://leetcode.com/problems/counting-bits/
// Accepted 2022-08-01
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

constexpr int32_t c_max_size {50001};

class BitCount {
public:
    constexpr BitCount() : m_arr{} {
        std::iota(m_arr.begin(), m_arr.end(), 0);
        int32_t largest_2 {2};
        auto start {m_arr.begin() + 2};
        std::transform(start, m_arr.end(), start, [&](const auto n) {
            if ((n / largest_2) > 1) { largest_2 <<= 1; }
            const int32_t rem {n - largest_2};
            return m_arr[rem] + 1;
        });
    }

    const auto begin() const { return m_arr.begin(); }
    const auto end() const { return m_arr.end(); }

private:
    std::array<int32_t,c_max_size> m_arr;
};

class Solution {
public:
    std::vector<int> countBits(int n) {
        constexpr BitCount count;
        std::vector<int> result;
        std::copy(count.begin(), count.begin() + n + 1, std::back_inserter(result));
        return result;
    }
};

class SolutionIter {
public:
    std::vector<int> countBits(int n) {
        if (n == 0) { return {0}; }
        if (n == 1) { return {0,1}; }

        std::vector<int> result = {0, 1, 1};
        int32_t largest_2 {2};
        
        for (int32_t i {3}; i <= n; ++i) {
            if ((i / largest_2) > 1) { largest_2 <<= 1; }
            const int32_t rem {i - largest_2};
            result.push_back(result[rem] + 1);
        }

        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<int,std::vector<int>>> input {
        {2, {0,1,1}}, {5, {0,1,1,2,1,2}}, {1, {0,1}},
        {3, {0,1,1,2}}, {4, {0,1,1,2,1}}, {6, {0,1,1,2,1,2,2}},
        {7, {0,1,1,2,1,2,2,3}}, {8, {0,1,1,2,1,2,2,3,1}},
        {9, {0,1,1,2,1,2,2,3,1,2}}, {10, {0,1,1,2,1,2,2,3,1,2,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBits(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
