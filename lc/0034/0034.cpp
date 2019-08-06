// 0034. Find First and Last Position of Element in Sorted Array
// Problem definition: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Accepted 2019-08-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto lower {std::lower_bound(nums.begin(), nums.end(), target)};
        auto upper {std::upper_bound(nums.begin(), nums.end(), target)};
        std::vector<int> a(2, -1);
        if (lower != nums.end() && *lower == target) {
            a[0] = lower - nums.begin();
            a[1] = upper - 1 - nums.begin();
        }
        return a;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Find First and Last Position of Element in Sorted Array]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> v = {5, 7, 7, 8, 8, 10};
        std::vector<int> a = {3, 4};
        REQUIRE(s.searchRange(v, 8) == a);
    }
    SECTION("LC test case 2") {
        std::vector<int> v = {5, 7, 7, 8, 8, 10};
        std::vector<int> a = {-1, -1};
        REQUIRE(s.searchRange(v, 6) == a);
    }
}

TEST_CASE("Local test cases", "[Find Pivot Index]") {
    Solution s;
    SECTION("Test case 1") {
        std::vector<int> v = {5, 7, 7, 8, 8, 10};
        std::vector<int> a = {-1, -1};
        REQUIRE(s.searchRange(v, 6) == a);
    }
    SECTION("Test case 2") {
        std::vector<int> v = {5, 7, 8, 10, 11, 12};
        std::vector<int> a = {-1, -1};
        REQUIRE(s.searchRange(v, 9) == a);
    }
    SECTION("Test case 3") {
        std::vector<int> v = {5, 7, 8, 9, 10, 11, 12};
        std::vector<int> a = {3, 3};
        REQUIRE(s.searchRange(v, 9) == a);
    }
    SECTION("Test case 4") {
        std::vector<int> v = {5, 7, 8, 9, 10, 11, 12};
        std::vector<int> a = {6, 6};
        REQUIRE(s.searchRange(v, 12) == a);
    }
}
