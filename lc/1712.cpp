// 1712. Ways to Split Array Into Three Subarrays
// Problem definition: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Accepted ?
// Cf. https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/1184986/Prefix-Sums-%2B-Binary-Search-or-C%2B%2B
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int waysToSplit(std::vector<int>& nums) {
        constexpr int32_t mod {1'000'000'007};
        const auto s {nums.size()};
        std::vector<int32_t> prefix(s);
        std::partial_sum(nums.begin(), nums.end(), prefix.begin());
        int64_t answer {0};
        for (int32_t x {0}; x < s; ++x) {
            int32_t i = std::distance(prefix.begin(), 
                std::lower_bound(prefix.begin() + x + 1, prefix.end(), 2 * prefix[x]));
            int32_t j = std::distance(prefix.begin(), 
                std::upper_bound(prefix.begin(), prefix.end() - 1, (prefix.back() + prefix[x]) / 2));
            if (j > i && j < s && i < s) {
                answer += (j - i);
            }
        }
        return answer % mod;
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
