// 0665. Non-decreasing Array
// Problem definition: https://leetcode.com/problems/non-decreasing-array/
// Accepted 2020-07-20

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        bool updated {false};
        int limit = nums.size() - 1;
        for (int i {0}; i < limit; ++i) {
            if (nums[i] > nums[i+1]) {
                if (updated) { return false; }
                if  (i == 0) {
                    nums[i] = nums[i+1];
                } else if (nums[i+1] > nums[i-1]) {
                    nums[i] = nums[i+1];
                } else { // nums[i+1] <= nums[i-1]
                    nums[i+1] = nums[i];
                }
                updated = true;
            }
        }
        return true;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Non-decreasing Array]") {
    SECTION("Case 1") {
        std::vector<int> input = {4,2,3};
        Solution s;
        REQUIRE(s.checkPossibility(input) == true);
    }
    SECTION("Case 2") {
        std::vector<int> input = {4,2,1};
        Solution s;
        REQUIRE(s.checkPossibility(input) == false);
    }
    SECTION("Case 3") {
        std::vector<int> input = {3,4,2,3};
        Solution s;
        REQUIRE(s.checkPossibility(input) == false);
    }
    SECTION("Case 4") {
        std::vector<int> input = {2,3,3,2,4};
        Solution s;
        REQUIRE(s.checkPossibility(input) == true);
    }
    SECTION("Case 5") {
        std::vector<int> input = {-1,4,2,3};
        Solution s;
        REQUIRE(s.checkPossibility(input) == true);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
