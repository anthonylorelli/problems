// 1266. Minimum Time Visiting All Points
// Problem definition: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>

using point = std::pair<int,int>;

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int count {0};
        point current{points[0][0], points[0][1]};
        std::for_each(points.begin() + 1, points.end(), [&](const auto& next) {
            point n{next[0], next[1]};
            while (current != n) {
                count++;
                current = move(current, n);
            }
        });
        return count;
    }

private:
    std::pair<int,int> move(const point& current, const point& next) {
        int x = current.first == next.first ? current.first : next.first > current.first ? current.first + 1 : current.first - 1;
        int y = current.second == next.second ? current.second : next.second > current.second ? current.second + 1 : current.second - 1;
        return {x,y};
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
