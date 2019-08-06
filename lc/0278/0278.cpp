// 0278. First Bad Version
// Problem definition: https://leetcode.com/problems/first-bad-version/
// Accepted 2019-08-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return 0;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[First Bad Version]") {
    Solution s;
    SECTION("LC test case 1") {
    }
}

TEST_CASE("Local test cases", "[Find Pivot Index]") {
    Solution s;
    SECTION("Test case 1") {
    }
}
