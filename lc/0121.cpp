// 0121. Best Time to Buy and Sell Stock
// Problem definition: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Accepted 2021-09-29
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int32_t min {100000};
        int32_t profit {0};
        for (const auto p : prices) {
            min = std::min(min, p);
            if (p > min) {
                profit = std::max(profit, p - min);
            }
        }
        return profit;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{7,1,5,3,6,4},5},{{7,6,4,3,1},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxProfit(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
