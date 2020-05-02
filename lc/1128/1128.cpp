// 1128. Number of Equivalent Domino Pairs
// Problem definition: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Accepted 2020-05-02

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

constexpr int count_pairs(const int n) {
    return (n * (n - 1)) / 2;
}

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::vector<int> list(100, 0);
        for (const auto& d : dominoes) {
            int index = std::min(d[0], d[1]) * 10 + std::max(d[0], d[1]);
            list[index]++;
        }
        return std::accumulate(list.begin(), list.end(), 0, [](const auto t, const auto count) {
            return t + (count > 1 ? count_pairs(count) : 0);
        });
    }
};

TEST_CASE("LC test cases", "[Number of Equivalent Domino Pairs]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{1,2},{2,1},{3,4},{5,6}},1},{{{1,2},{2,1},{1,2},{5,6}},3},
        {{{1,2},{2,1},{1,2},{2,1}},6},{{{1,1},{1,1},{1,2},{2,1}},2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numEquivDominoPairs(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
