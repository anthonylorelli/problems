// 1029. Two City Scheduling
// Problem definition: https://leetcode.com/problems/two-city-scheduling/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        size_t n {costs.size() / 2};
        std::sort(costs.begin(), costs.end(), [](const auto& v1, const auto& v2) {
            return v1[0] == v2[0] ? v2[0] < v2[0] : v1[0] < v2[0];
        });
        int total = std::accumulate(costs.begin(), costs.begin() + n, 0, [](int sum, auto& v) {
            v[1] += 1000;
            return sum + v[0];
        });
        std::sort(costs.begin(), costs.end(), [](const auto& v1, const auto& v2) {
            return v1[1] < v2[1];
        });
        total = std::accumulate(costs.begin(), costs.begin() + n, total, [](int sum, const auto& v) {
            return sum + v[1];
        });
        return total;
    }
};

TEST_CASE("LC test cases", "[Two City Scheduling]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{10,20},{30,200},{400,50},{30,20}},110}
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
