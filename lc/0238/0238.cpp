// 0238. Product of Array Except Self
// Problem definition: https://leetcode.com/problems/product-of-array-except-self/
// Accepted 2019-07-26
// Adapted from: https://leetcode.com/problems/product-of-array-except-self/discuss/148153/C%2B%2B-solution-O(n)-without-extra-space-with-explanation

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> products(nums.size(), 1);
        int preProduct {1}, postProduct {1};
        for (size_t i {0}, j {nums.size() - 1}; i < nums.size(); ++i, --j) {
            products[i] *= preProduct;
            products[j] *= postProduct;
            preProduct *= nums[i];
            postProduct *= nums[j];
        }
        return products;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Product of Array Except Self]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {1, 2, 3, 4};
        std::vector<int> product = {24, 12, 8, 6};
        REQUIRE(s.productExceptSelf(v) == product);
    }
}
