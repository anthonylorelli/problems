// 1266. Minimum Time Visiting All Points
// Problem definition: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Minimum Time Visiting All Points]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{1,1},{3,4},{-1,0}},7},{{{3,2},{-2,2}},5}
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
