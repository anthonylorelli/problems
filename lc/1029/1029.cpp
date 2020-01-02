// 1029. Two City Scheduling
// Problem definition: https://leetcode.com/problems/two-city-scheduling/
// Accepted 2020-01-01

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        std::sort(costs.begin(), costs.end(), [](const auto& v1, const auto& v2) {
            return v1[1] - v1[0] > v2[1] - v2[0];
        });
        const auto n {costs.size() / 2};
        int total = std::accumulate(costs.begin(), costs.begin() + n, 0, [](int sum, const auto& v) {
            return sum + v[0];
        });
        total = std::accumulate(costs.begin() + n, costs.end(), total, [](int sum, const auto& v) {
            return sum + v[1];
        });
        return total;
    }
};

TEST_CASE("LC test cases", "[Two City Scheduling]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{10,20},{30,200},{400,50},{30,20}},110},
        {{{20,10},{200,30},{50,400},{20,30}},110},
        {{{999,1},{999,2},{999,3},{999,4}},2001},
        {{{1,999},{2,999},{3,999},{4,999}},2001}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.twoCitySchedCost(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
