// 1822. Sign of the Product of an Array
// Problem definition: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Accepted 2021-04-22
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 1, [](const auto total, const auto n) {
            return n == 0 ? 0 : n > 0 ? total : -total;
        });
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{-1,-2,-3,-4,3,2,1},1}, {{1,5,0,2,-3},0}, {{-1,1,-1,1,-1},-1}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.arraySign(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
