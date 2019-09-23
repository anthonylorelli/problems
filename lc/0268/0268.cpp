// 0268. Missing Number
// Problem definition: https://leetcode.com/problems/missing-number/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Shortest Palindrome]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.missingNumber(p.first) == p.second); 
            });
    }
}
