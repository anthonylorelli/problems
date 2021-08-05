// 0300. Longest Increasing Subsequence
// Problem definition: https://leetcode.com/problems/longest-increasing-subsequence/
// Accepted 2021-08-04
// Cf. https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326780/C%2B%2B-Clean-Easy-O(N2)-and-O(N*log(N))-Solutions
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> result(1, nums[0]);
        for (size_t i {1}; i < nums.size(); ++i) {
            auto offset = std::distance(result.begin(), 
                std::lower_bound(result.begin(), result.end(), nums[i]));
            if (offset >= result.size()) {
                result.push_back(nums[i]);
            } else {
                result[offset] = nums[i];
            }
        }
        return result.size();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{10,9,2,5,3,7,101,18},4},{{0,1,0,3,2,3},4},{{7,7,7,7,7,7,7},1},
        {{1,3,6,7,9,4,10,5,6},6}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.lengthOfLIS(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
