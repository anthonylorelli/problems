// 0278. First Bad Version
// Problem definition: https://leetcode.com/problems/first-bad-version/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <numeric>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        std::vector<int> v(n);
        std::iota(v.begin(), v.end(), 1);
        auto first {std::upper_bound(v.begin(), v.end(), 1, [](const int i, const int j) { 
            const bool iIsBad {isBadVersion(i)};
            const bool jIsBad {isBadVersion(j)};
            return !iIsBad && jIsBad ? true : false;
        })};
        return first != v.end() ? *first : *v.begin();
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
