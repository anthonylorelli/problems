// 1712. Ways to Split Array Into Three Subarrays
// Problem definition: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Accepted 2021-05-10
// Cf. https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/1184986/Prefix-Sums-%2B-Binary-Search-or-C%2B%2B
//     https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/999596/Easy-C%2B%2B-Ways-to-Split-Array-Into-Three-Subarrays
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int waysToSplit(std::vector<int>& nums) {
        const auto s {nums.size()};
        std::vector<int32_t> prefix(s);
        std::partial_sum(nums.begin(), nums.end(), prefix.begin());
        int64_t answer {0};
        for (int32_t x {0}; x < s - 2; ++x) {
            int32_t left {prefix[x]}, remain {prefix.back() - prefix[x]};
            if (remain < left * 2) { break; }
            int32_t i = std::distance(prefix.begin(), 
                std::lower_bound(prefix.begin() + x + 1, prefix.end() - 1, 2 * left));
            int32_t j = std::distance(prefix.begin(), 
                std::upper_bound(prefix.begin() + x + 1, prefix.end() - 1, left + remain / 2)) - 1;
            if (j - i + 1 > 0) {
                answer += j - i + 1;
            }
        }
        return answer % c_mod;
    }

private:
    static constexpr int32_t c_mod {1'000'000'007};
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
