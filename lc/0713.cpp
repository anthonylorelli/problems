// 0713. Subarray Product Less Than K
// Problem definition: https://leetcode.com/problems/subarray-product-less-than-k/
// Accepted 2019-07-26
// Adapted from: https://leetcode.com/problems/subarray-product-less-than-k/discuss/108830/C%2B%2B-concise-solution-O(n)

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        int product {1}, answer{0};
        for (size_t i {0}, left {0}; i < nums.size(); ++i) {
            product *= nums[i];
            while (product >= k && left <= i) { product /= nums[left++]; }
            answer += i - left + 1;
        }
        return answer;
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
