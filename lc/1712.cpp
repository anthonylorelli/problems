// 1712. Ways to Split Array Into Three Subarrays
// Problem definition: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int waysToSplit(std::vector<int>& nums) {
        constexpr int32_t mod {1'000'000'000+7};
        std::vector<int32_t> prefix(nums.size());
        std::partial_sum(nums.begin(), nums.end(), prefix.begin());
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{1,1,1},1},{{1,2,2,2,5,0},3},{{3,2,1},0}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.waysToSplit(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
