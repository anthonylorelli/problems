// 0238. Product of Array Except Self
// Problem definition: https://leetcode.com/problems/product-of-array-except-self/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        return {};        
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
