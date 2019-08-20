// 0035. Search Insert Position
// Problem definition: https://leetcode.com/problems/search-insert-position/
// Accepted 2019-08-19

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto l {std::lower_bound(nums.cbegin(), nums.cend(), target)};
        return l != nums.cend() ? l - nums.cbegin() : static_cast<int>(nums.size());
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Search Insert Position]") {
    Solution s;
    std::vector<int> i = {1, 3, 5, 6};
    SECTION("LC test case 1") {
        REQUIRE(s.searchInsert(i, 5) == 2);
    }
    SECTION("LC test case 2") {
        REQUIRE(s.searchInsert(i, 2) == 1);
    }
    SECTION("LC test case 3") {
        REQUIRE(s.searchInsert(i, 7) == 4);
    }
    SECTION("LC test case 4") {
        REQUIRE(s.searchInsert(i, 0) == 0);
    }
}

TEST_CASE("Local test cases", "[Search Insert Position]") {
    Solution s;
    std::vector<int> i = {1, 3, 5, 6};
    SECTION("Element found") {
        REQUIRE(s.searchInsert(i, 1) == 0);
        REQUIRE(s.searchInsert(i, 3) == 1);
        REQUIRE(s.searchInsert(i, 5) == 2);
        REQUIRE(s.searchInsert(i, 6) == 3);
    }
}