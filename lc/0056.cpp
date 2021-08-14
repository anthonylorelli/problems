// 0056. Merge Interval
// Problem definition: https://leetcode.com/problems/merge-intervals/
// Accepted 2021-08-13
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        std::vector<std::vector<int>> result;
        std::vector<int> interval = {intervals[0][0], intervals[0][1]};
        for (size_t i {1}; i < intervals.size(); ++i) {
            if (intervals[i][0] <= interval[1]) {
                interval[0] = std::min(intervals[i][0], interval[0]);
                interval[1] = std::max(intervals[i][1], interval[1]);
            } else {
                result.push_back(interval);
                interval[0] = intervals[i][0];
                interval[1] = intervals[i][1];
            }
        }
        result.push_back(interval);
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,std::vector<std::vector<int>>>> input {
        {{{1,3},{2,6},{8,10},{15,18}},{{1,6},{8,10},{15,18}}},
        {{{1,4},{4,5}},{{1,5}}},{{{1,8}},{{1,8}}},{{{1,3},{1,3},{1,3}},{{1,3}}},
        {{{1,4},{5,6}},{{{1,4},{5,6}}}},
        {{{1,3},{4,6},{8,10},{15,18},{17,33}},{{1,3},{4,6},{8,10},{15,33}}},
        {{{1,4},{0,2},{3,5}},{{0,5}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.merge(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
