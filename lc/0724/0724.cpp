// 0724. Find Pivot Index
// Problem definition: https://leetcode.com/problems/find-pivot-index/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        return 0;        
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
}

TEST_CASE("Local test cases", "[Find Pivot Index]") {
    Solution s;
    SECTION("Test case 1") {
        std::vector<int> v = {1, 7, 3, 6, 5, 6};
        REQUIRE(s.pivotIndex(v) == 3);
    }
    SECTION("Test case 2") {
        std::vector<int> v = {1, 2, 3};
        REQUIRE(s.pivotIndex(v) == -1);
    }
}
