// 0354. Russian Doll Envelopes
// Problem definition: https://leetcode.com/problems/russian-doll-envelopes/
// Accepted 2021-08-28
// Cf. https://leetcode.com/problems/russian-doll-envelopes/discuss/1410015/C%2B%2B-or-NLogN-or-LIS-beats-80-or-commented-code-or-Easy-explanation
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        std::vector<int> dp(1, envelopes[0][1]);
        std::for_each(envelopes.begin() + 1, envelopes.end(), [&dp](const auto& a) {
            auto iter = std::lower_bound(dp.begin(), dp.end(), a[1]);
            if (iter == dp.end()) {
                dp.push_back(a[1]);
            } else if (*iter > a[1]) {
                *iter = a[1];
            }
        });
        return dp.size();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,int>> input {
        {{{5,4},{6,4},{6,7},{2,3}},3},{{{1}},1},
        {{{1,10},{10,1},{11,2},{12,3}},3},
        {{{1,10},{1,11},{1,12}},1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxEnvelopes(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
