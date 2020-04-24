// 1266. Minimum Time Visiting All Points
// Problem definition: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Accepted 2020-04-22

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>

using point = std::pair<int,int>;

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        auto total = std::accumulate(points.begin() + 1, points.end(), 
            std::tuple{0, points[0][0], points[0][1]}, [](const auto t, const auto& next) {
            auto [sum, x, y] = t;
            sum += std::max(std::abs(next[0] - x), std::abs(next[1] - y));
            return std::tuple{sum, next[0], next[1]};
        });
        return std::get<0>(total);
    }
};

TEST_CASE("LC test cases", "[Minimum Time Visiting All Points]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{1,1},{3,4},{-1,0}},7},{{{3,2},{-2,2}},5},
        {{{1,1}},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.minTimeToVisitAllPoints(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
