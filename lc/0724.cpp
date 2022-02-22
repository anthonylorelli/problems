// 0724. Find Pivot Index
// Problem definition: https://leetcode.com/problems/find-pivot-index/
// Accepted 2019-08-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        if (nums.size() > 0) {
            int left {0}, sum {std::accumulate(nums.begin(), nums.end(), 0)};
            for (size_t i {0}; i < nums.size(); ++i) {
                if ((sum - nums[i] - left) == left) { return i; }
                left += nums[i];
            }
        }
        return -1;
    }

    int pivotIndexInPlace(std::vector<int>& nums) {
        if (nums.size() > 0) { 
            std::partial_sum(nums.begin(), nums.end(), nums.begin());
            int final {*nums.rbegin()};
            for (size_t i {0}; i < nums.size(); ++i) {
                int left {i == 0 ? 0 : nums[i-1]};
                if (left == final - nums[i]) { return i; }
            }
        }
        return -1;
    }

    int pivotIndexPartialSum(std::vector<int>& nums) {
        if (nums.size() > 0) { 
            std::vector<int> s(nums.size());
            std::partial_sum(nums.begin(), nums.end(), s.begin());
            int final {*s.rbegin()};
            for (size_t i {0}; i < s.size(); ++i) {
                int left {i == 0 ? 0 : s[i-1]};
                if (left == final - s[i]) { return i; }
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Find Pivot Index]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> v = {1, 7, 3, 6, 5, 6};
        REQUIRE(s.pivotIndex(v) == 3);
    }
    SECTION("LC test case 2") {
        std::vector<int> v = {1, 2, 3};
        REQUIRE(s.pivotIndex(v) == -1);
    }
    SECTION("LC test case 3") {
        std::vector<int> v = {-1, -1, -1, 0, 1, 1};
        REQUIRE(s.pivotIndex(v) == 0);
    }
}

TEST_CASE("Local test cases", "[Find Pivot Index]") {
    Solution s;
    SECTION("Test case 1") {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 15};
        REQUIRE(s.pivotIndex(v) == 5);
    }
    SECTION("Test case 2") {
        std::vector<int> v = {1, 1, 1, 1, 1, 1};
        REQUIRE(s.pivotIndex(v) == -1);
    }
    SECTION("Test case 3") {
        std::vector<int> v = {0, 0, 0, 0, 0, 0};
        REQUIRE(s.pivotIndex(v) == 0);
    }
    SECTION("Test case 4") {
        std::vector<int> v = {};
        REQUIRE(s.pivotIndex(v) == -1);
    }
    SECTION("Test case 5") {
        std::vector<int> v = {0};
        REQUIRE(s.pivotIndex(v) == 0);
    }
    SECTION("Test case 6") {
        std::vector<int> v = {0, 0};
        REQUIRE(s.pivotIndex(v) == 0);
    }
    SECTION("Test case 7") {
        std::vector<int> v = {0, 0, 0};
        REQUIRE(s.pivotIndex(v) == 0);
    }
    SECTION("Test case 8") {
        std::vector<int> v = {1, 0};
        REQUIRE(s.pivotIndex(v) == 0);
    }
    SECTION("Test case 9") {
        std::vector<int> v = {1, 1};
        REQUIRE(s.pivotIndex(v) == -1);
    }
}
