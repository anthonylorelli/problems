// 0287. Find the Duplicate Number
// Problem definition: https://leetcode.com/problems/find-the-duplicate-number/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <numeric>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int inclusive_sum {0};
        for (auto i {1u}; i < nums.size(); ++i) {
            inclusive_sum += i;
        }

        return sum - inclusive_sum;
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
        REQUIRE(s.findDuplicate(i) == 0);
    }
}
