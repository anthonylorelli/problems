// 0523. Continuous Subarray Sum
// Problem definition: https://leetcode.com/problems/continuous-subarray-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        return false;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Continuous Subarray Sum]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {23, 2, 4, 6, 7};
        REQUIRE(s.checkSubarraySum(v, 6));
    }
    SECTION("LC test case 2") {
        Solution s;
        std::vector<int> v = {23, 2, 4, 6, 7};
        REQUIRE(s.checkSubarraySum(v, 6));
    }
}
