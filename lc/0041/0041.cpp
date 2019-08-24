// 0041. First Missing Positive
// Problem definition: https://leetcode.com/problems/first-missing-positive/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <limits>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int high {std::numeric_limits<int>::max()};
        int low {1};
        for (const auto i : nums) {
            if (i > 1 && i < high) {
                high = i - 1;
            } else if (i == low) {
                low++;
            }
        }
        return low;
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
}

TEST_CASE("Local test cases", "[First Missing Positive]") {
    Solution s;
    SECTION("Test case 1") {
    }
}
