// 0057. Insert Interval
// Problem definition: https://leetcode.com/problems/insert-interval/
// Accepted 2021-08-12
// Cf. https://leetcode.com/problems/insert-interval/discuss/1327206/99.16-faster-or-proper-explainationor-c%2B%2B-solutionor-O(N)
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        insert(intervals.begin(), intervals.end(), newInterval, result);
        return result;
    }

    template<typename It, typename End, typename Result>
    void insert(It begin, End end, std::vector<int>& interval, Result& result) {
        if (begin == end) {
            result.push_back(interval);
            return;
        }
        while (begin != end && (*begin)[1] < interval[0]) {
            result.push_back(*begin++);
        }
        if (begin != end) {
            interval[0] = std::min(interval[0], (*begin)[0]);
        }
        while (begin != end && interval[1] >= (*begin)[0]) {
            interval[1] = std::max(interval[1], (*begin++)[1]);
        }
        result.push_back(interval);
        while (begin != end) {
            result.push_back(*begin++);
        }
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,std::vector<int>,std::vector<std::vector<int>>>> input {
        {{{1,3},{6,9}},{2,5},{{1,5},{6,9}}},
        {{{1,2},{3,5},{6,7},{8,10},{12,16}},{4,8},{{1,2},{3,10},{12,16}}},
        {{},{5,7},{{5,7}}},
        {{{1,5}},{2,3},{{1,5}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, interval, expected] = p;
                REQUIRE(s.insert(testInput, interval) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
