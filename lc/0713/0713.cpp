// 0713. Subarray Product Less Than K
// Problem definition: https://leetcode.com/problems/subarray-product-less-than-k/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        return 0;        
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Subarray Product Less Than K]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {10, 5, 2, 6};
        REQUIRE(s.numSubarrayProductLessThanK(v, 100) == 8);
    }
}
