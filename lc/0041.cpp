// 0041. First Missing Positive
// Problem definition: https://leetcode.com/problems/first-missing-positive/
// Accepted 2019-08-25

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        for (size_t i {0}; i < nums.size(); ++i) {
            int current {nums[i]};
            if (current > 0 && current != i+1 && current <= nums.size()) {
                std::swap(nums[i], nums[current-1]);
                if (nums[i] != nums[current-1]) { i--; }
            }
        }

        for (size_t i {0}; i < nums.size(); ++i) {
            if (nums[i] != i+1) { return i+1; }
        }

        return nums.size() + 1;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[First Missing Positive]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> i = {1, 2, 0};
        REQUIRE(s.firstMissingPositive(i) == 3);
    }
    SECTION("LC test case 2") {
        std::vector<int> i = {3, 4, -1, 1};
        REQUIRE(s.firstMissingPositive(i) == 2);
    }
    SECTION("LC test case 3") {
        std::vector<int> i = {7, 8, 9, 11, 12};
        REQUIRE(s.firstMissingPositive(i) == 1);
    }    
    SECTION("LC test case 4") {
        std::vector<int> i = {};
        REQUIRE(s.firstMissingPositive(i) == 1);
    }
    SECTION("LC test case 4") {
        std::vector<int> i = {1};
        REQUIRE(s.firstMissingPositive(i) == 2);
    }
}

TEST_CASE("Local test cases", "[First Missing Positive]") {
    Solution s;
    SECTION("Test case 1") {
        std::vector<int> i = {0, 2, 1};
        REQUIRE(s.firstMissingPositive(i) == 3);
    }
    SECTION("Test case 2") {
        std::vector<int> i = {1, -1, 4, 3};
        REQUIRE(s.firstMissingPositive(i) == 2);
    }
    SECTION("Test case 3") {
        std::vector<int> i = {12, 11, 10, 9, 8, 7};
        REQUIRE(s.firstMissingPositive(i) == 1);
    }
    SECTION("Test case 4") {
        std::vector<int> i = {2, 2, 2, 2, 0, 3};
        REQUIRE(s.firstMissingPositive(i) == 1);
    }
}
