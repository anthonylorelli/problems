// 1672. Richest Customer Wealth
// Problem definition: https://leetcode.com/problems/richest-customer-wealth/
// Accepted 2021-04-23
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int32_t max {0};
        for (const auto& customer : accounts) {
            max = std::max(max, std::accumulate(customer.begin(), customer.end(), 0));
        }
        return max;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,int>> input {
        {{{1,2,3},{3,2,1}},6},{{{1,5},{7,3},{3,5}},10},{{{2,8,7},{7,1,3},{1,9,5}},17}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.maximumWealth(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
