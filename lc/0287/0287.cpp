// 0287. Find the Duplicate Number
// Problem definition: https://leetcode.com/problems/find-the-duplicate-number/
// Accepted 2019-08-21
// Adapted from: https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.
// which is based on: https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow {nums[0]};
        int fast {nums[nums[0]]};
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Find the Duplicate Number]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> i = {1, 3, 4, 2, 2};
        REQUIRE(s.findDuplicate(i) == 2);
    }
    SECTION("LC test case 2") {
        std::vector<int> i = {3, 1, 3, 4, 2};
        REQUIRE(s.findDuplicate(i) == 3);
    }
    SECTION("LC test case 3") {
        std::vector<int> i = {2, 2, 2, 2, 2};
        REQUIRE(s.findDuplicate(i) == 2);
    }    
    SECTION("LC test case 4") {
        std::vector<int> i = {18,13,14,17,9,19,7,17,4,6,17,5,11,10,2,15,8,12,16,17};
        REQUIRE(s.findDuplicate(i) == 17);
    }    
}

TEST_CASE("Local test cases", "[Find the Duplicate Number]") {
    Solution s;
    SECTION("Test case 1") {
        std::vector<int> i = {1, 3, 2, 4, 5, 4};
        REQUIRE(s.findDuplicate(i) == 4);
    }
}
