// 0216. Combination Sum III
// Problem definition: https://leetcode.com/problems/combination-sum-iii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        constexpr auto nums = {1,2,3,4,5,6,7,8,9};
        constexpr int32_t limit = std::accumulate(nums.begin(), nums.end(), 0);
        if (n > limit) {
            return {};
        }
        m_k = k;
        std::vector<int> combo(k);
        for (int32_t i {0}; i < nums.size(); ++i) {
            combine(nums.begin() + i, nums.end(), n, combo, 0);
        }
        return m_result;
    }

    template <typename It>
    void combine(It begin, It end, const int32_t delta, std::vector<int>& combo, const int32_t j) {
        if (delta == 0 && j == m_k) {
            m_result.push_back(combo);
            return;
        }
        if ((delta == 0 && j != m_k) || j == m_k || begin == end) {
            return;
        }
        if (*begin <= delta) {
            combo[j] = *begin;
            combine(begin + 1, end, delta - *begin, combo, j+1);
        }
        if (j > 0) {
            combine(begin + 1, end, delta, combo, j);
        }
    }

private:
    std::vector<std::vector<int>> m_result;
    int32_t m_k;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int,std::vector<std::vector<int>>>> input {
        {3,7,{{1,2,4}}},{3,9,{{1,2,6},{1,3,5},{2,3,4}}},{4,1,{}},
        {3,2,{}},{9,45,{{1,2,3,4,5,6,7,8,9}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [k, n, expected] = p;
                REQUIRE(s.combinationSum3(k,n) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
