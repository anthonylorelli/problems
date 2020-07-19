// 0665. Non-decreasing Array
// Problem definition: https://leetcode.com/problems/non-decreasing-array/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        int count {0};
        int limit = nums.size() - 1;
        for (int i {0}; i < limit; ++i) {
            if (nums[i] > nums[i+1]) {
                count++;
                if (i > 0 && nums[i-1] > nums[i+1]) {
                    count++;
                }
                if (count > 1) {
                    return false;
                }
            }
        }
        return false;
    }

    bool checkPossibilityAdjacent(std::vector<int>& nums) {
        int count {0};
        auto predicate = std::greater<int>{};
        auto it = std::adjacent_find(nums.begin(), nums.end(), predicate);
        while (it != nums.end()) {
            if (++count > 1) {
                return false;
            }
            it = std::adjacent_find(it + 1, nums.end(), predicate);
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
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
