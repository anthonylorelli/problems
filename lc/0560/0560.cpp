// 0560. Subarray Sum Equals K
// Problem definition: https://leetcode.com/problems/subarray-sum-equals-k/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        return 0;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Subarray Sum Equals K]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {1, 1, 1};
        REQUIRE(s.subarraySum(v, 2) == 2);
    }
}
